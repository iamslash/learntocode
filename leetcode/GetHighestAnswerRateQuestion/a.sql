
-- 167ms 44.26%
SELECT question_id AS survey_log
FROM survey_log
GROUP BY question_id
ORDER BY COUNT(answer_id) / COUNT(IF(action='show', 1, 0)) DESC
LIMIT 1
