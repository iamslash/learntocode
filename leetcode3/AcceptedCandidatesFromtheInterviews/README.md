# Problem

[Accepted Candidates From the Interviews](https://leetcode.com/problems/accepted-candidates-from-the-interviews/)

# Implementation

```
  SELECT c.candidate_id
    FROM Candidates c
    JOIN Rounds r
      ON c.interview_id = r.interview_id  
   WHERE c.years_of_exp >= 2     
GROUP BY c.candidate_id
  HAVING SUM(r.score) > 15;
```
