#include "a7Defs.h"

/*
    Function:  initCat
     Purpose:  fill a CatType with collected information
         out:  filled CatType pointer
*/
void initCat(int id, char* name, GenderType gender, CatType** currCat){
  *currCat = malloc(sizeof(CatType)); //double pointer dynamic allocated
  (*currCat)->id = id; 
  strcpy((*currCat)->name, name);
  (*currCat)->gender = gender;
}


/*
    Function:  initAllCats
     Purpose:  fill a CatListType with CatType
         out:  filled CatListType pointer
*/
void initAllCats(CatListType** catList){
  int id, gen;
  char name[MAX_STR];
  GenderType gender;
  CatType* currCat;
  NodeType* currNode;  

  while(1){
    
    printf("Enter id: ");
    scanf("%d", &id);
    if (id == -1) { //terminate process
      printf("(You have stopped input.)\n\n");
      break;
    }

    printf("Enter name: ");
    scanf("%s", name);
    if (strcmp(name, "-1") == 0) { //terminate process
      printf("(You have stopped input.)\n\n");
      break;
    }

    printf("It's(1.Male  2.Female): "); 
    scanf("%d", &gen);
    if (gen == -1){ //terminate process
        printf("(You have stopped input.)\n\n");
        break;
    }
    while(gen!=1 && gen!=2){ //invalid re-enter request
      printf("Invaild gender, please enter again: ");
      scanf("%d", &gen);
      if (gen == -1){ //terminate process
        printf("(You have stopped input.)\n\n");
        break;
      }
    }
    gen--; //user friendly method

    gender = gen; //int -> GenderType

    initCat(id, name, gender, &currCat); //prepare data

    currNode = malloc(sizeof(NodeType));
    currNode->data = currCat;
    currNode->prev = NULL;
    currNode->next = NULL; //new Node for adding

    if((*catList)->head==NULL){ //situation of no head
       (*catList)->head = currNode;
       (*catList)->tail = currNode;
    }
    else{
      if(strcmp((*catList)->head->data->name,currNode->data->name)>=0){
        currNode->next = (*catList)->head;
        (*catList)->head->prev = currNode;
        (*catList)->head = currNode;
      } // add before head
      else if(strcmp((*catList)->tail->data->name,currNode->data->name)<=0){
        currNode->prev = (*catList)->tail;
        (*catList)->tail->next = currNode;
        (*catList)->tail = currNode;
      } // add after tail
      else{
        for(NodeType* i = (*catList)->head; i->next != NULL; i = i->next){
          if(((strcmp(i->data->name,currNode->data->name)<=0)&&(strcmp(i->next->data->name,currNode->data->name)>=0))){
            currNode->next = i->next;
            currNode->prev = i;
            i->next->prev = currNode;
            i->next = currNode;
            break;
          }
        } 
      } // add in middle    
    }
 
  }

}


/*
    Function:  printCatlist
     Purpose:  print all information in a CatListType
*/
void printCatlist(CatListType** catList){
  char gPtr[MAX_STR];
  printf("Forward: \n");
  for(NodeType* f = (*catList)->head; f !=NULL; f = f->next){
    genderToString(gPtr, f->data->gender);
    printf("#%d: %s (%s)\n", f->data->id, f->data->name, gPtr);
  } //print forward
  printf("\nBackward: \n");
  for(NodeType* b = (*catList)->tail; b !=NULL; b = b->prev){
    genderToString(gPtr, b->data->gender);
    printf("#%d: %s (%s)\n", b->data->id, b->data->name, gPtr);
  } //print backward
}


/*
    Function:  genderToString
     Purpose:  Transfer the gender integer into the match string
         out:  a string of gender
*/
void genderToString(char* g, GenderType gender){
  if(gender==0) strcpy(g,"MALE"); 
  else strcpy(g,"FEMALE"); 
}


/*
    Function:  cleanup
     Purpose:  free all dynamic allocated space
*/
void cleanup(CatListType** catList){
  for(NodeType* i = (*catList)->tail; i !=NULL; i = i->prev){
    free(i->data);
    free(i);
  }
  free(*catList);
}


