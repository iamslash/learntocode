# Problem

[Maximum Compatibility Score Sum](https://leetcode.com/problems/maximum-compatibility-score-sum/)

2 차원 배열 `students[][], mentors[][]` 가 주어진다. `students[i][j]`
는 i 학생의 j 질문에 대한 답변을 의미한다. `mentors[k][l]` 는 k
선생님의 l 질문에 대한 답변을 의미한다. 답의 후보는 `0` 혹은 `1` 이다.

i 학생의 답변들을 `students[i]` 라 하고 k 선생님의 답변들을
`mentors[k]` 라고 하자. 이때 학생과 선생님이 같은 답변을 한 횟수를
모두 더해 compatibility score 라고 하자.

i 학생과 k 선생님을 잘 짝지어서 compatibility score 가 최대가 되도록
해보자.  그때의 compatibility score 의 합을 구하라.

# Idea

문제의 조건에 의해 `1 <= students.length, mentors.length <= 8` 이다.

모든 학생을 순회하면서 학생 한 명당 선생님 한 명을 모두 짝지워 본다. 그리고 모두 짝지웠을 때 comaptibility score 의 최대합을 업데이트한다. [back tracking](/doc/backtracking.md) 으로 해결할 만 하다.

다음과 같이 dfs 를 정의하고 구현한다.

```c
int maxScore;
void dfs(visit[], students[][], mentors[][], idx, sum)

   visit: j 선생이 학생과 짝이어졌는가?
students: input data
 mentors: input data
     idx: 이번에 따져볼 학생의 인덱스
     sum: 지금까지 짝지어져 계산된 compatibility score
```

캐시를 이용하여 최적화 해보자. 지금까지 짝지어졌던 선생님들을 bitmask 로 표현한다면 
recursive dynamic programming 으로 접근할 수 있다.

다음과 같이 `C[][]` 를 선언하고 캐시로 이용하자.

```
C[idx][bm]: i 학생을 따져보자. 이미 짝지어진 선생님들의 목록을 bm 이라 할 때 
            max compatibility score sum. 예를 들어 0 번 선생님을 이미 
            짝지었다면 bm 을 00000001 으로 표현할 수 있다.
```

그리고 다음과 같이 부문문제 dfs 를 정의하고 구현한다.

```c
int dfs(C[][], students[][], mentors[][], idx, bm)

  return: max compatibility score sum
       C: cache
students: input data
 mentors: input data
     idx: 이번에 따져볼 학생의 인덱스
      bm: 지금까지 짝지어진 선생님들의 목록
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O((M*2^M)*N) O(M*(2^M))

M: length of students
N: length of answers
```
