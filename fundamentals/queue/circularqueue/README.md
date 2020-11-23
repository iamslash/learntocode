# Problem

* [Design Circular Queue @ leetcode](https://leetcode.com/problems/design-circular-queue/)
* [Design Circular Queue @ leetcode](https://leetcode.com/explore/learn/card/queue-stack/228/first-in-first-out-data-structure/1337/)

First-in-First-out Data Structure 를 design 하고 다음을 구현하라.

```cpp
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        
    }
    
    /** Get the front item from the queue. */
    int Front() {
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        
    }
```

# Idea

`vector<int> m_data, int m_capa, m_size, m_head, m_tail` 를 선언하고 구혀한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
enQueue: O(1)
deQueue: O(1)
  front: O(1)
   rear: O(1)
isEmpty: O(1)
 isFull: O(1)
```
