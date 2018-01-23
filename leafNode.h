#ifndef __LEAFNODE__H

#define __LEAFNODE__H

#include <stdlib.h>
#include <stdio.h>
#include "makeNode.h"
#include "makeStruct.h"

//struct for the leaf nodes
struct leaf_node_struct
{
  Node *nodeInTree; //node
  struct leaf_node_struct *nextLeafInTree; //next node
};

typedef struct leaf_node_struct LeafNode;


LeafNode *createFilledNode(Node *leaf_node);

#endif
