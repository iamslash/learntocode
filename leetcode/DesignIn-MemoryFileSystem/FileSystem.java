// Copyright (C) 2022 by iamslash

import java.util.*;

// 53ms 76.81% 54.2MB 72.64%
// design
class FSNode {
    public boolean isFile = false;
    public String path = "";
    public String content = "";
    public Map<String, FSNode> childMap = new HashMap<>();
}
class FileSystem {

    private FSNode root = new FSNode();

    private FSNode getOrCreateNode(String path, boolean isFile) {
        FSNode u = root;
        String[] pathArr = path.substring(1).split("/");
        for (String token : pathArr) {
            if (!token.isEmpty()) {
                u.childMap.putIfAbsent(token, new FSNode());
                u = u.childMap.get(token);
                u.path = token;
            } 
        }
        if (isFile) {
            u.isFile = true;
        }
        return u;
    }
    
    public List<String> ls(String path) {
        FSNode u = getOrCreateNode(path, false);
        if (u.isFile == true) {
            return new ArrayList<String>(Arrays.asList(u.path));
        }
        List<String> ans = new ArrayList<>();
        for (String key : u.childMap.keySet()) {
            ans.add(key);
        }
        Collections.sort(ans);
        return ans;
    }
    
    public void mkdir(String path) {
        getOrCreateNode(path, false);
    }
    
    public void addContentToFile(String filePath, String content) {
        FSNode u = getOrCreateNode(filePath, true);
        u.content += content;
    }
    
    public String readContentFromFile(String filePath) {
        FSNode u = getOrCreateNode(filePath, true);
        return u.content;
    }
}
