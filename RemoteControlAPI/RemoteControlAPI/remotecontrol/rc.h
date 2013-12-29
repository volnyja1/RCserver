#include <iostream>
#include <cstdlib>
#include "rc_var.h"
#include "rcapi.h"

namespace rc{


	/**
   *   Construct a SocketException with a explanatory message.
   *   @param message explanatory message
   *   @param incSysMsg true if system message (from strerror(errno))
   *   should be postfixed to the user provided message
   */
  SocketException(const std::string &message, bool inclSysMsg = false) throw();

	/**
	* Initialize the Remote Control API
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
	void autoExecute();

	/**
	*
	*
	*/
	//void registerFunction(std::function<int __cdecl(any)> f, int valueType);

	/**
	*
	*
	*/
	//void registerFunction(std::function<int __cdecl(any)> f, int valueType, std::string name, int preferedModule);

	/**
	*
	*
	*/
	//void registerFunction(std::function<int __cdecl(any)> f, int valueType, std::string name, int preferedModule, int context);

	/**
	*
	*
	*/
	//void registerDefaultAction(int actionType, std::function<int __cdecl(any)> f);

	/**
	*
	*
	*/
	//void registerDefaultAction(int actionType, std::function<int __cdecl(any)> f, int context);

	/**
	*
	*
	*/
	void setConfigFile(std::string filename);

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
	void registerDefaultListener(int actionType, int valueType, std::string name, int preferedModule, int context);

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