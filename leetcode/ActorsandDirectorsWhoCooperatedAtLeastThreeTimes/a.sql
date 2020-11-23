-- 241ms 56.63%
SELECT 
  actor_id, 
  director_id
FROM
  ActorDirector
GROUP BY 
  actor_id, director_id
HAVING
  COUNT(actor_id) >= 3
;  
