# Problem

> [Maximum Average Pass Ratio](https://leetcode.com/problems/maximum-average-pass-ratio/)

클래스의 모음 `classes[][]`, 숫자 `extraStudents` 가 주어진다.
`len(classes)` 만큼의 시험이 있다. `classes[i][0], classes[i][1]` 은
각각 `i-th` 시험을 통과한 학생수와 `i-th` 시험을 치른 학생수를
의미한다.  `i-th` 시험의 합격률은 `classes[i][0]/classes[i][1]` 과
같다.

`classes[][]` 에 포함된 학생들숫자에 `extraStudens` 만큼의 학생을 추가하여
합격률이 최대가 되도록 해보자. 그때의 평균 합격률을 구하라.

`extraStudens` 의 학생들을 한명 씩 분리해서 추가할 수 있다는 점을 주의하자.

# Idea

예를 들어 `classes = [[1,2],[3,5],[2,2]], extraStudents = 2` 의 경우를 살펴보자.

```
3/4 + 3/5 + 2/2 = 0.78333
```

따라서 답은 0.78333 이다.

한명이 추가되었을 때 합격률의 이익은 다음과 같이 계산한다.

```
profit = classes[i][0] + 1 / classes[i][1] + 1 - classes[i][0] / classes[i][1]
```

`classes[]` 를 `profit` 의 내림차순으로 정렬하고 `profit` 이 가장 높은
시험에 학생 하나를 더하는 식으로 생각해 보자. priority queue 를
이용하여 해결할 만 하다.

다음과 같은 변수를 선언한다.

> * `maxheap`: `profit, accepted student, total student` 를 저장한다.

`classes[]` 를 순회하면서 `maxheap` 에 `(-profit(a,b), a, b)` 를
저장한다.

`range(extraStudents)` 동안 다음을 반복한다.

> * 가장 profit 이 큰 시험을 가져온다. 즉, `c, a, b =
>   heap.heappop(maxheap)` 를 수행한다.
> * 추가학생을 한명 포함시킨 시험을 다시 삽입한다. 즉,
>   `heapq.heappush(maxheap, (-profit(a+1,b+1), a+1, a+1)` 를
>   수행한다.

모든 반복을 마치면 평균 합격률을 계산하여 리턴한다. 즉, `sum(a/b for
c, a, b in maxheap) / len(maxheap)` 를 리턴한다.

# Implementation

* [python3](a.py)

# Complexity

```
O(NlgN) O(N)
```
