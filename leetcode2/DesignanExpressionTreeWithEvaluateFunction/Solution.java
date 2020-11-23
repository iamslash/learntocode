// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 100.00% 36.7MB 68.33%
// stack
// O(N) O(N)
abstract class Node {
	public abstract int evaluate();
};
class TreeNode extends Node {
	private Node left;
	private Node right;
	private char op = 0;
	private int num = 0;
	public TreeNode(int num, Node left, Node right) {
		this.num = num;
		this.left = left;
		this.right = right;
	}
	public TreeNode(char op, Node left, Node right) {
		this.op = op;
		this.left = left;
		this.right = right;
	}
	public int evaluate() {
		// base
		if (left == null && right == null) {
			return num;
		}
		// recursion
		int a = left.evaluate();
		int b = right.evaluate();
		if (op == '+') {
			return a + b;
		} else if (op == '-') {
			return a - b;
		} else if (op == '*') {
			return a * b;
		}
		return a / b;
	}
}
class TreeBuilder {
	Node buildTree(String[] s) {
		Deque<Node> deq = new ArrayDeque<>();
		for (int i = 0; i < s.length; ++i) {
			if (s[i].equals("+") || s[i].equals("-") || 
          s[i].equals("*") || s[i].equals("/")) {
				Node v = deq.pop();
				Node u = deq.pop();
				deq.push(new TreeNode(s[i].charAt(0), u, v));
			} else {
				deq.push(new TreeNode(Integer.parseInt(s[i]), null, null));
			}
		}
		return deq.pop();
	}
};
