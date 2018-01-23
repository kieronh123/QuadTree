#ifndef __LINKEDLIST__H

#define __LINKEDLIST__H


#include <stdlib.h>
#include <stdio.h>
#include "makeNode.h"
#include "makeStruct.h"
#include "leafNode.h"

//head of linked list
struct leaf_node_linked_list
{
  LeafNode *leafHead;
};

typedef struct leaf_node_linked_list LeafList;

void initialiseList(LeafList *leaf_List);

void addNode(LeafList *leaf_List, LeafNode *leaf_Node);

void listNodes(LeafList *list, Node *node);

#endif
