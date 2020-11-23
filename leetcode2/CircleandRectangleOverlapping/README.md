# Problem

[Circle and Rectangle Overlapping](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

Given Circle information `radius, x_center, y_center`, Rectangle
information `x1, y1, x2, y2`, Validate they are intersected. `(x1,
y1)` is left bottom, `(x2, y2)` is right top of the rectangle.

# Idea


Check `(x, y)` minimum distance from ciecle to rectangle less than
square of radius `r`. And You can validate the intersection with this
circle equation.

```
x^2 + y^2 <= r^2
```

If x1 * x2 < 0, x should be 0.
If y1 * y2 < 0, y should be 0.

# Implementation

* [go](a.go)

# Complexity

```
O(1) O(1)
```
