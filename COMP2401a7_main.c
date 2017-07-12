#include "a7Defs.h"

int main(){
  CatListType* catList;

  catList = malloc(sizeof(CatListType)); //allocate space for pointer
  catList->head = NULL;
  catList->tail = NULL;

  printf("Welcome! \n");
  printf("Please enter the information of cats\n\n");

  initAllCats(&catList);
  printCatlist(&catList);
  cleanup(&catList);

  return 0;
}
