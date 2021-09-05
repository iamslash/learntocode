# Problem

[Count the Number of Experiments](https://leetcode.com/problems/count-the-number-of-experiments/)

# Implementation

```sql
WITH t AS
(
   SELECT platform, 
          experiment_name
     FROM () t1
     JOIN () t2
)

   SELECT t.platform, 
          t.experiment_name,
          COUNT(experiment_id) AS num_experiments
     FROM t
LEFT JOIN Experiments e
       ON t.platform = e.platform AND
          t.experiment_name = e.experiment_name
 GROUP BY t.platform, t.experiment_name;         
```

```
-- 520ms 100.00% 0B 100.00%
WITH t AS
(
   SELECT platform, 
          experiment_name
     FROM (
       SELECT 'Android' AS platform
        UNION
       SELECT 'IOS'
        UNION
       SELECT 'Web'
     ) t1
     JOIN (
       SELECT 'Reading' AS experiment_name
        UNION
       SELECT 'Sports' AS experiment_name
        UNION
       SELECT 'Programming' AS experiment_name
     ) t2
)

   SELECT t.platform, 
          t.experiment_name,
          COUNT(experiment_id) AS num_experiments
     FROM t
LEFT JOIN Experiments e
       ON t.platform = e.platform AND
          t.experiment_name = e.experiment_name
 GROUP BY t.platform, t.experiment_name;         
```
