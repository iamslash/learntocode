# Problem

[LFU Cache](https://leetcode.com/problems/lfu-cache/)

LFUCache 를 디자인 하고 다음을 구현하는 문제이다.

```java
int get(int key)
void put(int key, int val)
```

# Idea

[LRUCache](/leetcode/LRUCache/README.md) 는 가장 오래전에 사용된
녀석들을 퇴출하는 Cache Strategy
이다. [LFUCache](/leetcode2/LFUCache/README.md) 는 가장 덜 사용된
녀석들을 evict 하는 Cache Strategy 이다.

`key, val` 를 저장해야 한다. 얼마나 자주 사용했는지와 그 만큼 사용한
`key` 들을 저장할 필요가 있다. 그리고 `int minFreq = -1` 를 선언하여
가장 덜 사용한 횟수도 저장해야 한다. 가장 덜 사용한 `key` 들이 evict
의 대상이다. 다음과 같은 자료구조를 선언한다.

```java
Map<Integer, Integer> valMap;  // {key, val}
Map<Integer, Integer> freqMap; // {key, freq}
Map<Integer, LinkedHashSet<Integer>> freq2keysMap; // {freq, {key, ...}}
int cap;           // capacity
int minFreq = -1;  // minimum frequency to evict
```

get 은 다음을 순서대로 구현한다.

* miss (없으면 -1 을 리턴한다.)
* hit (있으면 freq 를 늘리고 값을 리턴한다.)

put 은 다음을 순서대로 구현한다.

* `cap <= 0` 이면 리턴한다.
* hit (있으면 freq 를 늘리고 값을 저장한다.)
* miss
  * evict (꽉 찼으면 하나 지운다.)
  * save (새로운 값을 저장한다.)

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
