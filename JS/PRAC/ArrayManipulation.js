/**
 * Array manipulation from HackerRank 
 * 
 */
/**
 * 
 * @param {*} arr
 * @param {*} n 
 */
function arrMan(arr,n){

    const z = new Array(n);
    z.fill(0);
    for (let i = 0; i < arr.length; i++) {
        let a =arr[i][0]
        let b = arr[i][1]
        let k = arr[i][2]

        for(let u = 1 ; u < z.length +1  ; u++ ){
            if(u >= a && u<=b){
                z[u] += k
            }
        }   
    }

    let big = z.reduce((max, x)=>{
        if(x > max){
            max =x
        }
        return max
    },0)

    return big 
}  

console.log(arrMan([[1,5,3],[4,8,7],[6,9,1]],10))