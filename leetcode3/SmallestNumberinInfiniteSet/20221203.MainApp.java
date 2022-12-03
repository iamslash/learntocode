// Copyright (C) 2022 by iamslash

import java.util.*;

// 27ms 68.23% 54.6MB 72.59%
// heap
//     addBack: O(NlgN) O(N)
// popSmallest: O(N) O(N)
class SmallestInfiniteSet {
    int minNum = 1;
    Queue<Integer> pq = new PriorityQueue<>();

    public int popSmallest() {
        int rst = minNum;
        // When pq.peek() is lesser than minNum
        if (!pq.isEmpty() && pq.peek() < minNum) {
            rst = pq.poll();
        } else {
            minNum++;
        }
        // Clean up same with return value
        while (!pq.isEmpty() && pq.peek() == rst) {
            pq.poll();
        }
        // return backed value up
        return rst;
    }
    
    public void addBack(int num) {
        pq.offer(num);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
