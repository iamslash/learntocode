// Copyright (C) 2022 by iamslash

import java.util.*;

//   i
// 1 6 4
// greatPq: 1 4
//  lessPq: 6  

// 171ms 54.86% 139.3MB 5.03%
// min max heap
//   addNum: O(NlgN) O(N)
//   findMedian: O(1) O(N)
class MedianFinder {
    Queue<Integer> greatPq = new PriorityQueue<>((a, b) -> b - a);
    Queue<Integer> lessPq = new PriorityQueue<>();

    public MedianFinder() {}
    
    public void addNum(int num) {
        if (lessPq.size() == greatPq.size()) {
            greatPq.offer(num);
        } else {
            lessPq.offer(num);
        }
        if (!lessPq.isEmpty() && !greatPq.isEmpty() &&
            lessPq.peek() < greatPq.peek()) {
            int a = greatPq.poll();
            int b = lessPq.poll();
            greatPq.offer(b);
            lessPq.offer(a);
        }      
    }
    
    public double findMedian() {
        if (greatPq.size() > lessPq.size()) {
            return (double)greatPq.peek();
        }
        return (greatPq.peek() + lessPq.peek()) / 2.0;
    }
}
