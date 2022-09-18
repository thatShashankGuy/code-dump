

/**
 * @brief sparce from hacker rank 
 */

const stringList = ['ab','bcc', 'ab' ,'xyz'];
const queries = ['ab','ce','xyz']



/**
 * BRUTE FORCE BAD ANSWER 
 * @param {*} stringList 
 * @param {*} queries 
 * @returns 
 */
function sparseOld(stringList,queries){
        const ob = {}

        queries.forEach(x => {
            ob[x] = 0
        });
        let res = [];

        for (let i = 0; i < stringList.length; i++) {
           for (let j = 0; j < queries.length; j++) {
                    if(stringList[i] !== queries[j]){
                            continue
                    }
                 
                        ob[queries[j]] += 1 ;
            
           }
            
        }

       for (const key in ob) {
        if (ob.hasOwnProperty.call(ob, key)) {
            res.push(ob[key]);
            
        }
       }
    return res
}




function sparse(stringList,queries){
       const m = new Map();
       const ar = [];
       stringList.forEach(x => {
            if(m[x]){
                m[x] += 1 
            }else{
                m[x] = 1
            }
       });

       queries.forEach(q => {
            if(m[q]){
                ar.push(m[q]);
            }else{
                ar.push(0);
            }
       })

      return ar;
}

sparse(stringList,queries)