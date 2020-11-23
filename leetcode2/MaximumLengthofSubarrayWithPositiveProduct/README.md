# Problem

[Maximum Length of Subarray With Positive Product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/)

수열 `A[]` 가 주어진다. subarray 들 중 원소들의 곱이 최대인 것의
길이를 구하라.

# Idea

몇가지 규칙을 생각해 보자. `A[0]` 이면 그것은 subarray 에 포함하지
말아야 한다. 원소들의 곱이 최대가 되기 위해서는 음수인 원소가
짝수이어야 한다. 음수 원소들의 개수를 세어서 최대 짝수인 것을 찾아야
한다.

```
//                          i
//            A:    1 -2 -3 4
//       negCnt:  0 0  1  2 2
// firstEvenNeg: -1-1 -1 -1-1  
//  firstOddNeg: -2-2  1  1 1
//          ans:  0 1  1  3 4

```

It's too difficult.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
