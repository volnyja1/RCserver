#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>
#include <queue>
#include <thread>
#include <iostream>
#include "xmlparser.h"
#include "socket.h"

namespace netsvc{
	class TCPClient{
	public:
		TCPClient();
		TCPClient(TCPSocket* sock, int _id);
		TCPClient(std::string _ip, int _port);
		~TCPClient();
		void setIP(std::string _ip);
		void setPort(int _port);
		void setId(int id);
		std::string getIP();
		int getPort();
		int getId();
		void startReceiver();
		void startSender();
		void start();
		void run();
		void close();
		void setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp);
	private:
		void handleAppEvents();
		void sendMessageToClient(xml::XMLMessage m);
		void handleClientEvents();
		bool clientStop;
		int port, id, bufSize;
		std::string ip;
		TCPSocket* sock;
		std::queue<xml::XMLMessage> *messagesToApp;
		std::queue<xml::XMLMessage> *messagesFromApp;
	};
}

#endif;