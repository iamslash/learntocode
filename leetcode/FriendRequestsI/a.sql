# 223ms 98.23%
SELECT IFNULL((SELECT 
               ROUND(COUNT(DISTINCT requester_id, accepter_id) / COUNT(DISTINCT sender_id, send_to_id), 2)
     FROM friend_request, request_accepted), 0)
AS accept_rate;
