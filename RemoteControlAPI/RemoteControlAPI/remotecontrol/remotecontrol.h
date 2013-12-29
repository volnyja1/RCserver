#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <map>
#include "networkservices.h"
#include "virtualcontroller.h"
#include "application.h"
#include "clientconfig.h"
#include "command.h"
#include "rapidxml\rapidxml.hpp"

namespace rc{

	class RemoteControl{
	public:
		RemoteControl();
		~RemoteControl();
		void registerDefaultAction(boost::any _content, int _actionType, int _context);
		void registerAction(boost::any _content, int _primitiveType, std::string _name, int _preferedModule, int _context);
		void registerToDefault(int _actionType, int _primitiveType, std::string _name, int _preferedModule, int _context);
		void parseController(int context, rapidxml::xml_node<> *node);
		void parseContext(rapidxml::xml_node<> *node);
		void setQueues(std::queue<Command> &_commandsFromRC, std::queue<Command> &_commandsFromApp);
		void runQueues();
		void start();
		void run();
		void close();
		bool stop;
	private:
		void handleAppEvents();
		void handleClientEvents();
		netsvc::NetworkServices netServices;
		VControl vrc;
		Application app;
		ClientControl clients;
		std::queue<Command> *commandsFromRC;
		std::queue<Command> *commandsFromApp;
		std::queue<xml::XMLMessage> messagesFromNetwork;
		std::queue<xml::XMLMessage> messagesToNetwork;
		std::map<int,boost::any> actions;
		std::map<int,boost::any> defaultActions;
	};
}

#endif;