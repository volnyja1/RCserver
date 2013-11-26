#include "sock.h"
#include <iostream>

namespace netsvc{
	Sock::Sock(){
		//std::cout << "Socket created" << std::endl;
	}

	Sock::Sock(int _localPort){
		localPort = _localPort;
	}

	Sock::Sock(std::string _ip, int _localPort){
		ip = _ip;
		localPort = _localPort;
	}

	Sock::Sock(std::string _ip, int _localPort, int _remotePort){
		ip = _ip;
		localPort = _localPort;
		remotePort = _remotePort;
	}

	Sock::~Sock(){
		//std::cout << "Socket destroyed" << std::endl;
	}

	void Sock::setIP(std::string _ip){
		ip = _ip;
	}

	std::string Sock::getIP(){
		return ip;
	}

	void Sock::setRemotePort(int _port){
		remotePort = _port;
	}

	int Sock::getRemotePort(){
		return remotePort;
	}

	void Sock::setLocalPort(int _port){
		localPort = _port;
	}

	int Sock::getLocalPort(){
		return localPort;
	}

	void Sock::setId(int _id){
		id = _id;
	}

	int Sock::getId(){
		return id;
	}

}