
### **1. Basic Data Structures**

* **Linear vs. Non-Linear Data Structures:**
* **Linear:** Elements are arranged in a sequential order (e.g., Arrays, Linked Lists, Stacks, Queues).
* **Non-Linear:** Elements are arranged in a hierarchical or interconnected manner (e.g., Trees, Graphs).


* **Array:** A collection of items stored at contiguous memory locations. It allows for fast, $O(1)$ random access using an index, but has a fixed size.
* **Stack:** A linear data structure following the **LIFO** (Last In, First Out) principle. Think of a stack of plates.
* *Operations:* `Push` (insert), `Pop` (remove), `Peek/Top` (view top element), `isEmpty`.


* **Queue:** A linear data structure following the **FIFO** (First In, First Out) principle. Think of a line at a ticket counter.
* *Operations:* `Enqueue` (insert at rear), `Dequeue` (remove from front), `Front`, `Rear`, `isEmpty`.


* **Linked List:** A linear structure where elements (nodes) are not stored in contiguous memory. Each node contains data and a pointer to the next node.
* *Types:* Singly Linked List (pointer to next), Doubly Linked List (pointers to next and previous), Circular Linked List (last node points back to the first).


* **Linked List vs. Array:**
* *Advantages of LL:* Dynamic size; fast insertions/deletions ($O(1)$) if the node pointer is known, as it doesn't require shifting elements.
* *When to use LL:* When you need frequent insertions and deletions, and you don't know the size of the data in advance.
* *When to use Array:* When you need frequent random access (reading data by index) and memory usage needs to be strictly controlled.



### **2. Trees & Graphs**

* **Binary Tree:** A tree where every node has at most two children (left and right).
* **Binary Search Tree (BST):** A binary tree with a strict rule: for any node, all values in its left subtree are smaller, and all values in its right subtree are larger.
* **Tree Traversals:** Methods to visit every node in a tree.
* **Inorder:** Left, Root, Right (Yields sorted data in a BST).
* **Preorder:** Root, Left, Right (Used to create a copy of the tree).
* **Postorder:** Left, Right, Root (Used to delete a tree).


* **AVL Tree:** A self-balancing Binary Search Tree where the difference in heights between the left and right subtrees of any node is at most 1. This ensures $O(\log n)$ search times.
* **Red-Black Tree:** A self-balancing BST where nodes are colored red or black, following specific rules (e.g., the root is black, red nodes cannot have red children). It balances less strictly than AVL, making insertions/deletions slightly faster.
* **Heap:** A specialized tree-based structure that satisfies the heap property. In a **Max-Heap**, the parent is always greater than or equal to its children. In a **Min-Heap**, the parent is smaller. It is typically represented as an array.
* **Priority Queue:** An abstract data type usually implemented using a Heap. Elements are dequeued based on priority rather than FIFO order.
* **Graph:** A non-linear structure consisting of **Vertices (nodes)** connected by **Edges**.
* *Representations:* **Adjacency Matrix** (a 2D array) and **Adjacency List** (an array of linked lists).


* **BFS vs. DFS:**
* **Breadth-First Search (BFS):** Explores a graph level-by-level, moving wide before moving deep. Uses a **Queue**.
* **Depth-First Search (DFS):** Explores as far down a branch as possible before backtracking. Uses a **Stack** (or recursion).



### **3. Hashing**

* **Hashing / Hashmap:** A technique to map keys to values using a "hash function." The hash function converts a key into an index within an array (the hash table), allowing for extremely fast lookups.
* **Collision Resolution Techniques:** When two keys hash to the same index (a collision).
* *Chaining:* Storing a Linked List at that index to hold multiple values.
* *Open Addressing:* Finding the next available empty slot (using Linear Probing, Quadratic Probing, or Double Hashing).


* **Hash Table Time Complexity:**
* Search, Insert, Delete: **Average case $O(1)$**, Worst case $O(n)$ (if all elements collide into the same slot).



### **4. Sorting & Searching Algorithms**

* **Merge Sort (How it works):** A "Divide and Conquer" algorithm. It repeatedly divides the array in half until each sub-array has only 1 element. Then, it repeatedly merges these sorted sub-arrays back together to form the final sorted array.
* **Fastest Sorting Algorithm:** **Quick Sort** is generally considered the fastest in practice for primitive types because of excellent cache locality and low memory overhead, despite its worst-case time complexity. **Merge Sort** is preferred when stability is required or for linked lists.
* **Sorting Time Complexities:**
* **Bubble Sort:** Best $O(n)$ (if already sorted), Avg/Worst $O(n^2)$.
* **Selection Sort:** Best, Avg, Worst all $O(n^2)$.
* **Insertion Sort:** Best $O(n)$, Avg/Worst $O(n^2)$.
* **Merge Sort:** Best, Avg, Worst all $O(n \log n)$.
* **Quick Sort:** Best/Avg $O(n \log n)$, Worst $O(n^2)$.


* **Binary vs. Linear Search:** Linear search checks items one by one. Binary search repeatedly divides a *sorted* array in half, ignoring the half where the target cannot exist.
* **Searching Time Complexities:**
* *Linear Search (Unsorted):* $O(n)$
* *Binary Search (Sorted):* $O(\log n)$



### **5. Core Concepts & Complexities**

* **Asymptotic Analysis:** Evaluating the performance (time and space complexity) of an algorithm as the size of the input data ($n$) grows toward infinity. Uses notations like Big-O (worst-case), Theta (average), and Omega (best-case).
* **Recursion:** A programming technique where a function calls itself to solve smaller instances of the same problem. It must have a "base case" to stop the loop.
* **Linked List Time Complexities:**
* *Search & Traversal:* $O(n)$
* *Insertion/Deletion at Head:* $O(1)$
* *Insertion/Deletion at specific index:* $O(n)$ (because you must traverse to find the spot).



### **6. Advanced Graph Algorithms**

* **Shortest Route (Dijkstra's Algorithm):** To find the shortest path from a starting node to all other nodes in a graph with non-negative edge weights. It uses a Priority Queue to greedily visit the closest unvisited node and update the distances to its neighbors.
* **Minimum Spanning Tree (MST):** A subset of edges in a connected, weighted graph that connects all vertices together without forming any cycles, and with the lowest possible total edge weight.
* **Prim's Algorithm:** Finds an MST by starting at an arbitrary node and greedily adding the cheapest edge that connects a visited node to an unvisited node.
* **Kruskal's Algorithm:** Finds an MST by sorting all edges by weight, then adding them one by one from lightest to heaviest, using a "Union-Find" data structure to ensure no cycles are created.