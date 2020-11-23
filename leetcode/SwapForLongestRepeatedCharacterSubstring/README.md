# Problem

[Swap For Longest Repeated Character Substring](https://leetcode.com/problems/swap-for-longest-repeated-character-substring/)

# Idea

문자열 `s` 가 주어진다. 단 하나의 문자를 교체하여 같은 문자들이
가장 길게 만들어 보자. 그 때의 길이를 구하는 문제이다.

예를 들어 `s = "aaabaaa"` 의 경우를 살펴보자. 중간의 `b` 를
끝의 `a` 와 교체하면 `aaaaaab` 가 되고 답은 `6` 이 된다.

먼저 `vector<vector<int>> ch2ids(26)` 를 선언하여 문자별 출현인덱스를
추가해보자. 위의 경우 `ch2ids` 의 모양은 다음과 같다.

```
ch2ids: 'a' 0: 0 1 2 4 5 6
        'b' 1: 3
```

`ch2ids` 가 완성되면 인덱스 `i` 를 `[0..26)` 동안 순회하면서 다음을 반복한다.

* `int locmax = 0, prv = 0, cnt = 1` 을 선언하여 `local max count,  previous count, current count` 를 저장하자. 그리고 `vector<int> ids = ch2ids[i]` 를 선언하여 문자별 출현인덱스를 얻어온다.
  * `prv` 는 `a` 가 아닌 인덱스를 기준으로 왼쪽에 존재하는 `a` 의 수이다.`cnt` 는 가장 최근의 `a` 가 아닌 인덱스부터 현재까지 존재하는 `a` 의 수이다. 만약 `prv` 와 `cnt` 사이에 `a` 가 아닌 문자가 하나만 존재한다면 `prv + cnt` 가 곧 연속된 `a` 의 개수와 같다.
* 인덱스 `j` 를 `[1..ids.size())` 동안 순회하면서 다음을 반복한다.
  * `ids[j-1] + 1 == ids[j]` 이면 지금까지 연속이다. `cnt++` 를 수행하자.
  * `ids[j-1] + 1 != ids[j]` 이면 하나 빼고 연속이다. `prv = cnt, cnt = 1` 를 수행하자.
  * `locmax = max(locmax, prv + cnt)` 를 수행한다.
* `glbmax = max(glbmax, locmax + (ids.size() > locmax ? 1 : 0))` 를 수행한다.
  * `idx.size() > locmax` 이면 같은 문자가 세블록 이상이다. 하나 더 추가해야 한다.
  * `aaabaaabaaa` 의 경우를 살펴보자. `a` 의 세번째 블록에서 하나 빌려서 첫번째 `b` 와 교체하면 `locmax` 에 하나를 더해야 한다.

다음은 `ch2ids[0]` 의 경우 `ids` 의 풀이과정이다.

```
                                i                i                i              
ch2ids: 'a' 0: 0 1 2 4 5 6    0 1 2 4 5 6    0 1 2 4 5 6    0 1 2 4 5 6
          prv: 0              0 0            0 0 0          0 0 0 3       
          cnt: 1              1 2            1 2 3          1 2 3 1
       locmax: 0              1 2            1 2 3          1 2 3 4
                       i                i    
ch2ids: 'a' 0: 0 1 2 4 5 6    0 1 2 4 5 6 
          prv: 0 0 0 3 3      0 0 0 3 3 3
          cnt: 1 2 3 1 2      1 2 3 1 2 3
       locmax: 1 2 3 4 5      1 2 3 4 5 6 
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
