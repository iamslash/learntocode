# Problem

[Maximum Points You Can Obtain from Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)

수열 `P[]` 와 숫자 `k` 가 주어진다. `P[]` 의 양끝의 숫자들을 `k` 개
선택할 수 있다. 선택한 숫자들의 합이 최대인 것을 구하라.

# Idea

예를 들어 `P = [1,2,3,4,5,6,1], k = 3` 인 경우를 살펴보자.

```     
P: 1 2 3 4 5 6 1
           ----- 12
   -         ---  8
   ---         -  4
   -----          6
```

따라서 답은 12 이다.

`int n = P.size(), i = 0, j = n-k` 를 선언한다.  `int sum` 을 선언하여
`P[n-k..n)` 의 합을 저장하자. `int ans = sum` 를 선언하여 답을
저장한다.

`k-- > 0` 인 동안 다음을 반복한다. 

* `sum` 에 `P[i]` 를 더하고 `P[j]` 를 뺀다. 그리고 `i++, j++` 를
  수행한다. 양끝의 윈도우가 오른쪽으로 한칸씩 이동한 것과 같다.
* `ans = max(ans, sum)` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
