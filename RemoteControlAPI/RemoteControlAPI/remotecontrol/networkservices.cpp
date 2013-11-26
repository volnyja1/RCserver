#include "networkservices.h"
#include <iostream>
#include <thread>

namespace netsvc{

	NetworkServices::NetworkServices(){
		countOfClients = 0;
	}

	void NetworkServices::setQueues(std::queue<xml::XMLMessage> &_messagesToApp, std::queue<xml::XMLMessage> &_messagesFromApp){
		//std::cout << "NetworkServices created" << std::endl;
		messagesToApp = &_messagesToApp;
		messagesFromApp = &_messagesFromApp;
	}

	NetworkServices::~NetworkServices(){
		//std::cout << "NetworkServices detroyed" << std::endl;
	}

	void NetworkServices::setProtocol(ProtocolType _type){
		protocol = _type;
	}

	void NetworkServices::setServer(Sock _server){
		server = _server;
	}

	void NetworkServices::start(){
		switch (protocol){
		case ProtocolType::TCP:
			startTCP();
			break;
		case ProtocolType::UDP:
			startUDP();
			break;
		default:
			startTCP();
			break;
		}
	}

	void NetworkServices::createTCP(){
		tcp t = tcp(server.getLocalPort(), countOfClients);
		t.setQueues(messagesToApp, messagesFromApp);
		t.startServer();
	}

	void NetworkServices::createUDP(){
		//udp u = udp(server.getLocalPort());
		//u.setQueues(messagesToApp, messagesFromApp, countOfClients);
		//u.startServer();
	}

	void NetworkServices::startTCP(){
		std::thread tcp(&NetworkServices::createTCP, this);
		tcp.detach();
	}

	void NetworkServices::startUDP(){
		std::thread u(&NetworkServices::createUDP, this);
		u.detach();
	}

	void NetworkServices::close(std::vector<int> ids){
		std::vector<int>::iterator it;
		for (it = ids.begin(); it != ids.end(); it++)
		{
			xml::XMLMessage m;
			m.setId(*it);
			m.setMessageType("close");
			messagesFromApp->push(m);
		}
	}

	void NetworkServices::run(){
		int client = -2;
		for (int i = 0; i < countOfClients; i++)
		{
			xml::XMLMessage m;
			m.setId(client--);
			m.setMessageType("start");
			messagesFromApp->push(m);
		}
	}

	void NetworkServices::sendBroadcast(std::vector<int> ids, xml::XMLMessage _m){
		std::vector<int>::iterator it;
		for (it = ids.begin(); it != ids.end(); it++)
		{
			xml::XMLMessage m;
			m.setId(*it);
			m.setMessageType(_m.getMessageType());
			m.setData(_m.getData());
			m.setTextContent(_m.getTextContent());
			m.setPort(_m.getPort());
			messagesFromApp->push(m);
		}
	}

}