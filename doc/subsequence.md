
- [Abstract](#abstract)
- [How To Loop Subsequence](#how-to-loop-subsequence)
- [References](#references)

----

# Abstract

subsequence 의 특징들을 몇가지 정리해 본다.

# How To Loop Subsequence

이번 숫자를 `num[i]` 다음 숫자를 `num[i+1]` 라고 하자. 다음과 같은 두가지 방법을
이용해서 subsequence 를 만들어낼 수 있다.

* `{num[i], num[i+1]}`
* `{num[i+1]}`

예를 들어 `1, 2, 3, 4` 의 subsequence 들을 살펴보자. 

```
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
