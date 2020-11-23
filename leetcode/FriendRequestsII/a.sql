-- 161ms 37.14%
SELECT requester_id AS id,
  COUNT(requester_id) + (SELECT                                              COUNT(accepter_id)
                         FROM request_accepted
                         WHERE id = accepter_id) AS num                         
FROM request_accepted 
GROUP BY requester_id
ORDER BY num DESC
LIMIT 1

-- 124ms 99.78%
SELECT id, COUNT(*) AS num
FROM (
  SELECT requester_id AS id
  FROM request_accepted
    UNION ALL
    SELECT accepter_id
    FROM request_accepted
)
GROUP BY id
ORDER BY COUNT(*) DESC
LIMIT 1
