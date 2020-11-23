
-- 248ms 44.74%
SELECT
  id AS Id,
  CASE
    WHEN t.id = (SELECT a.id FROM tree a WHERE a.p_id IS NULL)
      THEN 'Root'
    WHEN t.id IN (SELECT a.p_id FROM tree a)
      THEN 'Inner'
    ELSE
      'Leaf'
  END AS Type
FROM
  tree t
ORDER BY Id

-- 252ms 41.35%
SELECT id,
  CASE
    WHEN p_id is NULL
      THEN 'Root'
    WHEN id IN (SELECT p_id FROM tree)
      THEN 'Inner'
    ELSE
      'Leaf'
  END AS Type
FROM Tree
    
