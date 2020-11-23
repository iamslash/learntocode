# Problem

* [Unique Substrings in Wraparound String](https://leetcode.com/problems/unique-substrings-in-wraparound-string/)

# Idea

문자열 `s` 를 `abcdefghijklmnopqrstuvwxyz` 가 여러개 중첩된 문자열의 부분문자열이라고
해보자. 예를 들면
`ab`, `zab`, `abcdefg`, `abcdefghijklmnopqrstuvwxyzabc...` 같은
문자열들을 말한다. 따라서 `s` 의 각 문자는 이전 문자에서 1 만큼 증가한 문자이다. 
이전 문자가 `z` 인 경우는 현재 문자가 `a` 가 된다.

`s` 에 관한 몇가지 중요한 성질을 알아낼 수 있다. 만약 `p` 가 `z` 라고
해보자. 그럼 `s` 의 개수는 1 개임이 자명하다. 만약 `p` 가 `za` 라고
해보자. `s` 의 후보는 `z`, `a`, `za` 이므로 총 3개이다.  이것은 바로
이전에 `p` 가 `z` 일 때 구한 `s` 의 개수 1 개에 문자열 `za` 의 길이 2
개를 더한 것과 같다. 이번에는 `p` 가 `zab` 라고 해보자. `s` 의 후보는
`z`, `a`, `za`, `b`, `ab`, `zab` 이므로 총 6 개이다. 이것은 바로
이전에 `p` 가 `za` 일 때 `s` 의 개수 3 개에 `zab` 의 문자열의 길이 3
을 더한 것과 같다. 앞서 언급한 내용을 기반으로 규칙을 만들어 낼 수 있다.
`p` 의 전체 문자열이 `s` 의 속성과 일치한다면 `s` 의 개수는 마지막
문자열을 제외한 문자열의 `s` 의 개수와 문자열 `p` 의 개수의 합과 같다.

```
s count of p[0..i] = s count of p[0..i-1] + length of p[0..i]
```

이번에는 다른 경우를 보자. `p` 가 `zabdab` 의 경우를 살펴보자. 
`d` 를 중심으로 `zab` 와 `ab` 로 나뉘어 진다. `zab` 인 경우
`s` 의 후보는 `z`, `a`, `za`, `b`, `ab`, `zab` 이므로 총 6개이다.
`ab` 의 경우 `s` 의 후보는 `a`, `b`, `ab` 이다. 이것은 앞서
`zab` 의 경우 이미 고려되었기 때문에 `p` 의 `s` 의 개수에 포함되지 않는다.

dynamic programming 으로 해결하기 위해 다음과 같이 CACHE `C` 를 정의한다. 

```
int C[26]
C[i] = max length of s string ends with i+'a' character
```

`C[i]` 가 예전 값보다 클 때만 갱신한다. 만약 예전 값보다 클 경우는 이미 총합에 더해져 있기 때문에 총합에서 예전 값을 제거해야 한다. 

예를 들어서 `zab` 인 경우 다음과 같은 순서로 `C` 와 결과 `rslt` 를 채울 수 있다. 

```
C[25] = 1 // z
C[0]  = 2 // a
C[1]  = 3 // b
rslt  = C[25] + C[0] + C[1]
```

예를 들어서 `zabdabcd` 인 경우 다음과 같은 순서로 `C` 와 결과 `rslt` 를 채울 수 있다. 두번 째 `d` 의 경우 총합에서 예전 `C[3]` 을 제거해야 한다.

```
C[25] = 1 // z
C[0]  = 2 // a
C[1]  = 3 // b
C[3]  = 1 // d 1st
C[0]  = 2 // a
C[1]  = 3 // b
C[2]  = 3 // c
C[3]  = 4 // d 2nd
rslt  = C[25] + C[0] + C[1] + C[2] + 2nd C[3] - 1st C[3]
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
Time: O(N), Space: O(1)
```
