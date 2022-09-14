
/**
 * 
 * @brief Problem Statement 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * @note the return array must be malloced , assume caller calls free();
 */

arr = [2,7,11,15];
target = 9 ; 

/**
 * 
 * @param {*} arr 
 * @param {*} t 
 */
function twosum_brute(arr,t) {
    for(let i = 0 ; i <arr.length ;i++){
        for(let j = i+ 1 ; j< arr.length ; j++){
            if(target === arr[i] + arr[j]){
                    return [i,j]
            }
        }
    }
    return[]
}

/**
 * Optimize method 
 * @param {*} arr 
 * @param {*} t 
 * @returns 
 */

function twoSum(arr,t){
     const hash_table = {}
     for(let i = 0 ; i < arr.length ; i++){

        if(hash_table[t - arr[i]] !== undefined){
                return[hash_table[t-arr[i]],i]
        }else{
            hash_table[arr[i]] =  i ;
        }
     }
     return []
}


/**
 * Calling both optimal and brute force approch and timing the to understand time complexity better 
 * results 
 * [ 0, 1 ]
 * Brute Force : 8.078ms
 *  [ 0, 1 ]
 *  Optimal : 0.168ms
 * 
 */
console.time('Brute Force ')
console.log(twoSum(arr,target))
console.timeEnd('Brute Force ')


console.time('Optimal ')
console.log(twosum_brute(arr,target))
console.timeEnd('Optimal ')