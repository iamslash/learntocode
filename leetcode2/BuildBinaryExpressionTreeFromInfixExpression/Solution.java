// Copyright (C) 2020 by iamslash

import java.util.*;

// 16ms 46.81% 44.4MB 78.72%
class Solution {
	private boolean needCollapse(Deque<Character> opDeq, char c) {
		if (opDeq.isEmpty())
			return false;
		if (opDeq.peek() == '(')
			return false;
		if ((opDeq.peek() == '+' || opDeq.peek() == '-') &&
				(c == '*' || c == '/'))
			return false;
		return true;
	}
	private void doCollapse(Deque<Node> nodeDeq, Deque<Character> opDeq) {
		Node a = nodeDeq.pop();
		Node b = nodeDeq.pop();
		Node c = new Node(opDeq.pop());
		c.left = b;
		c.right = a;
		nodeDeq.push(c);
	}
	private void collapse(Deque<Node> nodeDeq,
												Deque<Character> opDeq, char c) {
		while (needCollapse(opDeq, c)) {
			doCollapse(nodeDeq, opDeq);
		}
		opDeq.push(c);
	}
	private void collapseUntilLeftParen(Deque<Node> nodeDeq,
																			Deque<Character> opDeq) {
		while (opDeq.peek() != '(') {
			doCollapse(nodeDeq, opDeq);
		}
		opDeq.pop();
	}
	private void collapseAll(Deque<Node> nodeDeq, Deque<Character> opDeq) {
		while (nodeDeq.size() > 1) {
			doCollapse(nodeDeq, opDeq);
		}
	}
	public Node expTree(String s) {
		Deque<Node> nodeDeq = new ArrayDeque<>();
		Deque<Character> opDeq = new ArrayDeque<>();
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (Character.isDigit(c)) {
				nodeDeq.push(new Node(c));
			} else if (c == '(') {
				opDeq.push(c);
			} else if (c == ')') {
				collapseUntilLeftParen(nodeDeq, opDeq);
			} else {
				collapse(nodeDeq, opDeq, c);
			}
		}
		collapseAll(nodeDeq, opDeq);
		return nodeDeq.pop();
	}
}
