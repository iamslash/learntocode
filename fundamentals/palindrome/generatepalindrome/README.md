- [Problem](#problem)
- [Idea](#idea)

------

# Problem

숫자 `num` 이 주어지면 palindrome 을 리턴해 보자.

# Idea

`num` 으로 `type` 에 따라 짝수 palindrome, 홀수 palindrome 을 만들 수 있다.

```cpp
//    n: 123
// type: 1
//    x: 123  12 123 1232 12321
//    y: 123 123  12    1     0
int64_t genPalindrome(int n, int type) {
    int64_t x = n;
    int64_t y = n;

    if (type == 1) {
        x /= 10;
    }
    
    while (y > 0) {
        x = x * 10 + y % 10;
        y /= 10;
    }

    return x;
}
```
