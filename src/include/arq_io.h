#ifndef ARQIO_H
#define ARQIO_H

class Socket;

extern void WriteARQsocket(unsigned int data);
extern bool Socket_arqRx();

class ARQ_SOCKET_Server
{
public:
	static bool start(const char* node, const char* service);
	static void stop(void);
private:
	ARQ_SOCKET_Server();
	~ARQ_SOCKET_Server();
	ARQ_SOCKET_Server(const ARQ_SOCKET_Server&);
	ARQ_SOCKET_Server operator=(const ARQ_SOCKET_Server&);
	static void* thread_func(void*);

private:
	static ARQ_SOCKET_Server* inst;
	bool run;
	Socket* server_socket;
};

#endif // ARQIO_H