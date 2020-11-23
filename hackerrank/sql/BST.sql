/*
Enter your query here.
*/
SELECT B.N,   CASE 
                WHEN B.P IS NULL THEN "Root"
                WHEN (SELECT COUNT(B2.N) FROM BST B2 WHERE B2.P = B.N) > 0 THEN "Leaf"
                ELSE "Inner"
            END
FROM BST B
ORDER BY N;

