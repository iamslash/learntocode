# Abstract

최대 공약수를 구하는 유클리디안 알고리즘에 대해 적는다.

# Problem

숫자 `p, q` 가 주어지면 최대공약수를 구하는 문제이다.

# References

* [유클리드 호제법 @ youtube](https://www.youtube.com/watch?v=5VvZbcxu5oI)
* [유클리드 호제법 @ 나무위키](https://namu.wiki/w/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C%20%ED%98%B8%EC%A0%9C%EB%B2%95)
* [유클리드 호제법 @ wikipedia](https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95)

# Idea

특정 숫자 `p` 와 `q` 의 최대 공약수를 구해보자. `p = p'g, q = q'g` 로
표현하자. 이때 `p >= q` 이고 `p'` 와 `q'` 는 서로소, `g` 는 최대공약수이다.

```
p - q = p'g - q'g
p - q = g(p' - q')
p와 q의 최대 공약수는 q와 p-q의 최대 공약수와 같다.
```

이번에는 조금 다르게 접근해 보자.

```
p = p'g, q = q'g (p >= q, p'와 q'는 서로소, g는 최대공약수)
p = qa + r
p'g = q'ga + r
r = g(p' - q'a) (q와 r의 최대공약수가 g가 되려면 q'과 p'-q'a가 서로소이면 된다.)
귀류법을 이용해서 증명해보자.
q'과 p' - q'a가 서로소가 아니라면
q' = xG, p'-q'a = yG (G != 1)라고 할 수 있다.
p' - xGa = yG
p' = (y +xa)G
p'과 q'는 G때문에 서로소가 아니다. 이것은 p'과 q'는 서로소 라는 것에 모순이다.
따라서 q'과 p' - q'a는 서로소이다.
p와 q의 최대 공약수는 q와 r의 최대 공약수와 같다.
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
??? ???
```