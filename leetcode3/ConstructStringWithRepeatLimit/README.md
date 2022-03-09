# Problem

[Construct String With Repeat Limit](https://leetcode.com/problems/construct-string-with-repeat-limit/)

문자열 `s` 와 숫자 `repeatLimit` 이 주어진다.  `s` 는 영문 소문자로만
구성되어 있다. `s` 의 문자를 조합하여 사전순으로 가장 큰 문자열을
만들어 보자. 이때 한 문자는 연속으로 `repeatLimit` 만큼 쓸 수 있다.

# Idea

예를 들어 `s = "zzzzzaabbcc", repeatLimit = 3` 의 경우를
살펴보자.

```
  s: zzaabbcc
ans: zzz
  s: zzaabbc
ans: zzzc
  s: aabbc
ans: zzzczz
  s: 
ans: zzzczzcbbaa
```

따라서 답은 `zzzczzcbbaa` 이다.

`StringBuilder ans = new StringBuilder()` 를 선언하여 답을 저장한다.

`Queue<int[]> pq = new PriorityQueue<>()` 선언하여 `(code, freq)` 를
삽입하고 `freq` 가 높은 것을 꼭대기 값으로 하자.

`!pq.isEmpty()` 동안 `ans` 를 완성한다. `pq` 에서 이번에 추출한 문자는
`pq` 에 남아있는 문자보다 사전순이 높다. 이번에 추출한 문자를
`repeatLimit` 만큼 사용하고 남았다면 `pq` 에 남아있는 문자를 하나만
사용한다. 그리고 이번에 추출한 문자를 다시 `pq` 에 삽입한다.

모든 반복을 마치면 `ans.toString()` 이 답이다. 

# Implementation

* [java8](MainApp.java)
* [kotlin](MainApp.kt)

# Complexity

```
O(NlgN) O(N)
```
