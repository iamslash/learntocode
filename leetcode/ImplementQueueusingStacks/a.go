/* Copyright (C) 2020 by iamslash */

package main

import "fmt"


// 0
// 1 0
// 2 1 0

// 0ms 100.00% 2MB 25.00%
// two stacks
// Push: O(N) O(N)
type MyQueue struct {
  stack []int
}
func Constructor() MyQueue {
  return MyQueue{
    stack: []int{},
  }
}
func (this *MyQueue) Push(x int)  {
  tStack := []int{}
  for len(this.stack) > 0 {
    tStack = append(tStack, this.Pop())
  }
  this.stack = append(this.stack, x)
  for len(tStack) > 0 {
    this.stack = append(this.stack, tStack[len(tStack)-1])
    tStack = tStack[:len(tStack)-1]
  }  
}

func (this *MyQueue) Pop() int {
  top := this.stack[len(this.stack)-1]
  this.stack = this.stack[:len(this.stack)-1]
  return top
}

func (this *MyQueue) Peek() int {
  return this.stack[len(this.stack)-1]
}

func (this *MyQueue) Empty() bool {
  return len(this.stack) == 0
}

func main() {
    fmt.Println("hello world")
}
