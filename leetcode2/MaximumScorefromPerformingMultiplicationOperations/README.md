# Problem

> [Maximum Score from Performing Multiplication Operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/)

수열 `nums[], mults[]` 가 주어진다. 처음 `prod = 0` 가 주어진다.
`len(mults)` 만큼 다음과 같은 동작을 수행한다.

> * `i` 번째 동작이라고 해보자. `nums[]` 의 양끝 숫자중 하나 고르고
> 그것을 `mults[i]` 에 곱하여 `prod` 에 더한다.

`prod` 가 최대가 되도록 `nums[]` 의 숫자를 골라보자. 그리고 그때의
`prod` 를 구하라.

# Idea

모두 해보고 중복되는 것은 캐시를 이용한다. 전형적인 dynamic
programming 이다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```
dfs(l, i)

return: prod of given arguments
     l: the left index of nums[]
     i: the index of mults[]
```

`C[len(mults)][len(mults)]` 를 선언하여 `dfs(l, i)` 에 대해
memoization 한다. `prod < 0` 이므로 `C[][]` 의 처음값은 
음수의 최소값 혹은 `None` 을 사용해야 한다.

`l, r` 를 선언하여 이번에 선택할 후보의 인덱스를 저장하자. 즉,
`nums[]` 의 왼쪽 끝 혹은 오른쪽 끝의 인덱스를 저장하자. `i` 는
`mults[]` 의 인덱스이고 `nums[]` 의 숫자를 하나 선택할 때마다 하나씩
증가한다. 

이때 `i` 는 항상 증가하지만 `l` 은 증가할 수도 있고 그렇지 않을 수도
있다. 즉, `l < i` 임이 보장된다.

`l` 과 `i` 를 알면 `r` 를 구할 수 있다. 혹은 `l, r` 을 알면 `i` 를
구할 수도 있다.

```
         l
 nums: 0 1 2 3 4
             r
mults: 1 2 3 4 5
           i
         
    r: len(nums) - 1 - (i - l)
```

# Implementation

* [c++11](a.cpp)
* [python3](a.py)

# Complexity

```
O(M^2) O(M^2)
```
