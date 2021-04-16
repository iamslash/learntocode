// Copyright (C) 2021 by iamslash

//              i
// s: 2 3 2 2 3 2
// t: 2 3 2 3 2 7
//          j
//      i
// s: 2 3 4 5
// t: 2 1 3 4
//      j
//            i
// s: 2 2 2 2 2
// t: 2 2 2 2 5
//            j

// 0ms 100.00% 38.5MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int badSensor(int[] sensor1, int[] sensor2) {
		int i = 0, j = 0, n = sensor1.length;
		while (i < n && sensor1[i] == sensor2[j]) {
			i++;
			j++;
		}
		if (i+1 >= n) {
			return -1;
		}
		while (i+1 < n && sensor1[i+1] == sensor2[i]) {
			i++;
		}
		if (i+1 >= n) {
			return 2;
		}
		while (j+1 < n && sensor1[j] == sensor2[j+1]) {
			j++;
		}
		if (j+1 >= n) {
			return 1;
		}		
		return -1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
