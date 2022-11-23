# Problem

[Minimum Fuel Cost to Report to the Capital](https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/)

이차원 배열 `roads[][]`, 숫자 `seats` 가 주어진다.  `roads[i][0],
roads[i][1]` 을 간선으로 하는 그래프가 존재한다.  그래프는
트리이다. 즉, 다음과 같은 특성을 갖는다.

* connected
* undirected
* no cycles

`seats` 만큼의 좌석을 갖는 자동차가 있다. 각 노드에는 사람이 한명씩
있다. 모든 노드에서 `0` 으로 사람들을 자동차로 이동시키자. 노드를
하나 이동하는데 1 fuel 이 소모된다. 모든 사람들을 `0` 노드로
이동하는데 소모되는 최소비용은 얼마인가?

# Idea

예를 들어 `roads = [[0,1],[1,2],[2,3]], seats = 5` 의 
경우를 살펴보자.

```
      0
     /
    1 (+1)
   /
  2 (+1)
 /
3 (+1)
```

따라서 답은 3 이다.

예를 들어 `roads = [[0,1],[1,2],[2,3]], seats = 2` 의 
경우를 살펴보자.

```
      0
     /
    1 (+2)
   /
  2 (+1)
 /
3 (+1)
```

따라서 답은 4 이다.

각 노드별로 부모 노드로 향할 때 필요한 비용을 답에 더해야 한다.  이때
필요한 비용은 다음과 같이 구한다. 사람들의 숫자를 좌석수로 나눈 것의
천장값이 필요하다.

```
ans += (people + seats - 1) / seats

   ans: 답
people: leaf node 에서 해당 node 까지 사람의 합
 seats: 자동차의 좌석수
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
