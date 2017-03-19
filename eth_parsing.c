/************************************************************ 
FileName: eth_parsing.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: 管理平台通信命令解析

History: //历史修改记录
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this moudle
***********************************************************/
#include "shell.h"

/************************************************************ 
Function: eth_parsing
Author: Zhaojq
Version: 1.0
Date: 2015/12/08
Description: 管理平台通信命令解析函数

Called By: builtin_command

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
Zhaojq		15/12/08		1.0				增加命令错误验证机制
***********************************************************/
int eth_parsing(char **parameters,int ParaNum)
{
   int ret = 0;
  /*显示平台通信设置信息*/
  if(strcmp(parameters[1],"showall") ==0)
  {
  	if(ParaNum == 2)
      printf("show all\n");
    else
    	printf("ERROR: Garbage option, e.g.[eth showall]\n");
    return 0; 
  }
  
  /*设置网口状态*/
  else if(strcmp(parameters[1],"enable") ==0)
  {
  	if(ParaNum == 2)
      printf("eth enable\n");
    else
    	printf("ERROR: Garbage option, e.g.[eth enable]\n");
    return 0; 
  }
  else if(strcmp(parameters[1],"disable") ==0)
  {
  	if(ParaNum == 2)
      printf("eth disable\n");
    else
    	printf("ERROR: Garbage option, e.g.[eth disable]\n");
    return 0; 
  }
  
  /*设置网口类型 */
  else if(strcmp(parameters[1],"eth0") ==0)
  {
  	if(ParaNum == 2)
      printf("eth0\n");
    else
    	printf("ERROR: Garbage option, e.g.[eth eth0]\n");
    return 0; 
  }
  else if(strcmp(parameters[1],"3g") ==0)
  {
  	if(ParaNum == 4)
      printf("3g uname = %s, passwd = %s\n", parameters[2], parameters[3]);
    else
    	printf("ERROR: Garbage option, e.g.[eth 3g 'username' 'password']\n");
    return 0; 
  }
  else if(strcmp(parameters[1],"wifi") ==0)
  {
  	if(ParaNum == 4)
      printf("wifi ssid = %s, passwd = %s\n", parameters[2], parameters[3]);
    else
    	printf("ERROR: Garbage option, e.g.[eth wifi 'ssid' 'password']\n");
    return 0; 
  }
  
  /*设置通信IP地址*/
  else if(strcmp(parameters[1],"ipaddress") ==0)
  {
		if(ParaNum == 3) {
  		ret = is_valid_ip(parameters[2]);
  		if(ret)
  			printf("ipaddress = %s\n", parameters[2]);
  		else
      	printf("ERROR: Garbage option, e.g.[eth ipaddress '0.0.0.0~255.255.255.255']\n");
    }
    else
    	printf("ERROR: Garbage option, e.g.[eth ipaddress '0.0.0.0~255.255.255.255']\n");
    return 0;
  }
  else if(strcmp(parameters[1],"domain") ==0)
  {
  	if(ParaNum == 3)
      printf("domain = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option.\n");
    return 0; 
  }
  
  /*设置通信端口*/
  else if(strcmp(parameters[1],"port") ==0)
  {
  	int port = atoi(parameters[2]);
  	if(ParaNum == 3) {
  		if(port > 0 && port < 65536)
  			printf("port = %d\n",port);
  		else
      	printf("ERROR: Garbage option, e.g.[eth port 1~65535]\n");
  	}
    else
    	printf("ERROR: Garbage option, e.g.[eth port 1~65535]\n");
    return 0; 
  }
  
  /*设置通信发送协议*/
  else if(strcmp(parameters[1],"sendproto") ==0)
  {
  	if(ParaNum == 3)
      printf("sendproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[eth sendproto 'send protocol']\n");
    return 0; 
  }
  
  /*设置通信接收协议*/
  else if(strcmp(parameters[1],"recvproto") ==0)
  {
  	if(ParaNum == 3)
      printf("recvproto = %s\n",parameters[2]);
    else
    	printf("ERROR: Garbage option, e.g.[eth recvproto 'recv protocol']\n");
    return 0; 
  }
  
  return INVALID_ACTION_OPTION;
}