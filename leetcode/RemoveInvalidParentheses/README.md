# Problem

[Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/)

문자열 `s` 가 주어진다. `s` 는 `(, )` 및 alphabet 으로 구성되어
있다. 괄호의 짝이 맞도록 임의의 괄호를 제거해 보자.  모든 경우에
해당하는 문자열을 구하라.

# Idea

예를 들어 `s = "()())()"` 의 경우를 살펴보자.

```
s: ( ) ( ) ) ( )
   ( ) ( )   ( )
   (   ( ) ) ( )
```

따라서 답은 `["()()()", "(())()"]` 이다.

`vector<string> ans` 를 선언하여 답을 저장한다.

인덱스 `i` 를 활용하여 `s` 를 처음부터 순회한다. `int stck = 0` 를
선언하여 `(` 를 만나면 하나 증가하고 `)` 를 만나면 하나 감소한다.
`stck < 0` 이면 `)` 가 하나 많다는 의미이다. `)` 를 제거하자.  이때
`)` 가 여러개일 수도 있다. 그러나 답이 겹치는 걸 막기 위해 가장 먼저
만나는 `)` 를 제거한다.

`stck > 0` 인 경우는 `s` 를 거꾸로 뒤집어서 앞서 언급한 알고리즘을
적용한다.

다음과 같은 부분문제 `dfs` 를 선언한다.

```
int dfs(s, ans, lastI, lastJ, par0, par1)

return:
     s: input string
   ans: answer
 lastI: last i
 lastJ: last j
  par0: parenthese which increase stck
  par1: parenthese which decrease stck  
```

# Implementation

* [c++11](a.cpp)
* [java8](Solution.java)

# Complexity

```
O(2^N) O(N)
```
