# Problem

[Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)

문자열 `s`, 숫자 `k` 가 주어진다. `s` 는 `T, F` 로만 구성되어 있다.
최대 `k` 만큼 `T` 를 `F` 로 바꾸거나 `F` 를 `T` 로 바꾸는 것이
가능하다. 같은 문자로 이루어진 최대 부분문자열의 길이를 구하라.

# Idea

예를 들어 `s = "TFFT", k = 1` 의 경우를 살펴보자.

```
k: 1
     _____
s: T F F T
```

따라서 답은 3 이다. 이 것을 다음과 같은 방법으로 구현해 보자.

먼저 다음과 같은 변수들을 선언한다.

* `char[] freqs = new char[128]` 
  * 답에 해당하는 최대길이 부분문자열을 윈도우라고 하자. 윈도우에서
    발생한 `T, F` 의 출현 횟수를 저장한다.
* `int maxFreq = 0`
  * 지금까지 최대 출현한 문자의 개수를 저장한다.
* `int maxWndLen = 0`
  * 지금까지 만들 수 있는 윈도우의 최대 크기를 저장한다.
* `int n = s.length()`
  * 문자열 `s` 의 길이를 저장한다.
  
이제 인덱스 `i` 를 이용하여 `[0, n)` 만큼 순회하며 다음을 반복한다.

* `char c = s.charAt(i)` 를 선언하여 `s` 의 `i` 번째 문자를 저장한다.
* `c` 의 출현횟수를 증가한다. 즉, `++freqs[c]` 를 수행한다.
* `maxFreq` 를 업데이트 한다. 즉, `maxFreq = max(maxFreq, freqs[c])` 를 수행한다.
* `maxWndLen - maxFreq < k` 이면 최대 크기 윈도우를 하나 증가해도
  된다. `maxWndLen - maxFreq` 는 바꿀 수 있는 문자의 개수를 의미하기
  때문이다.
* `maxWndLen - maxFreq >= k` 이면 윈도우를 한 칸 오른쪽으로 이동해야
  한다. 따라서 윈도우의 시작에 해당하는 문자의 출현횟수를 하나 감소한다.
  
모든 반복을 마치면 `maxWndLen` 이 답이다.

다음은 `answerKey = "TTFTTFTT", k = 1` 의 풀이과정이다.

```
        k: 1
                         i
        s: T T F T T F T T
                 ---------
    freqs: T F
           4 1
  maxFreq: 4
maxWndLen: 5
```

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(N) O(1)
```
