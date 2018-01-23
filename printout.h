#ifndef __PRINTOUT__H
#define __PRINTOUT__H

#include "makeStruct.h"
#include "linkedList.h"

void printOut( FILE *fp, Node *node );

void writeTree( Node *head );

void writeNode( FILE *fp, Node *node );

void writeLeafTree(LeafList *leaf_List);

void printOutLeafTree(FILE *fp, LeafNode *leaf_Node);

void growLeafTree(LeafList *leaf_List);

#endif
