#ifndef _UTILITY_H
#define _UTILITY_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "types.h"


uint16 htons( unsigned short hostshort);	                /* htons function converts a unsigned short from host to TCP/IP network byte order (which is big-endian).*/

uint32 htonl(unsigned long hostlong);	          	        /* htonl function converts a unsigned long from host to TCP/IP network byte order (which is big-endian). */
 
uint32 ntohs(unsigned short netshort);		                /* ntohs function converts a unsigned short from TCP/IP network byte order to host byte order (which is little-endian on Intel processors). */

uint32 ntohl(unsigned long netlong);		                  /* ntohl function converts a u_long from TCP/IP network order to host byte order (which is little-endian on Intel processors). */
void mid(int8* src, int8* s1, int8* s2, int8* sub);
char c2d(uint8 c	);
uint16 atoi16(char* str,uint16 base	);
void inet_addr_(unsigned char* addr,unsigned char *ip);
void replacetochar(char * str,	char oldchar,char newchar	);
#endif
