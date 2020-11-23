# Abstract

스도쿠 퍼즐을 해결해 보자.

# Problem

* [sudoku solver @ leetcode](https://leetcode.com/problems/sudoku-solver/)

# References

- [sudoku @ geeksforgeeks](https://www.geeksforgeeks.org/sudoku-backtracking-7/)
- [sudoku](http://norvig.com/sudoku.html)
  - [sudoku-kor](https://github.com/jongman/articles/wiki/solving-every-sudoku-puzzle)
- 스도쿠 퍼즐을 해결하는 방법에 관한 peter norvig 의 에세이이다. 약 100 줄의 python code 는 99.9% 의 퍼즐을 1 초 내에 해결한다.

# Idea

`9 X 9` 크기의 보드판이 다음과 같은 세가지 조건을 만족해야 한다.

* 각 행의 숫자들은 `[1, 9]` 의 숫자를 한번씩 만 사용해야 한다.
* 각 열의 숫자들은 `[1, 9]` 의 숫자를 한번씩 만 사용해야 한다.
* 보드판은 9 개의 블록으로 이루어져 있다. 각 블록의 숫자들은 `[1, 9]` 의 숫자를 한번씩 만 사용해야 한다.

backtracking 전략을 사용하자. 보드판을 처음부터 검색하여 숫자를 놓을 수 있는 곳의 좌표를 얻어오는 함수 `pair<int, int> getEmptySlot()` 을 정의하자. 특정한 행에 숫자를 놓을 수 있는지 점검하는 함수 `bool usedInRow(int y, char c)` 를 정의하자. 특정한 열에 숫자를 놓을 수 있는지 점검하는 함수 `bool usedInCol(int x, char c)` 를 정의하자. 특정한 블록에 숫자를 놓을 수 있는지 점검하는 함수 `bool usedInBlock(int bx, int by, char c)` 를 정의하자. 

특정한 좌표에 숫자를 놓을 수 있는지 점검하는 함수 `bool isPlaceable(int y, int x, char c)` 를 정의하자. `isPlaceable` 은 앞서 언급한 세가지 함수들을 이용하여 손 쉽게 구할 수 있다.

```cpp
  bool isPlaceable(std::vector<std::vector<char>>& B, int y, int x, char c) {
    int box_start_row = y - y % 3;
    int box_start_col = x - x % 3;
    return !usedInRow(B, y, c) &&
        !usedInCol(B, x, c) &&
        !usedInBox(B, box_start_row, box_start_col, c) &&
        B[y][x] == '0';

  }
```

앞서 언급한 함수들을 이용하여 `bool solve()` 를 다음과 같이 정의한다. 최초 `solve` 가 `true` 일 때가 답이된다.

```cpp
  bool solve(std::vector<std::vector<char>>& B) {
    auto pr = getEmptySlot(B);
    int y = pr.first; int x = pr.second;
    if (y == -1 && x == -1)
      return true; // done
    for (char c = '1'; c <= '9'; ++c) {
      if (isPlaceable(B, y, x, c)) {
        B[y][x] = c;
        if (solve(B))
          return true;
        B[y][x] = '0';
      }
    }
    return false;
  }  
```

# Implementation

* [c++11](a.cpp)