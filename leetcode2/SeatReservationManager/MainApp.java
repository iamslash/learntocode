// Copyright (C) 2021 by iamslash

import java.util.*;

// 1 2 3 4 5
// 

// 85ms 70.83% 82.3MB 84.35%
// priority queue
// SeatManager: O(NlgN)
//     reserve: O(1)
//   unreserve: O(lgN)
class SeatManager {

	private Queue<Integer> pq = new PriorityQueue<>();

	public SeatManager(int n) {
		for (int i = 1; i <= n; ++i) {
			pq.offer(i);
		}
	}
    
	public int reserve() {
		return pq.poll();
	}
    
	public void unreserve(int seatNumber) {
		pq.offer(seatNumber);
	}
}

public class MainApp {
  public static void main(String[] args) {

		SeatManager sm = 
  }
}
