// Copyright (C) 2020 by iamslash

// 5ms 95.57% 42.2MB 7.70%
// sort
// O(NlgN) O(N)
class Solution {
    public int[][] merge(int[][] I) {
        if (I.length == 0)
            return I;
        Arrays.sort(I, (a, b) -> {
            return Integer.compare(a[0], b[0]);
        });
        List<int[]> ans = new ArrayList<>();
        ans.add(I[0]);
        // System.out.println(Arrays.deepToString(I));
        for (int[] interval : I) {
            int[] last = ans.get(ans.size()-1); 
            if (last[1] < interval[0]) {
                ans.add(interval);
            } else {
                last[1] = Math.max(last[1], interval[1]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
