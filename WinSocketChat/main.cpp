#include"ServerSocket.h"
#include"ClientSocket.h"
#include<string>

void main()
{
	setlocale(LC_ALL, "");
	//CONST int NAME_SIZE = 32;
	//CHAR sz_username[NAME_SIZE] = {"Server"};
	int nChoice;
	int port = 22000;
	std::string ipAddress;
	char receaveMessage[MAXSTRLEN]{};
	char sendMessage[MAXSTRLEN]{};
	std::cout << "1. Strat server" << std::endl;
	std::cout << "2. Connect to server" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cin >> nChoice;
	switch (nChoice)
	{
		case 1:
		{
			ServerSocket server;
			std::cout << "Starting server" << std::endl;
			server.StartHosting(port);
			while (true)
			{
				ZeroMemory(receaveMessage, MAXSTRLEN);
				//std::cout << "Waiting..." << std::endl;
				server.ReceiveData(receaveMessage, MAXSTRLEN);
				std::cout /*<< "Received: "*/ << receaveMessage << std::endl;
				if (strstr(receaveMessage, "bye"))
				{
					server.AcceptSocket();
				}
				strcpy(sendMessage, server.SendDataMessage());
				if (strstr(sendMessage, "bye")) break;
			}
		}
		break;
		case 2:
		{
			std::string sz_username;
			ipAddress = "127.0.0.1";
			//std::cout << "Enter IP addres: "; std::cin >> ipAddress;
			std::cout << "Enter username: "; std::cin >> sz_username;
			ClientSocket client = sz_username;;
			client.ConnectToServer(ipAddress.c_str(), port);
			while (true)
			{
				ZeroMemory(receaveMessage, MAXSTRLEN);
				strcpy(sendMessage, client.SendDataMessage());
				if (strstr(sendMessage, "bye")) break;
				//sendMessage = client.SendDataMessage();
				//std::cout << "Waiting..." << std::endl;
				client.ReceiveData(receaveMessage, MAXSTRLEN);
				std::cout /*<< "Received:"*/ << receaveMessage << std::endl;
				if (strstr(receaveMessage, "bye")) break;
			}
			client.CloseConnection();
		}
		break;
	}
}