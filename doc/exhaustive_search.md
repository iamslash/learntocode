# Abstract

- 모든 경우를 다 시도해 보는 알고리즘이다. combinatorial search problem 을 만나면 첫번째로 시도해 볼 만하다. 
- [exhaustive search vs combinatorial search](/doc/combinatorial_search.md#combinatorial-search-vs-다른-탐색-기법) 참고

# 유용한 문제의 유형들

- permutation(순열)
- brute force(그냥 다 해보자)
- N중 for문을 이용하는 방법
- BFS
- backtracking
- bitmask를 이용해서 모든 경우를 다 해보자.
- 성능을 위해 일부 경우만 다 해보자.
- BFS with deque
- meet in the middle (search space가 너무 커서 문제의 크기를 절반으로
  나누어 풀자. 중간에서 만나는 알고리즘)
