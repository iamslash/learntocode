# Problem

* [N-Queen @ leetcode](https://leetcode.com/problems/n-queens/)

# Backtracking

## Idea

숫자 `N` 이 주어지면 `NxN` 보드판에 퀸을 놓을 수 있는 방법을
구하는 문제이다.

보드판의 `[0..N-1]` 행들을 순회하며 하나의 행에 하나의 퀸을 놓자. 퀸이 놓여진 위치는 `int Q[N]` 에 `Q[y]=x` 형태로 저장할 수 있다. 

퀸을 놓을 수 있는지 검증하는 함수를 `bool isValidPos(int y, int x)` 라고 하자. 보드판의 행들을 순회하기 때문에 `(y,x)` 를 기준으로 수직, 왼쪽 대각선, 오른쪽 대각선을 검사한다. `Q` 를 확인하면 퀸이 있는지 확인할 수 있다.

예를 들어 다음과 같이 `4X4` 의 보드가 있고 `y = 2, x = 2` 이라고 해보자. `#` 는 수직선, `@` 는 왼쪽 대각선, `$` 는 오른쪽 대각선에 해당한다.

```
@.#.
.@#$
..o.
....
```

다음과 같은 부분문제를 정의하여 backtracking 전략으로 해결한다.

```cpp
void nqueen(int y) {
...
  for (int x = 0; x < n; ++x) {
    Q[y] = x;
    nqueen(y+1);
    Q[y] = -1;
  }
...
}
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N^3) O(N)
```

# Backgracking with bitmanipulation

## Idea

기본적인 아이디어는 앞서 언급한 Backtracking 과 같다. 그러나
퀸을 놓을 수 있는 곳인지 확인하는 것을 bitsequence 를 이용하여
시간복잡도를 개선한다.

먼저 부분문제 `nqueen` 을 다음과 같이 정의한다.

```cpp
void nqueen(int y, int vr, int ld, int rd) {
...
    // recursion
    int last = m_END & (~(vr | ld | rd));
    while (last != 0) {
      int pos = last & (-last);
      last -= pos;
      int x = __builtin_ctz(pos);
      
      m_Q[y] = x;
      solve(y+1, vr + pos, (ld + pos) << 1, (rd + pos) >> 1);
      m_Q[y] = -1;
    }
...
}
```

`y` 는 이번에 퀸을 놓을 행을 의미한다. `vr` 은 지금까지 놓여진
퀸의 열 정보를 담고 있다. 예를 들어 `vr = 00100` 이면 이전에
`2` 열에 퀸을 놓았다는 의미이다. `ld` 는 기존의 퀸과 왼쪽 대각선으로 
충돌하는 퀸의 열 정보를 담고 있다. 예를 들어 `vl = 01000` 이면 이전에
`?` 열에 퀸을 놓았고 이번에 `1` 열에 퀸을 놓으면 기존의 퀸과
왼쪽 대각선으로 충돌하기 때문에 놓을 수 없다는 의미이다. 
`rd` 는 왼쪽 대신 오른쪽 대각선 인 것을 제외하고 `ld` 와 같다. 

`pos` 는 이번에 놓을 열의 비트시퀀스를 의미하고 비트시퀀스 `last` 의 가장 오른쪽 `1` 만 세트된 비트시퀀스로 얻어낸다. 예를 들어 `last = 01100` 일 때 `pos = 00100` 이다.

```
int pos = last & (-last);
```

`vr, ld, rd` 는 모두 이번에 놓을 수 없는 열의 정보를 의미한다.
그러므로 `~(vr | ld | rd)` 는 이번에 놓을 수 있는 열의 정보를 의미한다. 이것을 종료조건 `m_END` 와 `&` 했을 때 이것이 `0` 이면 더이상 퀸을 놓을 수 있는 곳이 없다는 의미이다.

`__builtin_ctz` 는 비트시퀀스를 읽어서 가장 오른쪽 `1` 의 
인덱스를 얻어올 수 있다. 그러나 g++ builtin function 이다.

`solve(y, vr, ld, lr)` 에서 다시 `solve` 를 호출할 때를 살펴보자.
`pos` 를 `00100` 이라고 해보자. `2` 열에 퀸을 놓았다는 의미이다.
다음 행에서 다시 `2` 열에 퀸을 놓을 수 없으므로 `vr = vr + pos` 한다.

또한 `pos = 00100` 이면 다음행에서 왼쪽 대각선과 오른쪽 대각선 때문에
놓을 수 없는 열의 정보가 다음과 같다.

```
00100
0l0r0
```

즉 `01000` 는 `ld` 가 될 수 있고 `00010` 은 `rd` 가 될 수 있다.
따라서 `ld = (ld + pos) << 1` 이고 `rd = (rd + pos) >> 1` 이다.

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(N^2) O(N)
```