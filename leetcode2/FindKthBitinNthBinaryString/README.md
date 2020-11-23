# Problem

[Find Kth Bit in Nth Binary String](https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/)

숫자 `n, k` 가 주어진다. 수열 `s_1 = 0` 을 시작으로 `s_i` 를 다음과
같은 규칙으로 생성했을 때 `s-n` 의 `k` 번째 숫자를 구하라. `k` 는
1-based index 이다.

* `s_i = s_(i-1) + '1' + reverse(invert(s_i-1))`

# Idea

예를 들어 다음과 같이 `s_1, s_2, s_3` 을 생성해 보자.

```
s_1: 0
s_2: 0 1 1
s_3: 0 1 1 1 0 0 1
```

그리고 `s_3` 의 경우 다양한 `k` 에 대해서 생각해 보자.

```
s_1: 0
s_2: 0 1 1
s_3: 0 1 1 1 0 0 1
           k
             k
               k
                 k
```

다음과 같은 몇가지 규칙들을 발견할 수 있다. 

* `len` 을 선언하여 `s_3` 의 길이를 저장한다. 즉, `len = pow(2, 3) - 1 = 7` 이다.
* `prevLen` 을 선언하여 `s_2` 의 길이를 저장한다. 즉, `prevLen = pow(2, n-2) - 1 = 3` 이다.
* `k-1 == prevLen` 이면 답은 `1` 이다.
* `k-1 < prevLen` 이면 답은 `s_2[k-1]` 이다.
* `k-1 > prevLen` 이면 `s_2[len-k+1]` 의 반대 값이다. 

`findKthBit` 을 재귀적으로 구현하여 해결할 수 있다.

```
* findKthBit(3, 4): 1

* findKthBit(3, 5): 1
          |
  findKthBit(2, 3): 1
          |
  findKthBit(1, 1): 1

* findKthBit(3, 6): 1
          |
  findKthBit(2, 2): 1

* findKthBit(3, 7): 1
          |
  findKthBit(2, 1): 1
          |
  findKthBit(1, 1): 1
```

# Implementation

* [go](a.go)

# Complexity

```
O(N) O(N)
```
