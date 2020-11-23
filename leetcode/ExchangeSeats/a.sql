
-- 364ms 6.27%
SELECT
  IF(id < (SELECT count(*) from seat),
     IF(id mod 2 = 0, id - 1, id + 1),
     IF(id mod 2 = 0, id - 1, id))
AS id, student
FROM seat
ORDER BY id ASC;
