# Problem

https://algospot.com/judge/problem/read/POTION

# Idea

병의 개수를 `n`이라고 하자.  각 병의 제조 가능한 레시피의 양을
`r_{i}`, 각 병에 미리 들어있는 양을 `p_{i}`라고 하자.  모든
병을 순회하면서 `p_{i} / r_{i}`를 계산하고 이것을 `l_{i}`라고 하자.

`l_{i}`들 중 가장 큰 값을 선택하고 이것을 `X`라고 하자.  `X`는
유리수 이다.

모든 병의 비율을 똑같이 맞출 수 있는 `X`이상의 최소 유리수를 `Y`라고
하면 모든 i에 대해 `l_{i} = Y`이다. `p_{i}`는 정수이므로 `r_{i} * Y`도
정수이어야 한다. Y는 유리수이므로 정수 a, b에 대해 `Y = a /
b`이다. Y는 최소의 유리수 이므로 b는 모든 `r_{i}`의 GCD이어야 한다.

`X <= Y = a / b`, `X * b <= a` 이므로 최소 유리수 Y를 찾기 위해
`X * b` 이상의 정수 a를 찾는다. 결국 a, b를 찾았으니 Y를 구할 수 있다.

각 병을 순회하면서 `(p_{i} + q_{i}) / r_{i} = Y`가 되도록
`q_{i}`를 찾아내면 된다. 이때 `q_{i} = r_{i} * Y - p_{i}`
가 된다.

# Implementation

```cpp
int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

std::vector<int> solve(const std::vector<int>& R,
                       const std::vector<int>& P) {
  std::vector<int> r(N);

  // get X
  double X = 0.0;
  for (int i = 0; i < N; ++i) {
    X = fmax(X, static_cast<double>(P[i]) / R[i]);
  }

  // get b
  int b = R[0];
  for (int i = 1; i < N; ++i) {
    b = gcd(b, R[i]);
  }

  // get a
  // Y is 1 at least
  int a = ceil(X * b);

  for (int i = 0; i < N; ++i) {
    r[i] = R[i] * a / b - P[i];
  }

  return r;
}
```

# Time Complexity

O(N)
