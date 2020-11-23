# Problem

[Number of Ways to Form a Target String Given a Dictionary](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

문자열의 모음 `words[]` 와 문자열 `target` 이 주어진다. 

# Recursive Dynamic Programming

## Idea

예를 들어 다음과 같은 경우를 살펴보자.

```
 words:
        a c c a
        b b b b 
        c a c a
target: a b a

0 (acca) 1 (bbbb) 3 (caca)
```

따라서 답은 6 이다.

`C[n][m]` 을 선언한다. `n` 은 `words[0]` 의 길이다. `m` 은 `target` 의
길이이다. `freqs[m][26]` 을 선언한다. `words[i]` 의 문자별 발생횟수를
`freqs[j]` 에 저장한다.

다음과 같은 부분문제 `dfs` 를 정의한다.

```
int dfs(C, freqs, target, i, j)

 return: total count
  freqs: frequencies for words
 target: one of inputs
      i: index of word
      j: index of target
```

모든 경우의 수를 고려해 보자. 경우의 수를 고려할 때 word[i] 를 포함할 것인가
포함하지 않을 것인가가 중요하다.

```
r += dfs(C, freqs, target, i+1, j)
r += freqs[i][j] * dfs(C, freqs, target, i+1, j+1)
```

## Implementation

* [c++11](recursive.cpp)

## Complexity

```
O(WT) O(WT)
```

# Iterative Dynamic Programming

## Idea

## Implementation

* [c++11](iterative.cpp)

## Complexity

```
```
