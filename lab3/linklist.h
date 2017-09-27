#include<stdio.h>
#include<stdlib.h>

typedef struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDateNode;

tDateNode *findCmd(tDateNode *head,char *cmd);

int showAllCmd(tDateNode *head);
