// Copyright (C) 2021 by iamslash

import java.util.*;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode() {}
	TreeNode(int val) { this.val = val; }
	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

//          5
//       /     \
//      2       7
//    /   \    / \
//   1     4  6   8
//        / 
//       3
// 
// stck: 5 4 3

// 27ms 6.26% 48.9MB 5.43%
// stack
//    next: O(1) O(N)
// hasNext: O(1) O(N)
class BSTIterator {
	private Stack<TreeNode> stck = new Stack<>();

	public BSTIterator(TreeNode root) {
		pushSmallOnes(root);
	}
    
	public int next() {
		TreeNode t = stck.pop();
		pushSmallOnes(t.right);
		return t.val;
	}
    
	public boolean hasNext() {
		return stck.size() > 0 ? true : false;
	}

	private void pushSmallOnes(TreeNode u) {
		while (u != null) {
			stck.push(u);
			u = u.left;
		}
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
