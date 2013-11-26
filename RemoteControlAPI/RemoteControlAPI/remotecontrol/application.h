#ifndef APPLICATION_H
#define APPLICATION_H

#include <map>
//#include "xmlparser.h"

namespace rc{

	enum AppState{
		CONFIGURING,
		RUNNING,
		TERMINATING
	};

	class AppConf{
	public:
		AppConf();
		AppConf(int _primitiveType, std::string _name, int _preferedModule);
		~AppConf();
		int getValueType();
		std::string getName();
		int getPreferedModule();
	private:
		int valueType, preferedModule;
		std::string name;
	};

	class Application{
	public:
		Application();
		~Application();
		void setContext(int _context);
		int getContext();
		int addAction(AppConf _action, int _context);
		std::string getAppConfig();
		void setState(AppState _state);
		AppState getState();
		int getValueType(int port);
	private:
		void createAppConfig();
		int context;
		// map<context,map<port,conf>>
		std::map<int,std::map<int,AppConf>> appControl;
		std::string appConfig;
		AppState state;
	};
}

#endif;