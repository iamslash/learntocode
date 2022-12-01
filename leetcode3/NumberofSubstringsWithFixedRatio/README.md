# Problem

[Number of Substrings With Fixed Ratio](https://leetcode.com/problems/number-of-substrings-with-fixed-ratio/)

문자열 `s`, 숫자 `num1, num2` 가 주어진다.  `num1, num2` 는 서로소인
소수이다. `s` 의 substring 중 `0` 의 개수와 `1` 의 비율이 `num1` 와
`num2` 의 비율과 같은 것들의 개수를 구하라.

# Idea

예를 들어 `s = "0110011", num1 = 1, num2 = 2` 의 경우를 살펴보자.

```
num1: 1
num2: 2
s: 0110011
   ---       '0': 1, '1': 2
    ---      '0': 1, '1': 2
       ---   '0': 1, '1': 2
    ------   '0': 2, '1': 4
```

`int sum = 0` 을 선언하여 `s` 를 순회한다. `0` 를 만나면 `num2` 를
더하고 `1` 를 만나면 `num1` 을 빼보자.

```
num1: 1
num2: 2
            i 
   s: 0 0 1 1 0 1 1 0 1 1
 sum: 2 4 3 2
```

이때 `sum == 2` 인 경우가 2 번 발생했다. `011` 이 한번 
만들어졌다는 의미이다. 계속 탐색한다.

```
num1: 1
num2: 2
                  i 
   s: 0 0 1 1 0 1 1 0 1 1
 sum: 2 4 3 2 4 3 2
```

이때 `sum == 2` 인 경우가 3 번 발생했다. `011` 이 다시 한번
만들어졌다는 의미이다. 앞서 발견한 `011` 과 지금 발견한 `011` 의
조합으로 다음과 같은 substring 제작이 가능하다.

```
011
   011
011011
```

즉, `1 + 2` 와 같다. 계속 탐색해 보자.

```
num1: 1
num2: 2
                        i 
   s: 0 0 1 1 0 1 1 0 1 1
 sum: 2 4 3 2 4 3 2 4 3 2
```

이때 `sum == 2` 인 경우가 `4` 번 발생했다. `011` 이 다시 한번
만들어졌다는 의미이다. 앞서 발견한 `011` 들과 지금 발견한 `011`
의 조합으로 다음과 같은 substring 제작이 가능하다.

```
011
   011
      011
011011
   011011
011011011
```

즉, `1 + 2 + 3` 와 같다. 

`Map<Integer, Integer> freqMap = new HashMap<>()` 을
선언하여 탐색 할 때 마다 다음을 반복한다.

* 답에 `freqMap.get(sum)` 을 더한다.
* `sum` 과 `sum` 의 발생횟수를 `freqMap` 에 저장한다. 

magic seed 를 위해 `freqMap.put(0, 1)` 을 수행한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N) O(N)
```
