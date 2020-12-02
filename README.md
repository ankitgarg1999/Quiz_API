# Quiz_API
The API is a file which can be run in the terminal and supports all the functionality that has been asked. It has been implemented in cpp.

There are three courses available :- Physics, Chemistry and Maths
The student names in the database:- S1, S2, S3
Quiz names available for each course :- Q1,Q2
Currently none of the students is registered with any of the courses

Now, you have to enter one of the three strings (“enroll”, “attempt”, “feedback”) for each particular API.
There are 3 type of queries (corresponding to each API)

1.	enroll
It enrolls the student (S1,S2 or S3) with one of the courses.
It takes input course name and the student name

2.	attempt
Student can attempt the quiz of the course with which It has enrolled. It asks for thr student name, course name, quiz name. 
It then prints the questions. Then you submit your answers. There are 4 questions. You are graded out of 4. 

3.	feedback
This asks for a student name, and prints all the quizzes with the marks attempted by the student
