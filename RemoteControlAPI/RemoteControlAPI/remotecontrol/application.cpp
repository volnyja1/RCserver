#include "application.h"
#include <iostream>
#include <string>

namespace rc{
	AppConf::AppConf(){}

	AppConf::AppConf(int _primitiveType, std::string _name, int _preferedModule){
		valueType = _primitiveType;
		name = _name;
		preferedModule = _preferedModule;
	}

	AppConf::~AppConf(){}

	int AppConf::getValueType(){
		return valueType;
	}

	int AppConf::getPreferedModule(){
		return preferedModule;
	}

	std::string AppConf::getName(){
		return name;
	}

	Application::Application(){
		//std::cout << "App created" << std::endl;
		context = 0;
		state = AppState::CONFIGURING;
	}

	Application::~Application(){
		//std::cout << "App destroyed" << std::endl;
	}

	void Application::setContext(int _context){
		context = _context;
	}

	int Application::getContext(){
		return context;
	}

	void Application::setState(AppState _state){
		state = _state;
	}

	AppState Application::getState(){
		return state;
	}

	int Application::getValueType(int port){
		return appControl[context][port].getValueType();
	}

	int Application::addAction(AppConf _action, int _context){
		int type = _action.getValueType();
		int max = 0;
		std::map<int,AppConf>::iterator it;
		for (it=appControl[_context].begin(); it!=appControl[_context].end(); ++it){
			max = it->first;
		}
		int port = max+1;
		std::cout <<"app adding to "<<port<<"\n";
		appControl[_context][port] = _action;
		return port;
	}

	std::string Application::getAppConfig(){
		std::map<int,std::map<int,AppConf>>::iterator it1;
		std::map<int,AppConf>::iterator it2;
		std::string content =  "";
		for (it1=appControl.begin(); it1!=appControl.end(); ++it1){
			std::string context = std::to_string(it1->first);
			content += std::string("<context id=\"")+context+"\">";
			for (it2=appControl[it1->first].begin(); it2!=appControl[it1->first].end(); ++it2){
				content += std::string("<module port=\"")+std::to_string(it2->first)+
					"\" valueType=\""+std::to_string(it2->second.getValueType())+
					"\" name=\""+it2->second.getName()+
					"\" moduleType=\""+std::to_string(it2->second.getPreferedModule())+"\"></module>";
			}
			content += "</context>";
		}
		return content;
	}

	void Application::createAppConfig(){

	}
}