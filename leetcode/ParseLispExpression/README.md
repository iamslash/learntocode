# Problem

[Parse Lisp Expression](https://leetcode.com/problems/parse-lisp-expression/)

# Idea

문자열 `s` 가 주어진다. `let, add, mult` 로 구성된 리스프
문자열을 평가하는 문제이다. 

구현이 매우 까다롭다. 도움이 될만한 몇가지를 정리한다.

`stringstream m_ss` 를 멤버변수로 선언한다. `m_ss >> t` 와 같이 공백을
구분자로 하여 토큰을 파싱할 수 있다.

`s` 의 `(, )` 전 후에 공백을 삽입한다. 그렇게 하면 `stringstream` 으로
쉽게 파싱할 수 있다. 예를 들어 `(add 1 2)` 의 경우 ` ( add 1 2 ) ` 로
만들자.

`unordered_map<string, vector<int>> m_ctx` 를 멤버변수로
선언한다. `let` 으로 구성된 `key, val` 들은
`m_ctx[key].push_back(val)` 으로 저장하자. `m_ctx[k].back()` 가 곧
해당 스택에 맞는 값이 된다. 만약 해당 변수가 스택을 벗어나는 경우는
`m_ctx[key].pop_back()` 을 잊지 말자.

부분문제 `eval` 을 다음과 같이 정의한다.

```cpp
pair<string, int> eval()

return: token string, evaluated value
```

`eval()` 을 호출하면 하나의 토큰을 읽어서 평가한 후 결과를 리턴한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(N) O(N)
```
