# Problem

정렬된 수열 `V[]` 와 구간 `qvleft, qvright` 가 주어진다. `V[qvleft..qvright]` 에서 가장 빈도수가 높은 수를 구하는 문제이다.

# Idea

다음과 같이 RangeItem 을 정의하여 가장 빈도수가 높은 수를 표현하자.

```cpp
// range freqeucy query
struct RangeItem {
  int size;       // size of range
  int mostfreq;   // frequency of the most frequent number
  int leftnum;    // left most number
  int leftfreq;   // frequency of the left most number
  int rightnum;   // right most number
  int rightfreq;  // frequency of the right most number
  RangeItem() {
    Set(0, 0, 0, 0, 0, 0);
  }
  explicit RangeItem(int _size, int _mostfreq, int _leftnum,
                     int _leftfreq, int _rightnum, int _rightfreq) {
    Set(_size, _mostfreq, _leftnum,
        _leftfreq, _rightnum, _rightfreq);
  }
  void Set(int _size, int _mostfreq, int _leftnum,
                     int _leftfreq, int _rightnum, int _rightfreq) {
    size      = _size;
    mostfreq  = _mostfreq;
    leftnum   = _leftnum;
    leftfreq  = _leftfreq;
    rightnum  = _rightnum;
    rightfreq = _rightfreq;
  }
  void Dump() {
    printf("size: %d, modstfreq: %d, leftnum: %d, leftfreq: %d, rightnum: %d, rightfreq: %d\n",
           size, mostfreq, leftnum, leftfreq, rightnum, rightfreq);
  }
};
```

[RMQ](/fundamentals/tree/rmq/README.md) 에서 `min` 대신 다음과 같은 `merge` 를 사용하여 구현한다. 

```cpp
RangeItem merge(const RangeItem& a, const RangeItem& b) {
  RangeItem r;
  r.size = a.size + b.size;
  // handle left numbers
  r.leftnum = a.leftnum;
  r.leftfreq = a.leftfreq;
  // ex. [1, 1, 1, 1] [1, 2, 2, 2]
  // ex. [2] [2]
  if (a.size == a.leftfreq && a.leftnum == b.leftnum)
    r.leftfreq += b.leftfreq;
  // handle right numbers
  r.rightnum = b.rightnum;
  r.rightfreq = b.rightfreq;
  // ex. [1, 1, 1, 2] [2, 2, 2, 2]
  // ex. [2] [2]
  if (b.size == b.rightfreq && a.rightnum == b.rightnum)
    r.rightfreq += a.rightfreq;
  // handle mostfreq
  r.mostfreq = std::max(a.mostfreq, b.mostfreq);
  // ex. [1, 2, 2, 2] [2, 3, 3, 3]
  // ex. [2] [2]
  if (a.rightnum == b.leftnum)
    r.mostfreq = std::max(r.mostfreq, a.rightfreq + b.leftfreq);
  return r;
}
```

# Implementation

[c++11](a.cpp)

# Complexity

```
build segment tree: O(N)   O(lgN)
             query: O(lgN) O(1)
```