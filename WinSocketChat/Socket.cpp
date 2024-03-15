#include "Socket.h"

Socket::Socket()
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != NO_ERROR)
	{
		std::cerr << "WSAStartup error" << std::endl;
		system("PAUSE");
		WSACleanup();
		exit(10);
	}
	_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_socket == INVALID_SOCKET)
	{
		std::cerr << "Socket create error" << std::endl;
		WSACleanup();
		exit(11);
	}
}

Socket::Socket(std::string sz_username) : Socket()
{
	this->username = sz_username;
}

Socket::~Socket()
{
	WSACleanup();
}

bool Socket::SendData(char* buffer)
{
	send(_socket, buffer, strlen(buffer), 0);

	return true;
}

bool Socket::ReceiveData(char* buffer, int size)
{
	INT i = recv(_socket, buffer, size, 0);
	return true;
}

void Socket::CloseConnection()
{
	std::cout << "Connection closing..." << std::endl;
	closesocket(_socket);
}

CONST CHAR* Socket::SendDataMessage()
{
	CHAR message[MAXSTRLEN]{};
	CHAR buffer[MAXSTRLEN]{};
	std::cout << "Enter message: ";
	std::cin.ignore();
	std::cin.get(buffer, MAXSTRLEN);
	sprintf(message, "%s: %s", username.c_str(), buffer);
	SendData(message);
	return message;
}
