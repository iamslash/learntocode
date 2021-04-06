# Abstract

완전 탐색의 방법으로 접근할때 새로운 `search space` 를 탐색하고 다시 이전
`search space` 로 돌아가서 새로운 `search space` 를 탐색하는 방법이다. 주로
`recursion` 전에 상태를 바꾸고 `recursion` 후에 상태를 원래대로 복원하는 방법을
사용한다.

또한 `best`, `comb` 를 member variable 로 선언하고 후보자인 `comb` 를
교체해가면서 DFS 를 수행한다. 가장 적당한 후보자 `comb` 를 발견하면 `best` 에
assign 하고 탐색를 종료한다.

[backtracking on TSP](/algospot/TSP2/README.md#backtracking) 은 Traveling sales
person 문제를 backtracking 을 사용하여 해결한다.
