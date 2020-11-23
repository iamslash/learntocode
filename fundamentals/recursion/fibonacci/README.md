# Problem

숫자 `n` 이 주어지면 피보나치 수열을 구하는 문제이다.

# References

* [Program for Fibonacci numbers](https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/)

# Recursive way

## Idea

다음과 같은 부분문제를 정의할 수 있다.

```
fib(0) = 0
fib(1) = 1
fib(n) = fib(n-1) + fib(n-2)
```

다음과 같이 overlapping subproblem 이 존재한다. 캐시를 이용하면
최적화할 수 있다.

```
                           fib(5)   
                     /                \
               fib(4)                fib(3)   
             /        \              /       \ 
         fib(3)      fib(2)         fib(2)   fib(1)
        /    \       /    \        /      \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /     \
fib(1) fib(0)
```

## Implementation

* [c++11](a.cpp)

## Complexity

```
O(2^N) O(lgN)
```

# Iterative Way

## Idea

```cpp
// n: 3 2 1 0
// a: 0 1 1 2 
// b: 1 1 2 3
int fibonacci_i(int n) {
  int a = 0, b = 1;
  while (n-- > 0) {
    swap(a, b);
    b += a;
  }
  return a;
}
```

## Implemetation

* [c++11](a.cpp)

## Complexity

```
O(N) O(1)
```
