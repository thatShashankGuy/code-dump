/**
 * @brief problem from HackerRank
 * Rotate Array to left by K for eg : given array [1,2,3,4,5] and K = 2 so the output shall be [3,4,5,1,2]
 * @param {*} arr 
 * @param {*} k 
 */

function rotateArrayUnshift(arr,k){
       let i = 0;

       while(i < k){
        let temp = arr.shift();S
        arr.push(temp);
        i++
       }

       return arr;
}

function rotateArray(arr,k){
        temp= [];
        for(let i = 0 ; i <k; i++){
            temp[i] = arr[i];
        } // create a temp array and saved thhe last part of array 
        for(let i = 0 ; i < arr.length ; i++){
            if(arr[i+k] === undefined){
                continue    
            }
            arr[i] = arr[i+k];
            
        }

        for(let i = 0  ; i < temp.length; i++){
            arr[arr.length - k + i ] = temp[i];
        }
        return arr

}

//console.log(rotateArray([1,2,3,4,5],4));
//console.log(rotateArrayUnshift([1,2,3,4,5],4))

console.time("Using Unshift")
rotateArrayUnshift([1,2,3,4,5],4)
console.timeEnd("Using Unshift")

console.time("Without Using Unshift")
rotateArray([1,2,3,4,5],4)
console.timeEnd("Without Using Unshift")