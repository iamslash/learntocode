# Problem

[Ambiguous Coordinates](https://leetcode.com/problems/ambiguous-coordinates/)

# Idea

문자열 `s` 가 주어진다. `s` 는 `',', ' ',', '.'` 가 제거된 문자열이다.
`s` 에 `',', ' ',', '.'` 을 적당한 자리에 추가하여 만들어 낼 수 있는
좌표들을 구하는 문제이다.

예를 들어 `s = (123)` 일 때 답은 `["(1, 23)", "(12, 3)", "(1.2, 3)",
"(1, 2.3)"]` 와 같다.

`s` 를 2 차원 좌표로 표현해야 한다. 따라서 `s` 를 `a, b` 와 같이 두
개의 그룹으로 나눈다. 이것은 `, ` 를 적용한 문자열들을 만들어낸 것과
같다. 답을 저장할 벡터 `vector<string> rslt` 를 선언한다.  그리고
여러개의 `a, b` 에 대해 다음을 반복한다.

`a, b` 각각 `.` 을 적용한 문자열들을 구한다. 이것을 각각 
`vector<string> c, vector<string> d` 라고 하자.
`c, d` 를 cartesian product 한 것을 `rslt` 추가한다.

모든 반복을 종료하면 `rslt` 가 답이다.

참고로 임의의 문자열 `s` 에 대해 `.` 을 적용한 문자열들은 문제의
조건에 의해 다음과 같다.

| s | rslt | desc |
|:--|:-----|:-----|
| `''` | `{}` | no reason |
| `0???0` | `{}` | already considered |
| `0???` | `{0.???}` | `0?.??` is not allowed |
| `0` | `{0}` | of course |
| `?0` | `{s}` | other cases already considered |
| `???` | `{s, ?.??, ??.?}` | so natural |

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^3) O(N)
```
