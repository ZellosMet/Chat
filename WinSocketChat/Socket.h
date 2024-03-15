#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<WS2tcpip.h>
#include<WinSock2.h>

#pragma comment(lib, "WS2_32.lib")

CONST INT MAXSTRLEN = 255;

class Socket
{
protected:
	WSADATA wsaData;
	SOCKET _socket;
	SOCKET acceptSocket;
	sockaddr_in addr;
	std::string username;

public:
	Socket();
	Socket(std::string sz_username);
	~Socket();

	bool SendData(char* buffer);
	bool ReceiveData(char* buffer, int size);
	void CloseConnection();
	CONST CHAR* SendDataMessage();
};