# Problem

수열 `V[]` 와 범위 `qvleft, qvright` 가 주어진다. `V[qvleft..qvright]` 에서 가장 작은 두수를 구하는 문제이다.

# Idea

다음과 같이 RangeItem 을 정의하여 가장 작은 두수를 표현하자.

```cpp
// range freqeucy query
struct RangeItem {
  int no1;
  int no2;
  RangeItem() {
    no1  = -1;
    no2  = -1;
  }
  explicit RangeItem(int _no1, int _no2) {
    no1  = _no1;
    no2  = _no2;
  }
};
```

[RMQ](/fundamentals/tree/rmq/README.md) 에서 `min` 대신 다음과 같은 `merge` 를 사용하여 구현한다. 

```cpp
RangeItem merge(const RangeItem& a, const RangeItem& b) {
  RangeItem r;
  if (a.no1 < b.no1) {
    r.no1 = a.no1;
    r.no2 = std::min(a.no2, b.no1);
  } else {
    r.no1 = b.no1;
    r.no2 = std::min(a.no1, b.no2);
  }
  return r;
}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
build segment tree: O(N)   O(N)
             query: O(lgN) O(1)
```