#include <iostream>
#include <sstream>
#include "xmlparser.h"
#include "rapidxml\rapidxml.hpp"
#include "rc_var.h"

namespace xml{
	XMLMessage::XMLMessage(){
		messageType = MessageType::ERR;
		id = "";
	}

	XMLMessage::XMLMessage(MessageType _messageType){
		messageType = _messageType;
	}

	XMLMessage::XMLMessage(MessageType _messageType, int _id, std::string _data){
		messageType = _messageType;
	}

	XMLMessage::XMLMessage(MessageType _messageType, int _tempId, std::string _IP, int _port){
		messageType = _messageType;
	}

	XMLMessage::~XMLMessage(){}

	std::string XMLMessage::getValueType(){
		return valueType;
	}

	std::string XMLMessage::getMessageType(){
		return messageType;
	}

	MessageType XMLMessage::getMessageTypeEnum(){
		if(messageType.compare(messageTypes[7])==0){
			return MessageType::ERR;
		} else if(messageType.compare(messageTypes[1])==0){
			return MessageType::CONNECT;
		} else if(messageType.compare(messageTypes[2])==0){
			return MessageType::CONFIGURATION;
		} else if(messageType.compare(messageTypes[3])==0){
			return MessageType::START;
		} else if(messageType.compare(messageTypes[4])==0){
			return MessageType::ALIVE;
		} else if(messageType.compare(messageTypes[5])==0){
			return MessageType::DATA;
		} else if(messageType.compare(messageTypes[6])==0){
			return MessageType::CLOSE;
		} else if(messageType.compare(messageTypes[0])==0){
			return MessageType::HELLO;
		} else if(messageType.compare(messageTypes[8])==0){
			return MessageType::OTHER;
		} else if(messageType.compare(messageTypes[9])==0){
			return MessageType::CLOSE_CONFIRM;
		}
		return MessageType::ERR;
	}

	std::string XMLMessage::getPort(){
		return port;
	}

	int XMLMessage::getPortInt(){
		std::istringstream is(port);
		int portInt = 0;
		is >> portInt;
		return portInt;
	}

	std::string XMLMessage::getData(){
		return data;
	}

	XMLClientConfData XMLMessage::getStructuredData(){
		return structuredData;
	}

	std::string XMLMessage::getId(){
		return id;
	}

	int XMLMessage::getIdInt(){
		std::istringstream is(id);
		int idInt = 0;
		is >> idInt;
		return idInt;
	}

	std::string XMLMessage::getTextContent(){
		return textContent;
	}

	void XMLMessage::setValueType(std::string _valueType){
		valueType = _valueType;
	}

	void XMLMessage::setMessageType(std::string _messageType){
		messageType = _messageType;
	}

	void XMLMessage::setPort(std::string _port){
		port = _port;
	}

	void XMLMessage::setData(std::string _data){
		data = _data;
	}

	void XMLMessage::setStructuredData(XMLClientConfData _data){
		structuredData = _data;
	}

	void XMLMessage::setId(std::string _id){
		id = _id;
	}

	void XMLMessage::setId(int _id){
		id = std::to_string(_id);
	}

	void XMLMessage::setTextContent(std::string _textContent){
		textContent = _textContent;
	}

	XMLClientConfData::XMLClientConfData(){}

	XMLClientConfData::~XMLClientConfData(){}

	std::string XMLClientConfData::getIp(){
		return ip;
	}

	std::string XMLClientConfData::getDevice(){
		return device;
	}

	int XMLClientConfData::getPort(){
		return port;
	}

	void XMLClientConfData::setIp(std::string _ip){
		ip = _ip;
	}

	void XMLClientConfData::setDevice(std::string _device){
		device = _device;
	}

	void XMLClientConfData::setPort(int _port){
		port = _port;
	}

	std::string XMLParser::getText(XMLMessage m){
		std::string id = (m.getIdInt() > 0)?m.getId():"";
		std::string s = "<message id=\""+id+"\" type=\"" + m.getMessageType() + "\" port=\""+m.getPort()+"\">";
		s += "<data>"+m.getData()+"</data>";
		s += "</message>";
		//std::cout << s << "\n";
		return s;
	}

	XMLMessage XMLParser::getMessage(std::string _m){
		XMLMessage m;
		m.setTextContent(_m);
		if(_m.compare("") == 0 || _m.compare("\n") == 0){
			m.setMessageType("error");
			return m;
		}
		char* cstr = new char[_m.size() + 1];
		strcpy_s(cstr, _m.size() + 1, _m.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(cstr);
		rapidxml::xml_node<> *messageNode = doc.first_node("message");
		if(messageNode == NULL || messageNode->first_attribute("type") == NULL){
			m.setMessageType("error");
			return m;
		}
		if(messageNode->first_attribute("id")!=NULL)
			m.setId(messageNode->first_attribute("id")->value());
		if(messageNode->first_attribute("port")!=NULL)
			m.setPort(messageNode->first_attribute("port")->value());
		if(messageNode->first_attribute("type")!=NULL)
			m.setMessageType(messageNode->first_attribute("type")->value());
		if(m.getMessageTypeEnum() == MessageType::CONNECT){
			if(messageNode->first_node("data")!=NULL){
				XMLClientConfData data = getConnectData(_m);
				m.setStructuredData(data);
			}
		} else if(m.getMessageTypeEnum() == MessageType::DATA){
			if(messageNode->first_node("data")!=NULL){
				m.setData(messageNode->first_node("data")->value());
			}
		}
		return m;
	}

	XMLClientConfData XMLParser::getConnectData(std::string m){
		XMLClientConfData d;
		char* cstr = new char[m.size() + 1];
		strcpy_s(cstr, m.size() + 1, m.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(cstr);
		rapidxml::xml_node<> *dataNode = doc.first_node("message")->first_node("data");
		if(dataNode->first_node("ip")!=NULL)
			d.setIp(dataNode->first_node("ip")->value());
		if(dataNode->first_node("device")!=NULL)
			d.setDevice(dataNode->first_node("device")->value());
		if(dataNode->first_node("port")!=NULL){
			std::string port = dataNode->first_node("port")->value();
			std::istringstream is(port);
			int portInt = 0;
			is >> portInt;
			d.setPort(portInt);
		}
		return d;
	}

	int XMLParser::ActualizeTempId(XMLMessage m){
		std::string _m = m.getData();
		char* cstr = new char[_m.size() + 1];
		strcpy_s(cstr, _m.size() + 1, _m.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(cstr);
		rapidxml::xml_node<> *addressNode = doc.first_node("id");
		std::string newIdText = addressNode->value();
		std::istringstream is(newIdText);
		int newId = 0;
		is >> newId;
		return newId;
	}

	MessageType XMLParser::getMessageType(std::string _m){
		XMLMessage m;
		char* cstr = new char[_m.size() + 1];
		strcpy_s(cstr, _m.size() + 1, _m.c_str());
		rapidxml::xml_document<> doc;
		doc.parse<0>(cstr);
		rapidxml::xml_node<> *addressNode = doc.first_node("message");
		std::string type = addressNode->first_attribute("type")->value();
		if(type.compare(messageTypes[0])==0){
			return MessageType::HELLO;
		} else if(type.compare(messageTypes[1])==0){
			return MessageType::CONNECT;
		} else if(type.compare(messageTypes[2])==0){
			return MessageType::CONFIGURATION;
		} else if(type.compare(messageTypes[3])==0){
			return MessageType::START;
		} else if(type.compare(messageTypes[4])==0){
			return MessageType::ALIVE;
		} else if(type.compare(messageTypes[5])==0){
			return MessageType::DATA;
		} else if(type.compare(messageTypes[6])==0){
			return MessageType::CLOSE;
		} else if(type.compare(messageTypes[7])==0){
			return MessageType::ERR;
		} else if(type.compare(messageTypes[8])==0){
			return MessageType::OTHER;
		} else if(type.compare(messageTypes[9])==0){
			return MessageType::CLOSE_CONFIRM;
		}
		return MessageType::ERR;
	}
}