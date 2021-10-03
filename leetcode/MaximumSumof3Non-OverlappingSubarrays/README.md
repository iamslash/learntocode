# Problem

[Maximum Sum of 3 Non-Overlapping Subarrays](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/)

수열 `A[]` 와 숫자 `k` 가 주어진다. 서로 겹치지 않고 크기가 `k` 인
연속된 부분 수열 3 개를 찾는다. 부분 수열들은 그 합이 최고가 되어야
한다. 3 개의 부분수열을 찾았다면 그 시작 인덱스를 구하는 문제이다.

# Idea

연속된 부분 수열의 합을 캐싱하기 위해 부분합 `ps[]` 를 생성한다.  `k`
개수 만큼의 subarray 가 3 개 있다고 해보자. 왼쪽 부터 left subarray,
middle subarray, right subarray 라고 하자.

middle subarray 를 표현하는 윈도우를 한칸씩 이동하면서 left subarray 중
합이 최고인 것과 right subarray 중 합이 최고인 것을 더한다. 그것을 maxSum
이라고 하자. maxSum 이 최고일 때 그 때 더한 left subarray 의 인덱스,
right subarray 의 인덱스를 구하여 답에 저장한다.

`int[] leftIdxs = new int[n]` 을 선언하여 `leftIdxs[i]` 에 i 부터
왼쪽으로 펼쳐진 left subarray 중 합이 최고일 때 그 시작 인덱스를
저장한다.  `int[] rightIdxs = new int[n]` 을 선언하여 `rightIdxs[i]`
에 i 부터 오른쪽으로 펼쳐진 right subarray 중 합이 최고일 때 그 시작
인덱스를 저장한다.

다음은 `nums = [1,2,1,2,6,7,5,1], k = 2` 의 풀이과정이다.

```
         k: 2
         n: 8
                  ___
      nums:   1 2 1 2  6  7  5  1
                  i
        ps: 0 1 3 4 6 12 19 24 25
       ans:   0 3 5
  leftIdxs:   0 0 0 0  3  4  4  4 
 rightIdxs:   4 4 4 4  4  5  6  0
    maxSum: 0
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(N) O(N)
```
