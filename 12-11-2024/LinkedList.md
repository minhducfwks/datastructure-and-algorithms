## Linked List

### **A linked list**
**Linked list** is a data structure used for storing collections of data. A linked list has the following properties.

- Successive elements are connected by pointers
- The last element points to NULL
- Can grow or shrink in size during execution of a program
- Can be made just as long as required (until systems memory exhausts)
- Does not waste memory space (but takes some extra memory for pointers). It
allocates memory as list grows.


### **Some basic operation on a list:**
Traversing the list: Starting from the head node, we can traverse the list by following the next pointers of each node.

Inserting a new node: We can insert a new node at the beginning or at the end of the list.
- Insertion into a singly-linked list has three cases: 
- Inserting a new node before the head (at the beginning)
- Inserting a new node after the tail (at the end of the list)
- Inserting a new node at the middle of the list (random location)

Deleting a node: We can delete a node from the list by updating the next pointers of the previous and next nodes.


### **Singly Linked List**
**Singly Linked List** consists of a number of nodes in which each node has a next pointer to the following element. The link of the last node in the list is NULL, which indicates the end of the list.

### **Doubly Linked List**
The advantage of a **doubly linked list** (also called two – way linked list) is that given a node in the list, we can navigate in both directions. A node in a singly linked list cannot be removed unless we have the pointer to its predecessor. But in a doubly linked list, we can delete a node even if we don’t have the previous node’s address (since each node has a left pointer pointing to the previous node and can move backward).



