# Problem

* [Median of Two Sorted Arrays](https://leetcode.com/explore/interview/card/top-interview-questions-hard/120/sorting-and-searching/859/)

# Idea

먼저 median 의 정의부터 알아보자. 예를 들어 `1 2 3` 과 같이 홀수의
개수를 갖는 리스트가 있다고 할 때 median 은 중앙의 한개의 숫자 `2` 와
같다.  다시 예를 들어 `1 2 3 4` 와 같이 짝수의 개수를 갖는 리스트가
있다고 할 때 median 은 중앙의 두개의 숫자 `2 3` 의 평균값 `2.5` 와
같다.

벡터 V 에 대해 길이를 N 이라고 하자. median 의 인덱스를 구하기 위해
다음과 같은 수식들을 적용해보자.

| V         | N/2-1 | (N-1)/2 | N/2 | (N+1)/2 | N/2+1 |
|:----------|:------|:--------|:----|:--------|:------|
| `1 2`     |  0    |   0     | 1   |   1     |  2    |
| `1 2 3`   |  0    |   1     | 1   |   2     |  2    |
| `1 2 3 4` |  1    |   1     | 2   |   2     |  3    |

결국 리스트의 길이가 홀수일때 median 의 인덱스는 `N/2` 이다.  리스트의
길이가 짝수일때 두개의 후보중 큰 median 의 인덱스는 `N/2` 이고 작은
median 의 인덱스는 `N/2-1` 이다.

만약 리스트의 길이가 홀수일 때 median 의 인덱스를 구하고 리스트의
길이가 짝수일 때 두개의 후보중 작은 median 의 인덱스를 구하고 싶다면
`(N-1)/2` 를 이용한다.

두개의 벡터를 `M, N` 이라고 하고 크기를 각각 `m, n` 이라고 하자.  M 를
두부분으로 적당히 나누고 왼쪽부분을 LM, 오른쪽 부분을 RM 이라고 하자.
N 역시 두 부분으로 적당히 나누고 왼쪽부분을 LN, 오른쪽 부분을 RN
이라고 하자.

```
M = LM RM
N = LN RN
```

이때 RM 의 최소값의 인덱스를 `pm`, LM 의 최대값의 인덱스를 `pm-1`
이라고 하자. 그리고 각각의 값을 `minrm, maxlm` 이라고 하자.  역시 RN
의 최소값의 인덱스를 `pn`, LN 의 최대값의 인덱스를 `pn-1` 이라고
하자. 그리고 각각의 값을 `minrn, maxln` 이라고 하자.

`pm` 과 `pn` 을 잘 찾아서 `maxlm <= minrn && maxln <= minrm` 를
만족한다면 median 을 구할 수 있다. `m+n` 이 홀수이면 `max(maxlm,
maxln)` 이 median 이고 `m+n` 이 짝수이면 두개의 median 후보가 존재하기
때문에 `(max(maxln, maxln) + min(minrm, minrn)) / 2` 가 median 이다.

`pm` 과 `pn` 은 Binary Search 를 이용해서 찾는다. `pm` 이 먼저
구해지면 `pn = (m + n + 1)/2 - pm` 이다. LM 과 LN 을 합한
길이와 RM 과 RN 을 합한 길이가 같아야 하기 때문이다.

# Implementation

[c++11](a.cpp)

# Time Complexity

```
O(log(min(m,n)))
```

# Space Complexity

```
O(1)
```

# References

* [Binary Search : Median of two sorted arrays of different sizes @ youtube](https://www.youtube.com/watch?v=LPFhl65R7ww)
