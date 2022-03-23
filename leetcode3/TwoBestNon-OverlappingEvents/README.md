# Problem

[Two Best Non-Overlapping Events](https://leetcode.com/problems/two-best-non-overlapping-events/)

수열의 모음 `events[]` 가 주어진다. `events[i].length == 3` 이고
앞에서 부터 다음과 같은 값을 갖는다.

* 이벤트의 시작시간
* 이벤트의 종료시간
* 이벤트의 점수

`events[]` 에서 겹치지 않는 이벤트를 2 개 고르자. 이때 합친 점수는 최대가
되도록 하자. 그 최대 점수를 구하라.

# Idea

예를 들어 `events = [[1,3,2],[4,5,2],[2,4,3]]` 의 경우를 살펴보자.

```
events: 1   3      --- 2
              4 5  --- 2
          2   4    --- 3
          
choose [1,3,2], [4,5,2]
``` 

따라서 답은 `4` 이다. 

다음과 같은 순서대로 풀이해 보자.

* `int ans = 0` 을 선언하여 답을 저장한다.
* `events[]` 를 이벤트의 시작시간, 종료시간의 오름차순으로 정렬한다.
* `Queue<int[]> pq = new PriorityQueue<>()` 를 선언한다. `[종료시간,
  점수]` 를 저장하도록 한다.
* `int maxPastVal = 0` 을 선언하여 `pq` 에서 발견한 최대 점수를 기록한다.
* `int[] evt` 로 `events[]` 를 순회하며 다음을 반복한다.
  * `evt[0]` 보다 먼저 끝나는 이벤트들을 `pq` 에서 뽑아내어
    `maxPastVal` 을 업데이트 한다. 
  * `evt[i]` 와 합칠 수 있고 점수가 최대인 후보자를 얻었으니 답을
    업데이트 한다. 즉, `ans = max(ans, evt[2] + maxPastVal)` 을 수행한다.
  * `evt[i]` 는 아직 `maxPastVal` 의 대상이 아니다. `pq` 에 삽입한다.  

모든 반복을 마치면 `ans` 가 곧 답이다.

`maxPastVal` 업데이트에 사용된 이벤트는 더이상 `pq` 에 남아있을 필요가
없음을 유의하자.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
