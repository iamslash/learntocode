# Problem

[K Empty Slots](https://leetcode.com/problems/k-empty-slots/)

`pos[]` 와 숫자 `k` 가 주어진다. `pos[d] = i` 는 `d` 날짜에 `i` 위치의
전구가 켜진다는 의미이다. 두개의 전구가 켜질 때 그사이에 켜지지 않은 전구가
`k` 개 있을 때의 최소 날짜를 구하라.

# Idea

예를 들어 `bulbs = [1,3,2], k = 1` 의 경우를 살펴보자.

`days[]` 를 선언하여 전구가 켜지는 날짜 (1-indexed) 를 저장해보자.
`k` 만큼 연속되게 꺼진 전구가 발견된 날짜를 구해야 한다. `k` 크기의
sliding window 를 만들어 이동한다. sliding window 를 이동하면서
`k` 만큼 연속되게 꺼진 전구가 발견된 날짜중 가장 빠른 날짜를 구한다.

```
bulbs: 1 3 2
       l   r
 days: 1 3 2
         i
```

따라서 답은 `2` 이다.

다음과 같은 변수들을 선언한다.

> * `pos2day[]` 를 선언하여 위치별 켜지는 날짜를 저장한다.
> * `n = len(pos)` 를 선언하여 날짜의 크기를 저장한다.
> * `l = 0` 은 sliding window 의 시작 인덱스이다.
> * `r = k+1` 은 sliding window 의 끝 인덱스이다.
> * `i = 1` 를 선언하여 `days[]` 를 순회한다.
> * `minday = n+1` 를 선언하여 답을 저장한다.

이제 `r < n` 동안 다음을 반복한다.

> * `pos2day[i] < pos2day[l] or pos2day[i] <= pos2day[r]` 이면 `l` 과
>   `r` 사이에 이미 켜진 전구가 있다는 의미이다. minday 를
>   업데이트하고 sliding window 를 움직여야 한다.
>   * `i == r` 이면 `minday` 를 업데이트 한다. 즉, `min(minday,
>     max(pos2day[l], pos2day[r]))` 를 수행한다. 참고로 날짜는 distinct 하다.
>     따라서 sliding window 를 움직일 때 최소날짜를 업데이트하는 것이 효율적이다.
>   * `l = i` 를 수행한다.
>   * `r = l + k + 1` 를 수행한다.
> * `i` 를 하나 증가한다.

모든 반복을 마치고 `mindeay == n + 1` 이면 `-1` 를 리턴한다. 그렇지
않으면 `minday` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [py3](a.py)

# Complexity

```
O(N) O(N)
```
