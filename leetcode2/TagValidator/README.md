# Problem

[Tag Validator](https://leetcode.com/problems/tag-validator/)

문자열 `s` 가 주어진다. 옳바른 tag 로 구성되어있는지 검증하라. tag 의
종류는 `<*>`, `</*>` 와 `<![CDATA[`, `]]>` 이다.

# Idea

`stack<string> stck` 를 선언하여 tag 의 시작을 저장한다.

인덱스 `i` 를 이용하여 `s` 를 순회하며 다음을 반복한다.

* `s.substr(i, 9) == "<![CDATA["` 이면 "`]]>`" 를 찾는다. 없다면 false
  를 리턴한다. 있다면 건너뛰어도 좋다.
* `s.substr(i, 2) == "</"` 이면 "`>`" 를 찾는다. 없다면 false 를
  리턴한다. 있다면 "`</`" 와 짝이 맞는 "`<`" 가 stack 에 있는지
  확인하고 없다면 false 를 리턴한다. 있다면 `stck.pop()` 를 수행한다.
* `s.substr(i, 1) == "<"` 이면 "`>`" 를 찾는다. 없다면 false 를
  리턴한다. 있다면 tag 문자열의 길이가 9 이하인지, 모두 대문자 인지
  검증한다. 이상이 없다면 `stck` 에 push 한다.

모든 반복을 마치고 `stck` 이 비어있다면 true 를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
