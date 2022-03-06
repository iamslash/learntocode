# Problem

[LFU Cache](https://leetcode.com/problems/lfu-cache/)

`LFU Cache` 의 `int get(int key), void put(int key, int val)` 을
`O(1)` 의 시간복잡도로 구현하라.

# Idea

[LRUCache](/leetcode/LRUCache/README.md) 는 가장 오래전에 사용된 녀석들을
퇴출하는 Cache Strategy 이다. LFUCache 는 가장 덜 사용된 녀석들을 evict 하는
Cache Strategy 이다.

다음과 같은 자료구조를 선언한다.

```java
Map<Integer, Integer> valMap;  // {key, val}
Map<Integer, Integer> freqMap; // {key, freq}
Map<Integer, LinkedHashSet<Integer>> freq2keysMap; // {freq, {key, ...}}
int cap;
int minFreq = -1;
```

get 은 다음을 순서대로 구현한다.

* cache miss (없으면 -1 을 리턴한다.)
* cache hit (있으면 freq 를 늘리고 값을 리턴한다.)

put 은 다음을 순서대로 구현한다.

* `cap <= 0` 이면 리턴한다.
* cache hit (있으면 freq 를 늘리고 값을 저장한다.)
* evit (꽉 찼으면 하나 지운다.)
* save (새로운 값을 저장한다.)

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
