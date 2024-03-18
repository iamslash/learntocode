# Problem

[Find Trending Hashtags](https://leetcode.com/problems/find-trending-hashtags/)

# Implementation

```sql
-- 476ms 100.00% 0B 100.00%
  SELECT CONCAT("#", SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, "#", -1), " ", 1)) AS hashtag,
         COUNT(*) AS hashtag_count
    FROM Tweets
   WHERE tweet_date BETWEEN "2024-02-01" AND "2024-04-29" 
GROUP BY hashtag
ORDER BY hashtag_count DESC, 
         hashtag DESC
   LIMIT 3;
```
