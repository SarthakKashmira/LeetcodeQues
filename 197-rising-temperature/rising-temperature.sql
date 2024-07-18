# Write your MySQL query statement below
select id from Weather as w1
where w1.temperature >(
    select w2.temperature from Weather as w2
    where w2.recordDate=DATE_SUB(w1.recordDate,interval 1 day)
)