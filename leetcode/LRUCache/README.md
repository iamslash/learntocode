# Problem

[LRU Cache](https://leetcode.com/problems/lru-cache/)

LRUCache 를 디자인 하고 다음을 구현하는 문제이다.

# Idea

```cpp
int get(int key)
void put(int key, int val)
```

LRUCache 가 가득차 있다면 가장 오래된 녀석을 지워야 한다.  언제
사용되었는지를 저장할 자료구조가 필요하다.  `list<int> m_H` 를
선언하고 가장 최근에 사용된 `key` 를 `m_H` 에 추가한다. 만약 예전에
`key` 가 사용되어 `m_H` 에 있다면 제거하고 추가한다. `m_H` 에 `key` 를
추가하고 `iterator` 를 저장해 놓으면 `O(1)` 의 시간으로 `key` 를 찾을
수 있다.

다음으로 `unordered_map<int, pair<int, list<int>::iterator>> m_C`
를 선언하고 `{key, {value, iterator of m_H}}` 를 저장한다.

이제 `get, put` 을 구현해 보자. 먼저 `put` 을 살펴보자.

`put` 은 `key` 와 `value` 를 `m_C` 에 삽입해야 한다. 이때 `LRUCache`
가 가득차 있으면 가장 오래된 `oldkey` 를 제거해야 한다.  가장 오래된
`oldkey` 는 `m_H.front()` 를 이용하여 얻어낼 수 있다.  그리고
`m_H.pop_front()` 하여 `m_H` 에서 제거한다. 그다음 `m_C.erase(oldkey)`
하여 `m_C` 에서 제거한다.

`get` 은 `key` 에 해당하는 `value` 를 리턴한다. 없다면 `-1` 을
리턴하자. 있다면 `key` 는 가장 최근에 사용된 녀석이
된다. `m_C[key].second` 는 `m_H` 의 `key` 위치를 가리키고
있다. `m_H.erase(m_C[key].second)` 하여 제거하자. 그리고
`m_H.push_back(key)` 하자. 이제 `m_C[key]` 를 `{val, prev(m_H.end())}`
로 갱신하자.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
get: O(1) O(N)
put: O(1) O(N)
```
