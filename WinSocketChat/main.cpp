#include"ServerSocket.h"
#include"ClientSocket.h"
#include<string>

void main()
{
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
				std::cout << "Waiting..." << std::endl;
				server.ReceiveData(receaveMessage, MAXSTRLEN);
				std::cout << "Received: " << receaveMessage << std::endl;
				server.SendDataMessage();
				if (strcmp(receaveMessage, "end") == 0 || strcmp(sendMessage, "end") == 0) break;
			}
		}
		case 2:
		{
			std::cout << "Enter IP addres: "; std::cin >> ipAddress;
			ClientSocket client;
			client.ConnectToServer(ipAddress.c_str(), port);
			while (true)
			{
				client.SendDataMessage();
				std::cout << "Waiting..." << std::endl;
				client.ReceiveData(receaveMessage, MAXSTRLEN);
				std::cout << "Received:" << receaveMessage << std::endl;
				if (strcmp(receaveMessage, "end") == 0 || strcmp(sendMessage, "end") == 0) break;
			}
			client.CloseConnection();
		}	
	}
}