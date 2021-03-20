# Problem

> [Cracking the Safe @ leetcode](https://leetcode.com/problems/cracking-the-safe/)

숫자 `N` 과 `K` 가 주어진다. 암호의 자리수는 `N` 개이고 암호를
구성하는 숫자하나는 `0..K-1` 중 하나가 가능하다. 임의의 문자열을
차례대로 입력한다. 마지막 도달하면 다시 처음부터 입력한다. 이때 암호에
해당하는 문자열이 발견되었을 때 상자를 열 수 있다. `N` 과 `K` 조건을
만족하면서 어떠한 암호도 풀 수 있는 최소 길이의 문자열을 구하라.

# References

* [De Bruijn sequence | Set 1 @ geeksforgeeks](https://www.geeksforgeeks.org/de-bruijn-sequence-set-1/)
* [De Bruijn sequence](https://en.wikipedia.org/wiki/De_Bruijn_sequence)

# Idea

예를 들어 `N=2, K=2` 이라고 해보자. 암호는 두자리이고 암호 숫자는 `[0..1]` 중
하나이다. 가능한 암호는 `00, 01, 10, 11` 이다. 따라서 `00011011` 은 답이 될 수
있다. 그러나 `00110` 또한 답이 될 수 있다.

```
password: 00
     seq: 00110

password:  01
     seq: 00110

password:    10
     seq: 00110

password:   11
     seq: 00110
     
Why 0100 can not be an answer???     
password:    0 0
     seq: 0110 0110     
```

이러한 방법으로 만들어진 문자열을 [De Bruijn
sequence](https://en.wikipedia.org/wiki/De_Bruijn_sequence) 이라고
한다.

"a de Bruijn sequence of order n on a size-k alphabet A is a cyclic
sequence in which every possible length-n string on A occurs exactly
once as a substring".

"The de Bruijn sequences can be constructed by taking a Hamiltonian
path of an n-dimensional de Bruijn graph over k symbols (or
equivalently, an Eulerian cycle of an (n - 1) - dimensional de Bruijn
graph)."

De Bruijn sequence 는 특수한 directed graph 를 제작하고
[euleriancircuit](/fundamentals/graph/euleriancircuit/README.md) 을 이용하여
만들 수 있다. 그 그래프는 `K^(N-1)` 개의 node 와 각 node 별로 out degree 가 2 인
`K^(N-1)*K = K^N` 개의 edge 로 구성된 directed graph 이다. 이 그래프의 eulerian
circuit 을 따라 간선의 문자들과 첫번째 노드의 문자열을 이어 붙이면 그것이 De
Bruijn sequence 와 같다.

예를 들어 `N = 2, K = 2` 일 때의 방향 그래프와 De Bruijn sequence 는 다음과 같다.

![](n_2_k_2_directed_graph.png)

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(K^N) O(N)
```
