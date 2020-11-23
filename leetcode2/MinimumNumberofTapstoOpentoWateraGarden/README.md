# Problem

[Minimum Number of Taps to Open to Water a Garden](https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/)

숫자 `n` 과 수열 `R[]` 가 주어진다. 정원에 `R` 의 개수만큼의 스프링
쿨러가 있다. `R[i]` 는 `[i-R[i], i+R[i]]` 만큼의 영역에 물을 줄 수
있다.  `[0, n]` 영역을 모두 물을 주기 위해 필요한 스프링쿨러의 최소
개수를 구하는 문제이다.

# Idea

[Video Stretching](https://leetcode.com/problems/video-stitching/) 과
유사하다.

`vector<vector<int>> coolers` 를 선언하여 각 스프링 쿨러의 왼쪽 위치
오른쪽 위치를 저장한다. 그리고 시작시간의 오름차순으로 정렬한다.

`int beg = 0, end = 0` 를 선언하고 `coolers` 를 인덱스 `i` 를 이용하여
순회하면서 다음을 반복한다.

* `beg` 가 고정되었을 때 `end` 가 최대가 될 때까지 `i` 를 증가하면서
  `end` 를 전진한다.
* 만약 `beg == end` 이면 `end` 가 증가될 수 없기 때문에 `-1` 을
  리턴한다.
* `beg = end` 를 수행한다.

모든 반복을 마치면 `ans` 가 답이다.

다음은 `n = 5, R = [3, 4, 1, 1, 0, 0]` 의 풀이과정이다.

```
     n: 5
     R: 3 4 1 1 0 0
cooler: [-1, 1], [-1, 1], [0, 2], [0, 2], [2, 4], [3, 5]

       -1 0         5
        . . . . . . .
        _____________ [-1, 1]
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(NlgN) o(N)
```
