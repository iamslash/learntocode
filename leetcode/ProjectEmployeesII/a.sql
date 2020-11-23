
-- 538MS 43.07%
SELECT 
  project_id
FROM
  Project
GROUP BY
  project_id
HAVING
  COUNT(project_id) = (
    SELECT 
      COUNT(project_id)
    FROM
      Project
    GROUP BY
      project_id
    ORDER BY COUNT(project_id) DESC
    LIMIT 1
  )
