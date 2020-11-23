# Problem

[Mini Parser](https://leetcode.com/problems/mini-parser/)

# Idea

`'-' '0-9' '[' ']' ','` 으로 구성된 문자열 `s` 가 주어지면 이것을
deserialize 하는 문제이다. 문제의 조건에 의해 `s` 는 `welformed
string` 이다.

`s` 를 인덱스 `i` 를 이용하여 처음부터 끝까지 순회한다. `s[i]` 를
검사해보고 처리한다. 엔트리 함수 `NestedInteger
deserialize(std::string s)` 는 문자열을 입력받으면 `NestedInteger` 를
리턴한다. `NestedInteger` 의 모양은 충분히 재귀적이다.  `deserialize`
를 재귀적으로 호출하면 `[, ]` 에 의한 스택을 잘 처리할 수 있을 것
같다.

예를 들어 `s = "243"` 을 살펴보자. `s[0] == '2'` 이다.  숫자가
나타났다면 숫자가 종료될때 까지 `i` 를 증가하고 파싱된 부분문자열을
숫자 `num` 로 바꾸어 `NestedInteger(num)` 을 리턴한다.

이번에는 `s = [1,2,3]` 을 살펴보자. `s[0] == '['` 이다.  `while (s[i]
!= ']')` 동안 `deserialize(s)` 를 재귀호출할 만하다. `[` 다음에 `[` 가
따라오면 스택아이템이 하나 증가해야 하기 때문이다. 만약 `while-loop`
에서 `,` 를 만나면 스택을 증가시키지 않고 처리해야 하기 때문에 `i++`
를 해야 한다.

이것을 종합해보자. 먼저 인덱스 `int m_i = 0` 를 멤버 변수로 선언한다.
그리고 `deserialize` 를 recursive function 으로 design 한다.
또한 `s[m_i] != ']'` 일 때와 그렇지 않을 때를 고려하여 구현한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
