#ifndef TCP_H
#define TCP_H

#include <mutex>
#include "xmlparser.h"
#include "tcpclient.h"
//#include "Socket.h"

namespace netsvc{
	class tcp{
	public:
		tcp();
		tcp(int _port, int &_countOfClients);
		~tcp();
		void startServer();
		void startClient(TCPSocket* a);
		void setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp);
	private:
		void close();
		int port, clientId, *countOfClients;
		bool stop;
		std::queue<xml::XMLMessage> *messagesToApp;
		std::queue<xml::XMLMessage> *messagesFromApp;
	};
};

#endif;