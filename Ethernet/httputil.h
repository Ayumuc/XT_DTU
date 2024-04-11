#ifndef	__HTTPUTIL_H__
#define	__HTTPUTIL_H__

#include <stdio.h>
#include <string.h>
#include "w5500.h"

#include "utility.h"
#include "http_server.h"
#include "socket.h"

typedef struct Webpage_Reg{
	const char *Name;
	const char *page;
	uint8_t type;
}Webpage_Reg;


void proc_http(SOCKET s, u_char * buf , uint32_t len);
void do_https(void);
void cgi_ipconfig(st_http_request *http_request);
//void trimp(uint8* src, uint8* dst, uint16 len);
uint16 make_msg_response(uint8* buf,int8* msg);
void mid(int8* src, int8* s1, int8* s2, int8* sub);
void make_cgi_response(uint16 a,int8* b,int8* c);
void cgi_uartconfig(st_http_request *http_request);
void js_tasknet(st_http_request *http_request);
void make_pwd_response(int8 isRight,uint16 delay,int8* cgi_response_content, int8 isTimeout);
uint8_t NetTaskDele(void);


#endif


