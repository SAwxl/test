// FileName: linktable.h   
// Author  : Wuxiale
// Date    : 2017.10.10


#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#define SUCCESS 0
#define FAILURE (-1)

// LinkTable Type
typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
}tLinkTableNode;

typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int     SumOfNode;
}tLinkTable;

// Create a LinkTable
tLinkTable *CreateLinkTable();

// Delete a LinkTable
int DeleteLinkTable(tLinkTable *pLinkTable);

// Add a Node into LinkTable
int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

// Delete a Node from LinkTable
int DeleteLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

// Find the Head Pointer of LinkTable
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);

// Get the next Node
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode *pNode);

#endif
