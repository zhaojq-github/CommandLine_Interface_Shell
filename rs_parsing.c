/************************************************************ 
FileName: rs_parsing.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: RS232串口命令解析

History: //历史修改记录
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this moudle
***********************************************************/
#include "shell.h"

/************************************************************ 
Function: rs_parsing
Author: Zhaojq
Version: 1.0
Date: 2015/12/08
Description: RS232串口命令解析函数

Called By: builtin_command

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
Zhaojq		15/12/08		1.0				增加命令错误验证机制
***********************************************************/
int rs_parsing(char **parameters,int ParaNum)
{
   int ret = 0;
  /*显示串口通信设置信息*/
  if(strcmp(parameters[1],"showall") ==0)
  {
  	if(ParaNum == 2)
      printf("show all\n");
    else
    	printf("ERROR: Garbage option, e.g.[rs showall]\n");    
    return 0; 
  }
  
  /*设置串口状态*/
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
  
  /*设置串口波特率*/
  else if(strcmp(parameters[1],"baud") ==0)
  {
  	if(ParaNum == 3)
      printf("baud = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs baud '9600,115200' ]\n");
    return 0; 
  }
  
  /*设置串口超时时间*/
  else if(strcmp(parameters[1],"timeout") ==0)
  {
  	if(ParaNum == 3)
      printf("timeout = %s\n", parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs timeout 'time(100,200)ms']\n");
    return 0; 
  }
  
  /*设置串口通信发送协议*/
  else if(strcmp(parameters[1],"sendproto") ==0)
  {
  	if(ParaNum == 3)
      printf("sendproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[rs sendproto 'send protocol']\n");
    return 0; 
  }
  
  /*设置串口通信接收协议*/
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
