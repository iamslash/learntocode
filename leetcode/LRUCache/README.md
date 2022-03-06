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

다음과 같은 자료구조를 선언한다.

```cpp
int capacity;
unordered_map<int, pair<int, list<int>::iterator>> valueMap;
list<int> historyList;
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

`c++11` 의 경우 `valueMap` 의 값이 `historyList` 의 원소를 가리킬 수
있다. 

그러나 `java8` 의 경우 `LinkedList<Integer> historyList` 를
선언한 경우 `valueMap` 의 값이 `historyList` 의 원소를 가리킬 수
없다. 따라서 `ListNode, DoublyLinkedList` 를 구현해 주어야 한다. 

```java
class ListNode;
class DoubleyLinkedList;
Map<Integer, ListNode> valueMap = new HashMap<>();
DoublyLinkedList historyList = new DoublyLinkedList();
```
    
# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
