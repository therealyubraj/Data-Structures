# Data-Structures
Implementation of various Data Structures in C++.

##LinkedList.h##
LinkedList<*type*> linkedListName;

###Implementation details###
A node class is created for a single node in the list which stores the data and two pointers to its previous and next elements. The first and the last elements are linked as well.
So, this is a doubly linked list.

###Methods###
size() -> returns the size of the linked list and takes no parameters.
printLinkedList() -> prints all the contents of the linked list if they are printable using cout.
insert(o, i) -> Insert a new "object" o at index i.
deleteIndex(i) -> Removes the element ar index i from the linked list.
get(i) -> returns the value at index i.

###Currently working on heaps.###
