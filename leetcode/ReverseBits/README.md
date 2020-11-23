# Problem

[Reverse Bits](https://leetcode.com/problems/reverse-bits/)

# Idea

Reverse bits of a given 32 bits unsigned integer.

Let's reverse the string "a b c d e f g h"

```
                    8 chars : a b c d e f g h
switch each half of 8 chars : e f g h a b c d
switch each half of 4 chars : g h e f c d a b
switch each half of 2 chars : h g f e d c b a
```

Similarily swich each half of chars log32 times

```

bm =       abcdefgh ihklmnop qrstuvwx yz012345
     (bm & 11111111 11111111 00000000 00000000) >> 16 ||
     (bm & 00000000 00000000 11111111 11111111) << 16
bm =       qrstuvwx yz012345 abcdefgh ihklmnop
     (bm & 11111111 00000000 11111111 00000000) >>  8 ||
     (bm & 00000000 11111111 00000000 11111111) <<  8
bm =       yz012345 qrstuvwx ihklmnop abcdefgh
     (bm & 11110000 11110000 11110000 11110000) >>  4 ||
     (bm & 00001111 00001111 00001111 00001111) <<  4
bm =       2345yz01 uvwxqrst mnopihkl efghabcd
     (bm & 11001100 11001100 11001100 11001100) >>  2 ||
     (bm & 00110011 00110011 00110011 00110011) <<  2 ||
bm =       452301yz wxuvstqr opmnklih ghefcdab
     (bm & 10101010 10101010 10101010 10101010) >>  1 ||
     (bm & 01010101 01010101 01010101 01010101) <<  1 ||
bm =       543210zy xwvutsrq ponmlkji hgfedcba
```

# Implementation

* [c++11](a.cpp)

# Complexity

```
O(1) O(1)
```
