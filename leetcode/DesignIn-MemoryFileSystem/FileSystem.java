// Copyright (C) 2020 by iamslash

import java.util.*;

// hash map, inode
class FSNode {
	Map<String, FSNode> pathMap = new HashMap<>();
	String content = "";
	boolean bDir = true;
	String name = "";
}

class FileSystem {
	private FSNode root;

	private FSNode getNode(String filePath, boolean bDir) {
		FSNode u = root;
		String[] pathArray = filePath.substring(1).split("/");
    // System.out.println(Arrays.toString(pathArray));
		for (String token : pathArray) {
      if (token.isEmpty())
        continue;
			u.pathMap.putIfAbsent(token, new FSNode());
			u = u.pathMap.get(token);
			u.name = token;
		}
		if (bDir == false)
			u.bDir = false;
		return u;
	}

	public FileSystem() {
		root = new FSNode();
		// root.pathMap.put("", new FSNode());
	}
    
	public List<String> ls(String path) {
		FSNode u = getNode(path, true);
		if (u.bDir == false) {
			return new ArrayList<String>(Arrays.asList(u.name));
		}
		List<String> r = new ArrayList<>();
		for (String k : u.pathMap.keySet())
			r.add(k);
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

	public static void main(String[] args) {
		FileSystem fs = new FileSystem();
		System.out.println(fs.ls("/"));
		fs.mkdir("/a/b/c");
		fs.addContentToFile("/a/b/c/d", "hello");
		System.out.println(fs.ls("/"));
		System.out.println(fs.readContentFromFile("/a/b/c/d"));
		System.out.println(fs.ls("/a/b/c/d"));
	}
}
