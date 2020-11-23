# Problem

[Design File System](https://leetcode.com/problems/design-file-system/)

# Idea

파일 시스템을 디자인하기 위해 다음과 같은 함수들을 구현하는 문제이다.

```
bool createPath(string path, int val)
int get(string path)
```

트리를 이용하여 구현하는 것보다는 `unordered_map<string, int> m_data`
를 선언하여 구현하자. 보다 간결한 코드를 만들 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
createPath: O(1)
       get: O(1)
```
