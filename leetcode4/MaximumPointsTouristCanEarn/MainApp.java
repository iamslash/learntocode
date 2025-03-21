// Copyright (C) 2025 by iamslash

import java.util.*;


// n: 2
// k: 1
// stayScore:
// 2 3
// travelScore:
// 0 2
// 1 0
//
//

// n: 3
// k: 2
// stayScore:
// 3 4 2
// 2 1 2
// travelScore:
// 0 2 1
// 2 0 4
// 3 2 0

// 307ms 26.37% 55.20MB 74.73%
// recursive dynamic programming
// O(N^2K) O(NK)
class Solution {
    
    private int dfs(int n, int k, int[][] stayScore,
                    int[][] travelScore, int[][] cache,
                    int day, int curr) {
        // base
        if (day >= k) {
            return 0;
        }
        
        // memo
        if (cache[curr][day] >= 0) {
            return cache[curr][day];
        }
        
        // recursion
        int maxScore = stayScore[day][curr] +
            dfs(n, k, stayScore, travelScore, cache, day + 1, curr);
        for (int next = 0; next < n; ++next) {
            if (next == curr) {
                continue;
            }

            maxScore = Math.max(maxScore, travelScore[curr][next] +
                                dfs(n, k, stayScore, travelScore,
                                    cache, day + 1, next));
        }

        return cache[curr][day] = maxScore;
    }
    
    public int maxScore(int n, int k, int[][] stayScore,
                        int[][] travelScore) {
        //
        int[][] cache = new int[n + 1][k + 1];
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            Arrays.fill(cache[i], -1);
        }

        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, dfs(n, k, stayScore, travelScore, cache, 0, i));
        }

        return ans;
    }
}

// 60ms 97.80% 55.50MB 35.16%
// iterative dyanmic programming
// O(NK) O(NK)
class Solution {

    public int maxScore(int n, int k, int[][] stayScore,
                        int[][] travelScore) {
        int[] curr = new int[n];
        int[] prev = new int[n];

        for (int day = k - 1; day >= 0; --day) {
            for (int city = 0; city < n; ++city) {
                int move = 0;
                for (int i = 0; i < n; ++i) {
                    move = Math.max(move, prev[i] + travelScore[city][i]);
                }
                int stay = Math.max(curr[city], prev[city] +
                                    stayScore[day][city]);
                curr[city] = Math.max(move, stay);
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }

        int maxScore = 0;
        for (int score : prev) {
            maxScore = Math.max(maxScore, score);
        }

        return maxScore;
    }

}
