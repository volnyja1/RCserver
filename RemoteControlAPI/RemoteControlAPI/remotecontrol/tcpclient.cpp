#include "tcpclient.h"

namespace netsvc{
	TCPClient::TCPClient(){
		std::cout << "Client created" << std::endl;
	}

	TCPClient::TCPClient(TCPSocket* _sock, int _tempId){
		sock = _sock;
		ip = _sock->getForeignAddress();
		port = _sock->getForeignPort();
		id = _tempId;
		std::cout << "Client created" << std::endl;
	}

	TCPClient::~TCPClient(){
		std::cout << "Client destroyed" << std::endl;
	}

	void TCPClient::setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp){
		messagesFromApp = _messagesFromApp;
		messagesToApp = _messagesToApp;
	}

	void TCPClient::setIP(std::string _ip){
		ip = _ip;
	}

	std::string TCPClient::getIP(){
		return ip;
	}

	void TCPClient::setPort(int _port){
		port = _port;
	}

	int TCPClient::getPort(){
		return port;
	}

	void TCPClient::sendMessageToClient(xml::XMLMessage m){
		std::string s = xml::XMLParser::getText(m)+"\n";
		char *buffer = (char*)s.c_str();
		int msgSize = s.size();
		sock->send(buffer, msgSize);
	}

	void TCPClient::handleAppEvents(){
		if(!messagesFromApp->empty()){
			int id1 = messagesFromApp->front().getIdInt();
			if(id1 == id || id1 == -1){
				//std::cout << "app event for id "<< id << "\n";
				if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::CLOSE){
					sendMessageToClient(messagesFromApp->front());
					close();
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::CONFIGURATION){
					xml::XMLMessage mess = messagesFromApp->front();
					std::cout << messagesFromApp->front().getData();
					int newId = xml::XMLParser::ActualizeTempId(mess);
					id = newId;
					mess.setId(std::to_string(id));
					sendMessageToClient(mess);
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::CLOSE_CONFIRM){
					//close();
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::ALIVE){
					sendMessageToClient(messagesFromApp->front());
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::DATA){
					sendMessageToClient(messagesFromApp->front());
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::ERR){
					sendMessageToClient(messagesFromApp->front());
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::START){
					sendMessageToClient(messagesFromApp->front());
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::OTHER){
					sendMessageToClient(messagesFromApp->front());
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::HELLO){
					sendMessageToClient(messagesFromApp->front());
				}
				messagesFromApp->pop();
			}
		}
	}

	void TCPClient::handleClientEvents(){
		const int BUFSIZE = 255;
		char echoBuffer[BUFSIZE];
		int recvMsgSize;
		try{
			recvMsgSize = sock->recv(echoBuffer, BUFSIZE);
			/*if(errno = EWOULDBLOCK)
				return;*/
			if(recvMsgSize > 0){
				std::string s = "";
				for(int i=0; i<recvMsgSize; i++){
					s += echoBuffer[i];
				}
				xml::XMLMessage mess = xml::XMLParser::getMessage(s);
				if(mess.getMessageType().compare("")==0){
					mess.setMessageType("error");
					mess.setData("Error: Incorrect type.");
				}
				if(mess.getId().compare("")==0){
					mess.setId(id);
				}
				if(mess.getIdInt()!=id){
					mess.setMessageType("error");
					mess.setData("Error: incorrect id");
					mess.setId(id);
				}
				if(mess.getMessageTypeEnum() == xml::MessageType::CONNECT){
					xml::XMLClientConfData data = mess.getStructuredData();
					data.setIp(sock->getForeignAddress());
					data.setPort(sock->getForeignPort());
					mess.setStructuredData(data);
				} else if(mess.getMessageTypeEnum() == xml::MessageType::DATA){
					if(mess.getPort().compare("")==0){
						mess.setMessageType("error");
						mess.setData("Error: Port number not set");
					}
				}
				messagesToApp->push(mess);
			}
		} catch(...){
		}
	}

	void TCPClient::start(){
		clientStop = false;
		std::cout << "Handling client ";
		try {
			std::cout << sock->getForeignAddress() << ":";
		} catch (SocketException &e) {
			std::cerr << "Unable to get foreign address" << std::endl;
		}
		try {
			std::cout << sock->getForeignPort() << std::endl;
		} catch (SocketException &e) {
			std::cerr << "Unable to get foreign port" << std::endl;
		}
		//cout << " with new thread " << std::thread::id::id() << endl; // << pthread_self()

		try{
			sock->setNonblocking();
		} catch (SocketException &e){
			std::cerr << "Unable to set non-blocking" << std::endl;
		}

		while(!clientStop){
			handleAppEvents();
			handleClientEvents();
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

	void TCPClient::close(){
		clientStop = true;
	}
}