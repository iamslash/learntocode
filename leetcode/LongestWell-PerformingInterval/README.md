# Problem

[Longest Well-Performing Interval](https://leetcode.com/problems/longest-well-performing-interval/)

# Idea

어느 일꾼이 날짜별로 일을 한 시간의 모음 `H[]` 이 주어진다.  `H[i] >
8` 이면 그 날을 tiring day 라고 하자. well-performing interval 은
tiring day 가 non-tiring day 보다 많은 구간을 말한다. well-performing
interval 이 가장 클 때 그 구간의 길이를 구하는 문제이다.

예를 들어 `H = [9, 9, 6, 0, 6, 6, 9]` 인 경우를
살펴보자. 

```
_____A
  ___________B
9 9 6 0 6 6 9
```

위의 에에서 구간 A 가 well-performing interval 이다. 구간 B 는
tiring day 는 `2` 개이고 non-tiring day 는 `4` 개이다. 전체 크기는 A 보다 크지만
`tiring day > non-tiring day` 를 만족하지 못한다.

`int ans = 0` 을 선언하여 답을 저장한다.
`int cnt = 0` 를 선언하여 tiring day 개수를 저장하자. 
`H` 를 처음부터 순회하면서 `H[i] > 8` 이면 `++cnt` 하고
`H[i] <= 8` 이면 `--cnt` 해보자.

```
  H: 9 9 6 0 6 6 9 9 9
cnt: 1 2 1 0-1-2-1 0 1
```

위의 예에서 몇가지 규칙을 발견할 수 있다.

* `cnt > 0` 이면 `i + 1` 이 답의 후보가 된다. 
* `cnt <= 0` 이면 이전의 `cnt` 가 `cnt - 1` 이었을 때의 인덱스를 
  `p` 라고 하자. `i - p` 만큼이 답의 후보가 된다. 
  * 예를 들어 위의 예를 살펴보자. `i == 7` 이면 
    `cnt == 0` 이고 `cnt - 1 == -1` 이기 때문에 `p == 4` 이다.
    `-1` 에서 `0` 이 된 것이므로 tiring day 의 수가 non-tiring day 의 수보다
    하나 많다.

`unordered_map<int, int> C` 를 선언하여 `{cnt : i whose cnt is cnt}` 
를 저장한다. 이때 구하고자 하는 값은 최대값이기 때문에
동일한 key 에 대하여 저장은 한번만 해야 한다.

다음은 `H = 9 9 6 0 6 6 9 9 9` 의 풀이과정이다.

```
                          i                   i                   i
     H: 9 9 6 0 6 6 9     9 9 6 0 6 6 9     9 9 6 0 6 6 9     9 9 6 0 6 6 9     
   cnt: 0                 1                 1 2               1 2 1
   ans: 0                 1                 1 2               1 2 2
     C:                   1                 1 2               1 2  
                          0                 0 1               0 1
        
              i                   i                   i                   i
     H: 9 9 6 0 6 6 9     9 9 6 0 6 6 9     9 9 6 0 6 6 9     9 9 6 0 6 6 9     
   cnt: 1 2 1 0           1 2 1 0-1         1 2 1 0-1-2       1 2 1 0-1-2-1
   ans: 1 2 3             1 2 3 3 3         1 2 3 3 3 3       1 2 3 3 3 3 3
     C: 1 2               1 2-1             1 2-1-2           1 2-1-2  
        0 1               0 1 4             0 1 4 5           0 1 4 5
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
