/************************************************************ 
FileName: rs_parsing.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: RS232�����������

History: //��ʷ�޸ļ�¼
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this moudle
***********************************************************/
#include "shell.h"

/************************************************************ 
Function: rs_parsing
Author: Zhaojq
Version: 1.0
Date: 2015/12/08
Description: RS232���������������

Called By: builtin_command

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
Zhaojq		15/12/08		1.0				�������������֤����
***********************************************************/
int rs_parsing(char **parameters,int ParaNum)
{
   int ret = 0;
  /*��ʾ����ͨ��������Ϣ*/
  if(strcmp(parameters[1],"showall") ==0)
  {
  	if(ParaNum == 2)
      printf("show all\n");
    else
    	printf("ERROR: Garbage option, e.g.[rs showall]\n");    
    return 0; 
  }
  
  /*���ô���״̬*/
  else if(strcmp(parameters[1],"enable") ==0)
  {
  	if(ParaNum == 2)
      printf("rs enable\n");
    else
    	printf("ERROR: Garbage option, e.g.[rs enable]\n");
    return 0; 
  }
  else if(strcmp(parameters[1],"disable") ==0)
  {
  	if(ParaNum == 2)
      printf("rs disable\n");
    else
    	printf("ERROR: Garbage option, e.g.[rs disable]\n");
    return 0;
  }
  
  /*���ô��ڲ�����*/
  else if(strcmp(parameters[1],"baud") ==0)
  {
  	if(ParaNum == 3)
      printf("baud = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs baud '9600,115200' ]\n");
    return 0; 
  }
  
  /*���ô��ڳ�ʱʱ��*/
  else if(strcmp(parameters[1],"timeout") ==0)
  {
  	if(ParaNum == 3)
      printf("timeout = %s\n", parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs timeout 'time(100,200)ms']\n");
    return 0; 
  }
  
  /*���ô���ͨ�ŷ���Э��*/
  else if(strcmp(parameters[1],"sendproto") ==0)
  {
  	if(ParaNum == 3)
      printf("sendproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs sendproto 'send protocol']\n");
    return 0; 
  }
  
  /*���ô���ͨ�Ž���Э��*/
  else if(strcmp(parameters[1],"recvproto") ==0)
  {
  	if(ParaNum == 3)
      printf("recvproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs recvproto 'recv protocol']\n");
    return 0; 
  }
  
  return INVALID_ACTION_OPTION;
}
