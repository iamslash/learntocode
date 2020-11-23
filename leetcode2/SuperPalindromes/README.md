# Problem

[Super Palindromes](https://leetcode.com/problems/super-palindromes/)

숫자 `L, R` 이 주어진다.  `x` 가 palindrome 이고 `x` 또한 palindrome
의 제곱으로 표현할 수 있으면 그것을 super palindrome 이라고 한다.  `L`
보다 크거나 같고 `R` 보다 작거나 같은 수들 중 super palindrome 의
개수를 구하라.

# Idea

예를 들어 `L = "4", R = "1000"` 인 경우를 살펴보자.

```
  4 =  2 *  2
  9 =  3 *  3
121 = 11 * 11
484 = 22 * 22
```

따라서 답은 4 이다.

`genPalindrome(int64_t num, int type)` 을 정의하여 `num` 을 이용하여
palindrome 을 만들어 리턴하도록 한다.  이때 `type` 의 값에 따라 홀수
혹은 짝수 palindrme 을 만들 수 있다.

`isPalindrome(int64_t num)` 을 정의하여 `num` 이 주어지면 
palindrome 여부를 검사하도록 한다.

이제 인덱스 `i` 를 이용하여 `[0..1e5)` 를 순회하면서 다음을 반복한다.
문제의 조건에 의해 `1 <= len(R) <= 18` 이다. `1e5` 로 제작가능한
palindrome 은 `type == 0` 이면 `1e9` 이고 `type == 1` 이면 `1e10`
이다.

* 인덱스 `type` 를 이용하여 `[0..2)` 를 순회하면서 다음을 반복한다.
  * `int64_t pal = genPalindrome(i, type)` 을 수행한다.
  * `pal > 1e9` 이면 제곱해봐야 `1e18` 보다 크다. 따라서 건너뛴다.
  * `int64_t pp = pal * pal` 를 수행한다.
  * `pp >= l && pp <= r && isPalindrome(pp)` 이면 `ans` 를 하나 증가한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(R) O(1)
```
