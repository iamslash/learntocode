# Problem

* [Largest Rectangle in Histogram @ leetcode](https://leetcode.com/explore/interview/card/top-interview-questions-hard/124/others/877/)

# Idea

![](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)

위의 그림과 같이 높이가 다른 사각형들이 일렬로 늘어서 있을 때 가장 넓이가 큰 사각형을 찾는 문제이다. 

사각형들의 높이가 `H` 배열에 저장되어 있다고 해보자. `H` 의 처음과 끝에 `-1` 과 `0` 을 삽입한다. `-1` 은 최대 넓이 사각형이 첫번째 인덱스부터 시작되는 경우를 위해서 필요하다. `0` 은 스택을 사용하여 넓이를 구하는 반복문의 실행을 위해 필요하다. 인덱스 `r` 을 `1` 부터 `H.size()-1` 까지 순회하면서 다음을 반복한다. 

```cpp
      while (H[s.top()] > H[r]) {
        int i = s.top(); s.pop();
        int l = s.top();
        rslt = max(rslt, H[i] * (r - l - 1));
      }
      stck.push(r);
```

`i` 는 최대 사각형 후보의 높이에 해당하는 인덱스이다. `l` 은 최대 사각형 후보가 시작되는 곳의 바로 왼쪽 인덱스이다. `rslt` 는 지금까지 구한 최대 사각형의 넓이이다. `s` 는 지금까지 탐색한 인덱스들 중 일부가 저장되는데 오름차순으로 저장된다.

# Implementation

* [c++11](a.cpp)
