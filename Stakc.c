
#include <stdio.h>
#include <stdlib.h>

// Made by Husain Abugosh @20/5/2023

/* Stacks: is a list  with the restreaction that insertion and deletion can be performed only at one postion
(the end of list -> called TOP)

we can say the stack is like the pringles 🪘 the last chips 🫓 in >> will be the first one out :)
so that the stacks are known as LIFO(last in first out).

The fundamental operations of the stack are:
• Push: equivalent to insert. Inserts element at top.
• Pop: return and delete the most recently added element .
• Top: examines (returns) the most recently added element without deleteing it.

*NOTE: pop or top on empty stack is generally considered an error*

we can implement the stack using:
• Linked list.
• Dynamic array.

 _______________________________
| Top    |      |      |       | 
|        |      |      |       | 
|   >    |   >  |   >  |       |


*/

//______________________________________________________   👇🏽 by linked list 👇🏽  ______________________________________________________ // 

// to make a shortcut of data we can USE 'typedef' KeyWord:
// typedef struct Node* List   >>>  now List = struct node*
// typedef List Postion >>>>  now  Postion = List = struct node*



// the struct(we can say its like class in java hava atributes and we can make an object from this struct):
typedef struct  Node{
    int data;              // <<<  will store the data in the node.
    struct Node* next;    // <<<  will store the address of the next node (points on the NEXT NODE thats why its data is struct node).

}Node;


Node* createStack() {
    return NULL;
}

//Push function: equivalent to insert. Inserts element at top:
void push(Node* stack, int element) {

    Node* newNode = (Node*)malloc(sizeof(Node)); //<-- to find a address in the memo to save the new node in it.

     // if there is no space in the memo for this node tell the user:
    if (newNode == NULL) {
        printf("memory allocation failed, falied to push element.\n");
        return;
    }

    newNode->data = element;   //<-- sets the data of the newNode to be the element.
    newNode->next = stack;    //<-- sets the next pointer of newNode to point to the current top of the stack).
    stack = newNode;         //<-- sets the newNode to be the top(stack) node(top of the stack),  making it the new top of the stack.
    printf("element %d pushed to the stack. \n", element); // <-- to tell the user the push success. 

}


//Pop function: return AND delete the most recently added element:
int pop(Node* stack) {

    // if the theere is no elements inside the stack there is nothing to pop so it will cuse an error:
    if (stack == NULL) {
       printf("*EROOR the stack is empty, nothing to pop*\n");
        return -1;
    }

    Node* temp = stack;              //<--  temporary node will pointer to top node.
    int poppedElement = temp->data; //<-- to store the data that was in the last top.
    stack = temp->next;            //<-- will make the next node of the pervious top to be the the final top.
    free(temp);                   //<-- free the temp (node) from the memo.
     printf("element %d popped from the stack.\n", poppedElement); //<-- tell the user whats happend.
    return poppedElement;   //<-- return the poppedElement.

}

//getTop: examines (returns) the most recently added element without deleteing it:
int getTop(Node* stack) {

    // if the theere is no elements inside the stack there is nothing to pop so it will cuse an error:
    if (stack == NULL) {
        printf("*EROOR the stack is empty, nothing to pop*\n");
        return -1;
    }
    return stack->data;  //<-- will return the elemnt that in the top node.
}

//deleteStack function : will delete the nedeed stack:
void deleteStack(Node* stack) {

  // will delete all the nodes:
    while (stack != NULL) {
        Node* temp = stack;
        stack = stack->next;
        free(temp);
    }
    printf("Stack deleted.\n");
}

//sizeOf: to get the size of the stack:
int sizeOf(Node* stack) {

    int size = 0;
    while (stack != NULL) {
        stack = stack->next;
        size++;
    }
    return size;
}


//isEmpty: return if the stack is null or not:
int isEmpty(Node* stack){
    return (stack == NULL); //<-- to return if the stack is null or not 
}


//______________________________________________________   👇🏽 by Dynamic array 👇🏽  ______________________________________________________ // 







int main() {

     Node* stack1 = createStack(); //<-- to declear a stack.

    push(stack1,1);  //<-- will push into the only stack we have
    push(stack1,2); 
    push(stack1,3); //<--  last one in so that will be the top node (LIFO)

    // what will print is the last element did push in (TOP) which is >> 3:
    int topElement = getTop(stack1);
    printf("Top element: %d\n", topElement);

    // what will poped is the last element did push in (TOP) which is >> 3  and the element 2 will be the top node:
    int poppedElement = pop(stack1);
    printf("Popped element: %d\n", poppedElement);

    //  what will print is the  last element did push in (TOP) which is >> 3:
    topElement = getTop(stack1);
    printf("Top element: %d\n", topElement);

    return 0;
}