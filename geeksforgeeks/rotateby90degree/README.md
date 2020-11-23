# Problem

```
// Given NxN matrix and degree, then you rotate the matrix data by
// degree.  The value of degree can be minus 90 degree.
// Implement it and say
// timecomplexity and spacecomplexity.

//   ex)
//       matrix :
//           [ 1,  2,  3,  4]
//           [ 5,  6,  7,  8]
//           [ 9, 10, 11, 12]
//           [13, 14, 15, 16]
//       degree : -90
//       output :
//           [ 4,  8, 12, 16]
//           [ 3,  7, 11, 15]
//           [ 2,  6, 10, 14]
//           [ 1,  5,  9, 13]

// g++ -std=c++11 -o a.exe a.cpp

```

# Idea

입력이 다음과 같다고 하자. 

```
 1,  2,  3,  4
 5,  6,  7,  8
 9, 10, 11, 12
13, 14, 15, 16
```

그리고 숫자 1을 90도씩 시계 반대 방향으로 회전 해보자.  1은 13의 자리로
이동할 것이다.  그렇다면 13은 16의 자리로 이동할 것이다.  16은 4의
자리로 이동할 것이다.  4는 1의 자리로 이동할 것이다.

숫자 2 역시 마찬가지이다. 2는 9의 자리로 9는 15의 자리로 15는 8의 자리로
8은 2의 자리로 이동할 것이다.

하나의 숫자를 이동한다면 총 4번의 움직임이 필요하다. 이것을 추가적인
공간 없이 구현하려면 최초 이동할 숫자를 어딘가에 저장하고 4가지
움직임중 마지막 부터 갱신하면 된다.

그리고 숫자의 위치를 v[y][x]로 표현해보자. y는 행의 인덱스이고 x는
열의 인덱스이다. v는 입력 행렬을 저장한 2차원 배열이다. 숫자 1은
v[0][0]에서 v[3][0]으로, 숫자 13은 v[3][0]에서 v[3][3]으로, 숫자 16은
v[3][3]에서 v[0][3]으로, 숫자 4는 v[0][3]에서 v[0][0]으로 이동한다.

잘 살펴보면 어떤 숫자의 처음 위치가 v[y][x]일때 이동 후 위치는
v[N-1-y][y]가 된다.  N은 v의 가로 혹은 세로의 길이이다.

이제 행렬의 v[0][0]부터 v[3][3]까지 모든 숫자들을 순회 하면서
회전 시키면 된다.  이때 v[0][0], v[0][1]을 각각 4번씩 이동하게 되면
v[0][2], v[0][3]이동은 이미 처리가 되어 버린다. N이 만약 5라면
v[0][1], v[0][2], v[0][3]까지 순회하면서 이동시키면 된다. 이것은
행렬의 열을 고려해서 반복한 경우이다.  그렇다면 행렬의 행을 고려해서
생각해보자. v[0][0], v[1][0]을 이동하면 v[2][0], v[3][0]의 이동은 이미
처리되게 된다. 만약 N이 5라면 v[0][0], v[1][0], v[2][0]까지 이동해야
한다.

결과적으로 y는 0부터 (N/2)-1까지 반복하고 각각의 y에 대해서 x는 0부터
(N+1)/2-1까지 반복 하면서 이동 처리를 하면 전체 행렬을 회전시킬 수 있다.


# Implementation

```cpp
#include <cstdio>
#include <vector>

int N, A;
std::vector<std::vector<int>> V;

void print_v(const std::vector<std::vector<int>> & v) {
  // print r
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < N; ++x) {
      printf("%d ", v[y][x]);
    }
    printf("\n");
  }
}

void rotate(int& a, int& b, int& c, int& d) {
  int tmp = a;
  a = b;
  b = c;
  c = d;
  d = tmp;
}

void solve(std::vector<std::vector<int>> & v) {
  for (int y = 0; y < N/2; ++y) {
    for (int x = 0; x < (N+1)/2; ++x) {
      rotate(v[y][x], v[x][N-1-y], v[N-1-y][N-1-x], v[N-1-x][y]);
    }
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d %d", &N, &A);
    V = std::vector<std::vector<int>>(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        scanf("%d", &V[i][j]);
      }
    }
    solve(V);
    print_v(V);
  }
  return 0;
}
```

# Time Complexity

O(N^2)

# Space Complexity

O(1)
