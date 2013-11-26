#include "udp.h"
//#include "Socket.h"  // For Socket, ServerSocket, and SocketException
#include <iostream>           // For cout, cerr
#include <cstdlib>            // For atoi()  
/*#ifdef WIN32
#include "pthread.h"     // For POSIX threads on Windows  
#else
#include <thread.h>      // For POSIX threads on Unix
#endif*/
#include <thread>
#include <Windows.h>

namespace netsvc{
	udp::udp(){}

	udp::~udp(){}

	udp::udp(int _port){
		port = _port;
	}

	void udp::close(){
		stop = true;
		messagesToApp->push(xml::XMLMessage());
	}

	void udp::setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp){
		messagesFromApp = _messagesFromApp;
		messagesToApp = _messagesToApp;
	}

	const int RCVBUFSIZE = 255;

	void udp::startClient(TCPSocket* sock){
		int id = -1;
		std::cout << "Handling client ";
		try {
			std::cout << sock->getForeignAddress() << ":";
		} catch (SocketException &e) {
			std::cerr << "Unable to get foreign address" << std::endl;
		}
		try {
			std::cout << sock->getForeignPort();
		} catch (SocketException &e) {
			std::cerr << "Unable to get foreign port" << std::endl;
		}
		std::cout << " with new thread " << std::thread::id() << std::endl; // << pthread_self()

		char echoBuffer[RCVBUFSIZE];
		int recvMsgSize;
		while(!stop){
			if(id > 0 && !messagesFromApp->empty()){
				if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::CLOSE){
					close();
				} else if(messagesFromApp->front().getMessageTypeEnum() == xml::MessageType::CLOSE_CONFIRM){
					//close();
				}
				std::cout << ">> zprava od RC\n";
				messagesFromApp->pop();
			}
			/*while ((recvMsgSize = sock->recv(echoBuffer, RCVBUFSIZE)) > 0) {
				string s = "";
				for(int i=0; i<recvMsgSize; i++){
					s += echoBuffer[i];
				}

				if(s.compare("echo\n") == 0){
					cout << "jsem tu... ";
					cout << s << " " << recvMsgSize << endl;
					sock->send(echoBuffer, recvMsgSize);
					return;
				} else{
					cout << s << " " << recvMsgSize << endl;
					sock->send(echoBuffer, recvMsgSize);//sock->send("ahoj", 4);
				}
			}*/
		}
	}

	void udp::startServer(){
		stop = false;
		std::cout << ">> spusten TCP server...\n";
		unsigned short servPort = port;
		try {
			TCPServerSocket servSock(servPort);
			while(!stop){  
			TCPSocket *clntSock = servSock.accept();
			std::thread client(&udp::startClient, this, clntSock);
			client.detach();
		}
	  } catch (SocketException &e) {
		std::cerr << e.what() << std::endl;
		exit(1);
	  }
	}
};