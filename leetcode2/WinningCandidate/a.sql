# Write your MySQL query statement below

# 256ms 60.79%
SELECT Name 
FROM Candidate 
WHERE id = (SELECT CandidateId 
            FROM Vote 
            GROUP BY CandidateId
            ORDER BY COUNT(*) DESC
            LIMIT 1);
