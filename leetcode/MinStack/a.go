/* Copyright (C) 2019 by iamslash */

package main

import "fmt"

// stck: -2-2 0
//  min: -2     

// 20ms 81.96% 8.2MB 100.00%
// using onestack, min
type MinStack struct {
  min  int
  data []int
}

func Constructor() MinStack {
  return MinStack{
    min: math.MaxInt32,
  }
}

func (this *MinStack) Push(x int) {
  if x <= this.min {
    this.data = append(this.data, this.min)
    this.min = x
  }
  this.data = append(this.data, x)
}

func (this *MinStack) Pop()  {
  if this.Top() == this.min {
    this.data = this.data[:len(this.data)-1]
    this.min = this.Top()
  }
  this.data = this.data[:len(this.data)-1]
}


func (this *MinStack) Top() int {
  return this.data[len(this.data)-1]
}


func (this *MinStack) GetMin() int {
  return this.min
}

func main() {
    fmt.Println("hello world")
}
