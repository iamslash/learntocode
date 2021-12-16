# Problem

[Reorder Data in Log Files](https://leetcode.com/problems/reorder-data-in-log-files/)

문자열의 모음 `logs[]` 가 주어진다. `logs[i]` 는 영문 소문자, 숫자 와 공백으로
구성되어 있다. `len(logs[i]) > 2` 이다. `logs[i][0]` 을 log-id 라고 하자.
`logs[i]` 는 다음과 같은 2 종류가 있다.

* Letter-logs: log-id 를 제외한 단어들은 영문 소문자이다.
* Digit-logs: log-id 를 제외한 단어들은 숫자이다.

다음과 같은 규칙으로 `logs[]` 를 정렬하라.

* letter-logs 는 digit-logs 앞으로 온다.
* letter-logs 는 사전 순으로 정렬한다. 두 letter-logs 가
  같다면 log-id 의 사전순으로 정렬한다.
* digit-logs 는 주어진 순서를 유지한다.

# Idea

문제의 조건이 복잡하다. 문제를 잘 읽고 요구사항을 정확히 파악해야
한다.  `["let1 art1 b1"]` 는 옳바른 입력이 아니다. `["let1 art b1"]`
는 옳바른 입력이다. 숫자 이후는 모두 숫자이이어야 한다.

`log[i]` 를 공백을 구분자로 하여 log-id 와 나머지 부분으로
나눈다. 나머지 부분을 log-msg 라고 하자. `log-msg[0]` 이 문자이면
letter-logs 이고 `log-msg[0]` 이 숫자이면 digit-logs 이다.  그리고
다음과 같은 비교 함수를 구현한다.

* `String a` 를 선언하여 `log[i]` 의 첫번째 단어를 저장한다.
* `String b` 를 선언하여 `log[i]` 의 두번째 단어를 저장한다.
* `a` 의 `log-id, log-msg` 를 `a-log-id, a-log-msg` 라고 하자.
* `b` 의 `log-id, log-msg` 를 `b-log-id, b-log-msg` 라고 하자.
* `a-log-msg[0]` 이 문자, `b-log-msg[0]` 이 문자이면 `a` 는
  letter-logs 이고 `b` 는 letter-logs 이다. 다음을 수행한다.
  * `a-log-msg, b-log-msg` 를 사전순으로 비교하거나 `a-log-id,
    b-log-id` 를 사전순으로 비교한 결과를 리턴한다.
* `a-log-msg[0]` 이 문자, `b-log-msg[0]` 이 숫자이면 `a` 는
  letter-logs 이고 `b` 는 digit-logs 이다. a 가 b 보다 먼저이다. 즉,
  -1 을 리턴한다.
* `a-log-msg[0]` 이 숫자, `b-log-msg[0]` 이 문자이면 `a` 는 digit-logs
  이고 `b` 는 letter-logs 이다. a 가 b 보다 나중이다. 즉, 1 을
  리턴한다.
* `a-log-msg[0]` 이 숫자, `b-log-msg[0]` 이 숫자이면 `a` 는 digit-logs
  이고 `b` 는 digit-logs 이다. 주어진 순서를 유지한다. 즉, 0 을
  리턴한다.

# Implementation

* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(1)
```
