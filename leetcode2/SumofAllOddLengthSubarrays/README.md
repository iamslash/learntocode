# Problem

[Sum of All Odd Length Subarrays](https://leetcode.com/problems/sum-of-all-odd-length-subarrays/)

수열 `A[]` 가 주어진다. 길이가 홀수인 subarray 들을 찾아서 각 원소의
합을 모두 더한 것을 구하라.

# Idea

예를 들어 `A = [1,4,2,5,3]` 인 경우를 살펴보자.

```
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15

1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
```

따라서 답은 `58` 이다.

`A = [1,4,2,5,3]` 과 `A = [1,2,3,4,5]` 의 답은 같을 것이다. 그렇다면
모든 subarray 에 `A[i]` 가 몇번 포함되는지를 알면 `A[i] * (count of A[i])` 
를 이용하여 쉽게 해결할 수 있다.

```
A: 1 2 3 4 5

1 2 3 4 5 subarray length 1
1 2 X X X subarray length 2
X 2 3 X X subarray length 2
X X 3 4 X subarray length 2
X X X 4 5 subarray length 2
1 2 3 X X subarray length 3
X 2 3 4 X subarray length 3
X X 3 4 5 subarray length 3
1 2 3 4 X subarray length 4
X 2 3 4 5 subarray length 4
1 2 3 4 5 subarray length 5

5 8 9 8 5 The count of A[i]
3 4 5 4 3 The count of A[i] in odd length array with (x + 1) / 2
2 4 4 4 2 The count of A[i] in even length array with x / 2
```

`A[i]` 는 위치에 따라 즉, `i` 의 값에 따라 odd subarray 에 `((i+1) *
(n-i) + 1) / 2` 번 포함된다.

인덱스 `i` 를 이용하여 `[0..n)` 동안 순회하면서 다음을 반복한다.

* `ans += ((i + 1) * (n - i) + 1) / 2 * A[i]`

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(1)
```
