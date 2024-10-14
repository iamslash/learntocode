# Problem

[Guess the Word](https://leetcode.com/problems/guess-the-word/)

배열 `words[]`, 문자열 `secret`, 숫자 `allowedGuesses`, 객체 `master` 가 주어진다. `master.guess(word)` 는 `word` 가 `secret` 과 얼마나 같은지 그 숫자를 리턴한다. `allowedGuesses` 는 `master.guess()` 를 호출할 수 있는 숫자이다. `master.guess()` 가 `6` 을 리턴하면 답을 찾은 것이다. `allowedGuesses` 보다 작거나 같도록 `master.guess()` 를 호출하여 답을 찾도록 `findSecretWord()` 를 구현하라.

# Idea

우리는 주어진 단어 목록에서 비밀 단어 `secret`을 찾아야 합니다. 각 단어는 6글자이며, `master.guess(word)` 함수는 우리가 추측한 단어와 비밀 단어인 `secret`이 얼마나 일치하는지 숫자로 알려줍니다. 이때 중요한 것은 단순히 무작위로 단어를 추측하는 것이 아니라, 점진적으로 후보 단어들을 줄여가며 `secret`에 가까운 단어를 선택하는 방법입니다.

먼저, 단어 목록에서 임의의 단어를 선택하고, `master.guess(word)`를 호출하여 `secret`과 얼마나 일치하는지 확인합니다. `master.guess()`가 반환한 숫자(`matchCnt`)는 선택한 단어와 `secret`이 같은 위치에 같은 문자가 몇 개인지를 나타냅니다. 우리는 이 정보를 바탕으로, 추측한 단어와 `matchCnt`만큼 일치하는 단어들만 남겨서 새로운 후보군을 형성합니다. 그리고 이 과정을 반복해 나가면서 단어 목록을 점차 줄여 나갑니다.

하지만 무작위로 단어를 선택하는 전략은 실패할 위험이 있습니다. 예를 들어, 다음과 같은 경우를 생각해봅시다.

```c
secret: "zzzzzz"
words:["aaaaaa", "bbbbbb", "cccccc", "dddddd", "eeeeee", "ffffff", "gggggg", "hhhhhh", "iiiiii", "jjjjjj", "kkkkkk", "llllll", "mmmmmm", "nnnnnn", "oooooo", "pppppp", "qqqqqq", "rrrrrr", "ssssss", "tttttt", "uuuuuu", "vvvvvv", "wwwwww", "xxxxxx", "yyyyyy", "zzzzzz"]
allowedGuesses: 10
```

이 경우에는 단순히 무작위로 단어를 선택하면 제한된 `allowedGuesses` 안에 `secret`을 찾지 못할 가능성이 큽니다. 따라서 `secret`에 가까운 단어를 점진적으로 찾는 것이 훨씬 효과적입니다.

이를 위해 각 자리의 문자 빈도를 계산하는 방법을 사용할 수 있습니다. 먼저, 각 자리의 문자가 얼마나 자주 등장하는지를 기록하는 빈도 테이블을 만듭니다. 예를 들어, `words = ["acckzz","ccbazz","eiowzz","abcczz"]` 라는 단어 목록이 주어진 경우, 각 자리의 문자 빈도는 다음과 같이 계산할 수 있습니다.

```py
>>> from collections import Counter
>>> from pprint import pprint
>>> freqList = [Counter(word[i] for word in words) for i in range(6)]
>>> pprint(freqList)
[Counter({'a': 2, 'c': 1, 'e': 1}),
    Counter({'c': 2, 'i': 1, 'b': 1}),
    Counter({'c': 2, 'b': 1, 'o': 1}),
    Counter({'k': 1, 'a': 1, 'w': 1, 'c': 1}),
    Counter({'z': 4}),
    Counter({'z': 4})]
```

이 빈도 테이블을 통해 각 자리마다 자주 등장하는 문자가 무엇인지 알 수 있습니다. 예를 들어, 첫 번째 자리에서는 'a'가 가장 많이 등장했기 때문에, 이 정보를 바탕으로 `secret`에 가까운 단어를 선택할 수 있습니다.

빈도 테이블을 계산한 후, 각 단어의 '점수'를 계산합니다. 점수는 해당 단어가 `secret`과 얼마나 일치할 가능성이 높은지를 나타냅니다. 각 자리에서 자주 등장한 문자가 포함될수록 점수가 높아지며, 가장 높은 점수를 얻은 단어를 추측합니다.

이렇게 선택된 단어를 master.guess로 호출하여 그 결과를 바탕으로 다시 후보군을 필터링합니다. 필터링할 때는, 추측한 단어와 `matchCnt`만큼 일치하는 단어들만 남겨서 새로운 후보군을 형성합니다. 이 과정을 반복하면 후보군이 점차 줄어들면서도 `secret`이 포함된 후보를 유지할 수 있습니다.

마지막으로, master.guess에서 일치하는 문자가 6개라는 결과가 나오면 `secret`을 찾은 것이며, 이때 알고리즘은 종료됩니다.

빈도수를 참고하여 선택한 단어가 꼭 `secret`에 가장 가깝다는 보장은 없습니다. 다만, 빈도수가 높은 문자를 기준으로 단어를 선택하는 것은 단어 목록을 점차적으로 줄이는 데 효과적입니다.

이 전략의 핵심은 빈도수가 높은 문자를 가진 단어를 선택함으로써 `secret`과 정확히 일치하지 않더라도, 비슷한 단어들을 필터링하여 남은 후보군을 점점 좁히는 것입니다. 결국, `master.guess()`에서 반환된 일치한 문자의 개수(`matchCnt`)를 바탕으로 후보군을 필터링하면, 남은 후보군 내에서 `secret`이 반드시 포함되어 있게 됩니다.

# Implementation

- [c++11](a.cpp)
- [python3](a.py)
- [java17](MainApp.java)

# Complextiy

```
O(N) O(N)
```
