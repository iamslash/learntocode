# Abstract

radix sort 는 bucket sort 의 아이디어와 비슷하다.

# Problem

수열 `V` 가 주어지면 radix sort 를 이용하여 정렬하라.

# References

* [Radix Sort @ geeksforgeeks](https://www.geeksforgeeks.org/radix-sort/)

# Idea

`V` 의 숫자들중 최대값을 `maxv` 에 저장한다. 일의 자리 부터
`maxv` 의 최대 자리수까지 순회하면서 counting sort 한다.

다음은 수열 `V = 11 4 1 22 7 55 2` 를 radix sort 하는 과정이다. `maxv: 55`
이고 최대 자리수는 두자리이다.

```
exp: 1
      1-for, 2-for           3-for
                                            i
   V: 11 4 1 22 7 55 2       11 4 1 22 7 55 2
rslt:  0 0 0  0 0  0 0        0 0 0  2 0  0 0
cnts:  0 2 4 4 5 6 6 7 0 0    0 2 3 4 5 6 6 7 0 0
                                            
                   i                   i    
   V: 11 4 1 22 7 55 2       11 4 1 22 7 55 2    
rslt:  0 0 0  2 0 55 0        0 0 0  2 0 55 7    
cnts:  0 2 3 4 5 5 6 7 0 0    0 2 3 4 5 5 6 6 0 0

              i                     i    
   V: 11 4  1 22 7 55 2       11 4  1 22 7 55 2    
rslt:  0 0 22  2 0 55 7        1 0 22  2 0 55 7    
cnts:  0 2 2 4 5 5 6 6 0 0     0 2 2 4 5 5 6 6 0 0

```

# Implementation

* [c++1](a.cpp)

# Complexity

```
O(ND) O(N)

D: count of digit
```
