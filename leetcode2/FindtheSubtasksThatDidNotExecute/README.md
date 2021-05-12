# Problem

[Find the Subtasks That Did Not Execute](https://leetcode.com/problems/find-the-subtasks-that-did-not-execute/)

# Implementation

```sql
-- 1007ms 26.44% 0B 100.00%
WITH RECURSIVE t AS (
  SELECT task_id, subtasks_count, 1 AS subtask_id
    FROM Tasks
   UNION ALL
  SELECT task_id, subtasks_count, subtask_id + 1 AS subtask_id
    FROM t 
   WHERE subtask_id < subtasks_count
)
   SELECT t.task_id, t.subtask_id
     FROM t
LEFT JOIN Executed e
       ON t.task_id = e.task_id AND
          t.subtask_id = e.subtask_id
    WHERE e.subtask_id IS NULL
```   
