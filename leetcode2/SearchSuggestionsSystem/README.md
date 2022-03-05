# Problem

[Search Suggestions System](https://leetcode.com/problems/search-suggestions-system/)

문자열의 모음 `products[]`, 문자열 `searchWord` 가 주어진다.
`searchWord` 가 한 문자씩 입력될 때 마다 누적된 문자열로 시작되는 후보
문자열을 `products[]` 에서 최대 3 개 찾아 구하라.

# Idea

Java 의 경우 문자열의 모음을 대상으로 binary search 해 보자.  즉,
`Arrays.binarySearch(String[], String)` 의 특성을 이용하자.

```java
public class MainApp {
    private static void dump(String[] ss) {
        for (String s : ss) {
            System.out.printf("%s ", s);
        }
        System.out.println("");
    }
    public static void main(String[] args) {
        String[] products = {"mobile","mouse","moneypot","monitor","mousepad"};
        String searchWord = "mouse";
        Arrays.sort(products);
        dump(products);
        for (int i = 1; i <= searchWord.length(); ++i) {
            String word = searchWord.substring(0, i);
            System.out.printf("%2d: %s\n",
                              Arrays.binarySearch(products, word), word);
        }
    }
}
```

# Implementation

* [c++11](a.cpp)
* [java8](MainApp.java)

# Complexity

```
O(NlgN) O(N)
```
