# Problem

[Camelcase Matching](https://leetcode.com/problems/camelcase-matching/)

# Idea

쿼리들의 모음 `Q[]` 와 패턴 `p` 가 주어진다. `p` 의 사이사이에
소문자만을 추가하여 `Q[i]` 를 만들 수 있는지 검증하는 문제이다.

`Q[i]` 를 `q` 라 하자. `p` 를 소문자만을 추가하여 `q` 를 만드는 방법을
군더더기 없이 구현하는 것이 핵심이다.

```
int i = 0;
for (char c : q) {
  if (i < p.size() && c == p[i])
    ++i;
  else if (c < 'a')
    return false;
}
return i == p.size();
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(QP) O(P)
```
