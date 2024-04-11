#include "utility.h"

/**
*@brief	 	16λ�ַ���8λ��8λת��
*@param		i:Ҫת��������
*@return	ת���������
*/
uint16 swaps(uint16 i)
{
  uint16 ret=0;
  ret = (i & 0xFF) << 8;
  ret |= ((i >> 8)& 0xFF);
  return ret;	
}
/**
*@brief	 	32λ�ַ��ߵ�λ�任
*@param		i:Ҫת��������
*@return	ת���������
*/
uint32 swapl(uint32 l)
{
  uint32 ret=0;
  ret = (l & 0xFF) << 24;
  ret |= ((l >> 8) & 0xFF) << 16;
  ret |= ((l >> 16) & 0xFF) << 8;
  ret |= ((l >> 24) & 0xFF);
  return ret;
}


/**
*@brief		��һ�� ����ģʽ��unsigned short������ת�������ģʽ��TCP/IP �����ֽڸ�ʽ������.
*@param		Ҫת��������
*@return 	���ģʽ������
*/ 
uint16 htons( 
	uint16 hostshort	/**< A 16-bit number in host byte order.  */
	)
{
	#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )
		return swaps(hostshort);
	#else
		return hostshort;
	#endif		
}

/**
*@brief		��һ�� ����ģʽ��unsigned long������ת�������ģʽ��TCP/IP �����ֽڸ�ʽ������.
*@param		Ҫת��������
*@return 	���ģʽ������
*/ 
unsigned long htonl(
	unsigned long hostlong		/**< hostshort  - A 32-bit number in host byte order.  */
	)
{
#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )
	return swapl(hostlong);
#else
	return hostlong;
#endif	
}



/**
*@brief		��һ�����ģʽ��TCP/IP �����ֽڸ�ʽ������ת��������ģʽ��unsigned short������
*@param		Ҫת��������
*@return 	unsigned shortģʽ������
*/ 
unsigned long ntohs(
	unsigned short netshort	/**< netshort - network odering 16bit value */
	)
{
#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )	
	return htons(netshort);
#else
	return netshort;
#endif		
}


/**
*@brief		��һ�����ģʽ��TCP/IP �����ֽڸ�ʽ������ת��������ģʽ��unsigned long������
*@param		Ҫת��������
*@return 	unsigned longģʽ������
*/ 
unsigned long ntohl(unsigned long netlong)
{
#if ( SYSTEM_ENDIAN == _ENDIAN_LITTLE_ )
	return htonl(netlong);
#else
	return netlong;
#endif		
}

void mid(int8* src, int8* s1, int8* s2, int8* sub)
{
	int8* sub1;
	int8* sub2;
	uint16 n;

  sub1=strstr(src,s1);
  sub1+=strlen(s1);
  sub2=strstr(sub1,s2);
  n=sub2-sub1;
  strncpy(sub,sub1,n);
  sub[n]=0;
}

uint16 atoi16(char* str,uint16 base	)
{
  unsigned int num = 0;
  while (*str !=0)
          num = num * base + c2d(*str++);
  return num;
}


void inet_addr_(unsigned char* addr,unsigned char *ip)
{
	int i;
	char taddr[30];
	char * nexttok;
	char num;
	strcpy(taddr,(char *)addr);
	
	nexttok = taddr;
	for(i = 0; i < 4 ; i++)
	{
		nexttok = strtok(nexttok,".");
		if(nexttok[0] == '0' && nexttok[1] == 'x') num = atoi16(nexttok+2,0x10);
		else num = atoi16(nexttok,10);
		
		ip[i] = num;
		nexttok = NULL;
	}
}	

void replacetochar(char * str,	char oldchar,char newchar	)
{
  int x;
  for (x = 0; str[x]; x++) 
    if (str[x] == oldchar) str[x] = newchar;	
}

char c2d(uint8 c	)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return 10 + c -'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c -'A';

	return (char)c;
}


