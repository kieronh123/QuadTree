EXEDIR = .
EXE = $(EXEDIR)/quadTree
SRC= quadTree.c makeChild.c makeNode.c printout.c linkedList.c leafNode.c valueTree.c
CC= cc
COPT= -O
CFLAGS=
LIBS = -lm
OBJ= $(SRC:.c=.o)
.c.o:
				$(CC) $(COPT) -c -o $@ $<
$(EXE): $(OBJ)
				$(CC) $(OBJ) $(CFLAGS) -o $(EXE) $(LIBS) 
clean:
				rm -f $(OBJ) $(EXE)
quadTree.o:  quadTree.c makeStruct.h makeChild.h makeNode.h printout.h linkedList.h leafNode.h valueTree.h
makeChild.o:  makeChild.c makeStruct.h makeChild.h makeNode.h
makeNode.o:  makeNode.c makeStruct.h makeNode.h
printout.o: printout.c makeStruct.h printout.h
linkedList.o: linkedList.h leafNode.h makeStruct.h
leafNode.o: leafNode.c leafNode.h makeStruct.h linkedList.h
valueTree.o: valueTree.c valueTree.h makeStruct.h
