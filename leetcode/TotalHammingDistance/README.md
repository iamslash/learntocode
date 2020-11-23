# Problem

* [Total Hamming Distance](https://leetcode.com/problems/total-hamming-distance/)

# Idea

정수들의 배열 `a_0, a_1, a_2, a_3, ..., a_n-1` 가 주어졌을 때 각
정수들간의 hamming distance 를 구하는 문제이다.

정수의 크기를 `32` 비트라고 해보자. 모든 정수를 순회하면서 `0` 번
비트가 `0` 인 정수들의 숫자를 `p` 라 하고 `1` 인 정수들의 숫자를 `q`
라 하자.  `0` 번 비트에 대해서 hamming distance 가 1 인 정수들의
숫자는 `p * q` 이다.

이제 다음과 같이 `1` 번 비트부터 `31` 번 비트까지 동일한 과정을
반복하면 답을 구할 수 있다.

```cpp
    for (int i = 0; i < 32; ++i) {
      int cnt = 0;
      for (int j = 0; j < n; ++j) {
        if ((V[j] >> i) & 0x01)
          cnt += 1;
      }
      rslt += cnt * (n - cnt);
    }
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
