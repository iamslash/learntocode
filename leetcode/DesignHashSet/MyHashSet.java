// Copyright (C) 2020 by iamslash

import java.util.*;

// 23ms 40.64% 53.7MB 20.65%
// sperate chaining
class Bucket {
	private LinkedList<Integer> data;
	public Bucket() {
		data = new LinkedList<Integer>();
	}
	public void insert(Integer key) {
		int i = this.data.indexOf(key);
		if (i == -1)
			this.data.addFirst(key);
	}
	public void delete(Integer key) {
		this.data.remove(key);
	}
	public boolean exists(Integer key) {
		return this.data.indexOf(key) != -1;
	}
}
class MyHashSet {
	private Bucket[] data;
	private final int capacity;
	public MyHashSet() {
		this.capacity = 769;
		this.data = new Bucket[this.capacity];
		for (int i = 0; i < this.capacity; ++i)
			this.data[i] = new Bucket();
	}
	protected int _hash(int key) {
		return key % this.capacity;
	}
	public void add(int key) {
		int i = this._hash(key);
		this.data[i].insert(key);
	}
	public void remove(int key) {
		int i = this._hash(key);
		this.data[i].delete(key);
	}
	public boolean contains(int key) {
		int i = this._hash(key);
		return this.data[i].exists(key);
	}
}
