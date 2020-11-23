# Abstract

knuth morris prat algorithm 에 사용할 `pi[]` 를 naive 하게 만드는 방법이다.

# Problem

kmp algorithm 에서 사용할 `partial match index array` 를
생성하는 문제이다.

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

다음은 `pi[]` 를 생성하는 반복문의 일부이다.

```cpp
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (N[j] != N[i+j])
        break;
      r[i+j] = std::max(r[i+j], j+1);
    }
  }
```

다음은 naive algorithm 으로 `partial index array` 를 생성하는 과정이다. `i` 는 `begin` 을 의미하고 `j` 는 `matched` 를 의미한다. 그리고 `J = i + j` 를 의미한다.

```
    i           i            i            i
N: aabaabac    aabaabac    aabaabac    aabaabac
   jJ           jJ         j J         j  J
r: 01000000    01000000    01000000    01010000

      i           i           i           i
N: aabaabac    aabaabac    aabaabac    aabaabac
    j  J         j  J         j  J         j  J
r: 01012000    01012300    01012340    01012340

       i           i            i            i
N: aabaabac    aabaabac    aabaabac    aabaabac
   j   J        j   J      j    J      j     J
r: 01012340    01012340    01012340    01012340

         i            i  
N: aabaabac    aabaabac  
    j     J    j      J  
r: 01012340    01012340  
```

# Implementation

[c++11](a.cpp)

# Complexity

```
O(N^2) O(N)
```