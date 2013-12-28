#ifndef API_H
#define API_H

#include "remotecontrol.h"

namespace rc{

	class RemoteControlAPI{
	public:
		static RemoteControlAPI &getInstance();
		void registerAction(boost::any f, int primtiveType, std::string name, int preferedModule, int context);
		void registerDefaultAction(boost::any f, int actionType, int context);
		void registerListener(int actionType, int primtiveType, std::string name, int preferedModule, int context);
		void executeActions();
		void setContext(int context);
		void start();
		void close();
		void setConfigFile(std::string filename);
	private:
		RemoteControlAPI();
		~RemoteControlAPI();
		RemoteControlAPI(const RemoteControlAPI &);
		const RemoteControlAPI &operator =(const RemoteControlAPI &);
		void checkQueue();
		void createRC();
		void RCcreator();
		std::queue<Command> commandsFromRC;
		std::queue<Command> commandsFromApp;
	};
}

#endif;