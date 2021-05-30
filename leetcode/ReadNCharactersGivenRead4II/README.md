# Problem

[Read N Characters Given Read4 II - Call multiple times](https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/)

# Idea

정해진 크기의 buffer 를 이용하여 처리하는 방식을 구현한다.  real world
에서 충분히 만날 수 있는 문제이다.

먼저 `char[] buf4 = new char[4]` 를 선언하여 버퍼로 이용한다.  `int
idx4 = 0` 를 선언하여 `buf` 에서 읽어야할 인덱스를 저장한다.  `int
cnt4 = 0` 를 선언하여 `buf4` 로 읽어들인 것의 개수를 저장한다. 즉,
`read4(buf4)` 가 리턴한 값을 저장한다. `idx4 == cnt4` 이면 `buf4` 의
내용을 모두 읽은 것을 의미한다. `read4(buf4)` 를 호출해도 된다는
의미이다. `int nread = 0` 을 선언하여 `buf4` 에서 `buf` 에 복사한
문자의 개수를 저장한다.

`nread < n` 동안 다음을 반복한다. 
* `idx4 == cnt4` 이면 `buf4` 를 모두 `buf` 에 복사했다는 의미이다. 
  * `cnt4 = read4(buf4)` 를 수행한다.
  * `idx4 = 0` 을 수행한다.
  * `cnt4 == 0` 이면 더이상 읽을 문자가 없다는 의미이다. 반복문을 종료한다.
* `buf[nread] = buf4[idx4]` 를 수행한다. `nread, idx4` 를 하나씩 증가한다.

모든 반복을 마치면 `nread` 가 곧 답이다.

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.cpp)

# Complexity

```
O(N) O(1)
```
