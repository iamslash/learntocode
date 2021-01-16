# Problem

[Construct the Lexicographically Largest Valid Sequence](https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/)

숫자 `n` 이 주어진다. `2 * n - 1` 만큼의 배열 `ans[]` 를 만들자.  `1`
은 한번만 사용한다. 그 외의 숫자 `1 < k <= n` 은 2번씩 사용할 수 있다.
두 `k` 의 거리는 `k` 와 같도록 해보자.

가능한 `ans[]` 중 사전순으로 가장 큰 것을 구하라.

# Idea

[back tracking](/doc/backtracking.md) 으로 해결할 만 하다. 

`int[] ans = new boolean[2 * n - 1]` 을 선언하여 답을 저장한다. `boolean[] visit
= new boolean[2 * n - 1]` 을 선언하여 사용된 숫자들을 표시한다.

1 을 제외한 숫자 `k` 는 2 번 사용해야 한다. 또한 그 거리는 `k` 이어야 한다.
하나의 숫자 `k` 를 방문할 때 `k` 를 2 번 `ans[]` 에 저장해야 한다.

다음과 같은 부분문제 `dfs` 를 선언한다.

```c
boolean dfs(visit, ans, pos, n)

return: success of search space
 visit: pos is visited?
   ans: the answer
   pos: pos to visit
     n: input argument
```

`dfs` 를 다음과 같이 구현한다.

* `pos >= ans.length` 이면 탐색을 모두 마쳤다. `true` 를 리턴한다.
* `ans[pos] != 0` 이면 두번 째 방문이다. 계속 탐색한다. 즉, `dfs(visit, ans, pos+1, n)` 을 리턴한다.
* 인덱스 `i` 를 이용하여 `[n..0)` 만큼 순회하며 다음을 반복한다.
  * `visit[i] == ture` 이면 건너뛴다.
  * `visit[i] = true, ans[pos] = i` 를 수행한다.
  * `i == 1 && dfs(visit, ans, pos+1, n)` 이면 `true` 를 리턴한다.
  * `pos+i < ans.length && ans[pos+i] == 0` 이면 다음을 수행한다. 두번째 숫자를 방문할 수 있다. 
    * `ans[pos+i] = i` 를 수행한다.
    * `dfs(visit, ans, pos+1, i)` 이면 `true` 를 리턴한다.
    * `ans[pos+i] = 0` 을 수행한다.
* `ans[pos] = 0, visit[i] = false` 를 수행한다.

`false` 를 리턴한다.

# Implementation

* [java8](Solution.java)

# Complexity

```
O(N!) O(N)
```
