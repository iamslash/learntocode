# Problem

[Rectangle Overlap](https://leetcode.com/problems/rectangle-overlap/)

# References

* [C++ Solution with easy explanation](https://leetcode.com/problems/rectangle-overlap/discuss/133175/C%2B%2B-Solution-with-easy-explanation)

# Idea

두 사각형의 네 꼭지점이 주어진다. 두 사각형이 겹치는지 확인하라.

일차원 공간에서 다음과 같이 정리할 수 있다.

```
             x3,y2          x4,y2
               |--------------|
     |--------------|
     x1,y1         x2,y1
              
     x1 < x3 < x2  && x3 < x2 < x4 = x1 < x4 && x3 < x2
```

이차원 공간역시 비슷하게 정리할 수 있다.

```

               ____________________x4,y4
              |                   |
       _______|______x2,y2        |
      |       |______|____________|
      |      x3,y3   |
      |______________|
     x1,y1

              ____________________x2,y2
              |                   |
       _______|______x4,y4        |
      |       |______|____________|
      |      x1,y1   |
      |______________|
     x3,y3

      x1 < x4 && x3 < x2
      y1 < y4 && y3 < y2
```

# Implementation

* [go](a.go)

# Complexity

```
O(1) O(1)
```
