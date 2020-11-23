// Copyright (C) 2019 by iamslash
import java.util.Arrays;

// 29ms 31.56% 53.1MB 51.35%
// array
// O(1) O(N)
class MyHashMap {
	private int[] data;

	public MyHashMap() {
		data = new int[1000000];
		Arrays.fill(data, -1);
	}
    
	public void put(int key, int val) {
		data[key] = val;
	}
    
	public int get(int key) {
		return data[key];
	}
    
	public void remove(int key) {
		data[key] = -1;
	}
}
