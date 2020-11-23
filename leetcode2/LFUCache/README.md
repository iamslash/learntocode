# Problem

[LFU Cache](https://leetcode.com/problems/lfu-cache/)

`LFU Cache` 의 `int get(int key), void put(int key, int val)` 을
`O(1)` 의 시간복잡도로 구현하라.

# Idea

[LRUCache](/leetcode/LRUCache/README.md) 는 가장 오래전에 사용된 녀석들을
퇴출하는 Cache Strategy 이다. LFUCache 는 가장 덜 사용된 녀석들을 evict 하는
Cache Strategy 이다.

다음과 같은 자료구조를 선언한다.

```
int     cap : capacity of LFUCache
int    size : size of LFUCache
int minFreq : minimum freq of LFUCache
unordered_map<int, pair<int, int>> key2valFreq: {key: {val, freq}}
unordered_map<int, list<int>::iterator> key2iter: {key: iterator}
unordered_map<int, pair<int, int>> freq2keys: {freq: [key,...]}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
