# Problem

```
// Given a long integer, `x`, count the number of values of `a`
// satisfying the following conditions:

// 1. a `XOR` x > x
// 2. 0 < a < x

// where `a` and `x` are long integers and `XOR` is the bitwise XOR
// operator.

// Print the total number of values of `a` satisfying the conditions
// above on a new line.

// ex)
// input 10
// output 5

// * explanation

// For `x` = 10, the following values of `a` satisfy our conditions:
// 1 `XOR` 10 = 11
// 4 `XOR` 10 = 14
// 5 `XOR` 10 = 15
// 6 `XOR` 10 = 12
// 7 `XOR` 10 = 13
```

# Idea

- x를 2이라고 하자. 이진수로 표현하면 0010이다. 그렇다면
  x보다 작은수는 0001하나 뿐이다. 이것을 x와 XOR하면 0011이다.
  따라서 a의 개수는 1이다.
- x를 10이라고 하자. 이진수로 표현하면 1010이라고 하자. 그렇다면 x보다
  작은수는 여러개가 존재한다. 그중 x와 XOR해서 1010보다 큰 결과는
  11??, 1011이 존재한다. 언급한 숫자들은 a가 아니고 x XOR a임을
  주의하자. 여기서 ?는 0도 되고 1도 된다는 의미이다. 이것을 2의 승수로
  표현하면 2^2, 2^0이다. 따라서 a의 개수는 2^2 + 2^0 = 5이다.
- x를 11 1010 0110이라고 x보다 작은 수는 여러개가 존재한다. 그중 x와
  XOR해서 11 1010 0110보다 큰 결과는 11 11?? ????, 11 1011 ????, 11
  1010 1???, 11 1010 0111이 존재한다. 이것을 2의 승수로 표현하면 2^6,
  2^4, 2^3, 2^0이다.  따라서 a의 개수는 2^6 + 2^4 + 2^3 + 2^0이다.
- 이제 2의 승수 표현의 패턴이 존재한다는 것을 알 수 있다. 이준수 x의
  MSB부터 가장 우측까지 순회하면서 0이 등장할때 마다 고것을 1로 바꾸고
  고것 이후 비트의 개수를 n으로 한다면 0이 등장한 만큼 2의 승수 표현을
  만들 수 있고 그것의 형태는 2^n이 된다.
- 다시 1010을 살펴보자. 0은 두번 등장한다. 첫번째 등장시 n은 2이고
  두번째 등장시 n은 0이다. 따라서 2의 승수표현은 2^2, 2^0이 된다.
- 다시 11 1010 0110을 살펴보자. 0은 네번 등장한다. 첫번째 등장시 n은
  6이고 그이후는 4, 3, 0이 된다.
- 그렇다면 x를 순회해서 0이 등장할때 마다 2의 승수 표현을 만들어서
  모두 더하면 답이 된다.
- 그러나 이것보다 더 잘 할 수 있는 방법이 있다. 2의 승수표현을 잘
  살펴보자.  1010의 경우 a의 개수는 2^2 + 2^0이다. 1010은 4비트이므로
  4비트로 만들 수 있는 모든 표현은 2^4가 된다. 2^4는 이진수표현으로 1
  0000 이다.  여기서 1를 빼면 1111이다. 이것은 2의 승수표현으로 2^3 +
  2^2 + 2^1 + 2^0이다.  이것에서 2^3, 2^1을 빼면 2^2 + 2^0이
  된다. 이것은 a의 개수와 같다. 2^3 + 2^1은 1010과 같다. 이것은 x와
  같다.
- 따라서 x를 이진수로 표현해서 자리수로 표현가능한 모든 경우의 수를
  X라고 할때 X - 1 에서 다시 x를 빼면 a의 개수가 나온다.

# Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

long theGreatXor(long x){
    // Complete this function
    int n_leading_zero_cnt = 0;
    long i = x;
    while (i >= 0) {
        n_leading_zero_cnt++;
        i = i << 1;
    }
    int n_bit_cnt = 8 * sizeof(x) - n_leading_zero_cnt;
    return pow(2, n_bit_cnt) - x - 1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long x;
        cin >> x;
        long result = theGreatXor(x);
        cout << result << endl;
    }
    return 0;
}
```

# Time Complexity

O(1)

# Space Complexity

O(1)
