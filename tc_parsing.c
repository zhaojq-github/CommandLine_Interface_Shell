/************************************************************ 
FileName: tc_parsing.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: �ն˿������������

History: //��ʷ�޸ļ�¼
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this moudle
***********************************************************/
#include "shell.h"
static int startid = 0;
static int endid = 0;

/************************************************************ 
Function: tc_parsing
Author: Zhaojq
Version: 1.0
Date: 2015/12/07
Description: �ն˿����������������

Called By: builtin_command

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
Zhaojq		15/12/07		1.0				�������������֤����
***********************************************************/
int tc_parsing(char **parameters,int ParaNum)
{
  int ret = 0;
  /*��ʾ������������Ϣ*/
  if(strcmp(parameters[1],"showall") ==0)
  {
  	if(ParaNum == 2)
      printf("show all\n");
    else
    	printf("ERROR: Garbage option, e.g.[tc showall]\n");
    return 0;
  }
  
  /*���ÿ��������*/
  else if(strcmp(parameters[1],"id") ==0)
  {
  	if(ParaNum == 3)
      printf("tcid = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc id 'id']\n");
    return 0;
  }
  
  /*���ÿ������汾*/
  else if(strcmp(parameters[1],"ver") ==0)
  {
  	if(ParaNum == 3)
      printf("ver = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc ver 'version']\n");
    return 0;
  }
  
  /*���ÿ�����Ƶ��*/
  else if(strcmp(parameters[1],"freq") ==0)
  {
  	if(ParaNum == 3)
      printf("freq = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc freq 'frequence(1~16)']\n");
    return 0;
  }
  
  /*���ÿ�����״̬*/
  else if(strcmp(parameters[1],"enable") ==0)
  {
  	if(ParaNum == 2)
      printf("tc enable\n");
    else
    	printf("ERROR: Garbage option, e.g.[tc enable]\n");
    return 0;
  }
  else if(strcmp(parameters[1],"disable") ==0)
  {
  	if(ParaNum == 2)
      printf("tc disable\n");
    else
    	printf("ERROR: Garbage option, e.g.[tc disable]\n");
    return 0;
  }
  
  /*���ÿ�����ͨ�ŷ���Э��*/
  else if(strcmp(parameters[1],"sendproto") ==0)
  {
  	if(ParaNum == 3)
      printf("sendproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc sendproto 'send protocol']\n");
    return 0;
  }
  
  /*���ÿ�����ͨ�Ž���Э��*/
  else if(strcmp(parameters[1],"recvproto") ==0)
  {
  	if(ParaNum == 3)
      printf("recvproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc recvproto 'recv protocol']\n");
    return 0;
  }
  
  /*���ÿ������ط�ʱ��*/
  else if(strcmp(parameters[1],"resend") ==0)
  {
  	if(ParaNum == 3)
      printf("resend = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc resend 'time(100,200,300,400)ms']\n");
    return 0;
  }
  
  /*���ÿ�����IP*/
  else if(strcmp(parameters[1],"ipaddress") ==0)
  {
  	if(ParaNum == 3) {
  		ret = is_valid_ip(parameters[2]);
  		if(ret)
  			printf("ipaddress = %s\n", parameters[2]);
  		else
      	printf("ERROR: Garbage option, e.g.[tc ipaddress '0.0.0.0~255.255.255.255']\n");
    }
    else
    	printf("ERROR: Garbage option, e.g.[tc ipaddress '0.0.0.0~255.255.255.255']\n");
    return 0;
  }
  
  /*���ÿ���������*/
  else if(strcmp(parameters[1],"mask") ==0)
  {
  	if(ParaNum == 3) {
  		ret = is_valid_mask(parameters[2]);
  		if(ret)
				printf("mask = %s\n",parameters[2]);
			else
				printf("ERROR: Garbage option, e.g.[tc mask '255.255.255.0']\n");
		}
    else
    	printf("ERROR: Garbage option, e.g.[tc mask '255.255.255.0']\n");
    return 0;
  }
  
  /*���ÿ�����Ĭ������*/
  else if(strcmp(parameters[1],"gateway") ==0)
  {
  	if(ParaNum == 3) {
  		ret = is_valid_ip(parameters[2]);
  		if(ret == 0)
				printf("gateway = %s\n",parameters[2]);
			else
				printf("ERROR: Garbage option, e.g.[tc gateway '192.168.1.1']\n");
		}
    else
    	printf("ERROR: Garbage option, e.g.[tc gateway '192.168.1.1']\n");
    return 0;
  }
  
  /*���ÿ�����DNS*/
  else if(strcmp(parameters[1],"dns") ==0)
  {
  	if(ParaNum == 3)
      printf("dns = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[tc DNS '114.114.114.114']\n");
    return 0; 
  }
  
  return INVALID_ACTION_OPTION;
}
