// Copyright (C) 2020 by iamslash

import java.util.*;

// 16ms 5.21% 39.9MB 5.00%
// stack
// O(N) O(N)
class Item {
	int i;
	String s;
	public Item(int i, String s) {
		this.i = i;
		this.s = s;
	}
}
class Solution {
	public String decodeString(String s) {
		Stack<Item> stck = new Stack<>();
		stck.push(new Item(0, ""));
		String k = "";
		for (int i = 0; i < s.length(); ++i) {
			if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
				k += s.charAt(i);
			} else if (s.charAt(i) == '[') {
				stck.push(new Item(Integer.parseInt(k), ""));
				k = "";
			} else if (s.charAt(i) == ']') {
				Item u = stck.pop();
				for (int j = 0; j < u.i; ++j) {
					stck.peek().s += u.s; 
				}
			} else {
				stck.peek().s += s.charAt(i);
			}
		}
		return stck.peek().s;
	}
}
