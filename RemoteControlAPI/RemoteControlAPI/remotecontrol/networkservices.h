#ifndef NETWORKSERVICES_H
#define NETWORKSERVICES_H

//#include "client.h"
//#include "server.h"
#include <vector>
#include <queue>
#include "tcp.h"
#include "sock.h"

namespace netsvc{

	int DEFAULT_PORT = 62000;

	enum ProtocolType{
		TCP,
		UDP
	};

	class NetworkServices{
	public:
		NetworkServices();
		~NetworkServices();
		void setQueues(std::queue<xml::XMLMessage> &_messagesToApp, std::queue<xml::XMLMessage> &_messagesFromApp);
		void start();
		void close(std::vector<int> ids);
		void run();
		void sendBroadcast(std::vector<int> ids, xml::XMLMessage m);
		void setProtocol(ProtocolType);
		void setServer(Sock _server);
		Sock getServer();
	private:
		void createTCP();
		void createUDP();
		void startTCP();
		void startUDP();
		ProtocolType protocol;
		Sock server;
		std::vector<Sock> clients;
		std::queue<xml::XMLMessage> *messagesToApp;
		std::queue<xml::XMLMessage> *messagesFromApp;
		int countOfClients;
	};
}

#endif;