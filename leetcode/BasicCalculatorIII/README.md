# Problem

[Basic Calculator III](https://leetcode.com/problems/basic-calculator-iii/)

# Idea

문자열 `s` 가 주어진다. `s` 는 `+, -, *, /, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, ' '` 으로만
이루어진다. `s` 를 evaluation 한 값을 구하는 문제이다.

`parseNum, parseExpr` 과 같은 두가지 함수가 필요하다.

* `parseNum(string& s, int& i)`

`s[i]` 부터 시작하는 숫자를 파싱한다. `i` 는 파싱된 숫자 다음
문자를 가리킨다. `parseNum` 은 `s[i]` 가 숫자일 때는 숫자를 리턴하지만
그렇지 않을때는 0 을 리턴한다. 0 이 리턴되면 아무것도 하지 않고 `i` 를
전진한다.

* `parseExpr(string& s, int& i)` 
  
결과값들을 모두 저장할 `vector<int> nums` 를 선언한다.
`i` 를 전진하면서 수집된 숫자들중 바로 앞 연산자가 `+, -` 
인 것들을 삽입한다. `*, /` 인 경우는 `nums.back()` 과
바로 연산한다.

인덱스 `i` 를 하나씩 전진하면서 다음을 반복한다.

0. `s[i]` 가 `(` 이면 `num = parseExpr(s, ++i)` 한다. 그렇지 않으면 `num = parseNum(s, i)` 한다.
   이때 `num == 0` 이면 `s[i]` 는 숫자가 아니라는 얘기다. 아무것도 하지 말자.
1. `op == +, -` 이면 `nums` 에 `num` 을 삽입한다. `op == *, /` 이면 `nums.back()` 에 `num` 을 바로 연산하자.
2. 이미 `i` 는 전진되어 있다. `op = s[i]` 하자.

# Implementation

* [c++11](a.cpp)
* [java8](Solution.cpp)

# Complexity

```
O(N) O(N)
```
