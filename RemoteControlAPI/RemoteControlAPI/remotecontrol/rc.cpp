#include "rc.h"

namespace rc{

	RemoteControlAPI* rcAPI;
	int defaultActionName = 0;
	int defaultActionName2 = 0;
	bool autoExecuting = false;
	
	void init(){
		std::cout << "remote control initialization..." << std::endl;
		RemoteControlAPI& remote = RemoteControlAPI::getInstance();
		rcAPI = &remote;
	}

	void autoExecute(){
		while(true){
			executeActions();
		}
	}

	void executeActions(){
		if(!autoExecuting){
			rcAPI->executeActions();
		}
	}

	void registerFunction(boost::any f, int valueType){
		std::string name = "action_name_" + defaultActionName++;
		rcAPI->registerAction(f, valueType, name, rc::DEFAULT_MODULE, rc::DEFAULT_CONTEXT);
	}

	void registerFunction(boost::any f, int valueType, std::string name){
		rcAPI->registerAction(f, valueType, name, rc::DEFAULT_MODULE, rc::DEFAULT_CONTEXT);
	}

	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule){
		rcAPI->registerAction(f, valueType, name, preferedModule, rc::DEFAULT_CONTEXT);
	}

	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule, int context){
		rcAPI->registerAction(f, valueType, name, preferedModule, context);
	}

	void registerDefaultAction(int actionType, boost::any f){
		rcAPI->registerDefaultAction(f, actionType, rc::DEFAULT_CONTEXT);
	}

	void registerDefaultAction(int actionType, boost::any f, int context){
		rcAPI->registerDefaultAction(f, actionType, context);
	}

	void registerDefaultListener(int actionType, int valueType){
		std::string name = "default_action_name_" + defaultActionName2++;
		rcAPI->registerListener(actionType, valueType, name, rc::DEFAULT_MODULE, rc::DEFAULT_CONTEXT);
	}

	void registerDefaultListener(int actionType, int valueType, std::string name){
		rcAPI->registerListener(actionType, valueType, name, rc::DEFAULT_MODULE, rc::DEFAULT_CONTEXT);
	}
	
	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule){
		rcAPI->registerListener(actionType, valueType, name, preferedModule, rc::DEFAULT_CONTEXT);
	}

	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule, int context){
		rcAPI->registerListener(actionType, valueType, name, preferedModule, context);
	}

	void setContext(int context){
		rcAPI->setContext(context);
	}
	
	void send(int messageType, int message){
		
	}

	void start(){
		rcAPI->start();
		if(autoExecuting){
			std::thread t(&executeActions);
		}
	}
	
	void close(){
		rcAPI->close();
	}

};