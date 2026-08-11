# Write your MySQL query statement below
SELECT query_name,ROUND((SUM(q1.rating/q1.position)/COUNT(*)),2) AS quality,ROUND((SUM(q1.rating<3)/COUNT(*))*100,2) AS poor_query_percentage
FROM Queries q1
GROUP BY query_name