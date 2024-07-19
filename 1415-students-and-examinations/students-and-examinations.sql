# Write your MySQL query statement below
select st.student_id,st.student_name,su.subject_name,count(e.student_id) as attended_exams from Students as st
cross join subjects as su
left join Examinations as e ON st.student_id=e.student_id and su.subject_name=e.subject_name
group by st.student_id,st.student_name,su.subject_name
order by st.student_id,su.subject_name