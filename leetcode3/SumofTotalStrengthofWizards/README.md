# Problem

[Sum of Total Strength of Wizards]()

# Idea

i 를 중심으로 왼쪽의 인덱스들을 바라보자. i 를 중심으로 왼쪽으로
`strength[i]` 보다 작은 첫 번째 값을 `strength[left]` 라고 하자.

i 를 중심으로 오른쪽의 인덱스들을 바라보자. i 를 중심으로 오른쪽으로
`strength[i]` 보다 작은 첫 번째 값을 `strength[right]` 라고 하자.

그리고 다음과 같이 `left, i, right` 인덱스들이 늘어서 있다고 해보자.

`...left-1, left, left + 1, left + 2, ... i-1, i, i+1, ... right-1, right, right+1...`

`strength[i]` 가 min 으로 사용된 subarray 들은 다음과 같이 구한다.

```
subarrays that start with left + 1:
[left+1, i]
[left+1, i+1]
...
[left+1, right-1]

subarrays that start with left + 2:
[left+2, i]
[left+2, i+1]
...
[left+2, right-1]

...

subarrays that start with i:
[i, i]
[i, i+1]
...
[i, right-1]
```

각 subarray 들의 합은 다음과 같이 구한다.

```
the subarrays that start with left+1:
sum(left+1, ... i) = ps[i + 1] - ps[left + 1]
sum(left+1, ... i+1) = ps[i + 2] - ps[left + 1]
...
sum(left+1, ... right-1) = ps[right] - ps[left + 1]

the subarrays that start with left+2:
sum(left+2, ... i) = ps[i + 1] - ps[left + 2]
sum(left+2, ... i+1) = ps[i + 2] - ps[left + 2]
...
sum(left+2, ... right-1) = ps[right] - ps[left + 2]

...

the subarrays that start with i:
sum(i, ... i) = ps[i + 1] - ps[i]
sum(i, ... i+1) = ps[i + 2] - ps[i]
...
sum(i, ... right-1) = ps[right] - ps[i]
```

이제 모든 `sum()` 을 더하면 `strength[i]` 가 최소로 사용됬을 때
만들어질 수 있는 subarray 들의 합이 된다. 이 것에 `strength[i]` 만
곱하면 strength 를 얻을 수 있다. 다음과 같이 양의 부호 음의 부호를
분리해서 수식을 만들어 보자.

```
positive parts:
(ps[i + 1] + ps[i + 2] + ... + ps[right]) * (i - left)

negative parts:
(ps[left + 1] + ps[left + 2] + ... + ps[i]) * (right - i)
```

# Implementation

* [c++11](a.cpp)
* [java11](MainApp.java)

# Complexity

```
O(N) O(N) 
```
