#include "linkedList.h"
//initialise the linked list
void initialiseList(LeafList *leaf_List)
{
  leaf_List -> leafHead = NULL; //set head to null
}

//add node to top of list
void addNode(LeafList *leaf_List, LeafNode *leaf_Node)
{
  leaf_Node -> nextLeafInTree = leaf_List -> leafHead;
  leaf_List -> leafHead = leaf_Node;
}

//creates linked list of leaf nodes
void listNodes(LeafList *list, Node *node)
{
  int i;
  if(node -> child[0]==NULL)
  {
    addNode(list, createFilledNode(node));
  }
  else
  {
    for(i=0; i<4; i++)
    {
      listNodes(list, node -> child[i]);

    }
    return;
  }
}
