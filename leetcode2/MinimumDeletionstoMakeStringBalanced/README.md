# Problem

[Minimum Deletions to Make String Balanced](https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/)

문자열 `s` 가 주어진다. `s` 는 `a, b` 로만 구성되어 있다. `a` 혹은 `b`
를 적당히 삭제해서 `s` 를 균형잡히게 만들어 보자. `s` 가 균형잡힌다는
말은 임의의 `i, j (i < j)` 에 대해 `s[i] == 'b' && s[j] == 'a'` 인
것이 없다는 의미이다.

# Idea

`s` 의 임의의 지점을 `i` 라고 하자. `i` 의 오른편에 놓여진 `a` 의
개수와 `i` 의 왼편에 놓여진 `b` 의 개수를 합하면 지워야할 문자의
개수를 알 수 있다. `i` 를 움직여서 지워야할 문자의 개수가 최소일 때 그
수가 답이다.

`int cntA` 를 선언하여 오른편 `a` 의 개수를 저장한다. `a` 의 개수로
초기화 한다. `int cntB` 를 선언하여 왼편 `b` 를 저장한다. 0 으로
초기화 한다. `int ans = max(cntA, n-cntA)` 를 선언하고 답을
저장한다. 이제 인덱스 `i` 를 이용하여 `s` 를 처음부터 끝까지 순회하며
다음을 반복한다.

* `s[i] == 'a'` 이면 `cntA` 를 하나 감소한다.
* `s[i] == 'b'` 이면 `cntB` 를 하나 증가한다. 
* `ans = min(ans, cntA + cntB)` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(N) O(1)
```
