

-- 373ms 27.26%
SELECT ROUND(SUM(a.TIV_2016), 2) TIV_2016
FROM insurance a
WHERE 1 = (SELECT COUNT(*)
           FROM insurance b 
           WHERE a.LAT = b.LAT AND a.LON = b.LON) AND
      1 < (SELECT COUNT(*)
           FROM insurance b
           WHERE a.TIV_2015 = b.TIV_2015)
