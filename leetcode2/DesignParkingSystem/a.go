/* Copyright (C) 2020 by iamslash */

package main

import "fmt"

// 44ms 100.00% 6.7MB 100.00%
type ParkingSystem struct {
  avail []int
}

func Constructor(big int, medium int, small int) ParkingSystem {
  ps := ParkingSystem{
    avail: make([]int, 3),
  }
  ps.avail[0] = big
  ps.avail[1] = medium
  ps.avail[2] = small
  return ps
}

func (this *ParkingSystem) AddCar(carType int) bool {
  carType--
  this.avail[carType]--
  if this.avail[carType] < 0 {
    this.avail[carType] = 0
    return false
  }
  return true
}
