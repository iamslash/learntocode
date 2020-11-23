# Problem

숫자 `n` 이 주어진다. 에라토스테네스의 체를 이용하여 소인수분해를 구하는 문제이다.

# Idea

에라토스테네스의 체를 이용하여 `2` 부터 특정 숫자 `n` 까지 순회 하면서
소인수 분해한다. 숫자 `i` 의 제일 작은 소수를 `min_factor[i]` 에 기록해둔다. 


다음과 같이 반복하여 `min_factor[n]` 을 소인수분해에 추가한다.

```cpp
  while (n > 1) {
    r.push_back(min_factor[n]);
    n /= min_factor[n];
  }
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(sqrt(N)N) O(N)
```