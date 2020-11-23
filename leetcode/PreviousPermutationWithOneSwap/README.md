# Problem

[Previous Permutation With One Swap](https://leetcode.com/problems/previous-permutation-with-one-swap/)

# References

* [How to find Lexicographically previous permutation? @ geeksforgeeks](https://www.geeksforgeeks.org/lexicographically-previous-permutation-in-c/)

# Idea

수열 `A[]` 가 주어진다. 단 한번의 자리 바꿈으로 이전 순열을 구하는
문제이다.

예를 들어서 `1 2 3` 의 순열을 구해보자.

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

`3 2 1` 에서 `3 1 2` 를 찾는 것과 같다. 위의 예를 통해서 다음과 같은 규칙을 
발견할 수 있다.

0. `int i = n - 2, j = n - 1`
1. Find largest index i such that str[i] > str[i+1].
2. Find largest index j such that j >= i and str[i] > str[j]
3. `str[j-1] == str[j]` 이면 `--j` 를 수행한다.
4. Swap str[j] and str[i].

다음은 `1 9 4 6 7` 의 풀이 과정이다.

```
  i
1 9 4 6 7
        j
1 7 4 6 9
```

다음은 `3 1 1 3` 의 풀이 과정이다. 같은 숫자가 등장하기 때문에 앞서
언급한 알고리즘의 3 번 과정이 중요하다.

```
i
3 1 1 3
  j
1 3 1 3
```

한편 `1 1 3 3` 의 순열을 살펴보면 `3 1 1 3` 의 이전 순열은 `1 3 1 3`
이 아니고 `1 3 3 1` 이다. 문제의 조건을 다시 살펴보면 단 한번의 자리
바꿈으로 이전 순열을 만들어야 한다. 그러나 `3 1 1 3` 에서 `1 3 3 1` 은
단 한번의 단 한번의 자리바꿈으로 만들 수 없다.

```
1 1 3 3
1 3 1 3
1 3 3 1
3 1 1 3
3 1 3 1
3 3 1 1
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```
