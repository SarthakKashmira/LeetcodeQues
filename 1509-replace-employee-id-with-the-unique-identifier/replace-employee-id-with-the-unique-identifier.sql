# Write your MySQL query statement below
select unique_id,name from Employees as e
LEFT JOIN EmployeeUNI as eu
ON e.id=eu.id