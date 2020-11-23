# Problem

[Insert Interval](https://leetcode.com/problems/insert-interval/)

# Idea

Interval 의 모음 `I` 와 Interval `J` 가 주어진다.
`I` 의 Interval 들은 서로 겹치지 않는다. `J` 가
`I` 에 삽입될때 merge 가 된 `I` 를 구하는 문제이다.

첫번째 방법은 brute force 방법이다. 

* `I[i].end < J.start` 동안 `rslt.push_back(I[i])` 를 한다.
* `I[i].start <= J.end` 동안 `J` 를 갱신한다.
* `J.end < I[i].start` 동안 `rslt.push_back(I[i]` 한다.

복잡도는 `O(N), O(N)` 이다. 이것을 조금더 최적화 해보자.

두번째 방법은 binary search 방법이다.

`equal_range` 를 이용하면 `J` 의 lower bound `i` 와 uppper bound `j`
를 손쉽게 구할 수 있다.

* `i == j` 이면 `J` 와 겹치는 `I[i]` 가 없다는 의미이다. `I.insert(i,
  J)` 를 수행한다.
* `i != j` 이면 `J` 와 겹치는 `I[i]` 가 있다는 의미이다. `J.end <
  j->start` 이므로 `j = prev(j)` 를 수행한다. 그리고 `j->start,
  j->end` 를 merge 를 위해 갱신한다.  이제 `I.erase(i, j)` 하면 겹치는
  부분을 제거할 수 있다. `I.erase(i, j)` 에서 `*j` 는 지워지지 않는다.
  
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
