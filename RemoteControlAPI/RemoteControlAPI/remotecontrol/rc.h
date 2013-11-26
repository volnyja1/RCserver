#include <iostream>
#include <cstdlib>
#include "rc_var.h"
#include "rcapi.h"

namespace rc{

	/**
	*
	*
	*/
	void init();

	/**
	*
	*
	*/
	void executeActions();

	/**
	*
	*
	*/
	void registerFunction(boost::any f, int valueType);

	/**
	*
	*
	*/
	void registerFunction(boost::any f, int valueType, std::string name);
	
	/**
	*
	*
	*/
	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule);

	/**
	*
	*
	*/
	void registerFunction(boost::any f, int valueType, std::string name, int preferedModule, int context);

	/**
	*
	*
	*/
	void registerDefaultAction(int actionType, boost::any f);

	/**
	*
	*
	*/
	void registerDefaultAction(int actionType, boost::any f, int context);

	/**
	*
	*
	*/
	void registerDefaultListener(int actionType, int valueType);

	/**
	*
	*
	*/
	void registerDefaultListener(int actionType, int valueType, std::string name);
	
	/**
	*
	*
	*/
	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule);

	/**
	*
	*
	*/
	void setContext(int context);

	/**
	*
	*
	*/
	void send(int messageType, int message);

	/**
	*
	*
	*/
	void start();

	/**
	*
	*
	*/
	void close();

};