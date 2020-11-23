# Problem

* [Delete Columns to Make Sorted III](https://leetcode.com/problems/delete-columns-to-make-sorted-iii/)

# Idea

주어진 배열의 개수를 `M`, 배열의 원소에 해당하는 문자열의 길이를 `N`
이라고 하자. `M` 개의 문자열들의 길이는 모두 같다. 모든 문자열들의
공통된 `LIS (longest Increasing sequece)` 를 구하는 문제이다.

먼저 하나의 문자열에 대해 `LIS` 를 어떻게 구하는지 알아보자.  예를들어
문자열 `babca` 를 살펴보자. 부분문자열의 끝 인덱스를 `i` 라고 할 때
`[0..N-1]` 을 순회하면서 `i` 로 끝나는 부분문자열들중 가장 긴 `LIS` 의
리이를 캐시에 기록하면 된다. 다음은 2-D 테이블로 그 과정을 표현한
것이다.

| `i\j` | 0 | 1 | 2 | 3 | 4 |
|:------|:--|:--|:--|:--|:--|
| 0     |   |   |   |   |   |  
| 1     | 1 |   |   |   |   |  
| 2     | 1 | 2 |   |   |   |  
| 3     | 2 | 2 | 3 |   |   |  
| 4     | 1 | 1 | 1 | 1 |   |  

가로가 인덱스 `j` 의 값이고 세로가 인덱스 `i` 의 값이다. 그리고
교차하는 것은 캐시 `C[i]` 의 값이다. `C` 는 최초 magic number `1` 로
초기화 한다.

다음은 위의 과정을 코드로 표현한 것이다.

```
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < i; ++j) {
        if (s[j] < s[i])
            C[i] = max(C[i], C[j] + 1);
    }
}
```

이제 여러 문자열들에 대한 공통된 LIS 를 구해보자.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(MN^2) O(N)
M ; size of A
N : size of A[i]
```
