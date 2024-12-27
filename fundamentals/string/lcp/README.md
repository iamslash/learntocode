# Abstract 

suffix array 를 이용하여 longest common prefix array 를 만들어 두면 여러가지 문제들에 응용할 수 있다.

# References

* [kasai’s Algorithm for Construction of LCP array from Suffix Array @geeksforgeeks](https://www.geeksforgeeks.org/%C2%AD%C2%ADkasais-algorithm-for-construction-of-lcp-array-from-suffix-array/)
* [Kasai, T. et al., "Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its Applications"](http://alumni.cs.ucr.edu/~rakthant/cs234/01_KLAAP_Linear%20time%20LCP.PDF)

# Idea

다음은 문자열 `H = banana` 에 대한 suffix array 와 longest common prefix array 이다.

| i | `sa[i]` | `H[sa[i]..]` | `lcp[i]` |
|:--|:--------|:-------------|:---------|
| 0 | 5       | a            | 1        |
| 1 | 3       | ana          | 3        |
| 2 | 1       | anana        | 0        |
| 3 | 0       | banana       | 0        |
| 4 | 4       | na           | 2        |
| 5 | 2       | nana         | 0        |

lcp array 는 suffix array 와 함께 여러가지 문제들에 활용될 수 있다. [the number of differenct substring](/fundamentals/string/thenumberofdifferenctsubstring/README.md) 는 대표적인 예이다.
