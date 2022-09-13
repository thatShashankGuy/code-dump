class node {
    data;
    next;
    prev;
    constructor(data){
        this.data = data
        this.next = null;
        this.prev = null;
    }
}

const head = new node(99);
const two = new node(88);
const three = new node(77);
const tail = new node(66);

head.next = two;
head.prev = null;

two.next = three;
two.prev = head;

three.next = tail;
three.prev = two;

tail.next = null;
tail.prev = three;


function printdll(head,tail){
    while(head !== null){
        console.log(head.data);
        head = head.next;
    }
    while (tail !== null) {
        console.log(tail.data);
        tail = tail.prev
    }

}
printdll(head,tail)

/**
 * CIRCULAR LINK LIST - HEAD POINTS TO TAIL (TAIL POINTS TO HEAD WITH 'PREV' POINTER)
 */

 const _head = new node(99);
 const _two = new node(88);
 const _three = new node(77);
 const _tail = new node(66);
 
 _head.next = _two;
 _head.prev = _tail;

 _two.next = _three;
 _two.prev = _head;
 
 _three.next = _tail;
 _three.prev = _two;

 _tail.next = _head;
 _tail.prev = _three;
 
 
 function printcll(head,tail){
     let temp = head; 
     let tailtemp = tail
    
     console.log("circular link list")
     do {
        
        console.log(head.data);
        head = head.next;
     } while (head != temp );
     console.log("circular link list backwards")
     do {
     
        console.log(tail.data);
        tail = tail.prev;
     } while (tail != tailtemp );
 
 
 }

 function addAlink(head,node,pos){
    
 }
 printcll(_head,_tail)

