# Problem

[Build Binary Expression Tree From Infix Expression](https://leetcode.com/problems/build-binary-expression-tree-from-infix-expression/)

# Idea

`Deque<Node> nodeDeq = new ArrayDeque<>()` 를 선언하여 Node 들을
저장한다. Node 들은 merge 되면서 마지막에 하나의 Node 만 남는다.

`Deque<Character> opDeq = new ArrayDeque<>()` 를 선언하여 `(, +, -, *,
/` 를 포함한 operator 를 저장한다.

숫자는 `nodeDeq` 에 저장하고 operator 는 `opDeq` 에 저장한다.  서로
관계 있는 것들끼리 모아서 `Node` 를 만들고 `nodeDeq` 의 `Node` 들은
merge 한다. 마지막에 `nodeDeq` 에 남는 `Node` 가 곧 답이다.


# Implementation

* [java8](Solution.java)

# Complexity

```
```
