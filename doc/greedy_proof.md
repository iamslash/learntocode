# abstract

- `greedy algorithm` 을 적용할 수 있는지 판단 하려면 해당 문제에 대해
  `greedy choice property` (탐욕적 선택 속성) 과 `optimal
  substructure` (최적 부분 구조) 라는 두 가지 속성을 만족하는지
  증명해야 한다.
- `dynamic programming` 으로 해결하기에는 필요한 시간과 메모리가
  너무 클때 `greedy algorithm` 을 적용해보자.
- `greedy choice property` 는 `dynamic programming` 처럼 답의 모든 부분을
  고려하지 않고 탐욕적으로만 (지금 이순간 최저 혹은 최고) 선택하더라도
  최적해를 구할 수 있다는 것이다.  `optimal substructure` 는 문제에 대한
  최적해가 부분문제에 대해서도 역시 최적해라는 것이다.

# how to prove it

- `greedy choice property`
  - 선택한 답을 포함하는 최적해가 존재함을 보이자. 이 증명은 선택한 답과
    다른 최적해가 존재함을 가정하고, 이것을 조작해서 우리가 선택한 답을 포함하는
    최적해로 바꿀 수 있음을 보이자.
- `optimal substructure`
  - 각 단계에서 탐욕적으로(최적의) 선택했을때 전체 최적해를 구할 수
    있음을 보이자. 대부분의 경우 자명하다.

# example : [회의실배정](https://www.acmicpc.net/problem/1931)

- greedy choice property
  - "가장 종료 시간이 빠른 회의 (S-min) 을 포함하는 최적해가 반드시 존재한다." 를
    증명해보자.
  - `S` 의 최적해 중에 `S-min` 을 포함하지 않는 답이 있다고 하자. 이 답은
    서로 겹치지 않는 회의의 목록인데, 이 목록에서 첫 번째로 개최되는
    회의를 지우고 `S-min` 을 대신 추가해서 새로운 목록을 만들자. `S-min` 은
    `S` 에서 가장 일찍 끝나는 회의이기 때문에 지워진 회의는 `S-min` 보다
    일찍 끝날 수 없다. 따라서 두 번째 회의와 `S-min` 은 겹치는 일이
    없으며, 새로 만든 목록도 최적해 중 하나가 된다. 따라서 항상
    `S-min` 을 포함하는 최적해는 존재한다. 이러한 증명은 우리가 가장 일찍
    끝나는 회의를 선택해서 최적해를 얻는 것이 불가능해지는 경우는
    없음을 보여준다.
- optimal substructure
  - 자명해서 따로 증명할 필요가 없는 경우가 대부분이다. 첫 번째 회의를
    잘 선택하고 겹치는 회의를 모두 걸러냈다면, 남은 회의 중에 당연히
    최대한 많은 회의를 선택해야 한다.