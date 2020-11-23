# 207ms 67.99%
select DISTINCT(a.seat_id)
from cinema a 
join cinema b
  ON abs(a.seat_id - b.seat_id) = 1
  AND a.free = 1 AND b.free = 1
ORDER BY a.seat_id;
