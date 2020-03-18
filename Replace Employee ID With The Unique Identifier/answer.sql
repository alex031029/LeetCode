# beware of difference of `where` and `on`
# Write your MySQL query statement below

select `unique_id`, `name` from EmployeeUNI right join Employees on EmployeeUNI.id = Employees.id;
