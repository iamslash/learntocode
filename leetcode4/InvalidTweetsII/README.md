# Problem

[Invalid Tweets II](https://leetcode.com/problems/invalid-tweets-ii/)

# Implementation

```sql
-- 638ms 23.24% 0B 100.00%
SELECT tweet_id
  FROM Tweets
 WHERE CHAR_LENGTH(content) > 140 OR
       LENGTH(content) - LENGTH(REPLACE(content, '@', '')) > 3 OR
       LENGTH(content) - LENGTH(REPLACE(content, '#', '')) >3
 ORDER BY tweet_id ASC     
```
