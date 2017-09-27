#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

tDateNode *findCmd(tDateNode *head, char *cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDateNode *p = head;
    while(p != NULL)
    {
        if( !strcmp(p->cmd, cmd))
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int showAllCmd(tDateNode *head)
{
    printf("Menu List:\n");
    tDateNode *p = head;
    while(p != NULL)
    {
        printf("    %s\n",p->cmd);
        p = p->next;
    }
    return 0;
}
