# Problem

[Find All Possible Recipes from Given Supplies](https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/)

문자열의 모음 `recipes[], ingredients[][], supplies[]` 가 주어진다.
`recipes[i]` 는 `ingredients[i]` 들로 만들 수 있다.  `supplies[]` 는
나에게 주어지는 재료들이다. `receipes[i]` 는 다시 다른 요리를 위한
재료로 사용할 수 있다. `recipes[]` 중 만들 수 있는 것들을 구하라.

# Idea

예를 들어 `recipes = ["bread"], ingredients = [["yeast","flour"]],
supplies = ["yeast","flour","corn"]` 의 경우를 살펴보자.

```
bread: yeast flour
```

따라서 답은 `[bread]` 이다.

`recipes[i]` 를 만들 수 있는지 확인하는 방법을 생각해 보자. 

* `ingredients[i]` 가 모두 `supplies[]` 에 존재해야 한다.
* `ingredients[i]` 를 만들 수 있다면 이 것을 `supplies[]` 에 포함시켜야 한다.

`ingredients[]` 를 순회하며 `ingredients[i]` 들이 `supplies[]` 에 모두
있다면 `recipes[i]` 를 `spplies[]` 와 답에 추가한다.  이 것을
`ingredients.length` 만큼 한다. `recipes[i], recipes[j]` 가
`supplies[]` 에 추가되는 순서 때문에 여러번 반복해야 한다.

# Implementation

* [java11](MainApp.java)

# Complexity

```
O(N^2M) O(N)
N: recipes.length
M: ingredients[i].length
```
