# Problem

[Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)

# Idea

Implement the stack using queue.

For example, let's push from 1 to 5 to queue. Rote for n - 1 times after pushing x.

```
push 1: 1

push 2: 1 2
        2 1

push 3: 2 1 3
        1 3 2
        3 2 1

push 4: 3 2 1 4
        2 1 4 3
        1 4 3 2
        4 3 2 1
        
push 5: 4 3 2 1 5
        3 2 1 5 4
        2 1 5 4 3
        1 5 4 3 2
        5 4 3 2 1        
```

# Implementation

* [go](a.go)

# Complexity

```
push: o(N) O(N)
```
