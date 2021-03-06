# Problem

[Kth Smallest Instructions](https://leetcode.com/problems/kth-smallest-instructions/)

수열 `A[]` 와 숫자 `k` 가 주어진다. `M[0][0]` 에서 `M[A[0]][A[1]]`
까지 길찾기를 한다. 오른쪽 혹은 아래로만 이동할 수 있다. 오른쪽 이동은
`H` 로 표기하고 아래쪽 이동은 `V` 로 표기한다. 모든 경우의 이동 경로를
문자열로 표기할 수 있다. 사전순으로 `k` 번 째 경로(1-based)를 구하라.

# Idea

`int v = A[0], h = A[v]` 를 선언한다. `M[0][0]` 에서 `M[v][h]` 까지
만들 수 있는 모든 경로의 수를 생각해 보자. `v + h + 1` 의 슬롯에서 `v`
개의 `V` 를 배치하고 나머지 슬롯은 `h` 개의 `H` 로 채우는 방법과 같다.
즉, `(v+h+1)Cv` 와 같다.

`nCr` 은 [combination @
learntocode](/doc/dynamic_binomial_coefficient.md) 를 참고하여
구현한다.

`H` 가 `V` 보다 사전순으로 앞이다. `HHVV` 는 `HVHV` 보다 사전순으로
앞이다. `A = [2,2]` 인 경우 경로의 길이는 4 이고 가장 사전순으로 앞인
경로는 `HHVV` 이다. `H` 를 `V` 보다 먼저 사용한 것에 유의하자.

`v, h` 를 줄여가며 탐색한다. `v == 0 && h == 0` 이면 답이 완성된다.
이것은 `k` 를 줄여가며 탐색하는 것과 같다.

`int n = h + v` 를 선언한다. 인덱스 `i` 를 `[0..n)` 동안 순회하며
다음을 반복한다.

* `h > 0` 이면 `int c` 를 선언하고 `(h+v+1)Cv` 를 저장한다.
  * `k <= c` 이면 `c` 개수 안에 `k` 가 존재한다. `H` 를 `s` 에
    추가하고 `h` 를 하나 감소한다. `V` 를 추가한 것은 아니기 때문에 `k`
    는 줄어들 필요가 없다.
  * `k > c` 이면 `c` 개수는 `k` 에서 제거할 수 있다. `k` 에서 `c` 를
    제거한다. `V` 를 `s` 에 추가하고 `v` 를 하나 감소한다.
* `h <= 0` 이면 가능한 `H` 는 없다. `V` 만 가능하다. `s += 'V'`, `--v`
  를 수행한다.

모든 반복을 마치면 `s` 가 답이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N^2) O(1)
```
