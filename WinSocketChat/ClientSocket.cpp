#include "ClientSocket.h"

void ClientSocket::ConnectToServer(const char ip[], int port)
{
	addr.sin_family = AF_INET;
	inet_pton(AF_INET, ip, &addr.sin_addr);
	addr.sin_port = htons(port);
	if (connect(_socket, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		std::cerr << "Falid to connect Server" << std::endl;
		system("PAUSE");
		WSACleanup();
		exit(13);
	}
}

void ClientSocket::SendInfoClient(std::string name)
{
	char temp[MAXSTRLEN]{};
	strcpy(temp, name.c_str());
	SendData(temp);
}