# Problem

[Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/)

# Idea

문자열 `expr` 이 주어진다. brace expansion rule 이 적용된 문자열의
모음을 구하는 문제이다. 이때 결과 문자열들은 중복되지 않는다. brace
expansion rule 은 [Brace Expansion
II](https://leetcode.com/problems/brace-expansion-ii/) 를 참고한다.

* Single letters represent a singleton set containing that word.
  * R("a") = {"a"}
  * R("w") = {"w"}
* When we take a comma delimited list of 2 or more expressions, we
  take the union of possibilities.
  * R("{a,b,c}") = {"a","b","c"}
  * R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only
    contains each word at most once)
* When we concatenate two expressions, we take the set of possible
  concatenations between two words where the first word comes from the
  first expression and the second word comes from the second
  expression.
  * R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
  * R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh",
    "acdfg", "acdfh", "acefg", "acefh"}

다음과 같은 몇 가지 규칙들을 생각해 볼 수 있다.

* `b,c` 경우 결과는 `[b, c]` 이다. `a` 에 `b` 를 addrange 한 것이다.
* `{b,c}` 의 경우 결과는 `[b, c]` 이다. 역시 `a` 에 `b` 를 addrange 한 것이다.
* `a{b,c}` 의 경우 결과는 `[ab, ac]` 이다. `[a]` 에 `[b, c]` 를 crossjoin 한 것이다.
* `a{b}` 의 경우 결과는 `[ab]` 이다. `[a]` 에 `[b]` 를 crossjoin 한 것이다.
* `{a}{b}` 의 경우 결과는 `[ab]` 이다. `[a]` 에 `[b]` 를 crossjoin 한 것이다.

예를 들어 `expr = "{a,b}{c,{d,e}}"` 일 때 처리되는 과정은 다음과
같다. `{}` 가 addrange 혹은 crossjoin 으로 해결되면 `[]` 으로 바꾼다.

```
{a,b}{c,{d,e}}
{a,b}{c,[d,e]}
{a,b}[c,d,e]
[ac,ad,ae,bc,bd,be]
```

이번에는 다른 예 `expr = {{a,z},a{b,c},{ab,z}}` 의 처리과정을 살펴보자.

```
{{a,z},a{b,c},{ab,z}}
{[a,z],a[b,c],[ab,z]}
{[a,z],[ab,ac],[ab,z]}
[a,z,ab,ac,ab,z]
[a,ab,ac,z]
```

다음과 같이 부분문제 3 가지를 정의하고 재귀적으로 해결한다.

```c
unodered_set<string> dfs(string &expr, int &i)
void addrange(unordered_set<string> &a, unordered_set<string> &b)
void crossjoin(unordered_set<string> &a, unordered_set<string> &b)
```

`dfs` 는 다음과 같은 구조를 갖는다. 한 문자씩 fetch 해 와서 그 값에
따라 처리하는 방식이다. FSM (Finite State Machine) 이라 할 만 하다.

```cpp
unordered_set<string> dfs(string &expr, int &i) {
  unordered_set<string> ans;
  while(i < expr.size()) {
    char c = expr[i];
    if (c == ',') {
    } else if (c == '{') {
    } else if (c == '}') {
    } else {
    }
  }
  return ans;
}
```

예를 들어 `expr = {a,b}{c,{d,e}}` 의 경우 몇가지 사항을 고려하면 dfs
를 쉽게 구현할 수 있다.

* `dfs(expr, 0)`
  * `ans = []` 이고 `dfs(expr, 1) = [a,b]` 와 crossjoin 한다. 곧, `ans = [a,b]` 이다.
* `dfs(expr, 5)`
  * `ans = [a,b]` 이고 `dfs(expr, 6) = [c,d,e]` 와 crossjoin
    한다. 곧, `ans = [ac,ad,ae,bc,bd,be]` 이다.
* `dfs(expr, 1)` 
  * `ans = []` 이고 `dfs(expr, 2) = [a]` 와 crossjoin 한다. 곧, `ans =
    [a]` 이다.
* `dfs(expr, 2)`
  * `ans = [a]` 이고 `dfs(expr, 3) = [b]` 와 addrange 한다. 곧, `ans =
    [a,b]` 이다.
  
# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
