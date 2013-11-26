#ifndef UDP_H
#define UDP_H

#include <queue>
#include <mutex>
#include "xmlparser.h"
#include "udpclient.h"

namespace netsvc{
	class udp{
	public:
		udp();
		udp(int _port);
		~udp();
		void startServer();
		void startClient(TCPSocket* a);
		void setQueues(std::queue<xml::XMLMessage> *_messagesToApp, std::queue<xml::XMLMessage> *_messagesFromApp);
	private:
		void close();
		int port;
		bool stop;
		std::queue<xml::XMLMessage> *messagesToApp;
		std::queue<xml::XMLMessage> *messagesFromApp;
	};
};

#endif;