// FileName: menu.c    
// Author  : Wuxiale
// Date    : 2017.10.10


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linktable.h"

int help();
int quit();
int add();
int subtract();
int multiply();
int divide();
int rectangle();

#define CMD_MAX_LEN 128
#define DESC_LEN 1024
#define CMD_NUM 10

typedef struct DataNode
{
    tLinkTableNode *pNext;
    char* cmd;
    char* desc;                                                    //The description of the command
    int   (*handler)();                                            //When a command is called,executing a function
    struct DataNode *next;
}tDataNode;

tDataNode *FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode* pNode=(tDataNode*)GetLinkTableHead(head);
     while(pNode !=NULL)
    {
    if(strcmp(pNode->cmd,cmd) == 0)
    {
        return pNode;
    }
    pNode=(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return NULL;
}   

int ShowAllCmd(tLinkTable* head)
{
    tDataNode *pNode=(tDataNode*)GetLinkTableHead(head);
    while(pNode !=NULL)
    {
    printf("%s ==> %s\n",pNode->cmd,pNode->desc);
    pNode =(tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode*)pNode);
    }
    return 0;
}  

int InitMenuData(tLinkTable ** ppLinkTable)
{
    *ppLinkTable=CreateLinkTable();

    tDataNode* pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="help";
    pNode->desc="help command ";
    pNode->handler=help;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);

    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="version";
    pNode->desc="menu program v1.1 beta";
    pNode->handler=NULL;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);

    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="quit";
    pNode->desc="quit this software";
    pNode->handler=quit;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);

    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="add";
    pNode->desc="A + B";
    pNode->handler=add;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="subtract";
    pNode->desc="A - B";
    pNode->handler=subtract;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="multiply";
    pNode->desc="A * B";
    pNode->handler=multiply;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="divide";
    pNode->desc="A / B";
    pNode->handler=divide;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
    
    pNode=(tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd="rectangle";
    pNode->desc="A rectangle with A rows and B columes";
    pNode->handler=rectangle;
    AddLinkTableNode(*ppLinkTable,(tLinkTableNode *)pNode);
   
    return 0;
}

tLinkTable* head=NULL;

int main()
{
    InitMenuData(&head);
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Please Input Command >");
        scanf("%s",cmd);
        tDataNode *p = FindCmd(head,cmd);
        if(p == NULL)
        {
             printf("wrong cmd!\n");
             continue;
         }
         printf("%s ==> %s\n",p->cmd,p->desc);
         if(p -> handler != NULL)
        {
            p -> handler();
        }
     }
}

int help()                                                        //Show all of the comnmands which you can use
{
    printf("===========================================\n");
    printf("Menu List:\n");
    ShowAllCmd(head);
    return 0;
}

int quit()                                                        //Exit program
{
    exit(0);
    return 0;
}


int rectangle()                                                   //Draw a rectangle
{
    int length,width;
    int row,colume;
    printf("===========================================\n");
    printf("rectangle!\n please input length and width:\n");
    scanf("%d %d", &length, &width);
    for(row=1; row<=width; row++)
    {
        for(colume=1; colume<=length; colume++)
        {
           printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int add()                                                         //The addition of two numbers                                               
{
    double num1,num2,add;
    printf("Addition!\nplease input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    add = num1 + num2;
    printf("%lf + %lf = %lf \n",num1, num2, add);
    printf("===========================================\n");
    return 0;
}

int subtract()                                                    //The subtraction of two numbers
{
    double num1,num2,sub;
    printf("Subtraction!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    sub = num1 - num2;
    printf("%lf - %lf = %lf\n",num1, num2, sub);
    printf("===========================================\n");
    return 0;
}

int multiply()                                                    //The multiplication of two numbers
{
    double num1,num2,multi;
    printf("Multiplcation!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    multi = num1 * num2;
    printf("%lf * %lf = %lf\n",num1, num2, multi);
    printf("===========================================\n");
    return 0;
}

int divide()                                                      //The division of two numbers
{
    double num1,num2,div;
    printf("Division!\n please input two numbers:");
    scanf("%lf %lf",&num1, &num2);
    if( num2 == 0 )
    {
        printf("Error:divisor can not be zero!\n");
        printf("===========================================\n");
    }
    else
    {
        div = num1 / num2;
        printf("%lf / %lf = %lf\n",num1, num2, div);
    }
    printf("===========================================\n");
    return 0;
}
