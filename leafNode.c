#include "leafNode.h"

//allocates memory to node and points to next node (null)
LeafNode *createFilledNode(Node *leaf_node)
{
  LeafNode *newNode = (LeafNode *) malloc(sizeof(LeafNode));
  newNode -> nodeInTree = leaf_node;
  newNode -> nextLeafInTree = NULL;

  return newNode;
}
