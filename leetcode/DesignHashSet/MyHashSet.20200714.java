// Copyright (C) 2019 by iamslash

// 10ms 99.64% 50.2MB 88.89%
// array
// O(1) O(N)
class MyHashSet {
	private boolean[] data;

	public MyHashSet() {
		this.data = new boolean[1000000];
	}
    
	public void add(int key) {
		this.data[key] = true;
	}
    
	public void remove(int key) {
		this.data[key] = false;
	}
    
	public boolean contains(int key) {
		return this.data[key];
	}
}
