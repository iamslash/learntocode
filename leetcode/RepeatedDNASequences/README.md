# Problem

[Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences/)

# Idea

`A, C, G, T` 로 구성된 문자열 `s` 가 주어진다.  
두번 이상 반복되는 10 개의 부분문자열을 구하는 문제이다.

인덱스 `i` 를 이용하여 `[0..n-10]` 까지 순회하면서
10 개의 부분문자열 `seq` 가 맵에 있는지 검사해보고
두번째 `seq` 일 때만 `rslt` 에 추가하자.

이것을 더욱 최적화 하기 위해 맵의 키를 문자열이 아닌 숫자로 해보자.

`A, C, G, T` 는 모두 4 개이다. 이것을 숫자로 표현하면 이진수 2
자리이면 충분하다. 그리고 이러한 문자가 10개 모이면 이진수 20 자리이면
충분하다. 이진수 20 자리는 32 bit signed integer 로 충분히 표현
가능하다.

인덱스 `i` 를 이용하여 `[0..n)` 까지 순회하면서 
10 개의 부분문자열을 숫자 `num` 으로 바꾸고 맵에 있는지 검사한다.
두번째 `num` 일 때만 `rslt` 에 추가하자.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
