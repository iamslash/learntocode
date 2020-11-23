# Problem

[Online Stock Span
](https://leetcode.com/problems/online-stock-span/submissions/)

# Idea

`next(int price)` 가 호출되면 하루의 주가가 주어지고 오늘을 포함해서
몇일동안 주가가 작거나 같았는지를 리턴한다.

스택 `stack<pair<int, int>> m_stck` 를 선언하고 주가의 오름차순으로
유지한다. `m_stck.top().second` 는 `m_stck.top().first` 보다 몇일동안
주가가 작거나 같았는지 저장한다. `m_stck` 를 오름차순으로 유지하기
위해 `m_stck.pop()` 할 때 마다 `m_stck.top().second` 를 갱신한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
