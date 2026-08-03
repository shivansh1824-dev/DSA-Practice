# Write your MySQL query statement below
SELECT name,bonus
FROM Employee
LEFT JOIN Bonus ON Employee.empId=Bonus.empId
WHERE bonus IS NULL OR bonus<1000;