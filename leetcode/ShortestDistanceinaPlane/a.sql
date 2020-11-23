
-- 178ms 32.23%
SELECT ROUND(SQRT(POW(a.x - b.x, 2) + POW(a.y - b.y, 2)), 2) AS shortest 
FROM point_2d a
  JOIN point_2d b
  ON a.x != b.x OR a.y != b.y
ORDER BY shortest ASC
LIMIT 1
