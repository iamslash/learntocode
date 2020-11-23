SELECT S.hacker_id, H.name
FROM Submissions S 
INNER JOIN Challenges C
INNER JOIN Hackers H
INNER JOIN Difficulty D
ON S.challenge_id = C.challenge_id
AND S.hacker_id = H.hacker_id
AND C.difficulty_level = D.difficulty_level
AND D.score = S.score
GROUP BY S.hacker_id, H.name
HAVING COUNT(C.challenge_id) > 1
ORDER BY COUNT(S.score) DESC, S.hacker_id ASC;

