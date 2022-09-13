/**
 * @file dlinklist.c
 * @author thatshashankguy
 * @brief Double link list have two pointer storing address of next node as well as previous node 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief implementing node struct with address pointers and data 
 * 
 */

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

/**
 * @brief print data from front to back and back to front 
 * Providing head 
 * 
 * @param head  
 */
void printdll(struct node *head,struct node *tail){
    printf("DOUBLE LINKLIST PRINT FORWARD\n");
    while(head != NULL){
      printf("%d\n",head->data);
      head =head->next;
    }
    printf("DOUBLE LINKLIST PRINT BACKWORD\n");
    while(tail != NULL){
      printf("%d\n",head->data);
      tail = tail->prev;
    }


}

int main(){
  struct node *head;
  struct node *two;
  struct node *three;
  struct node *tail;

  head = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));
  tail = malloc(sizeof(struct node));
   
  head->data = 99;
  two->data = 88;
  three->data = 77;
  tail->data = 66;
  
  head->next = two;
  two->next= three;
  three->next = tail;
  tail->next = NULL;

  head->prev = NULL;
  two->prev =head;
  three->prev = two;
  tail->prev = three;


  printdll(head,tail);
	
 return 0;
}
