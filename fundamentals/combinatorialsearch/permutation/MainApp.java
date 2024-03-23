import java.util.*;

// 1ms 95.58% 44.5MB 45.96%
// back tracking
// O(N!) O(N!)
class Solution {
    private void dfs(int[] nums, List<List<Integer>> ans, int pos) {
        // base
        int n = nums.length;
        if (pos == n) {
            List<Integer> candList = new ArrayList<>();
            for (int num : nums) {
                candList.add(num);
            }
            ans.add(candList);
            return;
        }

        // recursion
        for (int i = pos; i < n; ++i) {
            // swap
            int tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;

            dfs(nums, ans, pos + 1);

            // swap
            tmp = nums[i];
            nums[i] = nums[pos];
            nums[pos] = tmp;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(nums, ans, 0);
        return ans;
    }
}
