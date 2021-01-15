# Abstract 

- 완전 탐색 알고리즘으로 문제를 해결할 때 주로 재귀호출을 이용해서 선택지를
  채워가는 형태로 구현한다. 이때 부분 답과 완성된 답의 집합을 `search space (탐색공간)`
  이라고 한다. 예를 들어 `TSP (traveling salesman problem)` 에서 `search space` 의 한 원소는 지금까지 방문한
  정점의 목록과 현재 위치로 구성된다. 
- 일반적으로 굉장히 크지만 유한한 탐색공간을 효율적으로 뒤지면서 답을 찾아내는 알고리즘을
  `combinatorial search (조합탐색)` 이라고 한다. `combinatorial search` 는 탐색공간을 줄이거나 휴리스틱을 동원하여 효율적으로 해결한다. 여러가지 알고리즘들이 조합되어 사용된다라는 의미일까?

# Reference

- [combinatorial search @ wikipedia](https://en.wikipedia.org/wiki/Combinatorial_search)
- [artificial intelligence: a modern approach by stuart russel, peter norvig](https://www.amazon.com/Artificial-Intelligence-Approach-Stuart-Russell/dp/1292024208/ref=mt_paperback?_encoding=UTF8&me=)
  - combinatorial search 를 잘 설명한 인공지능 교과서이다. java, python 소스가 제공된다.

# 유용한 개념들

* backtracking

  * `best`, `comb` 를 member variable 로 선언하고 recursion 을 이용해서 구현한다.
  * 완전 탐색의 방법으로 접근할때 새로운 `search space` 를 탐색하고 다시 이전
    `search space` 로 돌아가서 새로운 `search space` 를 탐색하는 방법이다. 주로
    `recursion` 전에 상태를 바꾸고 `recursion` 후에 상태를 원래대로 복원하는
    방법을 사용한다.
  * [backtracking on TSP](/algospot/TSP2/README.md#backtracking) 은 Traveling
    sales person 문제를 backtracking 을 사용하여 해결하는 방법에 관해 설명한다.

* heuristic

  * heuristic 은 '찾아내다', '발견하다'는 뜻의 그리스 말에 뿌리를 두고
  있는 말이다. 불확실하고 복잡한 문제를 가능한 빨리 풀기 위해 쓰는
  주먹구구식 셈법이나 직관적 판단, 경험과 상식에 바탕을 둔 단순하고
  즉흥적인 추론을 뜻한다.
  * heuristic 은 빨리 해결하기 위해 대충 때려맞추는 방법이다. 대충이기 때문에
  항상 최적의 해를 찾을 수는 없다. 하지만 제약적인 상황에서 적당히 만족하는
  해를 찾을 수 있다.
  * 학교에서 선생님이 100 명의 아이들을 데리고 소풍을 가서 점심값을
  계산할때 현금을 얼만큼 지갑에서 꺼내야할지 고민하는 경우를
  생각해보자. 다음 스케줄이 많아서 주어진 시간이 부족하여 재빨리
  해결하고 싶다.  실제 액수보다 적게 꺼냈다면 한번 더 지갑을 뒤지는
  수고를 해야한다. 아이들이 먹는 음식들을 대충 눈으로 스캔하고
  한사람당 만원이라는 판단을 해서 100 명을 곱한다.  한사람당 만원이면
  잔돈이 남을 것이라고 확신한다. 그야 말로 대충 때려 맞추는 방법이다.
  시간이 부족한 상황에서 적당히 만족하는 방법이다.

* metaheuristic
  
  * 휴리스틱을 찾아내는 방법이다.
  * metaheuristic algorithm 은 optimization algorithm 의 한 종류이다.
  일반적인 optimization algorithm 은 목적 함수를 미분할 수 있다는 가정을 
  사용한다. 그러나 metaheuristic 은 그러한 가정을 하지 않기 때문에
  프로그래밍 대회에서 종종 사용된다.
  * metaheuristic 은 종류가 매우 많지만 local search(국소탐색) 이나 
  simulated annealing (시뮬레이티드 어닐링) 이 구현과 튜닝이 가장 
  간단해서 자주 쓰인다.
  * [metaheuristic @ wikipedia](https://en.wikipedia.org/wiki/Metaheuristic)  

* CSP (constrained satisfaction problem)

  * 복수의 제약 조건을 충족하는 상태를 찾아내는 수학 문제이다.
  * 주로 combinatorial search 로 해결한다. 이때 `contraint propagation (제약조건전파)` 와
  `variable, value ordering (변수,값 순서 정하기)` 가 중요한다.
  * [NQUEEN @ learntocode](/algospot/NQUEEN/README.md),
  [KAKURO2 @ learntocode](/algospot/KAKURO2/README.md), map coloring problem, [sudoku @ learntocode](/fundamentals/combinatorialsearch/sudoku/README.md),
  crosswrods, futoshiki, numbrix, hidato 등이 해당된다. 
  * [Constraint satisfaction problem @ wikipedia](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem)
  * [Constraint Satisfaction, An Introduction @ youtube](https://www.youtube.com/watch?v=wrs6Lvo5LZM) 
   