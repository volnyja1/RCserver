#include "clientconfig.h"

namespace rc{
	ClientConfig::ClientConfig(){}

	ClientConfig::ClientConfig(std::string _IP, int _port, std::string _device, int _type){
		IP = _IP;
		port = _port;
		device = _device;
		type = _type;
	}

	ClientConfig::~ClientConfig(){}

	ClientStates ClientConfig::getState(){
		return state;
	}

	void ClientConfig::setState(ClientStates _state){
		state = _state;
	}

	void ClientConfig::setId(int _id){
		id = _id;
	}

	ClientControl::ClientControl(){}

	ClientControl::~ClientControl(){}

	int ClientControl::addClient(ClientConfig client){
		int max = 0;
		std::map<int,ClientConfig>::iterator it;
		for (it=clients.begin(); it!=clients.end(); ++it){
			max = it->first;
		}
		int id = max+1;
		client.setId(id);
		clients[id] = client;
		return id;
	}

	ClientConfig ClientControl::getClient(int id){
		return clients[id];
	}

	std::vector<int> ClientControl::getAllClientIds(){
		std::vector<int> v;
		std::map<int,ClientConfig>::iterator it;
		for (it = clients.begin(); it != clients.end(); it++)
		{
			v.push_back(it->first);
		}
		return v;
	}

	void ClientControl::stopClient(int id){
		clients[id].setState(ClientStates::C_TERMINATING);
	}

	bool ClientControl::closeConfirmed(){
		bool terminating = true;
		std::map<int,ClientConfig>::iterator it;
		for (it = clients.begin(); it != clients.end(); it++)
		{
			if(it->second.getState() != ClientStates::C_TERMINATING){
				terminating = false;
			}
		}
		return terminating;
	}
}