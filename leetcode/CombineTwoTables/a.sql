SELECT P.FirstName, P.LastName, A.City, A.State 
FROM Person P LEFT OUTER JOIN Address A
ON P.PersonId = A.PersonId;
