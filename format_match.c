/************************************************************ 
Copyright (C), 2005-2015, Huasai Tech. Co., Ltd. 
FileName: format_match.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description:指令集命令参数格式匹配

History: //历史修改记录
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/07		1.0				build this moudle
***********************************************************/
#include "shell.h"

/************************************************************ 
Function: is_valid_ip
Author: Zhaojq
Version: 1.0
Date: 2015/12/07
Description: ipv4地址格式匹配

Called By: tc_parsing, is_valid_mask

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
***********************************************************/
int is_valid_ip(char *ip) 
{
	int section = 0;  /* 点分十进制值 */ 
	int dot = 0;      /*  点分隔符 */
	int last = -1;
	while(*ip)
	{
		if(*ip == '.')
		{
			dot++;
			if(dot > 3)
			{ 
				return 0; 
			}
			if(section >= 0 && section <= 255)
			{ 
				section = 0; 
			}else{ 
				return 0; 
			} 
		}
		else if(*ip >= '0' && *ip <= '9')
		{ 
			section = section * 10 + *ip - '0'; 
		}else{
			return 0; 
		}
		last = *ip; 
		ip++;        
	}
		
	if(section >= 0 && section <=255)
	{ 
		if(3 == dot)
		{
			section = 0;
			return 1;
		}
	} 
	return 0; 
}

/************************************************************ 
Function: is_valid_mask
Author: Zhaojq
Version: 1.0
Date: 2015/12/07
Description: 掩码格式匹配

Called By: tc_parsing

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
***********************************************************/
int is_valid_mask(char* subnet)
{
	if(is_valid_ip(subnet))
	{
		unsigned int b = 0, i, n[4];
		sscanf(subnet, "%u.%u.%u.%u", &n[3], &n[2], &n[1], &n[0]);
		for(i = 0; i < 4; ++i)
		b += n[i] << (i * 8); 
		b = ~b + 1;
		if((b & (b - 1)) == 0)   //判断是否为2^n
			return 1;
	}
	return 0;
}
