# Problem

suffix array search 에서 사용할 suffix array 를 manber myers algorithm 을 이용하여 생성하는 문제이다.

# References

* [Suffix Array | Set 1 (Introduction) @ geeksforgeeks](https://www.geeksforgeeks.org/suffix-array-set-1-introduction/)
* [Manber, Udi; Myers, Gene (1990). Suffix arrays: a new method for on-line string searches](http://webglimpse.net/pubs/suffix.pdf)

# Keyword

```
sa[], group[], t
```

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

updating...

# Iimplementation

* [c++11](a.cpp)

# Complexity

```
O(N(lgN)^2) O(N)
```