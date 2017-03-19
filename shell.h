#include <stdlib.h>
#include <stdio.h>

#define MAX_PROMPT 1024
#define MAXLINE 4096 //the length of all args is ARG_MAX
#define MAXARG 20	//����������

/*������*/
#define INVALID_COMMAND 1	//��Ч����
#define NEED_ACTION_OPTION 2	//����Ĳ�����������
#define INVALID_ACTION_OPTION 3	//��Ч�������

char *buffer;
void proc(void);
int read_command(char **,char **,char*);
int builtin_command(char *,char **,int);
int tc_parsing(char **,int);
int eth_parsing(char **,int);
int rs_parsing(char **,int);
int rf_parsing(char **,int);
int dc_parsing(char **,int);

int is_valid_ip(char *);
int is_valid_mask(char *);