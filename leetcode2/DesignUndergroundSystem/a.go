/* Copyright (C) 2020 by iamslash */

package main

// [
//   "UndergroundSystem",
//     "checkIn",
//     "checkIn",
//     "checkIn",
//     "checkOut",
//     "checkOut",
//     "checkOut",
//     "getAverageTime",
//     "getAverageTime",
//     "checkIn",
//     "getAverageTime",
//     "checkOut",
//     "getAverageTime"]
// [
//
//   [],
//   [45,"Leyton",3],
//   [32,"Paradise",8],
//   [27,"Leyton",10],
//   [45,"Waterloo",15],
//   [27,"Waterloo",20],
//   [32,"Cambridge",22],
//   ["Paradise","Cambridge"],
//   ["Leyton","Waterloo"],
//   [10,"Leyton",24],
//   ["Leyton","Waterloo"],
//   [10,"Waterloo",38],
//   ["Leyton","Waterloo"]
// ]
//
// [
//   null,
//   null,
//   null,
//   null,
//   null,
//   null,
//   null,
//   14.00000,
//   11.00000,
//   null,
//   11.00000,
//   null,
//   12.00000
// ]

// 156ms 86.96% 19.7MB 45.45%
// hash map
// CheckIn: O(1)
// CheckOut: O(1)
// GetAverageTime: O(1)
type Stat struct {
	Duration int
	Count    int
}
type CheckIn struct {
	Station string
	Time    int
}
type UndergroundSystem struct {
	statMap    map[string]*Stat // {startStation_endStation, {duration, count}}
	checkinMap map[int]*CheckIn // {userid, {startStation, time}}
}

func Constructor() UndergroundSystem {
	return UndergroundSystem{
		statMap:    make(map[string]*Stat),
		checkinMap: make(map[int]*CheckIn),
	}
}

func (this *UndergroundSystem) CheckIn(id int, station string, t int) {
	this.checkinMap[id] = &CheckIn{
		Station: station,
		Time:    t,
	}
}

func (this *UndergroundSystem) CheckOut(id int, station string, t int) {
	path := this.checkinMap[id].Station + "_" + station
	if _, ok := this.statMap[path]; ok == false {
		this.statMap[path] = &Stat{
			Duration: 0,
			Count:    0,
		}
	}
	this.statMap[path].Duration += t - this.checkinMap[id].Time
	this.statMap[path].Count += 1
}

func (this *UndergroundSystem) GetAverageTime(start string, end string) float64 {
	path := start + "_" + end
	return float64(this.statMap[path].Duration) / float64(this.statMap[path].Count)
}
