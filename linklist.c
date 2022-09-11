


/**
 * @file linklist.c
 * @author thatshashankguy
 * @brief Implementing link list 
 * singly link list :  head-> data|pointer -> data|pointer -> null 
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>



/**
 * @brief lets create a node first using stuct in C ; 
 * class can be used in C++ ;
 * pointer(*) will store memory address of next node ;
 */
struct node {
    int data;
    struct node *next;  
};
 

/**
 * @brief function to print the link list value 
 * node p(first node of link list) have data and
 * pointer to point to next node 
 * @param p 
 */
void printLinklist(struct node *p){ 
    while(p != NULL){
        printf("%d\n", p->data);
        p = p->next;
    }
}

/**
 * @brief find the count of nodes in a given link list 
 * 
 */
void findcount(struct node *p){
    int count = 0 ; 
    while(p != NULL){
        count++;
        p = p->next;
    }

    printf("%d\n",count);
}

/**
 * @brief insert a node at start of a link list and print new link list 
 * @param p
 * @param newhead
 * @return int 
 */
struct node  *insertnodeatstart(struct node *p, int newdata){

    if(p ==NULL){
        printf("OVERFLOW\n");
    }else{
            struct node *newhead; 
            newhead = malloc(sizeof(struct node));
            newhead->data = newdata;
            newhead->next = p;
            p = newhead;
    }
    return p;
}

/**
 * @brief insert a node at end of a link list and print new link list 
 * @param p
 * @param newhead
 * @return int 
 */
void insertnodeatend(struct node *p, int newdata){
    struct node *end;
    end = malloc(sizeof(struct node));
    end->data = newdata;
    if(p == NULL){
        printf("OVERFLOW\n");
    }else{
        if(p->next == NULL){
            printf("linklist only contains a head\n"); //best case scenrio 
            p->next = end;
        }else{
                while(p->next != NULL){ 
                p = p->next; // traverse the whole link list to the last value 
            }
            p->next = end;
        }
    }
}

int main(){
    /**
     * @brief create link list 
     * initialize nodes
     */
    struct node *head = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;


    //Allocate Memory 
    /**
     * @brief allocating memory in C 
     * malloc is way to dynamically allocate a single 
     * large lbock of memory with specified size 
     * 
     * in our case with are checking the size of struct node and allocating 
     * same to our intiliazed nodes 
     * 
     */
    head = malloc(sizeof(struct node)); 
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));

    /**
     * @brief Assign  data the value and pointer
     */
    head->data = 1; 
    two->data = 2;
    three->data = 3;
    four->data = 4; 

    /**
     * @brief Assign pointer the address of next memory location and connect nodes 
     * 
     */

    head->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;
    /**
     * @brief Adding a new node at the end of linklist
     * 
     */
    printf("NEW NODE INSERTED AT END OF LINK LIST\n");
    insertnodeatend(head,15);


    /**
     * @brief finding the number of nodes in the given link list
     * 
     */
    printf("COUNT OF NODES IN GIVEN LINK LIST\n");
    findcount(head);

    /**
     * @brief Adding a new node at the start of linklist
     * 
     */
    printf("NEW NODE INSERTED AT START OF LINK LIST\n");
    head = insertnodeatstart(head,99);


    /**
     * @brief print the node value 
     * 
     */
    printf("NEW LINK LIST\n");
    printLinklist(head);

    
    return 0 ; 
}



