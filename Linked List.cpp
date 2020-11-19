/* Linked List
Like arrays, it is a linear data structure.
Unlike arrays, the elements are not stored at a contiguous location.
The elements are linked using pointers.

Arrays can be used to store linear data of similar types, but arrays have the following limitations:
1) The size of the arrays is fixed:
     So we must know the upper limit on the number of elements in advance.
     Also, generally, the allocated memory is equal to the upper limit irrespective of the usage.
2) Inserting a new element in an array of elements is expensive because the room has to be created for the new elements and to create room existing elements have to be shifted.
   For example, if we maintain a sorted list of IDs in an array id[]:
     id[] = [1000, 1010, 1050, 2000, 2040].
     And if we want to insert a new ID 1005, then to maintain the sorted order, we have to move all the elements after 1000 (excluding 1000).
     Deletion is also expensive with arrays until unless some special techniques are used.
     For example, to delete 1010 in id[], everything after 1010 has to be moved.

Advantages over arrays:
1) Dynamic size
2) Ease of insertion/deletion

Drawbacks:
1) Random access is not allowed.
   We have to access elements sequentially starting from the first node.
   So we cannot do binary search with linked lists efficiently with its default implementation.
2) Extra memory space for a pointer is required with each element of the list.
3) Not cache friendly.
   Since array elements are contiguous locations, there is locality of reference which is not there in case of linked lists.

Representation:
It is represented by a pointer to the first node of the linked list.
The first node is called the head.
If the linked list is empty, then the value of the head is NULL.
Each node in a list consists of at least two parts:
1) data
2) Pointer (Or Reference) to the next node
*/

// Single Linked List
#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
      int data;
      Node* next;
};

// Program to create a simple linked list with 3 nodes
int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    /* Three blocks have been allocated dynamically.
    We have pointers to these three blocks as head,
    second and third

    head         second         third
        |             |             |
        |             |             |
    +---+-----+     +----+----+     +----+----+
    | # | # |     | # | # |     | # | # |
    +---+-----+     +----+----+     +----+----+

    "#" represents any random value.
    Data is random because we haven’t assigned anything yet */

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with
    // the second node

    /* data has been assigned to the data part of first
    block (block pointed by the head). And next
    pointer of the first block points to second.
    So they both are linked.

    head         second         third
        |             |             |
        |             |             |
    +---+---+     +----+----+     +-----+----+
    | 1 | o----->| # | # |     | # | # |
    +---+---+     +----+----+     +-----+----+
*/

    // assign data to second node
    second->data = 2;

    // Link second node with the third node
    second->next = third;

    /* data has been assigned to the data part of the second
    block (block pointed by second). And next
    pointer of the second block points to the third
    block. So all three blocks are linked.

    head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1 | o----->| 2 | o-----> | # | # |
    +---+---+     +---+---+     +----+----+     */

    third->data = 3; // assign data to third node
    third->next = NULL;

    /* data has been assigned to the data part of the third
    block (block pointed by third). And next pointer
    of the third block is made NULL to indicate
    that the linked list is terminated here.

    We have the linked list ready.

        head
            |
            |
        +---+---+     +---+---+     +----+------+
        | 1 | o----->| 2 | o-----> | 3 | NULL |
        +---+---+     +---+---+     +----+------+

    Note that only the head is sufficient to represent
    the whole list. We can traverse the complete
    list by following the next pointers. */

    return 0;
}


/* Linked List vs Array
Key Differences Between Array and Linked List
1. An array is the data structure that contains a collection of similar type data elements.
   A Linked list is considered as non-primitive data structure contains a collection of unordered linked elements known as nodes.
2. In the array the elements belong to indexes, for example:
      If you want to get into the fourth element you have to write the variable name with its index or location within the square bracket.
3. In a linked list though, you have to start from the head and work your way through until you get to the fourth element.
4. Accessing an element in an array is fast, while Linked list takes linear time, so it is quite a bit slower.
5. Operations like insertion and deletion in arrays consume a lot of time.
   On the other hand, the performance of these operations in Linked lists is fast.
6. Arrays are of fixed size. In contrast, Linked lists are dynamic and flexible and can expand and contract its size.
7. In an array, memory is assigned during compile time while in a Linked list it is allocated during execution or runtime.
9. Elements are stored consecutively in arrays whereas it is stored randomly in Linked lists.
10. The requirement of memory is less due to actual data being stored within the index in the array.
    As against, there is a need for more memory in Linked Lists due to storage of additional next and previous referencing elements.
11. In addition memory utilization is inefficient in the array.
    Conversely, memory utilization is efficient in the linked list.
*/


/* Traversal Linked List
In the previous program, we have created a simple linked list with three nodes.
Let us traverse the created list and print the data of each node.
For traversal, let us write a general-purpose function printList() that prints any given list.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
   public:
      int data;
      Node* next;
};

// This function prints contents of linked list
// starting from the given node
void printList(Node* n){
   while (n != NULL) {
      cout << n->data << " ";
      n = n->next;
   }
}

// Driver code
int main(){
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second

    second->data = 2; // assign data to second node
    second->next = third;

    third->data = 3; // assign data to third node
    third->next = NULL;

    printList(head);
    return 0;
}


/* Inserting a node
Methods to insert a new node in linked list are discussed.
A node can be added in three ways:
1) At the front of the linked list
2) After a given node.
3) At the end of the linked list.

Add a node at the front: (A 4 steps process)
The new node is always added before the head of the given Linked List.
And newly added node becomes the new head of the Linked List.
For example if the given Linked List is 10->15->20->25 and we add an item 5 at the front, then the Linked List becomes 5->10->15->20->25.
Let us call the function that adds at the front of the list is push().
The push() must receive a pointer to the head pointer, because push must change the head pointer to point to the new node

Time complexity of push() is O(1) as it does constant amount of work.
Add a node after a given node: (5 steps process)
We are given pointer to a node, and the new node is inserted after the given node.

Time complexity of insertAfter() is O(1) as it does constant amount of work.
Add a node at the end: (6 steps process)
The new node is always added after the last node of the given Linked List.
For example if the given Linked List is 5->10->15->20->25 and we add an item 30 at the end, then the Linked List becomes 5->10->15->20->25->30.
Since a Linked List is typically represented by the head of it, we have to traverse the list till end and then change the next of last node to new node.

Time complexity of append is O(n) where n is the number of nodes in linked list.
Since there is a loop from head to end, the function does O(n) work.
This method can also be optimized to work in O(1) by keeping an extra pointer to tail of linked list.
*/

#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node{
    public:
      int data;
      Node *next;
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(Node** head_ref, int new_data){
    /* 1. allocate node */
    Node* new_node = new Node();

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node* prev_node, int new_data){
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL){
      cout<<"the given previous node cannot be NULL";
    return;
    }

    /* 2. allocate new node */
    Node* new_node = new Node();

    /* 3. put in the data */
    new_node->data = new_data;

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next;

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data){
    /* 1. allocate node */
    Node* new_node = new Node();
    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL){
       *head_ref = new_node;
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node){
   while (node != NULL){
      cout<<" "<<node->data;
      node = node->next;
   }
}

/* Driver code*/
int main(){
    /* Start with the empty list */
    Node* head = NULL;
    // Insert 6. So linked list becomes 6->NULL
    append(&head, 6);
    // Insert 7 at the beginning.
    // So linked list becomes 7->6->NULL
    push(&head, 7);
    // Insert 1 at the beginning.
    // So linked list becomes 1->7->6->NULL
    push(&head, 1);
    // Insert 4 at the end. So
    // linked list becomes 1->7->6->4->NULL
    append(&head, 4);
    // Insert 8, after 7. So linked
    // list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout<<"Created Linked list is: ";
    printList(head);
    return 0;
}


/* Deleting a node
Let us formulate the problem statement to understand the deletion process.
Given a ‘key’, delete the first occurrence of this key in linked list.
To delete a node from linked list, we need to do following steps:
1) Find previous node of the node to be deleted.
2) Change the next of previous node.
3) Free memory for the node to be deleted.

Since every node of linked list is dynamically allocated using malloc() in C, we need to call free() for freeing memory allocated for the node to be deleted.
*/

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node{
    int data;
    struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **head_ref, int key){
    // Store head node
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}

// This function prints contents of linked list starting from
// the given node
void printList(struct Node *node){
    while (node != NULL){
       printf(" %d ", node->data);
       node = node->next;
    }
}

/* Drier program to test above functions*/
int main(){
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    return 0;
}


/* Deleting a node at a given position
Given a singly linked list and a position, delete a linked list node at the given position.
Example:
Input: position = 1, Linked List = 8->2->3->1->7
Output: Linked List =  8->3->1->7

Input: position = 0, Linked List = 8->2->3->1->7
Output: Linked List = 2->3->1->7

If the node to be deleted is the root, simply delete it.
To delete a middle node, we must have a pointer to the node previous to the node to be deleted.
So if positions are not zero, we run a loop position-1 times and get a pointer to the previous node.
*/

#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node{
    int data;
    struct Node *next;
};

/* Given a reference (pointer to pointer) to the head of a list
   and an int inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position){
   // If linked list is empty
   if (*head_ref == NULL)
      return;

   // Store head node
   struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0){
        *head_ref = temp->next;   // Change head
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}

// This function prints contents of linked list starting from
// the given node
void printList(struct Node *node){
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

/* Driver program to test above functions*/
int main(){
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}
