
- [Abstract](#abstract)
- [Generate Subsequences](#generate-subsequences)
- [Generate Subsequences With Non-Decreasing Sum](#generate-subsequences-with-non-decreasing-sum)
- [References](#references)

----

# Abstract

subsequence 의 특징들을 몇가지 정리해 본다.

# Generate Subsequences

예를 들어 `s = "abc"` 의 subsequence 를 만들어 보자. 인덱스
`i` 를 `[0..n)` 동안 순회하면서 다음을 반복한다. 

* 이번문자를 포함한다.
* 이번문자를 포함하지 않는다.

```
a b c    a b c
    .    a b
  . c    a c  
    .    a
. b c    b c
    .    b
  . c    c
    .    .
```

# Generate Subsequences With Non-Decreasing Sum

수열 `nums[]` 이 주어지고 오름차순으로 정렬되어 있다.

subsequence 의 합이 작은 것부터 큰 것을 만들어 내는 방법을 설명한다. 생성된
subseq-sum 은 priority queue 에 삽입하고 하나씩 꺼낸다. 이때 priority queue 는
꼭대기 값이 큰 값이다. 

이번 숫자를 `num[i]` 다음 숫자를 `num[i+1]` 라고 하자. 최초의 숫자를 `nums[0]`
이라고 하자. 그외의 subseq 는 다음과 같은 두가지 방법을 이용해서 만들어낼 수
있다.

```
* num[i], num[i+1]
*         num[i+1]
```

예를 들어 `1, 2, 3, 4` 의 subsequence 들을 살펴보자. 

```
  i
1 2 3 4

1                
  1 2            
    1 2 3        
      1 2 3 4     
      1 2 4      
    1 3          
      1 3 4      
      1 4        
  2              
    2 3          
      2 3 4      
      2 4        
    3            
      3 4        
      4          
```

# References

* [L](/leetcode2/FindtheK-SumofanArray/README.md) | [Find the K-Sum of an Array](https://leetcode.com/problems/find-the-k-sum-of-an-array/)
