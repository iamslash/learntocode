-- 338ms 38.13%

SELECT a.follower AS follower, COUNT(DISTINCT b.follower) AS num
FROM follow a INNER JOIN follow b
ON a.follower = b.followee
GROUP BY a.follower
