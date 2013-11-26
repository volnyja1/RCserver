#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <string>
#include "socket.h"

namespace netsvc{
	class UDPClient{
	public:
		UDPClient();
		UDPClient(std::string _ip, int _port);
		~UDPClient();
		void setIP(std::string _ip);
		void setPortRecvFrom(int _port);
		void setPortSendTo(int _port);
		std::string getIP();
		int getPortRecvFrom();
		int getPortSendTo();
	private:
		int portSendTo, portRecvFrom;
		std::string ip;
	};
}

#endif;