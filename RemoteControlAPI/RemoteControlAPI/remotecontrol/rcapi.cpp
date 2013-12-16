#include "rcapi.h"
#include <iostream>
#include <sstream>
//#include "type.h"

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
				int valueType = commandsFromRC.front().getValueType();
				std::string params = commandsFromRC.front().getParams();
				int result = 1;
				if(valueType == RC_VOID){
					result = commandsFromRC.front().execute();
				} else if(valueType == RC_INT){
					std::istringstream is(params);
					int arg = 0;
					is >> arg;
					result = commandsFromRC.front().execute(arg);
				} else if(valueType == RC_FLOAT){
					std::istringstream is(params);
					float arg = 0.0f;
					is >> arg;
					result = commandsFromRC.front().execute(arg);
				} else if(valueType == RC_DOUBLE){
					std::istringstream is(params);
					double arg = 0.0;
					is >> arg;
					result = commandsFromRC.front().execute(arg);
				} else if(valueType == RC_MATRIX){
					//Matrix m;
					std::istringstream is(params);
					int arg = 0;
					is >> arg;
				} else if(valueType == RC_SCALAR){
					std::istringstream is(params);
					int arg = 0;
					is >> arg;
				} else if(valueType == RC_VECTOR){
					std::istringstream is(params);
					int arg = 0;
					is >> arg;
				} else if(valueType == RC_IMAGE){
					std::istringstream is(params);
					int arg = 0;
					is >> arg;
				} else if(valueType == RC_STRING || valueType == RC_TEXT){
					result = commandsFromRC.front().execute(params);
				}
				//std::cout << "result of callback: " << result << "\n";
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