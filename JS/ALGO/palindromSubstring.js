/** Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

A string is called a palindrome string if the reverse of that string is the same as the original string.

*/

str = 'cbbd'

function palinsub(s){
   
    const temp = [];

    for(let i = 0 ; i < s.length ; i++){

        let l = i;
        let r = i;
        let val = 0; 

        while(r>=l){
            if(l < 0 || r > s.length){
                break;
            }
            if(s[l] == s[r]){
                val += 1
            }
            l-- 
            r++
        }

        temp.push(val)
    }
    console.log(temp)
    const max = temp.reduce((max,x)=>{
        if(x > max){
            max = x 
        }
        return max
    }, 0)

    return temp.indexOf(max)

    
}
const res = palinsub(str);
console.log(res);