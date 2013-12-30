#include <iostream>
#include <cstdlib>
#include "rc_var.h"
#include "rcapi.h"

namespace rc{

	/**
	* Initialize the Remote Control API
	*/
	void init();

	/**
	* Execute all waiting actions in the queue
	*/
	void executeActions();

	/**
	* Allow auto-executing of all waiting actions
	*/
	void autoExecute();

	/**
	*
	*
	*/
	//void registerFunction1(std::function<int __cdecl(any)> f, int valueType);

	/**
	*
	*
	*/
	//void registerFunction1(std::function<int __cdecl(any)> f, int valueType, std::string name, int preferedModule);

	/**
	*
	*
	*/
	//void registerFunction1(std::function<int __cdecl(any)> f, int valueType, std::string name, int preferedModule, int context);

	/**
	*
	*
	*/
	//void registerDefaultAction1(int actionType, std::function<int __cdecl(any)> f);

	/**
	*
	*
	*/
	//void registerDefaultAction1(int actionType, std::function<int __cdecl(any)> f, int context);

	/**
	* Set configuration file for default client controllers
	* @param filename path to the configuration file
	*/
	void setConfigFile(std::string filename);

	/**
	* Register a callback function
	* @param f any callback function
	* @param valueType type of value assigned to the function
	*/
	void registerFunction(boost::any f, int valueType);

	/**
	* Register a callback function
	* @param f any callback function
	* @param valueType type of value assigned to the function
	* @param name name of controller, possibly function
	*/
	void registerFunction(boost::any f, int valueType, std::string name);
	
	/**
	* Register a callback function
	* @param f any callback function
	* @param valueType type of value assigned to the function
	* @param name name of controller, possibly function
	* @param prferedModule number of a prefered module as a client controller
	*/
	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule);

	/**
	* Register a callback function
	* @param f any callback function
	* @param valueType type of value assigned to the function
	* @param name name of controller, possibly function
	* @param prferedModule number of a prefered module as a client controller
	* @param context id of the assigned context
	*/
	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule, int context);

	/**
	* Register a default action callback function
	* @param actionType type of default action
	* @param f any callback function assigned to the type
	*/
	void registerDefaultAction(int actionType, boost::any f);

	/**
	* Register a default action callback function
	* @param actionType type of default action
	* @param f any callback function assigned to the type
	* @param context id of the assigned context
	*/
	void registerDefaultAction(int actionType, boost::any f, int context);

	/**
	* Register a default controller
	* @param actionType type of default action
	* @param valueType type of value
	*/
	void registerDefaultListener(int actionType, int valueType);

	/**
	* Register a default controller
	* @param actionType type of default action
	* @param valueType type of value
	* @param name name of a controller
	*/
	void registerDefaultListener(int actionType, int valueType, std::string name);
	
	/**
	* Register a default controller
	* @param actionType type of default action
	* @param valueType type of value
	* @param name name of a controller
	* @param preferedModule prfered controller
	*/
	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule);

	/**
	* Register a default controller
	* @param actionType type of default action
	* @param valueType type of value
	* @param name name of a controller
	* @param preferedModule prfered controller
	* @param context context id of the controller
	*/
	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule, int context);

	/**
	* Change context of the application
	* @param context id of a set context
	*/
	void setContext(int context);

	/**
	* Send any message
	* @param messageType type of a message
	* @param mesage any message
	*/
	void send(int messageType, boost::any message);

	/**
	* Start API
	*/
	void start();

	/**
	* Close all the network connections and end the API
	*/
	void close();

};