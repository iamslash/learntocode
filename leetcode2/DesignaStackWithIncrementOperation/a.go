/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 32ms 28.13% 6.6MB 96.55%
type CustomStack struct {
  MaxSize int
  Data []int
}


func Constructor(maxSize int) CustomStack {
  return CustomStack{
    MaxSize: maxSize,
    Data: make([]int, 0),
  }
}


func (this *CustomStack) Push(x int)  {
  if len(this.Data) < this.MaxSize {
    this.Data = append(this.Data, x)
  }
}


func (this *CustomStack) Pop() int {
    if len(this.Data) == 0 {
    return -1
  }
  top := this.Data[len(this.Data)-1]
  this.Data = this.Data[:len(this.Data)-1]
  return top
}


func (this *CustomStack) Increment(k int, val int)  {
  for i := 0; i < k && i < len(this.Data); i++ {
    this.Data[i] += val
  }
}
