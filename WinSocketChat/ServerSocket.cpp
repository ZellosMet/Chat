#include"ServerSocket.h"

void ServerSocket::Listen()
{
	std::cout << "Waiting for client..." << std::endl;
	if (listen(_socket, 1) == SOCKET_ERROR)
	{
		std::cerr << "Listen error" << std::endl;
		system("PAUSE");
		WSACleanup();
		exit(15);
	}
	acceptSocket = accept(_socket, NULL, NULL);
	while (acceptSocket == SOCKET_ERROR)
		acceptSocket = accept(_socket, NULL, NULL);
	clientList[acceptSocket] = "";
	_socket = acceptSocket;
}

void ServerSocket::Bind(int port)
{
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, "0.0.0.0", &addr.sin_addr);
	addr.sin_port = htons(port);
	std::cout << "Binding to port " << port << std::endl;
	if (bind(_socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		std::cerr << "Failed to bind port" << std::endl;system("PAUSE");
		WSACleanup();
		exit(15);
	}
}

void ServerSocket::StartHosting(int port)
{
	Bind(port);
	Listen();
}

void ServerSocket::set_NameClient(std::string name)
{
	clientList[acceptSocket] = name;
}

std::string ServerSocket::get_NameClient()
{
	return clientList[acceptSocket];
}