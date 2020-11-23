/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 452ms 33.33% 28.8MB 33.33%
// two pointers
// O(N) O(N)
type SparseVector struct {
  Data [][]int
}

func Constructor(A []int) SparseVector {
  sparseVector := SparseVector {
    Data: make([][]int, 0),
  }
  for i := 0; i < len(A); i++ {
    sparseVector.Data = append(sparseVector.Data, []int{i, A[i]})
  }
  return sparseVector
}

// Return the dotProduct of two sparse vectors
func (this *SparseVector) dotProduct(other SparseVector) int {
  n, m, ans := len(this.Data), len(other.Data), 0
  for i, j := 0, 0; i < n && j < m; i, j = i+1, j+1 {
    if this.Data[i][0] < other.Data[j][0] {
      j--
    } else if this.Data[i][0] > other.Data[j][0] {
      i--
    } else {
      ans += this.Data[i][1] * other.Data[i][1]
    }
  }
  return ans
}
