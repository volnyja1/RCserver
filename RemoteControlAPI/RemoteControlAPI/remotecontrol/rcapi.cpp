#include "rcapi.h"
#include <iostream>
//#include <thread>

namespace rc{
	RemoteControlAPI &RemoteControlAPI::getInstance()
	{
		static RemoteControlAPI instance;
		return instance;
	}

	RemoteControlAPI::RemoteControlAPI()
	{
		//std::cout << "RemoteControlAPI created" << std::endl;
		createRC();
	}

	RemoteControlAPI::~RemoteControlAPI()
	{
		//std::cout << "RemoteControlAPI destroyed" << std::endl;
	}

	void RemoteControlAPI::registerAction(boost::any f, int primtiveType, std::string name, int preferedModule, int context){
		commandsFromApp.push(Command(REGISTER_ACTION, f, primtiveType, name, preferedModule, context));
	}

	void RemoteControlAPI::registerDefaultAction(boost::any f, int actionType, int context){
		commandsFromApp.push(Command(REGISTER_DEFAULT_ACTION, f, actionType, context));
	}

	void RemoteControlAPI::registerListener(int actionType, int primtiveType, std::string name, int preferedModule, int context){
		commandsFromApp.push(Command(REGISTER_ACTION_TO_DEFAULT, actionType, name, primtiveType, preferedModule, context));
	}

	void RemoteControlAPI::executeActions(){
		while(!commandsFromRC.empty()){
			if(commandsFromRC.front().getType() == EXECUTE){
				if(commandsFromRC.front().getParams().compare("")==0){
					commandsFromRC.front().execute();
				}
				if(commandsFromRC.front().getParams().compare("1")==0){
					commandsFromRC.front().execute(42);
				}
				commandsFromRC.pop();
			} else{
				commandsFromRC.pop();
			}
		}
	}

	void RemoteControlAPI::setContext(int context){
		commandsFromApp.push(Command(CHANGE_CONTEXT, context));
	}

	void RemoteControlAPI::RCcreator(){
		RemoteControl rc;
		rc.setQueues(commandsFromRC,commandsFromApp);
		rc.start();
	}

	void RemoteControlAPI::createRC(){
		std::thread rc(&RemoteControlAPI::RCcreator,this);
		rc.detach();
	}

	void RemoteControlAPI::start(){
		commandsFromApp.push(Command(START));
	}

	void RemoteControlAPI::close(){
		commandsFromApp.push(Command(CLOSE));
	}
}