#pragma once
#include"Socket.h"

class ClientSocket : public Socket
{
public:
	ClientSocket(std::string username) : Socket(username) {}
	void ConnectToServer(const char ip[], int port);
};
