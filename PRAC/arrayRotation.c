/**
 * @file arrayRoation.c
 * @author thatshashankguy
 * @brief A left rotation operation on an array of size  shifts each of the array's elements  
 *          unit to the left. Given an integer, , 
 *          rotate the array that many steps left and return the result. 
 * @version 0.1
 * @date 2022-09-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include <stdlib.h>


/**
 * @brief 
 * 
 * @param arr 
 * @param k 
 * @param s 
 * @return int* 
 */
void rotateArray(int arr[], int k , int s){
    int temp[k];
    int i,j,m,p ;

    for(i = 0 ; i <k ;i++ ){
        temp[i] = arr[i];
    }


    for(j = 0 ; j < s ; j++){
        if(!arr[k+1]){
            continue;
        }
        arr[i] = arr[k+1];
    }

    for(m = 0 ; m < k; m++){
        if(!arr[s-k+1]) continue;
        
        arr[s - k + i ]  = temp[i];


    }

    for(p = 0 ; p < s ; p++){
        printf("%d\n",arr[p]);
    }
}


int main(){

    int arr[] = {1,2,3,4,5};

    int size = sizeof(arr)/sizeof(arr[0]);
    rotateArray(arr,4,size);
    return 0;
}