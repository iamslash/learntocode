# Abstract

- 15 puzzle을 bitmask를 이용해서 표현하는 방법을 적는다.

# Implementation

- 15 puzzle의 상태를 64bit로 표현할 수 있다. 64bit를 16개의 그룹으로
  나눈다. LSB부터 MSB까지 4bit를 활용해서 해당 그룹에 위치한 숫자를
  표현할 수 있다. 예를 들어서 0...0100이면 15 puzzle의 0번째 위치에
  숫자 4가 있다는 의미이다.

```cpp
// 0 1 2 3
// 4 5 6 7
// 8 9 A B
// C D E F

// get the value which is wrote on mask at index
// index is 15 puzzle's index
int get_15(uint64_t mask, int index) {
  return (mask >> (index << 2)) & 0x0f;
}

// set the value which is on mask at index
uint64_t set_15(uint64_t mask, int index, uint64_t value) {
  return mask | ((value & 0x0F) << (index << 2));
}
```
