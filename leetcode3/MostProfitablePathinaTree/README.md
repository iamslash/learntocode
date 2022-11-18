# Problem

[Most Profitable Path in a Tree](https://leetcode.com/problems/most-profitable-path-in-a-tree/)

이차원 배열 `edges[][]`, 숫자 `bob`, 일차원 배열 `amounts[]` 가
주어진다.  `edges[i][0]` 과 `edges[i][1]` 는 Tree 의 Node 가
연결되었음을 의미한다. `bob` 은 `bob` 이 출발하는 Node 를 의미한다.
`amounts[i]` 는 `i-th` Node 의 profit 을 의미한다.

`0-th` Node 에서 Alice 가 출발한다. Node 를 지날 때 profit 을
획득한다. 누적된 profit 이 최대가 되는 leaf Node 까지 이동한다.  Bob
은 `bob` Node 에서 `0-th` 로 이동한다. 

Alice 혹은 Bob 중 누구든지 Node 를 지나가면 amount 는 0 이 된다. Alice
와 Bob 이 만나면 그 Node 의 amount 를 절반씩 profit 으로 가져간다.

Alice 가 획득할 수 있는 max profit 을 구하라.

# Idea

Alice 와 Bob 은 한칸씩 이동한다. Alice 는 `0` Node 에서
출발하여 leaf 로 향한다. BFS 로 탐색할 만하다.

BFS 를 해야하므로 다음과 같이 `Node` 를 정의하고 children 을
채운다. Alice 가 한칸 이동할 때 마다 Bob 은 Node 의 부모로 이동한다.

```java
class Node {
    Node parent;
    int amount;
    int profit;
    List<Node> children = new ArrayList<>();

    public Node(int amount) {
        this.amount = amount;
    }
}
```

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
