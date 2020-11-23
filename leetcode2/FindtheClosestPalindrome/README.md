# Problem

[Find the Closest Palindrome](https://leetcode.com/problems/find-the-closest-palindrome/)

문자열 `s` 가 주어진다. `s` 는 숫자를 표현한 문자열이다.  `s` 와 가장
가까운 palindrome 을 찾아라.

# Idea

예를 들어 `s = 123` 인 경우를 살펴보자. `123` 보다 작거나 같으면서
가장 큰 palindrome 은 `99` 이다. 이것을 `lowBnd` 라고 하자.  이번에는
`123` 크거나 같으면서 가장 작은 `palindrome` 은 `1001` 이다. 이것을
`hiBnd` 라고 하자. `lowBnd = pow(10, n) + 1, hiBnd = pow(10, n-1) -1`
이다.

`set<int> candSet` 을 선언하여 palindrome 후보들을 저장한다.  `lowBnd,
hiBnd` 는 후보에 해당하므로 추가하자. 후보자의 범위는 `loBnd <= ans <=
hiBnd` 에 해당한다. 후보자를 찾아서 `candSet` 에 삽입해야 한다.

`string prefix` 를 선언하여 `s` 의 처음부터 중간까지를
저장한다. `prefix` 와 `prefix` 를 뒤집어서 연결하면 `palindrome` 이
된다. 이때 `s.size()` 가 홀수이면 `prefix` 의 마지막 문자는 겹치게
연결해야 한다. `prefix - 1, prefix, prefix + 1` 에 각각을 뒤집어서
연결한다음 `candSet` 에 삽입한다. 이제 `candSet` 에는 5 개의
후보자들이 저장되게 된다. 이중에서 `s` 와 차이가 가장 작은 것을 찾으면
답이 된다.

`int num = stol(s)` 를 선언하여 `s` 를 숫자로 바꾸어 저장한다. `int
minDiff, diff` 를 선언하여 최소차이값 및 차이값을 저장한다. `int ans`
는 답을 저장한다. `s` 와 가장 가까운 것을 찾아야 한다. `s` 가
palindrome 이더라도 답이 될 수 없다. 따라서 `candSet` 에서 `num` 은
제거한다.

`candSet` 을 순회하면서 다음을 반복한다.

* `diff = abs(cand - num)` 을 수행한다.
* `diff < minDiff` 이면 `minDiff = diff, ans = cand` 를 수행한다.
* `diff == minDiff` 이면 `ans = min(ans, cand)` 를 수행한다.

모든 반복을 마치면 `ans` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(S) O(1)
```
