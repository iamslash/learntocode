# Abstract

- consistent hashing 에 대해 적는다.

# References

- [consisten hashing @ joinc](https://www.joinc.co.kr/w/man/12/hash/consistent)
- [A Fast, Minimal Memory, Consistent Hash Algorithm](https://arxiv.org/pdf/1406.2294.pdf)
- [Consistent hashing and random trees: Distributed caching protocols for relieving hot spots on the World Wide Web (1997)](http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.147.1879)

# Idea

- key, value 를 저장할때 value 를 여러곳들중 하나로 분산 저장하는 경우를
  생각해보자. hash(key) 에 해당하는 저장소를 10 개 사용하다가 9 개로
  줄이거나 11 개로 늘릴 수 있다. 분산저장소의 개수가 변경될떄 가능한
  value 의 저장소 변경을 최소화 하여 저장하는 방법이다.

# Implementation

* [c++11](a.cpp)
  * [A Fast, Minimal Memory, Consistent Hash Algorithm](https://arxiv.org/pdf/1406.2294.pdf)

