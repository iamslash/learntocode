# Problem

* [Continuous Subarray Sum @ leetcode](https://leetcode.com/problems/continuous-subarray-sum/)

수열 `nums[]` 와 숫자 `k` 가 주어진다. `nums[]` 의 subarray 중 원소의 합이 `k` 의 배수인지 검증하라. 이때, subarray 의 개수는 2 개 이상이어야 한다.

# Idea

숫자들의 배열이 주어졌을 때 `i` 인덱스의 숫자를 `a[i]` 이라고 하자. `[0, i]` 영역 숫자들의 합을 `S[i]` 이라고 하자.  `[i, j]` 영역 숫자들의 합을 `T[i,j]` 이라고 하자.  `T[i,j] = S[j] - S[i-1]` 이다.

이때, `T[i,j]` 가 `k` 로 나누어 떨어진다는 말은 `S[j] - S[i-1]` 이 `k` 로 나누어 떨어진다는 말과 같다.  즉 `S[j] ≡ S[i-1] mod k` 이다.

`a[]` 를 처음부터 순회하면서 `S[i] % k` 가 이전에 등장했었다면 참이다. 이때 `a` 는 최소 두개이어야 하기 때문에 `T[i,j]` 에서 `j - i >= 2` 인 것을 유의하자.

`Map<Integer, Integer> modIdxMap` 을 선언하여 `{ mod : index }` 를 저장한다. 이때 나머지가 0 인 경우를 위해 magic seed `{0 : -1}` 를 삽입한다.
 
# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
C(N) C(N)
```
