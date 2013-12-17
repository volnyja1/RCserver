#include "tcp.h"

namespace netsvc{
	tcp::tcp(){}

	tcp::~tcp(){}

	tcp::tcp(int _port, int &_countOfClients){
		port = _port;
		countOfClients = &_countOfClients;
	}

	void tcp::close(){
		stop = true;
		messagesToApp->push(xml::XMLMessage());
	}

	void tcp::setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp){
		messagesFromApp = _messagesFromApp;
		messagesToApp = _messagesToApp;
	}

	const int RCVBUFSIZE = 255;

	void tcp::startClient(TCPSocket* sock){
		TCPClient client(sock, clientId--);
		(*countOfClients)++;
		client.setQueues(messagesToApp, messagesFromApp);
		client.start();
	}

	void tcp::startServer(){
		stop = false;
		clientId = -2;
		std::cout << ">> spusten TCP server na portu " << port << "...\n";
		unsigned short servPort = port;
		try {
			TCPServerSocket servSock(servPort);
			while(true){
				TCPSocket *clntSock = servSock.accept();
				std::cout << ">> novy klient\n";
				//startClient(clntSock);
				std::thread client(&tcp::startClient, this, clntSock);
				client.detach();
				//std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}
		} catch (SocketException &e) {
			std::cerr << e.what() << std::endl;
			exit(1);
		}
	}
};