# Problem

> [Minimum Sideway Jumps](https://leetcode.com/problems/minimum-sideway-jumps/)

숫자의 모음 `obstacles[]` 가 주어진다. `[1..3]` 만큼의 lane 이 있고
`obstacles.length` 만큼의 point 가 있다.  개구리는 `2` lane, `0` point
에서 출발한다. `obstacles[i]` 는 `i` point 에서 장애물이 존재하는 lane
을 의미한다.

개구리는 자신의 위치에서 오른쪽에 장애물이 없으면 jump 할 수
있다. 그렇지 않으면 다른 lane 으로 점프하고 side jump 를
증가한다. 마지막 point 까지 도착했을 때 최소 side jump 를 구하라.

# Idea

iterative dynamic programming 으로 해결할 만하다.

캐시 `int[] C = new int[]{1,0,1}` 를 선언한다. `C[i]` 는 `i` point
에서 minimum side jump 를 의미한다. 개구리는 `2` lane, `0` point 에서
출발하기 때문에 `C[1] == 0` 이다.

obs 로 `obstacles` 를 순회하면서 다음을 반복한다. 

* `obs > 0` 이면 `obs` lane 에 장애물이 있다는 의미이다. `C[obs-1]` 에 아주
  큰 값을 저장하자. 즉, `C[obs-1] = 1000000` 을 수행한다.
* 인덱스 `i` 를 `[0..3)` 동안 순회하면서 다음을 반복한다. 
  * `obs != i + 1` 이면 `i+1` lane 에 장애물이 없다는 의미이다. `C[i]` 에 `min(C[i], C[(i+1)%3], C[(i+2)%3])` 를 저장한다.
  
모든 반복을 마치면 `min(C[0], C[1], C[2])` 가 곧 답이다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
