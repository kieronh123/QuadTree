#include <stdio.h>
#include <stdlib.h>
#include "makeNode.h"
#include "makeStruct.h"



Node *makeNode( double x, double y, int level )
{
  int i;
  // allocate the data structure
  Node *node = (Node *)malloc(sizeof(Node));
  // set the node data
  node->level = level;
  node->xy[0] = x;
  node->xy[1] = y;
  // set children to NULL
  for( i=0; i<4; ++i )
    node->child[i] = NULL;
  return node;
}
