# 🚀 Singly Linked List in C++ (Full Implementation)

This project demonstrates a complete implementation of a **singly linked list** in C++. It includes all essential operations such as insertion, deletion, sorting, and reverse printing — all done manually, without STL.

---

## 🧠 What I Learned

✅ Data structure fundamentals  
✅ Pointer manipulation in C++  
✅ Encapsulation using classes  
✅ Memory management with destructors  
✅ Recursion for reverse printing  
✅ Sorting logic without arrays

---

## 📂 Features Demonstrated

- `insert_at_head(int val)`
- `insert_at_tail(int val)`
- `insert_at_position(int index, int val)`
- `delete_head()`
- `delete_at(int index)`
- `get_at(int index)` — returns value at a given position
- `sort(start, end)` — sorts nodes between indices
- `print_list()` — prints list in order
- `reverse_print(start, end)` — prints list in reverse using recursion
- Multiple object usage (`ls1`, `ls2`)

---

## 📌 Sample Output

```bash
Inserting at tail: 5 2 9 1 4
Inserting 99 at head: 99 5 2 9 1 4
Inserting 100 at index 2: 99 5 100 2 9 1 4
Element at index 3: 2
Deleting element at index 2: 99 5 2 9 1 4
Sorted list: 1 2 4 5 9 99
Reverse Print: 99 9 5 4 2 1

Creating new list (ls2) with different values:
8 3 7
```
