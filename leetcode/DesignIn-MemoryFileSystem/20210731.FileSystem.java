// Copyright (C) 2020 by iamslash

import java.util.*;

// 40ms 57.14% 40MB 74.51%
class FSNode {
	Map<String, FSNode> pathMap = new HashMap<>();
	String content = "";
	boolean bDir = true;
	String name = "";
}
class FileSystem {
	private FSNode root;

	public FileSystem() {
		root = new FSNode();
	}

	// "/a/b/c/d"
	// a b c d
  private FSNode getNode(String filePath, boolean bDir) {
		FSNode u = root;
		String[] pathArr = filePath.substring(1).split("/");
		for (String token : pathArr) {
			if (token.isEmpty()) {
				continue;
			}
			u.pathMap.putIfAbsent(token, new FSNode());
			u = u.pathMap.get(token);
			u.name = token;
		}
		if (bDir == false) {
			u.bDir = false;
		}
		return u;
	}
    
	public List<String> ls(String path) {
		FSNode u = getNode(path, true);
		if (u.bDir == false) {
			return new ArrayList<String>(Arrays.asList(u.name));
		}
		List<String> r = new ArrayList<>(u.pathMap.keySet());
		Collections.sort(r);
		return r;				
	}
    
	public void mkdir(String path) {
		getNode(path, true);
	}
    
	public void addContentToFile(String filePath, String content) {
		FSNode u = getNode(filePath, false);
		u.content += content;
	}
    
	public String readContentFromFile(String filePath) {
		FSNode u = getNode(filePath, false);
		return u.content;
	}
}
