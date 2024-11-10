# Problem

수열 `V` 가 주어지면 오름차순으로 정렬하는 문제이다.

# References

* [Mergesort.java | sedgwick](https://algs4.cs.princeton.edu/14analysis/Mergesort.java.html)
* [merge sort | sedgwick](https://algs4.cs.princeton.edu/22mergesort/)

# Idea

Divide and Conquer 전략을 이용한다. 수열을 두부분으로 나누고 왼쪽과 오른쪽을 재귀적으로 병합정렬한 후 두 수열을 잘 병합하면 전체 수열을 정렬하게 된다.  예를 들어 `1 7 4 0 9 4 8 8 2 4` 와 같은 수열이 있다고 하자. 수열을 분할 하면 왼쪽은 `1 7 4 0 9` 이고 오른쪽은 `4 8 8 2 4` 이다. 두 수열이 병합정렬에 의해 정렬되었다면 각각 `0 1 4 7 9`, `2 4 4 8 8` 이 된다. 두 수열을 왼쪽부터 오른쪽으로 각각 순회하면서 하나로 병합하면 `0 1 2 4 4 4 7 8 8 9` 가 된다. 


`dfs(beg, end)` 를 선언하여 나누고 합치는 것을 구현한다. `beg, end` 는 리스트의 시작, 끝 index 이다. 다음은 앞서 언급한 수열을 병합정렬하는 과정이다.

```c
1 7 4 0 9 4 8 8 2 4

dfs(0,9)| 1 7 4 0 9 4 8 8 2 4
  dfs(0,4) | 1 7 4 0 9
    dfs(0,2) | 1 7 4
      dfs(0,1) | 1 7
      dfs(2,2) | 4
    dfs(3,4) | 0 9
      dfs(3,3) | 0
      dfs(4,4) | 9
  dfs(5,9) | 4 8 8 2 4
    dfs(5,7) | 4 8 8
      dfs(5,6) | 4 8
      dfs(7,7) | 8
    dfs(8,9) | 2 4
      dfs(8,8) | 2
      dfs(9,9) | 4

0 1 2 4 4 4 7 8 8 9
```

리스트의 모든 노드를 방문하는 것은 `N` 만큼의 비용이 필요하다. 모든 노드를 방문하는 것을 `lgN` 만큼 수행한다. 따라서 시간복잡도는 `O(NlgN)` 이다.

```c
1.
dfs(0,9)| 1 7 4 0 9 4 8 8 2 4

2.
  dfs(0,4) | 1 7 4 0 9
  dfs(5,9) | 4 8 8 2 4

3.
    dfs(0,2) | 1 7 4
    dfs(3,4) | 0 9
    dfs(5,7) | 4 8 8
    dfs(8,9) | 2 4

4.
      dfs(0,1) | 1 7
      dfs(2,2) | 4
      dfs(3,3) | 0
      dfs(4,4) | 9
      dfs(5,6) | 4 8
      dfs(7,7) | 8
      dfs(8,8) | 2
      dfs(9,9) | 4
```

`V[]` 는 정렬할 수열이다. `W[]` 는 merge 한 결과를 저장할 일차원 배열이다. merge 가 완료되면 `V[]` 에 `W[]` 를 merge 한 영역만큼 복사한다.

```c
void merge_sort(vector<int>& V) {
  vector<int> W = V;
  dfs(V, W, 0, V.size()-1);
}
void dfs(vector<int>& V, vector<int>& W, int l, int r) {
  // base
  if (l >= r)
    return;
  // recursion
  int m = (l+r)/2;
  dfs(V, W, l, m);
  dfs(V, W, m+1, r);
  merge(V, W, l, m, r);
}
void merge(vector<int>& V, vector<int>& W, int l, int m, int r) {
  // W[k] 에 하나씩 골라서 저장하기
  // W[k] 에 남은녀석 한번에 저장하기
  // V[l..r] 에 W[l..r] 복사하기
}
```

# Implementation

- [c++11](a.cpp)

# Complexity

```
O(NlgN) O(N)
```
