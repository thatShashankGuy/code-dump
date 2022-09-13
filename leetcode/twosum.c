/**
 * @file twosum.c
 * @author ythatshashanlguy 
 * @brief Just Writing few Leetcode questions to get more hands on C 
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 
 * @brief Problem Statement 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * @note the return array must be malloced , assume caller calls free();
 */

#include <stdlib.h>
#include<stdio.h>

//brute force approach

int* twoSum(int* nums, int numsSize, int target, int *returnSize ){
    int i , j;
    int * output_arr = (int*)malloc(2*sizeof(int));

    if(output_arr == NULL || nums == NULL){
        *returnSize  ==0;
        return NULL;
    }

    for (i = 0; i < numsSize; i++){
        for(j = i+1;j < numsSize;j++){
            if(nums[i] + nums[j] == target)
            *returnSize = 2; 
            output_arr[0] = j ;
            output_arr[1] = i;
            return output_arr;
        }
    }

    *returnSize = 0 ;
    free(output_arr);

    return NULL;

    
}

/**
 * @brief optimizing the two sum funciton by using hash table 
 * 
 * @param nums 
 * @param numsSize 
 * @param target 
 * @param returnSize 
 * @return int* 
 */
int* twoSum(int* nums, int numsSize, int target, int *returnSize ){
// to be impelemented once Hash table is clear ; 
}
int main(){
    int a[] = {2,7,11,15};
    int rs,target = 9;
    int *p = NULL;

    p = twoSum(a,sizeof(a)/sizeof(a[0]),target,&rs);

    if(rs== 0 ){
        printf("target not found ");
    }else{
        printf("target found");
    }
}