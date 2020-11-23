/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 28ms 91.18% 6.5MB 100.00%
// Design
type Node struct {
  Val int
  Next *Node
}

type MyLinkedList struct {
  Size int
  Head *Node
}

func Constructor() MyLinkedList {
  return MyLinkedList{
    Size: 0,
    Head: &Node{},
  }
}

func (this *MyLinkedList) Get(idx int) int {
  if idx >= this.Size {
    return -1
  }
  p := this.Head.Next
  for i := 0; i < idx; i++ {
    p = p.Next
  }
  return p.Val
}

func (this *MyLinkedList) AddAtHead(val int)  {
  u := this.Head.Next
  this.Head.Next = &Node{
    Val: val,
  }
  this.Head.Next.Next = u
  this.Size++
}

func (this *MyLinkedList) AddAtTail(val int)  {
  p := this.Head
  for p.Next != nil {
    p = p.Next
  }
  p.Next = &Node{
    Val:val,
  }
  this.Size++
}

func (this *MyLinkedList) AddAtIndex(idx int, val int)  {
  if idx > this.Size {
    return
  }
  u := this.Head
  for i := 0; i < idx; i++ {
    u = u.Next
  }
  v := u.Next
  u.Next = &Node{
    Val: val,
    Next: v,
  }
  this.Size++
}

func (this *MyLinkedList) DeleteAtIndex(idx int)  {
  if idx >= this.Size {
    return
  }
  u := this.Head
  for i := 0; i < idx; i++ {
    u = u.Next
  }
  v := u.Next
  u.Next = v.Next
  v.Next = nil
  this.Size--
  v = nil
}


func main() {
  fmt.Println("hello world")
}
