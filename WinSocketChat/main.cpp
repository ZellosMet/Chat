#include"ServerSocket.h"
#include"ClientSocket.h"
#include<string>
#include<thread>

void main()
{
	int nChoice;
	int port = 22000;
	std::string ipAddress;
	std::string clientName;
	char sendMessage[MAXSTRLEN]{};
	char nameClient[MAXSTRLEN]{};
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
			char sReceiveMessage[MAXSTRLEN]{};
			std::cout << "Waiting..." << std::endl;
			server.ReceiveData(sReceiveMessage, MAXSTRLEN);
			std::string clientName = sReceiveMessage;
			if (clientName.find(">>>") == 0)
			{
				clientName.erase(std::remove(clientName.begin(), clientName.end(), '>'), clientName.end());
				std::cout << "New Client: " << clientName << std::endl;
				server.set_NameClient(clientName);
			}
			else
				std::cout << "Received: " << server.get_NameClient() << ": " << sReceiveMessage << std::endl;
			server.SendDataMessage();
			if (strcmp(sReceiveMessage, "end") == 0 || strcmp(sendMessage, "end") == 0) break;
		}
	}
	case 2:
	{
		std::cout << "Enter IP addres: "; std::cin >> ipAddress;
		std::cout << "Enter Name: "; std::cin >> clientName;
		ClientSocket client;
		client.ConnectToServer(ipAddress.c_str(), port);
		client.SendInfoClient(">>>" + clientName);
		while (true)
		{
			char cReceiveMessage[MAXSTRLEN]{};
			client.SendDataMessage();
			std::cout << "Waiting..." << std::endl;
			client.ReceiveData(cReceiveMessage, MAXSTRLEN);
			std::cout << "Received:" << cReceiveMessage << std::endl;
			if (strcmp(cReceiveMessage, "end") == 0 || strcmp(sendMessage, "end") == 0) break;
		}
		client.CloseConnection();
	}
	}
}