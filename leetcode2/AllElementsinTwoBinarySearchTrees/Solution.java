// Copyright (C) 2020 by iamslash

import java.util.Deque;
import java.util.ArrayDeque;
import java.util.List;
import java.util.ArrayList;

public class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) { val = x; }
}

// 15ms 48.66% 42.8MB 100.00%
// stack
// O(N) O(N)
class Solution {
	private void pushLeft(Deque<TreeNode> deque, TreeNode u) {
		while (u != null) {
			deque.offerFirst(u);
			u = u.left;
		}
	}
	public List<Integer> getAllElements(TreeNode u, TreeNode v) {
		Deque<TreeNode> uDeque = new ArrayDeque<>();
		Deque<TreeNode> vDeque = new ArrayDeque<>();
		pushLeft(uDeque, u);
		pushLeft(vDeque, v);
		List<Integer> ans = new ArrayList<>();
		while (uDeque.size() > 0 ||
					 vDeque.size() > 0) {
			Deque<TreeNode> deque = null;
			if (vDeque.size() == 0 ||
					(uDeque.size() > 0 &&
					 (uDeque.peek().val < vDeque.peek().val))) {
				deque = uDeque;
			} else {
				deque = vDeque;
			}				
			TreeNode t = deque.pollFirst();
			ans.add(t.val);
			pushLeft(deque, t.right);
		}
		return ans;
	}
}
