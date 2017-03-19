/************************************************************ 
FileName: shell.c
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description:������ļ�

Function List: //��Ҫ�������书�� 
1��main   ��ִ�к���
3��read_command   �����������

History: //��ʷ�޸ļ�¼
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this moudle
***********************************************************/
#include "shell.h"
#define TRUE 1

/************************************************************ 
Function: read_command
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: �����ȡ����

Called By: main

Return: number of parameters
				0:	represents only command without any parameters
				-1:	represents wrong input

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
***********************************************************/
int read_command(char **command,char **parameters,char *prompt)
{
	/*���������ʾ��*/
	printf("%s",prompt);
	char* Res_fgets = fgets(buffer,MAXLINE,stdin);
	if(Res_fgets == NULL)
	{
		printf("\n");
		exit(0);
	}
	
	if(buffer[0] == '\0')
		return -1;
	char *pStart,*pEnd;
	int count = 0;
	int isFinished = 0;
	pStart = pEnd = buffer;
	while(isFinished == 0)
	{
		while((*pEnd == ' ' && *pStart == ' ') || (*pEnd == '\t' && *pStart == '\t'))
		{
			pStart++;
			pEnd++;
		}
		/*��Ч����*/
		if(*pEnd == '\0' || *pEnd == '\n')
		{
			if(count == 0)
				return -1;
			break;
		}
		
		while(*pEnd != ' ' && *pEnd != '\0' && *pEnd != '\n')
			pEnd++;
		
		if(count == 0)
		{
			char *p = pEnd;
			*command = pStart;
			while(p!=pStart && *p !='/')
				p--;
			if(*p == '/')
				p++;
			parameters[0] = p;
			count += 2;
		}
		else if(count <= MAXARG)
		{
			parameters[count-1] = pStart;
			count++;
		}
		else
		{
			break;
		}
		
		if(*pEnd == '\0' || *pEnd == '\n')
		{
			*pEnd = '\0';
			isFinished = 1;
		}
		else
		{
			*pEnd = '\0';
			pEnd++;
			pStart = pEnd;
		}
	}
	parameters[count-1] = NULL;
	return count;
}

/************************************************************ 
Function: builtin_command
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: �����������

Called By: main

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
***********************************************************/
int builtin_command(char *command, char **parameters, int ParaNum)
{
	if(strcmp(command,"exit")==0 || strcmp(command,"quit")==0)
		exit(0);
	else if(strcmp(command,"about") == 0)
	{
		printf("This is a simulation of shell (bash).\n");
		return 0;
	}
	/*���ÿ���������*/
	else if(strcmp(command,"restart") == 0)
	{
		return 0;
	}
	
	int ret = 0;
	/*�ն˿���������*/
	if(strcmp(parameters[0],"tc")==0)
	{
		if(parameters[1] != NULL)
		{
			ret = tc_parsing(parameters,ParaNum);
			return ret;
		}
		else
			return NEED_ACTION_OPTION;
	}
	
	/*����ƽ̨ͨ������*/
	else if(strcmp(parameters[0],"eth")==0)
	{
		if(parameters[1] != NULL)
		{
			ret = eth_parsing(parameters,ParaNum);
			return ret;
		}
		else
			return NEED_ACTION_OPTION;
	}
	
	/*RS232��������*/
	else if(strcmp(parameters[0],"rs")==0)
	{
		if(parameters[1] != NULL)
		{
			ret = rs_parsing(parameters,ParaNum);
			return ret;
		}
		else
			return NEED_ACTION_OPTION;
	}

	return INVALID_COMMAND;
}

/************************************************************ 
Function: main
Author: Zhaojq
Version: 1.0
Date: 2015/12/04
Description: ��ִ�к���

History:
<author>	<time>		<version >	<desc> 
Zhaojq		15/12/04		1.0				build this function
***********************************************************/
int main()
{
	int status = 0;
	char *command = NULL;
	char **parameters;
	int ParaNum;
	char prompt[MAX_PROMPT];
	parameters = malloc(sizeof(char *)*(MAXARG+2));
	buffer = malloc(sizeof(char) * MAXLINE);
	if(parameters == NULL || buffer == NULL)
	{
		printf("shell error:malloc failed.\n");
		return;
	}

	while(TRUE)
	{
		sprintf(prompt,"[Standard Shell V2.0]# ");
		ParaNum = read_command(&command,parameters,prompt);
		if(-1 == ParaNum)
		{
			continue;
		}
		ParaNum--; 
		status = builtin_command(command,parameters,ParaNum);
		if(status)
		{
			if(status == NEED_ACTION_OPTION) {
				printf("ERROR: [%s] Need an Action Option\n", parameters[0]);
				continue;
			}
			
			if(status == INVALID_COMMAND) {
				printf("ERROR: [%s] is Invalid Command\n", parameters[0]);
				continue;
			}
			
			if(status == INVALID_ACTION_OPTION) {
				printf("ERROR: [%s %s] is Invalid Action Option\n", parameters[0], parameters[1]);
				continue;
			}	
		}
	}
	free(parameters);
	free(buffer);
}
