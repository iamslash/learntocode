# Abstract

counting sort 는 bucket sort 의 아이디어와 비슷하다.

# Problem

수열 `V` 가 주어지면 counting sort 를 이용하여 정렬하라.

# References

* [Counting Sort | GeeksforGeeks @ youtube](https://www.youtube.com/watch?v=7zuGmKfUt7s)

# Idea

`V` 의 숫자들중 최대값을 `maxv`, 최소값을 `minv` 에 저장하자.

벡터 `cnts` 를 `maxv - minv + 1` 의 크기로 생성한다.  인덱스 `i` 를
이용하여 `V[i]` 를 순회한다.  인덱스 `j = V[i] - minv` 를 이용하여
`cnts[j]` 에 `V[i]` 의 발생 횟수를 기록한다.

```
      0 1 2 3 4 5 6
   V: 1 4 1 2 7 5 2
minv: 1
maxv: 7   
cnts: 2 2 0 1 1 0 1
```

`cnts` 의 인덱스는 `V[i] - minv` 이다. 즉 `cnts` 의 인덱스들은 `V[i] -
minv` 의 숫자들이 오름차순으로 정렬된 형태이다.

`cnts` 의 값들을 누적하여 다시 저장한다.

```
      0 1 2 3 4 5 6 
cnts: 2 4 4 5 6 6 7
```

정렬된 결과를 저장할 벡터 `rslt` 를 `V` 의 크기로 생성한다.
발생회수의 누적합을 저장한 `cnts` 의 값들은 정렬되었을 때 삽입해야할
`rslt` 의 위치를 의미한다.

인덱스 `i, j` 를 이용하여 다음을 수행한다.

```cpp
  // set result
  for (int i = 0; i < n; ++i) {
    int j = V[i] - minv;
    rslt[cnts[j]-1] = V[i];
    cnts[j]--;    
  } 
```

다음은 수열 `V = 1 4 1 2 7 5 2` 를 counting sort 하는 과정이다.

```
minv: 1
maxv: 7    

      i                  i                  i                  i
   V: 1 4 1 2 7 5 2    1 4 1 2 7 5 2    1 4 1 2 7 5 2    1 4 1 2 7 5 2

rslt: 0 1 0 0 0 0 0    0 1 0 0 4 0 0    1 1 0 0 4 0 0    1 1 0 2 4 0 0
      0 1 2 3 4 5 6    0 1 2 3 4 5 6    0 1 2 3 4 5 6    0 1 2 3 4 5 6
cnts: 1 4 4 5 6 6 7    1 4 4 4 6 6 7    0 4 4 4 6 6 7    0 3 4 4 6 6 7

              i                  i                  i   
   V: 1 4 1 2 7 5 2    1 4 1 2 7 5 2    1 4 1 2 7 5 2   

rslt: 1 1 0 2 4 0 7    1 1 0 2 4 5 7    1 1 2 2 4 5 7
      0 1 2 3 4 5 6    0 1 2 3 4 5 6    0 1 2 3 4 5 6   
cnts: 0 3 4 4 6 6 6    0 3 4 4 5 6 6    0 2 4 4 5 6 6
```

# Implementation

* [c++1](a.cpp)

# Complexity

```
O(N+K) O(N)
```
