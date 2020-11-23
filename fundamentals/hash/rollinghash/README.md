# Abstract

이전에 만들었던 hash 값의 일부를 이용해서 새로운 hash 값을 제작하는 방법이다.

# Referneces

* [Rolling Hash @ Tistory](https://k2lkh.tistory.com/5)
* [Rabin-Karp Algorithm for Pattern Searching](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)
* [Rolling hash @ Wikipedia](https://en.wikipedia.org/wiki/Rolling_hash)

# Problem

* [Distinct Echo Substrings](https://leetcode.com/problems/distinct-echo-substrings/)

# Idea

예를 들어 문자열 `a = "abcde"` 에서 `b = "bcd"` 를 검색해 보자. 
`b` 에 해당하는 slide 를 오른쪽으로 이동하면서 일치하는 문자열을 찾으면 된다.

```
a: a b c d e
   b c d
     b c d
```

이번에는 문자열 비교대신 hash 를 비교하여 성능을 개선해 보자.
rolling hash 를 이용할 만 하다. 먼저 `b` 의 hash 를 구한다.
간단한 설명을 위해 base 에 해당하는 `R` 은 `7` 로 하자.

```c
hash(b) = 'b'*7^0 + 'c'*7^1 + 'd'*7^2 = 98*1 + 99*7 + 99*49 = 5691
```

이제 문자열 비교대신 `hash(window of a)` 와 `hash(b)` 를 비교한다.

```c
a: a b c d e
   'a'*7^0 + 'b'*7^1 + 'c'*7^2 = 5634
     'b'*7^0 + 'c'*7^1 + 'd'*7^2 = 5691
```

slide window 가 움직일 때 마다 window 에서 벗어나는 문자 `s` 와 들어오는 문자 `t` 를 이용하여
다음과 같이 `hash(new window)` 를 구할 수 있다.

```c
hash(new window) = (hash(old window) - 's'*7^0) / 7 * 't'*7^2
```

hash 의 값이 매우 크다면 적당히 큰 prime number (P) 로 modulo 연산을 해준다.

```c
hash(new window) = (hash(old window) - 's'*7^0 % P) / 7 * 't'*7^2 % P
```

이때 뺄셈 연산때문에 음수가 되는 것을 방지 하기 위해 prime number (P) 를 한번 더해준다.

```c
hash(new window) = (hash(old window) - 's'*7^0 % P + P) / 7 * 't'*7^2 % P
```

rolling hash 를 위해서는 `base (R)` 과 `prime number (Q)` 가 필요하다.
