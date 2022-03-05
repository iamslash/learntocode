# Problem

[Design Tic-Tac-Toe](https://leetcode.com/problems/design-tic-tac-toe/)

숫자 `n` 이 주어진다. `n x n` 크기의 Tic-Tac-Toe 를 구현하라.

# Idea

다음을 구현한다. `player` 는 `1` 혹은 `2` 이다.

```java
class TicTacToe {
    public TicTacToe(int n) {}
    public int move(int row, int col, int player) {}
}
```

예를 들어 `n == 3` 이라고 해보자. 입력된 값에 따라 보드의 모양은
다음과 같다.

```
ticTacToe.move(0, 0, 1); // return 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

ticTacToe.move(0, 2, 2); // return 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

ticTacToe.move(2, 2, 1); // return 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

ticTacToe.move(1, 1, 2); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

ticTacToe.move(2, 0, 1); // return 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

ticTacToe.move(1, 0, 2); // return 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
```

`player == 1` 이면 `cell` 의 값을 `1` 이라 하고, `player == 2` 이면
`cell` 의 값을 `-1` 이라 하자.  `row, col, player` 가 주어질 때마다 각
행, 열, 왼쪽 대각선, 오른쪽 대각선 에 놓여진 cell 의 합이 `n` 혹은
`-n` 과 같은지 한번에 확인할 수 있으면 좋을 것 같다.

다음과 같은 변수들을 선언하면 cell 의 합을 한번에 확인할 수 있다.

* `int[] rows = new int[n]`
* `int[] cols = new int[n]`
* `int ldiag = 0`
* `int rdiag = 0`

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
move: O(1) O(N)
```
