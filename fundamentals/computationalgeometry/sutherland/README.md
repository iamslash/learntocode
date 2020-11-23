# Abstract

폴리곤 만큼 오려내는 것을 클리핑이라고 한다. 폴리곤 클리핑 문제를 해결하는 알고리즘 중 하나인 서더랜드 호지맨
알고리즘을 정리한다.

# Idea

![](/_img/505px-Sutherland-Hodgman_clipping_sample.svg.png)

clipper 의 선분을 순회한다. 각 선분마다 clipper의 안쪽에 위치하는
clippee점들과 clipper와 clippee의 교점을 저장한다. 저장된 점들은
다음번 순회에서 입력으로 사용한다.

# Implementation

[c++11](a.cpp)

# Complexity

```
O(N) O(N)
```

# References

* [sutherland @ wikipedia](https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm)
* [Polygon Clipping | Sutherland–Hodgman Algorithm @ geeksforgeeks](http://www.geeksforgeeks.org/polygon-clipping-sutherland-hodgman-algorithm-please-change-bmp-images-jpeg-png/)