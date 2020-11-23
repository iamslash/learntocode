/* Copyright (C) 2020 by iamslash */

package main

// lo: 0, hi: 4, ha: 2
// lo: 0, hi: 5, ha: 2

// // 200ms 90.00% 17.3MB 90.00%
// // binary search
// func getIndex(reader *ArrayReader) int {
// 	lo, ha, hi := 0, 0, reader.length()-1
// 	for lo < hi {
// 		// ha * 2 <= hi - lo + 1
// 		ha = (hi - lo + 1) / 2
// 		if reader.compareSub(lo, lo+ha-1, lo+ha, lo+ha*2-1) <= 0 {
// 			lo = lo + ha
// 		} else {
// 			hi = lo + ha - 1
// 		}
// 	}
// 	return lo
// }

// // 408ms 10.00% 17.6MB 50.00%
// // binary search
// func getIndex(reader *ArrayReader) int {
// 	lo, mi, hi := 0, 0, reader.length()-1
// 	for lo < hi {
// 		mi = (hi + lo - 1) / 2
// 		en := hi
// 		if (hi-lo+1)%2 == 1 {
// 			en--
// 		}
// 		// fmt.Printf("en: %d, lo: %d, mi: %d, hi: %d\n", en, lo, mi, hi)
// 		r := reader.compareSub(lo, mi, mi+1, en)
// 		// fmt.Printf("r: %d\n", r)
// 		if r == 0 {
// 			return hi
// 		} else if r < 0 {
// 			lo = mi + 1
// 		} else {
// 			hi = mi
// 		}
// 	}
// 	return lo
// }

// l
// 5 5 5 7 5
//         h
//     m

// 272ms 50.00% 18.5MB 30.00%
// binary search
// O(lgN) O(1)
func getIndex(reader *ArrayReader) int {
	lo, hi := 0, reader.length()-1
	for lo < hi {
		mi := (lo + hi) / 2
		r := 0
		if (hi-lo+1)%2 == 0 {
			r = reader.compareSub(lo, mi, mi+1, hi)
		} else {
			r = reader.compareSub(lo, mi, mi, hi)
		}
		if r == -1 {
			lo = mi + 1
		} else {
			hi = mi
		}
	}
	return lo
}
