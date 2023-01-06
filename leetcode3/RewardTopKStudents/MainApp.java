// Copyright (C) 2023 by iamslash

import java.util.*;

// 73ms 91.19% 50.5MB 64.22%
// hash map, heap
// O(NlgN) O(N)
class Student {
    public int id = 0;
    public int score = 0;
    public Student(int id, int score) {
        this.id = id;
        this.score = score;
    }
}
class Solution {
    public List<Integer> topStudents(String[] positive_feedback,
                                     String[] negative_feedback,
                                     String[] reports,
                                     int[] student_id,
                                     int k) {
        Set<String> posScoreSet = new HashSet<>();
        Set<String> negScoreSet = new HashSet<>();
        Queue<Student> pq = new PriorityQueue<>((a, b) -> {
                if (a.score == b.score) {
                    return a.id - b.id;
                }
                return b.score - a.score;
        });
        for (String feedback : positive_feedback) {
            posScoreSet.add(feedback);
        }
        for (String feedback : negative_feedback) {
            negScoreSet.add(feedback);
        }
        for (int i = 0; i < reports.length; ++i) {
            int id = student_id[i];
            int score = 0;
            String[] tokens = reports[i].split(" ");
            for (String token : tokens) {
                if (posScoreSet.contains(token)) {
                    score += 3;
                }
                if (negScoreSet.contains(token)) {
                    score -= 1;
                }
            }
            pq.offer(new Student(id, score));
        }
        List<Integer> ans = new ArrayList<>();
        while (k-- > 0) {
            ans.add(pq.poll().id);
        }
        return ans;
    }
}
