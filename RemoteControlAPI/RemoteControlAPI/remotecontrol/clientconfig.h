#ifndef CLIENT_CONFIG_H
#define CLIENT_CONFIG_H

#include <map>
#include <vector>

namespace rc{

	enum ClientStates{
		C_CONNECTING,
		C_RUNNING,
		C_NOT_RESPONDING,
		C_TERMINATING,
		C_DISCONNECTED
	};

	class ClientConfig{
	public:
		ClientConfig();
		ClientConfig(std::string _IP, int _port, std::string _device, int _type);
		~ClientConfig();
		ClientStates getState();
		std::string getIP();
		std::string getDevice();
		int getType();
		int getId();
		int getPort();
		void setState(ClientStates _state);
		void setId(int _id);
		void setPort(int _port);
		void setIP(std::string _IP);
		void setType(int _type);
	private:
		ClientStates state;
		std::string device, IP;
		int port, type, id;
		long int lastTimestamp;
	};

	class ClientControl{
	public:
		ClientControl();
		~ClientControl();
		int addClient(ClientConfig client);
		ClientConfig getClient(int id);
		std::vector<int>getAllClientIds();
		void stopClient(int id);
		bool closeConfirmed();
	private:
		std::map<int,ClientConfig> clients;
	};
}

#endif;