# Abstract

- 소박한 문자열 검색 방법에 대해 적는다.

# Problem

문자열 `H` 에서 문자열 `N` 을 검색하는 문제이다.

# Idea

Brute Force 전략을 이용한다. 인덱스 `i,j` 를 이용하여 `H, N` 을 
순회하면서 검색한다. `N` 이 검색될 때 마다 `i` 를 일차원 벡터 `r` 에 추가한다. `r` 이 답이다.

```cpp
for (int i = 0; i + N.size() <= H.size(); ++i) {
  bool b = true;
  for (int j = 0; j < N.size(); ++j) {
    if (H[i+j] != N[j]) {
      b = false;
      brek;
    }
  }
  if (b)
    r.push_back(i);
}
```

# Complexity

```
O(N^2) O(1)
```

# Implementation

[c++11](a.cpp)