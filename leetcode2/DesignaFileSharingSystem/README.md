# Problem

[Design a File Sharing System](https://leetcode.com/problems/design-a-file-sharing-system/)

userid, chunkid 를 이용하여 파일공유 시스템을 구현하라.

# Idea

다음과 같은 요구사항을 생각해 볼 수 있다.

* userid 를 이용해서 chunkid 를 O(1) 으로 찾을 수 있어야 한다.
* chunkid 를 이용해서 userid 를 O(1) 으로 찾을 수 있어야 한다.
* userid 는 재활용할 수 있어야 한다.

reverse index 를 사용하여 해결할 만 하다. 다음의 자료구조를
정의하고 시작한다.

```cpp
  int userseq;
  unordered_map<int, set<int>> chunk2user;
  unordered_map<int, vector<int>> user2chunk;
  set<int> recycleUserSet;
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
   join: O(N)
  leave: O(N)
request: O(N)
```
