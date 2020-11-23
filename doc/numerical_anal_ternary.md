# Abstract

삼분 검색(ternary search) 에 대해 적는다.

# Idea

`x` 가 `[lo, hi]` 일때 가장 높은 `(local maximum)` 혹은 가장 낮은 `(local
minimum)` `y` 를 검색할 때 사용한다. `[lo, hi]` 를 `3` 등분 하면 `(2lo+hi)/3`와
`(lo+2hi)/3` 을 만들어 낼 수 있다.

```
----------------------------------------
|            |            |            |
lo     (2lo+hi)/3     (lo+2hi)/3     hi  
```

`f((2lo+hi)/3)` 와 `f((lo+2hi)/3)` 를 비교해서
`x` 의 구간을 `2/3` 로 줄이자

일반적인 구현은 다음과 같다.

```cpp
double f(double x);
double ternary(double lo, double hi) {
  if (lo > hi)
    swap(lo, hi);
  for (int i = 0; i < 100; ++i) {
    double a = (2*lo + hi) / 3;
    double b = (lo + 2*hi) / 3;
    if (f(a) > f(b))
      hi = b;
    else
      lo = a;
  }
  return (lo+hi)/2.0;
}
```

물론 도함수 값이 0 인 점들을 하나 하나 시도해서 해결해도 되지만
미분할 수 없는 함수의 경우도 해결 할 수 있다.

삼분 검색은 최고점 혹은 최저점의 y 값을 모를때 사용한다.  만약 y 값을
알고 있다면 ternary search 보다는 bisection method 가 성능이
더욱 좋다.