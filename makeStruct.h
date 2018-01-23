#ifndef __MAKESTRUCT__H

#define __MAKESTRUCT__H

struct qnode
{
  // node data
  int level;
  double xy[2];
  struct qnode *child[4];
//
};

// data type definition
typedef struct qnode Node;


#endif
