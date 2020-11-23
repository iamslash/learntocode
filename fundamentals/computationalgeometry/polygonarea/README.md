# Abstract

다각형의 면적을 구해 보자.

# References

* [Area of a polygon with given n ordered vertices @ geeksforgeeks](http://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/)

# Idea

`a = (x_{1}, y_{1})`, `b = (x_{2}, y_{2})` 일때 `a` 와 `b` 의 외적은 다음과
같다. 

![](/_img/cross_product_on_2D.png)

만약 `b` 의 위치벡터가 `a` 의 위치벡터의 반시계 방향에 있다면 외적의 값은 양수이고
그렇지 않다면 음수이다.

```
a x b = x_{1} * y_{2} - y_{1} * x_{2}
      = |a||b|sinθ
|a|sinθ 는 원점, a, b 를 꼭지점으로 하는 삼각형의 높이다.
언급한 삼각형의 넓이를 S 라 한다면

S = a x b * 0.5
```

다각형을 구성하는 점들을 `p_{i}` 라고 하자. (0 <= i < n)
원점에서 언급한 점들을 연결하여 위치벡터들의 외적을
모두 합하여 더하고 절반을 취하면 다각형의 면적과 같다.

![](/_img/polygonarea_eq.png)

```latex
\left | \sum_{i=0}^{n-1} p_{i}  \times p_{(i+1) \% n}\right | \frac{1}{2}
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(1)
```