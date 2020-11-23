
# Wrong Answer
SELECT
  MAX(num) AS num
FROM my_numbers
GROUP BY num
HAVING COUNT(num) = 1
ORDER BY num DESC
LIMIT 1;

# 194ms 67.24%
SELECT
  MAX(a.num) AS num
FROM
  (SELECT
    num
   FROM
    my_numbers
   GROUP BY num
   HAVING COUNT(num) = 1) AS a;
