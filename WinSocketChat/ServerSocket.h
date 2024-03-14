#pragma once
#include<map>
#include"Socket.h"

class ServerSocket : public Socket
{

public:
	std::map<SOCKET, std::string> clientList;
	void Listen();
	void Bind(int port);
	void StartHosting(int port);
	void set_NameClient(std::string name);
	std::string get_NameClient();
};