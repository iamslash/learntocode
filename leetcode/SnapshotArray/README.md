# Problem

[Snapshot Array](https://leetcode.com/problems/snapshot-array/)

# Idea

SnapshotArray 를 완성하기 위해 다음과 같은 함수들을 구현하는 문제이다.

```cpp
class SnapshotArray {
 public:
  SnapshotArray(int length) {
  }  
  void set(int index, int val) {
  }
  int snap() {
  }
  int get(int index, int snap_id) {
  }
};
```

`int m_shotid = 0` 를 선언하여 `snap()` 이 호출될 때 마다
하나씩 증가한다.

`unordered_map<int, map<int, int>> m_shot` 를 선언하여 `{dataid,
{snapid : value}}` 를 저장한다.

`get(dataid, snapid)` 에서 `m_shot[dataid]` 를 이용해 `{snapid:
value}` 의 맵 `snapid2value` 을 얻어올 수
있다. 그리고 `auto it = snapid2value.upper_bound(snapid)` 를 수행하면
`prev(it)->second` 가 곧 답이다. 

# Implementation

* [c++11](a.cpp)

# Complexity

```
get: O(lgN)
```
