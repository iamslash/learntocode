// Copyright (C) 2021 by iamslash

import java.util.*;

// 5 4 9
// 

// 506ms 58.71% 123.2MB 19.39%
// priority queue
// O(NlgN) O(N)
class Solution {
    public int minStoneSum(int[] piles, int k) {
        Queue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        int maxSum = 0;
        for (int stone : piles) {
            maxSum += stone;
            pq.offer(stone);
        }
        while (k-- > 0) {
            Integer stone = pq.poll();
            int removed = (stone / 2);
            maxSum -= removed;
            stone -= removed;
            pq.offer(stone);
        }
        return maxSum;
    }
}

// 12ms 98.72% 121.4MB 43.20%
// hash map
// O(N) O(N)
class Solution {
    public int minStoneSum(int[] piles, int k) {
        int maxSum = 0, maxPile = 0;
        for (int pile : piles) {
            maxPile = Math.max(maxPile, pile);
            maxSum += pile;
        }
        int[] cnts = new int[maxPile + 1];
        for (int pile : piles) {
            cnts[pile]++;
        }
        while (k > 0 && maxPile > 1) {
            int removedCnt = Math.min(cnts[maxPile], k);
            maxSum -= (maxPile / 2) * removedCnt;
            cnts[(maxPile + 1) / 2] += removedCnt;
            k -= removedCnt;
            --maxPile;
        }
        return maxSum;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
