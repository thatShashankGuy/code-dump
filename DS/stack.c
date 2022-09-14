/**
 * @file stack.c
 * @author your name (you@domain.com)
 * @brief Stacks are ADT with FIRST IN FIRST OUT (FIFO)
 * @version 0.1
 * @date 2022-09-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief implementing stack using Array 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

 #define MAXSIZE 20 
 struct  stack 
 {
    int top ;
    int capacity ; 
    int *array;
 };

 struct stack *Create_Stack(){
    struct stack *S = malloc(sizeof(struct stack));
    if(!S){
        return NULL;
    }

    S->capacity = MAXSIZE; 
    S->top = -1;
    S->array = malloc(sizeof(S->capacity *sizeof(int)));
        if(!S->array){
            return NULL; 
        }

        return S; 

 }
 

 /**
  * @brief Operations 
  * 
  * Is_Stack_Empty - Checks if the stack is empty by checking 'top' is its -1 meaning no element is in stack
  * 
  * Is_Stack_Full - Checks if the stack is full ; if 'top' equals the capacity of stack defined its full and no element can be added; 
  * 
  * Push - takes data and stack , add data to the top of stack by access S->array[top] and incrementing top and assigning data to it  
  * 
  * Pop - takes the stacks remove the top of the stack element and returns the stack with the updated array with element at top (element of last of the array ) removed 
  * by accessing S-> array and decrementing to the second last index and returning new array with second large index 
  * 
  * 
  * Delete - delete the stacks checks if stack -> array have any memory if so frees it and then frees the memory of the array ;
  */

int Is_Stack_Empty(struct stack *S ){
    if(S->top == -1){
        return 1;
    }else
    {
        return 0;
    }
    
}

int Is_Stack_Full(struct stack *S){
    if(S->top == S->capacity -1){
        return 1;
    }else{
        return 0; 
    }
}


void Push(struct stack *S,int data){
    if(Is_Stack_Full(S) == 1){
        printf("OVERFLOW \n");        
    }else{
        S->array[++S->top] = data;
    }
}

int Pop(struct  stack *S){
    if(Is_Stack_Empty(S) == 1){
        printf("STACK IS EMPTY");
        return INT_MIN;
    }else{
        return (S->array[S->top-- ]);
    }
}

void Delete_Stack(struct stack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
    
}


