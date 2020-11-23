
# 161ms 79,88%
SELECT abs(a.x-b.x) AS shortest
FROM point a JOIN point b
WHERE a.x < b.x
ORDER BY abs(a.x-b.x) LIMIT 1;

# 169ms 71.79%
SELECT MIN(ABS(a.x - b.x)) AS shortest
FROM point a
  JOIN point b
    ON a.x != b.x;
