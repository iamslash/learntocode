# Abstract

문자열 `H` 에서 문자열 `N` 을 검색할 때 suffix array 를 사용하여 검색하는 방법에 대해 적는다. [kmp search](/fundamentals/string/kmpsearch/README.md) 는 문자열 `N` 을 이용하여 `pi[]` 를 생성하지만 suffix array search 는 문자열 `H` 를 이용하여 `sa[]` 를 생성한다.

# Problem

문자열 `H` 에서 문자열 `N` 을 검색하는 문제이다.

# References

* [Suffix Array | Set 1 (Introduction) @ geeksforgeeks](https://www.geeksforgeeks.org/suffix-array-set-1-introduction/)
* [Manber, Udi; Myers, Gene (1990). Suffix arrays: a new method for on-line string searches](http://webglimpse.net/pubs/suffix.pdf)

# Idea

다음은 인덱스 `i` 에 따른 접미사 `H[i..]` 이다.

| i | `H[i..]` |
|:--|:---------|
| 0 | banana   |
| 1 | anana    |
| 2 | nana     |
| 3 | ana      |
| 4 | na       |
| 5 | a        |

`H[i..]` 를 사전순으로 정렬하고 접미사 배열 `sa[]` 에 다음과 같이 생성한다.

| i | `sa[i]` | `H[sa[i]..]` |
|:--|:--------|:-------------|
| 0 | 5       | a            |
| 1 | 3       | ana          |
| 2 | 1       | anana        |
| 3 | 0       | banana       |
| 4 | 4       | na           |
| 5 | 2       | nana         |

접미사 배열 `sa[]` 을 생성하는 방법은 [make suffix array with naive algorithm★](fundamentals/string/suffixarraynaive/) 와 [make suffix array with manber myers algorithm★](fundamentals/string/suffixarraymanber/) 을 참고하자.

문자열 `H` 에서 문자열 `N` 을 `sa[]` 를 이용하여 검색해보자. `N` 은 `H[sa[i]..]` 의 접두사에 해당한다. `H[sa[i]..]` 를 binary search 를 이용하여 검색하고 이후 linear search 한다. `H[sa[i]..]` 는 사전순으로 정렬되어 있기 때문이다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgH)
```