# Problem

* [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/)

# Idea

`N` 쌍의 `[0..2N-1]` 수열이 주어진다. `2n, 2n+1` 을 한쌍으로 하고
수열의 숫자는 섞여있다고 하자. 숫자들을 최소한으로 이동하여 수열의
모든 숫자들이 쌍을 이루도록 하는 문제이다.

몇가지 규칙을 발견할 수 있다. 한쌍을 이루는 두개의 숫자중 작은 것은
짝수이다. 그리고 두개의 숫자를 2 로 나누었을 때 몫이 같다. 예를 들어
`4, 5` 의 경우 2 로 나누면 몫이 `2` 이다.

이 문제는 이렇게 뒤집어 생각할 수 있다. 하나의 숫자가 두개씩 존재하는
수열이 있다고 하자. 그것의 영역은 `[0..N-1]` 이다. 같은 숫자 두개를
한 쌍으로 하고 수열의 숫자는 섞여있다고 하자. 숫자들을 최소한으로
이동하여 수열의 모든 숫자들이 쌍을 이루도록 해보자. 쌍을 이루지 못한
두개의 쌍에서 각각의 숫자를 이동하여 쌍을 이룬다면 1 번 이동했다고
생각하자.

[DisjointSet](/fundamentals/disjointset/unionfind/README.md) 를
이용하면 쉽게 해결할 수 있다. 수열을 처음부터 두개씩 순히화면서
`DisjointSet` 를 이용해서 merge 를 수행한다. merge 가 수행된 횟수가 곧
답이다.

예를 들어 다음과 같이 수열 `A = 0 0 1 1` 을 생각해보자. merge 는
수행되지 않는다. 그러나 수열 `A = 0 1 1 0` 을 생각해보자. `0 1` 은
merge 가 수행되지만 `1 0` 은 이미 처리되었으므로 merge 가 수행되지
않는다. [DisjointSet](/fundamentals/disjointset/unionfind/README.md)
이 이 문제에 매우 유용함을 알 수 있다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
