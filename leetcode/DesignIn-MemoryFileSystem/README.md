# Problem

[Design In-Memory File System](https://leetcode.com/problems/design-in-memory-file-system/)

# Idea

다음과 같이 파일시스템을 구성하는 노드를 디자인하는 것으로 시작한다.

```cpp
struct FSNode {
  map<string, FSNode*> children;
  string content;
  bool bDir = true;
  string name;
};
```

다음과 같이 `getOrCreateNode(String path)` 를 잘 구현하면 쉽게 해결할
수 있다.

```
FSNode getOrCreateNode(String path, boolean isDir)

 path: path
isDir: id dir??? when it is true, assign that
```

# Implementation

* [c++11](a.cpp)
* [java8](FileSystem.java)
* [py3](a.py)
