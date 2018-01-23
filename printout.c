#include <stdio.h>
#include <stdlib.h>
#include "makeStruct.h"
#include <math.h>
#include "printout.h"
#include "makeChild.h"

//print out nodes to file
void printOut( FILE *fp, Node *node )
{

  // node data
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

// open a file and prepare to write
void writeTree( Node *head )
{
  FILE *fp = fopen("quad.out","w");
  writeNode(fp,head);
  fclose(fp);
  return;
}

// recursively search for leaf nodes
void writeNode( FILE *fp, Node *node )
{
  int i;
  if( node->child[0] == NULL )
    printOut( fp, node );
  else
  {
    for ( i=0; i<4; ++i )
    {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}

//cycle through each node in tree and call print function on each node
void writeLeafTree(LeafList *leaf_list)
{
  FILE *fp = fopen("quad.out","w");
  LeafNode *cycle = leaf_list -> leafHead;
//  printf("write leaf called");
  for(; cycle!=NULL; cycle=cycle -> nextLeafInTree)
  {
    //printf("a");
    printOutLeafTree(fp, cycle);
  }
  fclose(fp);
  return;
}

//print out the leaf tree
void printOutLeafTree(FILE *fp, LeafNode *leaf_Node)
{
  // node data
  double x = leaf_Node-> nodeInTree-> xy[0];
  double y = leaf_Node-> nodeInTree-> xy[1];
  int level = leaf_Node-> nodeInTree-> level;
  double h = pow(2.0,-level);

  // print out the corner points
  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}

//cycle through the nodes in the list and create children for each node visited
void growLeafTree(LeafList *leaf_List)
{
  LeafNode *cycle = leaf_List -> leafHead;
  for(; cycle!=NULL; cycle=cycle -> nextLeafInTree)
  {
    printf("cycle");
    Node *node = cycle -> nodeInTree;
    makeChildren(node);
  }
  return;
}
