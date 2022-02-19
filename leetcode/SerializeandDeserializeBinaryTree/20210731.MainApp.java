// Copyright (C) 2021 by iamslash

import java.util.*;

// 12ms 59.08% 48.3MB 13.10%
// DFS
public class Codec {
	private static final String SEP = ",";
	private static final String NUL = "N";

	// Encodes a tree to a single string.
	public String serialize(TreeNode u) {
		StringBuilder sb = new StringBuilder();
		buildString(u, sb);
		return sb.toString();
	}
	private void buildString(TreeNode u, StringBuilder sb) {
		// base
		if (u == null) {
			sb.append(NUL).append(SEP);
			return;
		}
		// recursion
		sb.append(u.val).append(SEP);
		buildString(u.left, sb);
		buildString(u.right, sb);
	}
	// Decodes your encoded data to tree.
	public TreeNode deserialize(String s) {
		Deque<String> nodes = new LinkedList<>();
		nodes.addAll(Arrays.asList(s.split(SEP)));
		return buildTree(nodes);
	}
	private TreeNode buildTree(Deque<String> nodes) {
		String val = nodes.remove();
		// base
		if (val.equals(NUL)) {
			return null;
		}
		// recursion
		TreeNode u = new TreeNode(Integer.valueOf(val));
		u.left = buildTree(nodes);
		u.right = buildTree(nodes);
		return u;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
