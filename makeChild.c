#include <stdio.h>
#include <stdlib.h>
#include "makeChild.h"
#include "makeNode.h"
#include "makeStruct.h"
#include <math.h>

//make children 4 children from node
void makeChildren( Node *parent )
{
  // parent data
  double x = parent->xy[0];
  double y = parent->xy[1];
  int level = parent->level;
  int maxLevel=9; //set max level for 20mb max usage
  if(level+1 <= 9)
  {
    // child edge length
    double hChild = pow(2.0,-(level+1));
    // create children at level+1
    parent->child[0] = makeNode( x,y, level+1 );
    parent->child[1] = makeNode( x+hChild,y, level+1 );
    parent->child[2] = makeNode( x+hChild,y+hChild, level+1);
    parent->child[3] = makeNode( x,y+hChild, level+1 );
    return;
  }
  else
  {
    printf("max level reached");
  }
}

//remove node and it's children
void destroyNode( Node *node )
{
  int i;
  if(node->child[0] == NULL)
  {
    free(node);
  }
  else
  {
    for(i=0; i<4; i++) //if the node has children call this function and remove them all
    {
      destroyNode(node->child[i]);
    }
  }
  return;
}

//visits each node in tree and adds children
void growTree (Node *node)
{
  int i;
  if(node->child[0] == NULL)
  {
    makeChildren(node); //call make children function on the node
  }
  else
  {
    for(i=0; i<4; i++) //if the node has children then call this function on those children
    {
      growTree(node->child[i]);
    }
  }
  return;
}
