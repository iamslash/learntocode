# Abstract

knuth morris prat algorithm 에 대해 적는다. 검색도중 실패했을 때 건너뛰면서 검색하기 때문에 [naive search algorithm](/fundamentals/string/naivesearch/README.md) 보다 빠르다. 

[suffix array search](/fundamentals/string/suffixarraysearch/README.md) 는 문자열 `H` 를 이용하여 `sa[]` 를 생성하지만 [kmp search](/fundamentals/string/kmpsearch/README.md) 는 문자열 `N` 을 이용하여 `pi[]` 를 생성한다.

# Problem

문자열 `H` 에서 문자열 `N` 을 찾는 문제이다.

# Keyword

- kmp_search(string H, string N), begin, mached, vector<int> pi, get_pi

# References

- [KMP String matching algorithm @ youtube](https://www.youtube.com/watch?v=v82y5TCcBhQ)

# Idea

건초더미 문자열 `H` 에서 바늘 문자열 `N` 을 찾아보자. `N` 의 partial index 인 `pi[]` 를 생성한다. `pi[i]` 는 부분문자열 `N[0..i]` 의 접두사이면서 접미사인 문자열의 최대 개수를 의미한다. 

예를 들어 `N = aabaabac` 인 경우 `pi` 는 다음과 같다. 

| i | `N[0..i]` | max substring as prefix and postfix | `p[i]` |
|:--|:----------|:------------------------------------|:-------|
| 0 | a         |                                     | 0      |
| 1 | aa        | a                                   | 1      |
| 2 | aab       |                                     | 0      |
| 3 | aaba      | a                                   | 1      |
| 4 | aabaa     | aa                                  | 2      |
| 5 | aabaab    | aab                                 | 3      |
| 6 | aabaaba   | aaba                                | 4      |
| 7 | aabaabac  |                                     | 0      |

`pi[]` 를 만드는 방법은 [make pi array with naive algorithm](/fundamentals/string/kmppinaive/README.md) 와 [make pi array with kmp algorithm](/fundamentals/string/kmppikmp/README.md) 의 두가지 방법을 참고하자.

다음은 `H = kaabaabakaabaabac, N = aabaabac` 의 경우 kmp 과정이다. 
인덱스 `i, j` 와 `pi[]` 를 활용하면 `i, j` 를 건너뛰기하면서 검색이 가능하다. 

```
N: aabaabac
P: 01012340

   i                     i                    i
H: kaabaabakaabaabac    kaabaabakaabaabac    kaabaabakaabaabac
N: aabaabac              aabaabac             aabaabac 
   j                     j                           j

       i                     i                     i
H: kaabaabakaabaabac    kaabaabakaabaabac    kaabaabakaabaabac
N:     aabaabac              aabaabac              aabaabac 
           j                  j                    j

          i                    i                     i
H: kaabaabakaabaabac    kaabaabakaabaabac    kaabaabakaabaabac
N:        aabaabac             aabaabac              aabaabac 
          j                     j                    j

            i          
H: kaabaabakaabaabac   
N:          aabaabac   
            j          
```

# Implementation

[c++11](a.cpp)

# Complexity

```
O(H) O(N)
```