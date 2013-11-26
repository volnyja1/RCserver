#include "udpclient.h"
#include <iostream>

namespace netsvc{
	UDPClient::UDPClient(){
		std::cout << "Client created" << std::endl;
	}

	UDPClient::~UDPClient(){
		std::cout << "Client destroyed" << std::endl;
	}

	void UDPClient::setIP(std::string _ip){
		ip = _ip;
	}

	std::string UDPClient::getIP(){
		return ip;
	}

	void UDPClient::setPortRecvFrom(int _port){
		portRecvFrom = _port;
	}

	void UDPClient::setPortSendTo(int _port){
		portSendTo = _port;
	}

	int UDPClient::getPortRecvFrom(){
		return portRecvFrom;
	}

	int UDPClient::getPortSendTo(){
		return portSendTo;
	}
}