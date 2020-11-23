/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// q: 4 3 2 1
// s: 1 2 3 4

// 0ms 100.00% 1.9MB 50.00%
type MyStack struct {
	q []int
}

/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{}
}

/** Push element x onto stack. */
func (this *MyStack) Push(x int) {
	this.q = append(this.q, x)
	for i := 0; i < len(this.q)-1; i++ {
		this.q = append(this.q, this.q[0])
		this.q = this.q[1:]
	}
}

/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	r := this.q[0]
	this.q = this.q[1:]
	return r
}

/** Get the top element. */
func (this *MyStack) Top() int {
	return this.q[0]
}

/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return len(this.q) == 0
}

/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */

func main() {
	fmt.Println("hello world")
}
