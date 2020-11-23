# Problem

[Partition Array for Maximum Sum](https://leetcode.com/problems/partition-array-for-maximum-sum/)

# Idea

수열 `A[]` 와 숫자 `K` 가 주어진다. `A[]` 의 숫자들을 최대 길이 `K` 의
연속한 subarray 들로 그룹화할 수 있다. 이때 각 subarray 들의 원소들은
그 subarray 의 가장 큰 원소로 수정한다. 수정된 subarray 들의 각
원소들을 모두 더한 값을 구하는 문제이다.

dynamic programming 으로 해결해 보자.  캐시 `vector<int> C(n)` 을
선언하고 인덱스 `i` 를 선언하여 `A[]` 를 처음부터 순회한다.

예를 들어 `A = [1, 15, 7, 9, 2, 5, 10], K = 3` 인 경우를 살펴보자.
다음과 같이 인덱스 `i` 가 3 일 때 인덱스 `j` 를 `K` 의 수만큼
변경하면서 `C[i]` 를 수정할 수 있다.

```
          i
A: 1 15 7 9 2 5 10     C[i] = max(C[i], C[j-1] + 9)
          j
          
          i
A: 1 15 7 9 2 5 10     C[i] = max(C[i], C[j-1] + 9 * 2)
        j

          i
A: 1 15 7 9 2 5 10     C[i] = max(C[i], C[j-1] + 15 * 3)
      j
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
