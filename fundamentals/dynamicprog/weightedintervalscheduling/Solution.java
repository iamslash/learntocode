import java.util.*;

public class Solution {
    static class Job {
        int start, end, profit;
        Job(int s, int e, int p) {
            start = s;
            end = e;
            profit = p;
        }
    }
    
    public static int schedule(Job[] jobs) {
        Arrays.sort(jobs, Comparator.comparingInt(j -> j.end));
        int[] dp = new int[jobs.length];
        dp[0] = jobs[0].profit;
        for (int i = 1; i < jobs.length; i++) {
            int include = jobs[i].profit;
            int lastNonConflict = findLastNonConflict(jobs, i);
            if (lastNonConflict != -1) {
                include += dp[lastNonConflict];
            }
            dp[i] = Math.max(dp[i - 1], include);
        }
        return dp[jobs.length - 1];
    }
    
    private static int findLastNonConflict(Job[] jobs, int index) {
        for (int i = index - 1; i >= 0; i--) {
            if (jobs[i].end <= jobs[index].start) {
                return i;
            }
        }
        return -1;
    }
}
