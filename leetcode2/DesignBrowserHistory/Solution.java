// Copyright (C) 2020 by iamslash

import java.util.*;

// 49ms 44.56% 47MB 78.14%
// linked list
//   visit: O(1) O(N)
//    back: O(1) O(N)
// forward: O(1) O(N)
class BrowserHistory {
	private List<String> history = new LinkedList<>();
	int pos = 0;
	public BrowserHistory(String homepage) {
		history.add(homepage);
		pos = 0;
	}
    
	public void visit(String url) {
		history.subList(pos+1, history.size()).clear();
		history.add(url);
		pos++;
	}
    
	public String back(int steps) {
		pos = Math.max(0, pos-steps);
		return history.get(pos);
	}
    
	public String forward(int steps) {
		pos = Math.min(history.size()-1, pos+steps);
		return history.get(pos);
	}
}
