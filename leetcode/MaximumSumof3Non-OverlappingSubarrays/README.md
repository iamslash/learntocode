# Problem

[Maximum Sum of 3 Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

# Idea

수열 `A[]` 와 숫자 `k` 가 주어진다. 서로 겹치지 않고 크기가 `k` 인
연속된 부분 수열 3 개를 찾는다. 부분 수열들은 그 합이 최고가 되어야
한다. 3 개의 부분수열을 찾았다면 그 시작 인덱스를 구하는 문제이다.

연속된 부분 수열의 합을 캐싱하기 위해 부분합 `ps[]` 를 생성한다.

`A[]` 의 왼쪽 방향에서 오른쪽 방향으로 최고 부분 수열의 합과 시작
인덱스를 `forward[]` 에 `{A[i] + ... + A[i+k-1], i}` 형태로 삽입한다.
`forward[i].first <= forward[i+1].first` 가 보장되어야 한다.

`A[]` 의 오른쪽 방향에서 왼쪽 방향으로 최고 부분 수열의 합과 시작
인덱스를 `backward[]` 에 `{A[i] + ... + A[i+k-1], i}` 형태로 삽입한다.
`backward[i].first >= backward[i+1].first` 가 보장되어야 한다.

`ps[], forward[], backwar[]` 가 완성되었다면 3 개의 부분수열중 중간
수열을 특정했을 때 왼쪽 부분수열 합의 최고와 오른쪽 부분수열 합의
최고를 알아낼 수 있다.

다음은 `V = (4, 5, 10, 6, 11, 17, 4, 11, 1, 3), k = 1` 인 경우 `ps[],
foward[], backward[]` 를 표현한 것이다.

```
//  n: 10
//  V: 4  5 10  6 11 17  4 11  1  3
//  P: 4  9 19 25 36 53 57 68 69 72
//        i
//  F: 4  5 10 10 11 17 17 17 17 17
//     0  1  2  2  4  5  5  5  5  5
//  B:17 17 17 17 17 17 11 11  3  3 
//     5  5  5  5  5  5  8  8  9  9
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
