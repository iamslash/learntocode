# Problem

[Minimum Adjacent Swaps to Make a Valid Array](https://leetcode.com/problems/minimum-adjacent-swaps-to-make-a-valid-array/)

수열 `nums[]` 가 주어진다. 다음의 동작을 무수히 할 수 있다.

* 서로 인접한 두 수의 위치를 바꿀 수 있다. 

가장 작은 수가 왼쪽 끝에 가장 큰 수가 오른쪽 끝에 배치되기 위해 필요한
최소 횟수를 구하라.

# Idea

`nums[]` 를 정렬하는 문제가 아님을 주의하자.

예를 들어 `nums = [3, 4, 5, 5, 3, 1]` 의 경우를 살펴보자.

```
nums: 3 4 5 5 3 1
      3 4 5 3 1 5   2
      1 3 4 5 3 5   4
```

따라서 답은 6 이다.

최소 교체횟수를 구하기 위해서는 다음과 같이 두가지 인덱스가 필요하다.

* maxIdx: `nums[]` 의 수중 오른쪽에 있으면서 가장 큰 수의 인덱스
* minIdx: `nums[]` 의 수중 왼쪽에 있으면서 가장 작은 수의 인덱스

만약 `minIdx > maxIdx` 이면 큰수와 작은수를 교체할 때 한번은 이득을 본다.

따라서 답은 다음과 같다. 

```
  a: 오른쪽 가장 큰수를 nums[] 의 오른쪽 끝으로 이동하는 횟수
  b: 왼쪽 가장 큰수를 nums[] 의 왼쪽 끝으로 이동하는 횟수 
  c: minIdx > maxIdx 이면 1 아니면 0

ans: a + b - c
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(1)
```
