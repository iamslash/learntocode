# Problem

[Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

# Idea

수열 `A[]` 가 주어진다. `A[]` 는 circular array 이다. circular
subarray 중 가장 최대값을 찾는 문제이다.

`A[]` 를 straight array 라고 가정하고 maximum sum of subarray 를
구해보자.

예를 들어 `A = 1 -2 3 -2` 인 경우를 살펴보자. 다음과 같이 인덱스 `i`
를 이용하여 순회한다. 이전까지 구한 `locmaxsum` 에 `A[i]` 를 더한 값과
`A[i]` 를 비교해서 더 큰 값을 `locmaxsum` 에 저장한다.  만약
`locmaxsum + A[i] < A[i]` 이면 `A[i]` 부터 다시 더해야 하기 때문에
`locmaxsum = A[i]` 이다.  그리고 `locmaxsum` 와 `glbmaxsum` 를
비교하여 더 큰 값을 `glbmaxsum` 에 저장한다. 순회를 모두 마치면
`glbmaxsum` 가 곧 답이다.

```       
                        i               i              i
        A: 1 -2 3 -2    1 -2 3 -2    1 -2 3 -2    1 -2 3 -2
locmaxsum: 0            1           -1            3                      
glbmaxsum: .            1            1            3

                   i     
        A: 1 -2 3 -2    
locmaxsum: 1
glbmaxsum: 3
```

`locminsum, glbminsum` 역시 비슷한 방법으로 구할 수 있다. 잘 생각해
보면 circular array 이기 때문에 allsum 에서 glbminsum 를 제거한 값이
답의 후보가 될 수 있다.

```
| ... | glbminsum | ... |
```

따라서 `glbmaxsum = max(glbmaxsum, allsum - glbminsum)` 이다.

만약 `glbmaxsum < 0` 인 경우는 특별히 처리해야 한다. 예를 들어 모든
수들이 음수인 경우를 생각해 보자. `allsum - glbminsum` 은 `0` 과 같을
것이다. 따라서 `glbmaxsum = max(glbmaxsum, 0) = 0` 이 된다. 따라서
`glbmaxsum < 0` 인 경우는 `glbmaxsum` 을 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
