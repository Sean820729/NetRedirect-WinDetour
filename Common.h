#ifndef _COMMON_H_
#define _COMMON_H_

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef struct {
	char ID;
	unsigned short len;
	char* data;
} Packet;

Packet* unpackPacket(const char* data, int len, int& next);

enum class e_PacketType {
	RECEIVED = 1,
	SENDED = 2
};

// readSocket() error codes
#define SF_NODATA 0
#define SF_CLOSED -1

SOCKET createSocket(int port);
bool isConnected(SOCKET s);
bool dataWaiting(SOCKET s);
int readSocket(SOCKET s, char* buf, int len);

/* Alloc Console to Show DEBUG messages */
void debugInit();
void debug(const char* message);
void hexDump(const char* desc, const char* addr, int len);

#endif /* _COMMON_H_ */
