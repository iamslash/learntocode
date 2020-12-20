# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

# 52ms 87.74% 14.6MB 48.68%
from collections import defaultdict
class FSNode:
    def __init__(self):
        self.path_map = defaultdict(FSNode)
        self.content = ""
class FileSystem(object):
    def __init__(self):
        self.root = FSNode()    
    def find(self, path):
        # "/a/b/c/d"
        cur = self.root
        if len(path) == 1:
            return self.root
        for word in path.split("/")[1:]:
            cur = cur.path_map[word]        
        return cur;
    def ls(self, path):
        cur = self.find(path)
        if cur.content:
            return [path.split('/')[-1]]
        return sorted(cur.path_map.keys())
    def mkdir(self, path):
        self.find(path)
    def addContentToFile(self, path, content):
        cur = self.find(path)
        cur.content += content
    def readContentFromFile(self, path):
        cur = self.find(path)
        return cur.content

if __name__ == "__main__":
    main()
