OPTIONS = -g -Wall
OBJ = COMP2401a7_main.o COMP2401a7_util.o

COMP2406a7_CatList:	$(OBJ)
			gcc -o COMP2401a7_CatList $(OPTIONS) COMP2401a7_main.o COMP2401a7_util.o

COMP2406a7_main.o:	COMP2401a7_main.c a7Defs.h
			gcc -c $(OPTIONS) COMP2401a7_main.c

COMP2406a7_util.o:	COMP2401a7_util.c a7Defs.h
			gcc -c $(OPTIONS) COMP2401a7_util.c

clean:
	rm $(OBJ) COMP2401a7_CatList
