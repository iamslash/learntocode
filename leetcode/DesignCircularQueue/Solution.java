// Copyright (C) 2020 by iamslash

// 8ms 22.10% 45.8MB 5.26%
// array
class MyCircularQueue {
	private final int[] data;
	int head;
	int tail;
	int size;
	public MyCircularQueue(int k) {
		tail = -1;
		size = 0;
		data = new int[k];
	}
	public boolean enQueue(int val) {
		if (isFull()) {
			return false;
		}
		tail = (tail + 1) % data.length;
		data[tail] = val;
		size++;
		return true;
	}
	public boolean deQueue() {
		if (isEmpty())
			return false;
		head = (head + 1) % data.length;
		size--;
		return true;
	}
	public int Front() {
		if (isEmpty())
			return -1;
		return data[head];
	}    
	public int Rear() {
		if (isEmpty())
			return -1;
		return data[tail];
	}
	public boolean isEmpty() {
		return size == 0;
	}
	public boolean isFull() {
    return size == data.length;
	}
}
