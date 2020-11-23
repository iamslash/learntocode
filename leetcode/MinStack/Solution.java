// Copyright (C) 2020 by iamslash

import java.util.*;

// 12ms 15.28% 45.5MB 14.22%
// stack
// push: O(1)
// pop: O(1)
// pop: O(1)
// getMin: O(1)
class MinStack {
	private int min = Integer.MAX_VALUE;
	Stack<Integer> stack = new Stack<Integer>();
	
	public void push(int x) {
		if (x <= min) {
			stack.push(min);
			min = x;
		}
		stack.push(x);
	}
    
	public void pop() {
		if (stack.pop() == min)
			min = stack.pop();
	}
    
	public int top() {
    return stack.peek();
	}
    
	public int getMin() {
		return min;
	}
}

