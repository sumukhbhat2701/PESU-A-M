- Allocation policy used: First Fit method. 
The memory space is traversed and allocation happens in the first free space that is found on linear traversal from start to end of memory.

- Basic logic used for implementation: Singly linked lists
A singly linked list with each node with book-keeping information is created. The memory space is typecasted to structure type wherever necessary 
for the implementation of the same and consecutive book-keeping nodes connected in a typical singly list fashion.

- Explanation of the book-keeping structure:
buffer       : number of bytes/blocks allocated or free 
encoded_flag : 1 - allocated space ; 2 - free space (0 is explicitly print for bookkeeping in print_mem_map() function)
link         : the pointer holding the address of next book keeping node in the linked lists of book keeping nodes
returned     : the pointer pointing to the first allocated block which is returned to the caller.

- Any additional notes:
The code is written in such a way that if mymalloc function is called before allocate function, it returns NULL
The validity of b pointer passed as parameter to myfree function is not verified
size_of_structure is defined using #define and is not a global variable, hence cannot be accessed in sanity_client.c
Due to %ld format specifier in the print statement of size_of_structure in print_book function, compilation is giving a warning to change it to unsigned int. 
But it was not rectified as the print statement was not asked to be changed in the doc file.  