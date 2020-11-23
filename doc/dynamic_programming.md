# Abstract

- 동적 계획법에 대해 적어본다.

# 유용한 개념들

* overlapping subproblems
  * 중복되는 부분문제를 overlapping suproblems 이라고 한다. 캐시를 이용해 최적화 할 수 있다.

* optimal substructure

  * 어떤 문제가 부분문제로 나누어지고 그 부분문제는 다시 그 부분문제를 이용해서 최적의
  해결책을 찾을 수 있다면 그 문제는 optimal substructure 를 가지고 있다고 한다.
  * [TRIANGLEPATH @ algospot](https://algospot.com/judge/problem/read/TRIANGLEPATH) 처럼
  부분문제의 최대값을 취하는 방법으로 최적의 해결책을 갖는 형태의 문제가 해당된다.
  * [optimal substructure @ wikipedia](https://en.wikipedia.org/wiki/Optimal_substructure)
  * [dynamic programming @ wikipedia](https://en.wikipedia.org/wiki/Dynamic_programming)

* markov chain
  * 어떤 한 실험을 반복하는데 각 실험에서의 결과는 오직 바로 직전의
  실험결과에서만 영향을 받는 것을 markov chain 혹은 markov process 라고
  한다. 오늘 내가 담배피면, 내일 담배 필 확률이 `0.8`, 내일 안 필 확률이
  `0.2` 오늘 내가 담배 안 피면, 내일 담배 필 확률이 `0.5`, 내일 안 필
  확률이 `0.5` 라고 하자. 언급한 예처럼 임의 결과가 바로 전의 결과에만 영향을 받는 것을
  말한다.
  * 또한 다음과 같은 특징을 갖는 모델 역시 markov chain 에 해당한다.
  첫째 유한개의 상태가 있다. 둘째 매 시간마다
  상태가 변경된다. 셋째 어떤 상태 a 에서 다른 상태 b 로
  이동할 확률은 현재 상태 a 에 의해 좌우된다. a 이전에
  어느 상태에 있었는지, 현재 시간은 얼마인지 등은 영향을 주지 않는다.
  * [NUMB3RS @ algospot](https://algospot.com/judge/problem/read/NUMB3RS) 는 markov chain 의 대표적인 예이다.

# 유용한 문제의 유형들

- bitmask
- tree dynamic programming
- 왼쪽 오른쪽을 왔다 갔다 하면서 푸는 동적 계획법
- 점화식을 통해서 정답을 역추적하는 방법
- probability dynamic programming
- 왼쪽과 오른쪽에서 시작해서 가운데로 모이는 dynamic programming
- 기대값 DP
- dynamic programming optimization
  - knuth optimization
  - divide & conquer optimization
  - convex hull optimization
