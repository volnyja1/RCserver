#ifndef SOCK_H
#define SOCK_H

#include <string>

namespace netsvc{
	class Sock{
	public:
		Sock();
		Sock(int _localPort);
		Sock(std::string _ip, int _portRecvFrom);
		Sock(std::string _ip, int _portRecvFrom, int _portSendTo);
		~Sock();
		void setIP(std::string _ip);
		void setRemotePort(int _port);
		void setLocalPort(int _port);
		void setId(int _id);
		std::string getIP();
		int getRemotePort();
		int getLocalPort();
		int getId();
	private:
		int remotePort, localPort, id;
		std::string ip;
	};
}

#endif;