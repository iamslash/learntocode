# Abstract

**range caching** 은 영역의 값을 어딘가에 저장해 두고 이용하는 것을 말한다. 모든
영역들이 적용된 배열을 단 한번의 순회로 구할 수 있다.

# range caching 1 Dimension Array

일차원 배열 `A[]`, 이차원 배열 `queries[][]` 가 주어진다. `queries[i] = [b, e]` 
이다. `A[]` 의 `queries[][]` 영역을 1 씩 증가하자. `A[]` 에 `queries[][]`
를 적용한 `A[]` 를 구해보자.

`A[]` 를 `queries[][]` 만큼 모두 순회하여 `A[]` 를 구할 수도 있다. 더욱 효율적인 
방법을 찾아보자. 더하고 싶은 영역을 어딘가에 저장해 놓고 마지막에 한번 `A[]` 를 순회하여
`queries[][]` 가 적용된 `A[]` 를 구할 수 있다. 

예를 들어 `A[] = [0, 0, 0, 0, 0], queries = [[0,3],[2,4]]` 의 경우를 살펴보자. 

```
           Naive    Range Caching
    A: 0 0 0 0 0    0 0 0 0 0
[0,3]: 1 1 1 1 0    1 0 0 0 -
[2,4]: 1 1 2 2 1    1 0 1 0 - -
    A: 1 1 2 2 1    1 1 2 2 1
```

따라서 답은 `[1, 1, 2, 2, 1]` 이다.

# range caching 2 Dimension Array

* [L](/leetcode3/IncrementSubmatricesbyOne/README.md) | [Increment Submatrices by One](https://leetcode.com/problems/increment-submatrices-by-one/)
