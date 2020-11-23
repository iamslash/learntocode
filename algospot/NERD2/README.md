# Problem

[너드인가, 너드가 아닌가? 2 @ algospot](https://algospot.com/judge/problem/read/NERD2)

# Idea

참여자들은 문제 수 `p_i` 와 라면그릇 수 `q_i` 를 갖는다. 새로운 참여자를
추가 할때 마다 기존의 참여자들보다 `p_i`, `q_i` 가 작은지 검사한다.
만약 작다면 새로운 참여자는 참가 자격이 없다.

새로운 참여자가 참가 자격이 된다면 그 참여자의 `p_i`, `q_i` 를
기준으로 기존 참여자들 중 자격이 없는 참가자를 탈락 시킨다.

그렇게 한명의 참여자를 추가할 때 마다 등록된 유저의
수들을 더하면 답이 된다.

# Implementation

* [c++11](a.cpp)

# Time Complexity

```
O(N)
```
