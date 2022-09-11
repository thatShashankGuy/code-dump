/**
 * The Node is the primary data point of a link list , link list is made up of nodes 
 * each node have data and a next pointing to the next node 
 * 
 */

class node {
   data 
   next
    constructor(data){
        this.data = data
        this.next = null;
    }
}

/**
 * 
 * @param {*} p
 * function prints the link list and takes the head of the link list  as argument  
 */
function printlinklist(p){
    while(p !== null){
        console.log(p.data);
        p = p.next;        
    }
}

/**
 * function insert a node at the end of linklist , takes link list's head and data to be inserted 
 * as arguments 
 * 
 * @param {*} p 
 * @param {*} data 
 * @returns 
 */
function insertend(p,data){
    let end = new node(data);
    end.next = null;
    if(p == null){
        console.log('overflow');
    }else{
        while(p.next !== null){ //traversal of node is required to get to the end of link list 
            p = p.next;
        }
        p.next = end;
    }

   return p;
}

function insertstart(head,data){
    //because its start no need to travese the link list 
    if(head === null){
        console.log("OVERFLOW")
    }else{
        let newhead = new node(data);
        newhead.next = head;
        head = newhead;
    }
    console.log("head->", head)
    return head
}


const head = new node(0);
const two = new node(1);
const three = new node(2);



head.next = two;
two.next = three;
three.next = null;

//add 17 to the end 
insertend(head,17);
//add -1 to the head
head_new = insertstart(head,-1); //function returns new head with the last head now being the second element 
//hence to print list with new head we reassign head as insertstart return head  

printlinklist(head_new);




