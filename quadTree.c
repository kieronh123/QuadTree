#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "makeChild.h"
#include "makeStruct.h"
#include "makeNode.h"
#include "printout.h"
#include "linkedList.h"
#include "leafNode.h"
#include "valueTree.h"
int main( int argc, char **argv )
{
  // create the head node:  level 0
  Node *head = makeNode( 0.0,0.0, 0 );
  //makeChildren( head );
  //split one node to level 2
  //makeChildren( head->child[2] );
  //growTree( head ) ;
  //writeTree( head );

  //printf("%d",sizeof(*head));
  LeafList finalList;
  initialiseList(&finalList);
  listNodes(&finalList, head);
  growLeafTree(&finalList);
  writeTree(head);
  destroyNode(head);


  int x=2;
  while(x != 0)
  {

    x=1;
    //initialsise new list
    LeafList list;
    initialiseList(&list);
    listNodes(&list, head);
    LeafNode *cycle = list.leafHead; //declare cycle to walk through the list
    for(; cycle!=NULL; cycle=cycle->nextLeafInTree)
    {
      Node *node = cycle->nodeInTree; //set node to the current node in the list from the for loop
      bool value = indicator(node, 0.2, 1); //call indicator function
      if(value==false)
      {
        Node *node = cycle->nodeInTree; //if indicator returns false then set create new node and set to the current node
        makeChildren(node); //create children on newly created node.
        x = x+1; //set x equal to 2 again so the while loop continues.

      }
    }
    x=x-1; //set x = 0 to end the loop
  }
/*
  //the list that is used for task 4
  LeafList finalList;
  initialiseList(&finalList);
  listNodes(&finalList, head);
  writeLeafTree(&finalList);
  destroyNode(head);
*/


  return 0;
}
