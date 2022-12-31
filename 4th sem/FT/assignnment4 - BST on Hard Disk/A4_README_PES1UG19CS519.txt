# Key takeaways from the assignment:
- Practical implementation keeping in mind the concepts of virtual memory.
- Proper use of fseek, ftell, fread and fwrite.

# Additional notes:
- Initailly root is at offset sizeof(tree_t) + 0
- On deleting a node, right_offset is made -1, key left untouched.

