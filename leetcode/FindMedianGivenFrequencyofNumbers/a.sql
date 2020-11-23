
-- 705ms 52.46%
SELECT AVG(n.Number) median
FROM Numbers n
WHERE n.Frequency >= ABS((SELECT SUM(Frequency)
                          FROM Numbers
                          WHERE Number <= n.Number) -
                         (SELECT SUM(Frequency)
                          FROM Numbers
                          WHERE Number >= n.Number))
