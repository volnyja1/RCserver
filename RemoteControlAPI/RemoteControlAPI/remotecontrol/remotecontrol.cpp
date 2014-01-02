#include "remotecontrol.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "rc_var.h"

namespace rc{
	
	RemoteControl::RemoteControl()
	{
		//std::cout << "RemoteControl created" << std::endl;
		netServices.setQueues(messagesFromNetwork,messagesToNetwork);
		netServices.setProtocol(netsvc::ProtocolType::TCP);
		netServices.setServer(netsvc::Sock(netsvc::DEFAULT_PORT));
		netServices.start();
	}

	RemoteControl::~RemoteControl()
	{
		//std::cout << "RemoteControl destroyed" << std::endl;
	}

	void RemoteControl::setQueues(std::queue<Command> &_commandsFromRC, std::queue<Command> &_commandsFromApp){
		commandsFromApp = &_commandsFromApp;
		commandsFromRC = &_commandsFromRC;
	}

	void RemoteControl::parseController(int context, rapidxml::xml_node<> *node){
		int valueType, actionType, module;
		std::string name;
		name = "";
		module = DEFAULT_MODULE;
		std::istringstream is;
		if(node->first_attribute("valueType")==NULL || node->first_attribute("actionType")==NULL //||
			/*node->first_attribute("name")==NULL || node->first_attribute("module")==NULL*/)
			return;

		name = node->first_attribute("name")->value();
		is = std::istringstream(node->first_attribute("module")->value());
		is >> module;
		is = std::istringstream(node->first_attribute("valueType")->value());
		is >> valueType;
		is = std::istringstream(node->first_attribute("actionType")->value());
		is >> actionType;

		registerToDefault(actionType,valueType,name,module,context);
		//std::cout << context << " " << name << " " << module << " " << valueType << " " << actionType << "\n";
	}

	void RemoteControl::parseContext(rapidxml::xml_node<> *node){
		int context = DEFAULT_CONTEXT;
		if(node->first_attribute("id")!=NULL){
			std::istringstream is(node->first_attribute("id")->value());
			is >> context;
		}
		if(node->first_node("controller")!=NULL){
			rapidxml::xml_node<> *node1 = node->first_node("controller");
			parseController(context,node1);
			while(node1 = node1->next_sibling("controller")){
				parseController(context,node1);
			}
		}
	}

	void RemoteControl::handleAppEvents(){
		while (!commandsFromApp->empty())
		{
			if(commandsFromApp->front().getType()==CLOSE){
				std::cout << "> RC: close\n";
				close();
			} else if(commandsFromApp->front().getType()==START){
				std::cout << "> RC: start\n";
				run();
			} else if(commandsFromApp->front().getType()==REGISTER_ACTION){
				std::cout << "> RC: register action\n";
				registerAction(commandsFromApp->front().getContent(),commandsFromApp->front().getPrimitiveType(),
					commandsFromApp->front().getName(),commandsFromApp->front().getPreferedModule(),
					commandsFromApp->front().getContext());
			} else if(commandsFromApp->front().getType()==REGISTER_DEFAULT_ACTION){
				std::cout << "> RC: register default action\n";
				registerDefaultAction(commandsFromApp->front().getContent(),commandsFromApp->front().getActionType(),
					commandsFromApp->front().getContext());
			} else if(commandsFromApp->front().getType()==REGISTER_VARIABLE){
				std::cout << "> RC: register variable (not implemented yet)\n";
				// TODO
			} else if(commandsFromApp->front().getType()==REGISTER_ACTION_TO_DEFAULT){
				std::cout << "> RC: register action to default\n";
				registerToDefault(commandsFromApp->front().getActionType(),commandsFromApp->front().getPrimitiveType(),
					commandsFromApp->front().getName(),commandsFromApp->front().getPreferedModule(),
					commandsFromApp->front().getContext());
			} else if(commandsFromApp->front().getType()==CHANGE_CONTEXT){
				std::cout << "> RC: change context\n";
				if(app.getState() != AppState::RUNNING){
					app.setState(AppState::RUNNING);
				}
				app.setContext(commandsFromApp->front().getContext());
				xml::XMLMessage m;
				m.setMessageType("other");
				m.setData("<type>context</type><content>"+std::to_string(commandsFromApp->front().getContext())+"</content>");
				netServices.sendBroadcast(clients.getAllClientIds(),m);
			} else if(commandsFromApp->front().getType()==ERROR){
				std::cout << "> RC: error\n";
			} else if(commandsFromApp->front().getType()==OTHER){
				std::cout << "> RC: other message\n";
			} else if(commandsFromApp->front().getType()==SET_CONFIG_FILE){
				std::cout << "> RC: set config file - " << commandsFromApp->front().getConfig() << "\n";
				std::string file(commandsFromApp->front().getConfig());
				std::ifstream myfile(file);
				if (!myfile)
				{
					std::cout << "Cannot open file " << file << "\n";
				} else {
					rapidxml::xml_document<> doc;
					std::vector<char> buffer((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>( ));
					buffer.push_back('\0');
					try{
						doc.parse<0>(&buffer[0]);
						if(doc.first_node("application")!=NULL){
							rapidxml::xml_node<> *node = doc.first_node();
							if(node->first_node("context")!=NULL){
								node = node->first_node("context");
								parseContext(node);
								while(node = node->next_sibling("context")){
									parseContext(node);
								}
							}
						}
					} catch (...){
						std::cout << "XML file parsing error\n";
					}
				}
			} else if(commandsFromApp->front().getType()==EXECUTE){
				std::cout << "> RC: execution results\n";
				if(app.getState() != AppState::RUNNING){
					app.setState(AppState::RUNNING);
				}
			}
			commandsFromApp->pop();
		}
	}

	void RemoteControl::handleClientEvents(){
		while (!messagesFromNetwork.empty())
		{
			xml::XMLMessage m = messagesFromNetwork.front();
			xml::MessageType type = m.getMessageTypeEnum();
			int id = m.getIdInt();
			if(type == xml::MessageType::ALIVE){
				// prijde jako potvrzeni jen od pripojeneho klienta
				xml::XMLMessage m1;
				m1.setId(m.getId());
				m1.setMessageType("error");
				m1.setData("Error: Not implemented yet.");
				messagesToNetwork.push(m1);
			} else if(type == xml::MessageType::CLOSE){
				if(app.getState() == AppState::RUNNING){
					if(id > 0){
						close();
					} else{
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: You are not connected.");
						messagesToNetwork.push(m1);
					}
				} else{
					xml::XMLMessage m1;
					m1.setId(m.getId());
					m1.setMessageType("error");
					m1.setData("Error: You are not connected.");
					messagesToNetwork.push(m1);
				}
			} else if(type == xml::MessageType::CONNECT){
				if(app.getState() == AppState::RUNNING){
					if(id > 0){
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: You have been connected already.");
						messagesToNetwork.push(m1);
					} else{
						xml::XMLClientConfData data = m.getStructuredData();
						std::cout << data.getDevice() << "\n";
						int newId = clients.addClient(ClientConfig(data.getIp(),data.getPort(),data.getDevice(),0));
						std::string toClient = "<id>"+std::to_string(newId)+"</id>"+app.getAppConfig();
						xml::XMLMessage m1;
						m1.setMessageType("configuration");
						m1.setData(toClient);
						m1.setId(m.getId());
						messagesToNetwork.push(m1);
					}
				} else{
					xml::XMLMessage m1;
					m1.setId(m.getId());
					m1.setMessageType("error");
					m1.setData("Error: Application is not running, try connection later, please.");
					messagesToNetwork.push(m1);
				}
			} else if(type == xml::MessageType::DATA){
				if(app.getState() == AppState::RUNNING){
					if(id > 0){
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setPort(m.getPort());
						m1.setMessageType("data");

						// get arguments from message
						std::string data = m.getData();
						m1.setData(data);
						//std::cout << data << "\n";
						int context = app.getContext();
						int valueType = app.getValueType(m.getPortInt());
						boost::any f = vrc.getAction(id,0,context,m.getPortInt());
						
						// create Command
						Command c(EXECUTE);
						c.setContent(f);
						c.setParams(data);
						c.setValueType(valueType);
						commandsFromRC->push(c);
						netServices.sendBroadcast(clients.getAllClientIds(), m1);
					} else{
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: You are not connected.");
						messagesToNetwork.push(m1);
					}
				} else{
					xml::XMLMessage m1;
					m1.setId(m.getId());
					m1.setMessageType("error");
					m1.setData("Error: Application is not running, try connection later, please.");
					messagesToNetwork.push(m1);
				}
			} else if(type == xml::MessageType::HELLO){
				if(app.getState() == AppState::RUNNING){
					xml::XMLMessage m1;
					m1.setMessageType("hello");
					std::string mess = "<id>"+app.getAppId()+"<id><version>"+app.getVersion()+"</version><name>"+app.getName()+"</name>";
					m1.setData(mess);
					m1.setId(id);
					messagesToNetwork.push(m1);
				} else{
					xml::XMLMessage m1;
					m1.setMessageType("hello");
					m1.setData("0");
					m1.setId(id);
					messagesToNetwork.push(m1);
				}
			} else if(type == xml::MessageType::OTHER){
				std::cout << " -- other --\n";
				if(app.getState() == AppState::RUNNING){
					if(id > 0){
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: Not implemented yet.");
						messagesToNetwork.push(m1);
					} else{
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: You are not connected.");
						messagesToNetwork.push(m1);
					}
				} else{
					if(id > 0){
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: Not implemented yet.");
						messagesToNetwork.push(m1);
					} else{
						xml::XMLMessage m1;
						m1.setId(m.getId());
						m1.setMessageType("error");
						m1.setData("Error: You are not connected.");
						messagesToNetwork.push(m1);
					}
				}
			} else if(type == xml::MessageType::ERR){
				xml::XMLMessage m1;
				m1.setId(m.getId());
				m1.setMessageType("error");
				m1.setData("Error: You have an error. Who cares? :-)");
				messagesToNetwork.push(m1);
				m1.setData("P.S.: Try it later again...");
				messagesToNetwork.push(m1);
			} else {
				xml::XMLMessage m1;
				m1.setId(m.getId());
				m1.setMessageType("error");
				m1.setData("Error: Your message has incorrect type");
				messagesToNetwork.push(m1);
			}
			messagesFromNetwork.pop();
		}
	}

	void RemoteControl::registerDefaultAction(boost::any _f, int _actionType, int _context){
		vrc.registerDefaultAction(_f,_actionType,_context);
	}

	void RemoteControl::registerAction(boost::any _f, int _primitiveType, std::string _name, int _preferedModule, int _context){
		int port = app.addAction(AppConf(_primitiveType, _name, _preferedModule), _context);
		vrc.registerAction(_f,_context,port);
	}

	void RemoteControl::registerToDefault(int _actionType, int _primitiveType, std::string _name, int _preferedModule, int _context){
		int port = app.addAction(AppConf(_primitiveType, _name, _preferedModule), _context);
		vrc.registerAction(_actionType, _context, port);
	}

	void RemoteControl::runQueues(){
		while (!stop)
		{
			handleAppEvents();
			handleClientEvents();
		}
	}

	void RemoteControl::start(){
		stop = false;
		runQueues();
	}

	void RemoteControl::run(){
		app.setState(AppState::RUNNING);
		netServices.run();
	}

	void RemoteControl::close(){
		app.setState(AppState::TERMINATING);
		netServices.close(clients.getAllClientIds());
	}
}