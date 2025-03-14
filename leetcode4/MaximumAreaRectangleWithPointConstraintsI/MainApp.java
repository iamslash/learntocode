// Copyright (C) 2025 by iamslash

import java.util.*;


// points: [[1,1],[1,3],[3,1],[3,3],[2,2]]
//
//   4
//   3 .   .
//   2   .
//   1 .   .
//   0 1 2 3 4

// 12ms 40.93% 44.90MB 49.74%
// hash set
// O(N^3) O(N)
class Solution {

    private boolean isValid(int[][] points, int x1, int y1, int x2, int y2) {
        int minX = Math.min(x1, x2);
        int maxX = Math.max(x1, x2);
        int minY = Math.min(y1, y2);
        int maxY = Math.max(y1, y2);

        // Check the point inside rectangle, on rectangle 
        for (int[] pt : points) {
            int x = pt[0], y = pt[1];
            if ((x > minX && x < maxX && y > minY && y < maxY) ||
                ((x == minX || x == maxX) && (y > minY && y < maxY)) ||
                ((y == minY || y == maxY) && (x > minX && x < maxX))) {
                return false;
            }
        }

        return true;
    }
    
    public int maxRectangleArea(int[][] points) {
        int n = points.length;
        Set<String> pointSet = new HashSet<>();

        for (int[] pt : points) {
            pointSet.add(pt[0] + "," + pt[1]);
        }

        int maxArea = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];

                if (x1 != x2 && y1 != y2) {
                    String leftTop = x1 + "," + y2;
                    String rightBottom = x2 + "," + y1;

                    if (pointSet.contains(leftTop) &&
                        pointSet.contains(rightBottom) &&
                        isValid(points, x1, y1, x2, y2)) {
                        int area = Math.abs(x1 - x2) * Math.abs(y1 - y2);
                        maxArea = Math.max(maxArea, area);
                    }
                }
            }
        }


        return maxArea;
    }
}



// sort
// 1ms 100.00% 44.62MB 70.47%
// O(N^2) O(1)
class Solution {

    // Sort the points array by x coordinate, and if x is equal, by y
    // coordinate in ascending order.
    private void sortPoints(int[][] points) {
        int n = points.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] > points[j][0] ||
                   (points[i][0] == points[j][0] && points[i][1] > points[j][1])) {
                    swap(points, i, j);
                }
            }
        }
    }

    // Swap two points in the array.
    private void swap(int[][] points, int i, int j) {
        int temp0 = points[i][0];
        int temp1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = temp0;
        points[j][1] = temp1;
    }

    public int maxRectangleArea(int[][] points) {
        sortPoints(points);
        int maxArea = -1;
        int n = points.length;

        // Assume point at index i is the bottom-left corner
        for (int i = 0; i < n - 3; i++) {
            // If two consecutive points have the same x coordinate,
            // they form the vertical side (height)
            if (points[i][0] == points[i + 1][0]) {
                int height = points[i + 1][1] - points[i][1];

                // Look for the right vertical edge among the
                // remaining points
                for (int j = i + 2; j < n - 1; j++) {
                    // If the current point does not share the same y
                    // coordinate as the bottom edge and its y
                    // coordinate is between the bottom and top, it
                    // would be inside or on the border
                    if (points[j][1] != points[i][1]) {
                        if (points[j][1] >= points[i][1] &&
                            points[j][1] <= points[i + 1][1]) {
                            break;
                        }
                    } else {
                        // If points[j] is at the bottom (same y
                        // coordinate as points[i]), check if the next
                        // point has the same x coordinate as
                        // points[j] and its y coordinate is equal to
                        // the top edge.
                        if (points[j + 1][0] == points[j][0] &&
                            points[j + 1][1] == points[i + 1][1]) {
                            int width = points[j][0] - points[i][0];
                            maxArea = Math.max(maxArea, width * height);
                            break;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        return maxArea;
    }

}

