// Copyright (C) 2023 by iamslash

import java.util.*;

//          i
// nums1: 1,2 2,3 4,5
// nums2: 1,4 3,2 4,1
//          j

// // 1ms 100.00% 42.8MB 55.56%
// // two pointers
// // O(N) O(N)
// class Solution {
//     public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
//         int n = nums1.length, m = nums2.length;
//         int i = 0, j = 0;
//         List<int[]> ans = new ArrayList<>();
//         while (i < n || j < m) {
//             int id = 0;
//             int val = 0;
//             // System.out.printf("i: %d, j: %d\n", i, j);
//             if (i < n && j < m) {
//                 if (nums1[i][0] == nums2[j][0]) {
//                     id = nums1[i][0];
//                     val = nums1[i][1] + nums2[j][1];
//                     i++;
//                     j++;
//                 } else if (nums1[i][0] < nums2[j][0]) {
//                     id = nums1[i][0];
//                     val = nums1[i][1];
//                     i++;
//                 } else {
//                     id = nums2[j][0];
//                     val = nums2[j][1];
//                     j++;
//                 }
//             } else if (i < n) {
//                 id = nums1[i][0];
//                 val = nums1[i][1];
//                 i++;
//             } else {
//                 id = nums2[j][0];
//                 val = nums2[j][1];
//                 j++;
//             }
//             ans.add(new int[]{id, val});
//         }
//         return ans.toArray(new int[0][]);
//     }
// }

// // 1ms 100.00% 43.2MB 22.22%
// // two pointers
// // O(N) O(N)
// class Solution {
//     public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
//         int n = nums1.length, m = nums2.length;
//         int i = 0, j = 0;
//         List<int[]> ans = new ArrayList<>();
//         while (i < n || j < m) {
//             int id = 0;
//             int val = 0;
//             // System.out.printf("i: %d, j: %d\n", i, j);
//             if (i < n && j < m && nums1[i][0] == nums2[j][0]) {
//                 id = nums1[i][0];
//                 val = nums1[i][1] + nums2[j][1];
//                 i++;
//                 j++;
//             } else if ((i < n && j >= m) ||
//                        (i < n && j < m && nums1[i][0] < nums2[j][0])) {
//                 id = nums1[i][0];
//                 val = nums1[i][1];
//                 i++;
//             } else {
//                 id = nums2[j][0];
//                 val = nums2[j][1];
//                 j++;
//             }
//             ans.add(new int[]{id, val});
//         }
//         return ans.toArray(new int[0][]);
//     }
// }

// 1ms 100.00% 42.8MB 55.56%
// two pointers
// O(N) O(N)
class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int i = 0, j = 0, n = nums1.length, m = nums2.length;
        List<int[]> ans = new ArrayList<>();
        while (i < n || j < m) {
            int id = Math.min(i < n ? nums1[i][0] : 1001, j < m ? nums2[j][0] : 1001);
            ans.add(new int[]{id, 0});
            if (i < n && nums1[i][0] == id) {
                ans.get(ans.size() - 1)[1] += nums1[i++][1];
            }
            if (j < m && nums2[j][0] == id) {
                ans.get(ans.size() - 1)[1] += nums2[j++][1];
            }
        }
        return ans.toArray(new int[0][]);
    }
}
