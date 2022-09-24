/**
 * You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
 */

function maxProfit(prices){
     let min = prices.reduce((m,x)=>{
        if(x < m){
            m = x 
        }
        return m
     },100000)

     let p = prices.filter((x,t)=> (min < x && prices.indexOf(min)> t) === false)
  
     let max = p.reduce((m,x)=>{
        if(x> m){
            m = x
        }
        return m
     },-1)
     console.log(max -min )
     return max - min 
}

maxProfit([7,1,5,3,6,4])

maxProfit([2,4,1])