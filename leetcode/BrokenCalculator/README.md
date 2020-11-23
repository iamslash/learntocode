# Problem

[Broken Calculator](https://leetcode.com/problems/broken-calculator/)

# Idea

두개의 숫자 `X, Y` 가 주어진다. 고장 난 계산기는 두배 혹은 하나 감소만
가능하다. `X` 를 최소의 숫자로 계산기를 조작하여 `Y` 를 계산해 내었을
때 그 최소의 조작수를 구하는 문제이다.

먼저 `int ans = 0` 을 선언하여 답을 저장한다. 다음과 같이 다양한 예를
통해서 몇가지 규칙을 발견할 수 있다.

* `X > Y` 일 때는 `X` 를 두배해봐야 `Y` 보다 커지기 때문에 `X` 를 하나
  감소할 수 밖에 없다. `ans = X - Y` 이다.
  * `X = 1024, Y = 1` 
* `Y & 1 == true` 일 때는 `Y` 가 홀수이다. `Y++, ans++` 를 수행하고
  다시 처음으로 돌아간다.
  * `X = 2, Y = 3`
* `Y & 1 == false` 일 때는 `Y` 가 짝수이다. `Y /= 2, ans++` 를 수행하고
  다시 처음으로 돌아간다.
  * `X = 2, Y = 2`

위 규칙은 `X < Y` 동안 수행한다.

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(lgY) O(1)
```
