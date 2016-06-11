#ifndef _OOXX_SOCKETMANAGER_H
#define _OOXX_SOCKETMANAGER_H
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <iostream>
#include <string>
#include "OOXX_connection.h"
using namespace std;

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (SOCKET)(~0)
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR -1
#endif
#ifndef SD_RECEIVE
#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02
#endif

//user pre-compile identifiers
#define WSVERS MAKEWORD(2, 0)	 //winsock version 2.0


//������Socketͨ�ŷ�װ��connection.h�����ϵĴ��룬����û�д�����
//����ฺ���ͺͽ���
class SocketManager
{
private:
	WSADATA wsadata;
	string server;
	string port;
	SOCKET socket;
	Connection cn;

public:
	SocketManager(string server, string port){
		this->server = server;
		this->port = port;
		socket=INVALID_SOCKET;
	}

	~SocketManager(){
		try{
			shutdown(socket, SD_BOTH);
			closesocket(socket);
			WSACleanup();                            /* ж��ĳ�汾��DLL */ 
		}catch(ConnException e){
			cout<<e.msg<<" ����� "<<e.err<<endl;
		}
	}

  void link();
	//��������
	bool sendMessage(const char* message);
	//�������ݣ���buf���ݽ�β�Զ�����/0��ע��buf�Ĵ�СҪ��len��1����
	int receive(char * buf, int len);
};

void SocketManager::link() {
  try {
    if (WSAStartup(WSVERS, &wsadata) != 0) {   /* ����ĳ�汾��DLL */
      cout << "error" << endl;
      return;
    }
    cn.makeConnect(server, port, "tcp");
  }
  catch(ConnException e){
    cerr << "error:���ӷ�����ʧ��";
  }

}

bool SocketManager::sendMessage(const char* message)
{
	try{
		socket=cn.getSocket();
		if(send(socket, message, strlen(message), 0)==SOCKET_ERROR){	
			return false;
		}
		return true;
	}catch(ConnException e){
		cout<<e.msg<<" ����� "<<e.err<<endl;
		return false;
	}
}


int SocketManager::receive(char * buf, int len){
	try{
		int	charCount;			/* recv character count		*/
    unsigned long ul = 1;
		if(socket == INVALID_SOCKET || socket == SOCKET_ERROR) 
			return -1;

		//recieve messages
    charCount = ioctlsocket(socket, FIONBIO, (unsigned long *)&ul);
		charCount = recv(socket, buf, len, 0);
		if( charCount != SOCKET_ERROR && charCount > 0) {
			buf[charCount] = '\0';		/* ensure null-termination	*/
		}
		return charCount;
	}catch(ConnException e){
		cout<<"error in receive.."<<endl;
		return -1;
	}
}	

#endif