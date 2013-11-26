#ifndef CLIENT_H
#define CLIENT_H

#include <string>

namespace xml{

	enum MessageType{
		HELLO,
		CONNECT,
		CONFIGURATION,
		START,
		ALIVE,
		DATA,
		CLOSE,
		ERR,
		OTHER,
		CLOSE_CONFIRM,
		COUNT_OF_MESSAGES
	};

	static const char* messageTypes[COUNT_OF_MESSAGES] = { "hello",
														   "connect", 
														   "configuration", 
														   "start",
														   "alive",
														   "data",
														   "close",
														   "err",
														   "other",
														   "close_confirm"};

	struct XMLClientConfData{
	public:
		XMLClientConfData();
		~XMLClientConfData();
		std::string getIp();
		std::string getDevice();
		int getPort();
		void setIp(std::string _ip);
		void setDevice(std::string _device);
		void setPort(int _port);
	private:
		std::string ip, device;
		int port;
	};

	class XMLMessage{
	public:
		XMLMessage();
		XMLMessage(MessageType _messageType);
		XMLMessage(MessageType _messageType, int _id, std::string _data);
		XMLMessage(MessageType _messageType, int _tempId, std::string _IP, int _port);
		~XMLMessage();
		std::string getValueType();
		std::string getMessageType();
		MessageType getMessageTypeEnum();
		std::string getPort();
		std::string getData();
		XMLClientConfData getStructuredData();
		std::string getId();
		int getIdInt();
		int getPortInt();
		std::string getTextContent();
		void setValueType(std::string _valueType);
		void setMessageType(std::string _messageType);
		void setPort(std::string _port);
		void setData(std::string _data);
		void setStructuredData(XMLClientConfData _data);
		void setId(std::string _id);
		void setId(int _id);
		void setTextContent(std::string _textContent);
	private:
		std::string port, valueType, messageType, id;
		std::string data, textContent;
		XMLClientConfData structuredData;
	};

	class XMLParser{
	public:
		static std::string getText(XMLMessage m);
		static XMLMessage getMessage(std::string m);
		static MessageType getMessageType(std::string m);
		static XMLClientConfData getConnectData(std::string data);
		static int ActualizeTempId(XMLMessage m);
	private:
		
	};
}

#endif;