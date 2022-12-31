- How to compile your code?
gcc A3_client_PES1UG19CS519.c A3_impl_PES1UG19CS519.c
./a.out

- Data structures used?
doubly linked lists

- The logic behind your implementation? state space search in dfs manner and backtracking:

until we donot have all the solutions i.e until the list is not empty
    make a transition based on the fn_index which would be incremented based on the last transition
    if the resultant state is not in the linked list and is valid
        add it to the linked list
        if it is same as goal state, print the list as we found one of the solution and increment the count for number of solutions
        
    if the resultant state is in the linked list or is not valid
        until the list not empty and no more transitions can take place
			delete the state that caused non valid or repeated state and backtrack

- Key takeaways from this assignment?
Solving problems given a state and goal state solvable using state space search. Applying iterative backtracking to get a desired solution.