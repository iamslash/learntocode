SELECT C.Name Customers 
FROM Customers C
WHERE C.Id NOT IN (SELECT CustomerId FROM Orders);
