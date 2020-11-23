# Abstract

- bitmask를 이용하여 집합을 구현하는 방법에 대해 적어본다.

# null set, full set

```cpp
int null_set = 0;
int full_set = (1 << 20) - 1;
```

# add a element

```cpp
set |= (1 << p);
```

# check a element included

```cpp
if (set & (1 << p))
    std::cout << "it is in" << std::endl;
```

# del a element

```cpp
set &= ~(1 << p);
```

# toggle a element

```cpp
set ^= (1 << p);
```

# set operation (added, intersection, removed, toggled)

```cpp
int added = (a | b);
int intersection = (a & b);
int removed = (a & ~b);  // 101 100
int toggled = (a ^ b);
```

# size of set (__builtin_popcount())

```cpp
int bit_cnt(int x) {
    if (x == 0) 
        return 0;
    return x % 2 + bit_cnt(x / 2);
}
int bit_cnt(int x) {
    return __builtin_popcount(x);
}
```

# find a min element (__builtin_ctz())

```cpp
int find_min_idx(int x) {
    return __builtin_ctz(x);
}
int first_one_bit = (set & -set);  //     00001100
                                   //   & 11110100
```

# del a min element

```cpp
set &= (set - 1); //    0110 
                  //  & 0101
```

# traversal of set

```cpp
// ex. 1101
//     1100 & 1101 = 1100
//     1011 & 1101 = 1001
//     1000 & 1101 = 1000
//     0111 & 1101 = 0101
//     0100 & 1101 = 0100
//     0011 & 1101 = 0001

for (int subset = set; subset; subset = ((subset - 1) & set)) {
    //
}
```

# pickup rightmost one

```cpp
// -x = ~x + 1
int y = set & -set;  // 0110 & 1010
```

# Check subset

```cpp
int a = 0xF // 1111
int b = 0x2 // 0010
if (a & b == b)
  print("b is subset of a");  
```
