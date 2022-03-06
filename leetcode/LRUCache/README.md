# Problem

[LRU Cache](https://leetcode.com/problems/lru-cache/)

LRUCache 를 디자인 하고 다음을 구현하는 문제이다.

```cpp
int get(int key)
void put(int key, int val)
```

# Idea

[LRUCache](/leetcode/LRUCache/README.md) 는 가장 오래전에 사용된
녀석들을 퇴출하는 Cache Strategy
이다. [LFUCache](/leetcode2/LFUCache/README.md) 는 가장 덜 사용된
녀석들을 evict 하는 Cache Strategy 이다.

`key, val` 을 저장해야 한다. `key` 를 언제 사용했는지도 저장해야
한다. 다음과 같은 자료구조를 선언한다.

```cpp
int cap;
unordered_map<int, pair<int, list<int>::iterator>> valueMap;
list<int> historyList;
```

```java
int cap;
Map<Integer, Integer> valueMap = new HashMap<>(); // {key: val}
Set<Integer> historySet = new LinkedHashSet<>();  // {key, ...}
```

get 은 다음을 순서대로 구현한다.

* cache miss (없으면 -1 을 리턴한다.)
* cache hit (있으면 historyList 끝에 부착하고 값을 리턴한다.)

put 은 다음을 순서대로 구현한다.

* `cap <= 0` 이면 리턴한다.
* cache hit (있으면 historyList 의 끝에 부착하고 값을 저장한다.)
* cache miss
  * evict (꽉 찼으면 historyList 의 처음을 하나 지운다.)
  * save (새로운 값을 저장한다. historyList 끝에 부착한다.)
  
`java8` 의 경우 `LinkedHashSet` 대신 `ListNode, DoubleyLinkedList` 를
이용해도 좋다. 그러나 구현시간이 많이 걸린다.

또한 `java8` 의 경우 `LinkedHashSet` 대신 `LinkedHashMap` 을 이용해도
좋다. `LFUCache` 가 `LinkedHashMap` 을 상속한다. 그리고 `protected
boolean removeEldestEntry(Map.Entry eldest)` 를 override 한다. 그러나
구현은 짧지만 구현목적에 맞지 않다.
    
# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
