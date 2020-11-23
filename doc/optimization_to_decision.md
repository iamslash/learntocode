# Abstract

- optimization problem 을 decision problem 으로 바꾸어서 푸는 방법에
  대해 적어본다.
- optimization problem 은 최적화 문제이다. decision problem 은 예 혹은 아니오 답만이 나오는 문제이다. 최적화 문제를 예 혹은 아니오 답만이
  나오는 문제로 변환한 다음에 `bisection method(이분법)` 을 이용해서
  구간을 줄여가며 답을 찾아내는 방법이다.
- 주로 다음과 같이 `optimization()` 에서 `decision()` 을 반복하여 호출하는
  형태로 구현한다.

```cpp
bool decision(...) {
    ...
}

double optimize() {
  double lo = -1e-9;
  double hi = 1;

  for (int i=0; i < 100; i++) {
    double mid = (lo + hi) / 2;
    if (decision(mid))
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}
```
