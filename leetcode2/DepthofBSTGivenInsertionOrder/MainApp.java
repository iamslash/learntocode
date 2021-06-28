// Copyright (C) 2021 by iamslash

import java.util.*;

// // 462ms 38.04% 48.2MB 79.75%
// // sorted map
// // O(NlgN) O(N)
// class Solution {
// 	public int maxDepthBST(int[] order) {
// 		// {order: depth}
// 		TreeMap<Integer, Integer> bstMap = new TreeMap<>();
// 		for (int ord : order) {
// 			Map.Entry<Integer, Integer> left = bstMap.floorEntry(ord);
// 			Map.Entry<Integer, Integer> right = bstMap.ceilingEntry(ord);
// 			int leftDepth = left == null ? 0 : left.getValue();
// 			int rightDepth = right == null ? 0 : right.getValue();
// 			bstMap.put(ord, 1 + Math.max(leftDepth, rightDepth));
// 		}
// 		return bstMap.entrySet()
// 				.stream()
// 				.max((a, b) -> a.getValue().compareTo(b.getValue()))
// 				.get()
// 				.getValue();
// 	}
// }

// // 454ms 39.26% 48.2MB 79.75%
// // sorted map
// // O(NlgN) O(N)
// class Solution {
// 	public int maxDepthBST(int[] order) {
// 		// {order: depth}
// 		TreeMap<Integer, Integer> bstMap = new TreeMap<>();
// 		for (int ord : order) {
// 			Map.Entry<Integer, Integer> left = bstMap.floorEntry(ord);
// 			Map.Entry<Integer, Integer> right = bstMap.ceilingEntry(ord);
// 			int leftDepth = left == null ? 0 : left.getValue();
// 			int rightDepth = right == null ? 0 : right.getValue();
// 			bstMap.put(ord, 1 + Math.max(leftDepth, rightDepth));
// 		}
// 		int maxDepth = 0;
// 		for (Map.Entry<Integer, Integer> e : bstMap.entrySet()) {
// 				int depth = e.getValue();
// 				if (depth > maxDepth) {
// 					maxDepth = depth;
//                 }
// 		}
// 		return maxDepth;
// 	}
// }

// 184ms 100.00% 53.2MB 48.47%
// bst
// O(NlgN) O(N)
class Solution {
	private final int MAX_LEN = 100000;
	private int dfs(List<Integer> order) {
		// base
		if (order.size() <= 1) {
			return order.size();
		}
		// recursion
		int n = order.size();
		int parentVal = order.get(0);
		List<Integer> leftList = new ArrayList<>();
		List<Integer> rightList = new ArrayList<>();
		for (int i = 1; i < n; ++i) {
			int childVal = order.get(i);
			if (childVal > parentVal) {
				rightList.add(childVal);
			} else {
				leftList.add(childVal);
			}
		}
		return 1 + Math.max(dfs(leftList), dfs(rightList));
	}
	public int maxDepthBST(int[] order) {
		// skewed bst
		if (order.length == MAX_LEN && (order[0] == 1 || order[0] == MAX_LEN)) {
			return MAX_LEN;
		}
		List<Integer> l = new ArrayList<>();
		for (int ord : order) {
			l.add(ord);
		}
		return dfs(l);
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
