#include<bits/stdc++.h>
using namespace std;

class quiz{
public:
    vector<string> questions;
    vector<string> answers;
    // Feed in the actual data
    quiz() {
        
    }
    quiz (vector<string> que, vector<string> ans){
        questions = que;
        answers = ans;
    }

    vector<string> get_questions(){
        return questions;
    }
    
    int evaluate(vector<string> attempt){
        int marks = 0;
        for (int i=0;i<4;i++){
            if (attempt[i] == answers[i])
                marks++;
        }
        return marks;
    }
};

class course{
public:
    string course_name;
    unordered_map<string,quiz> q_list;
    course (){
        
    }
    course(string name){
        course_name = name;
    }
    void insert(string name,quiz q){
        q_list[name] = q;
    }

    quiz get_quiz(string name){
        return q_list[name];
    }
    
    vector<string> quiz_list(){
        vector<string> output;
        for (auto it:q_list){
            output.push_back(it.first);
        }
        return output;
    }
};

class student {
public:
    string name;
    unordered_map<string,course> courses;
    vector<string> attempts;
    vector<string> fetch_quiz(string co_name,string q_name){
        return courses[co_name].get_quiz(q_name).get_questions();
    }
    
    string score_attempt(string co_name,string q_name, vector<string> answers){
        int marks = courses[co_name].get_quiz(q_name).evaluate(answers);
        string output = to_string(marks) + "/ 4";
        string output2 = "Course Name : " + co_name + "Quiz Name: " + q_name + " " + output;
        attempts.push_back(output2);
        return output;
    }
    
    void enroll(string co_name,course to_enroll){
        courses[co_name] = to_enroll;
        cout << "Student enrolled successfully\n";
    }
    
    vector<string> get_attempts(){
        return attempts;
    }
    
};

class student_list{
public:
    unordered_map<string,student> mp;
    
    student get_student(string s){
        return mp[s];
    }
    void new_student(string name){
        student new_st;
        new_st.name = name;
        mp[name] = new_st;
    }
    void enroll(string co_name, string st_name, course to_enroll){
        mp[st_name].enroll(co_name, to_enroll);
    }
};

int main(){
    //Creating a dummy database
//    course_list all_courses;
    student_list all_students;
    all_students.new_student("S1");
    all_students.new_student("S2");
    all_students.new_student("S3");
    course Physics("Physics");
    course Chemistry("Chemistry");
    course Maths("Maths");
    vector<string> questions;
    vector<string> answers;
    questions.push_back("Which one is the kill curse? a) Avara Kadavra b) Patronius charm c) Stupify d) SectumSepra");
    questions.push_back("Which one is the Voldemort? a) Harry Potter b) Tom Riddle c) Dumbledore d) Vernom Dudely");
    questions.push_back("Which one is 1 + 2? a) 1 b) 2 c) 3 d) 4");
    questions.push_back("What is 1/0? a) 0 b) 1 c) infinite d) not defined");
    answers.push_back("a");
    answers.push_back("b");
    answers.push_back("c");
    answers.push_back("d");
    quiz q1(questions, answers);
    Physics.insert("Q1",q1);
    Physics.insert("Q2",q1);
    Chemistry.insert("Q1",q1);
    Chemistry.insert("Q2",q1);
    Maths.insert("Q1",q1);
    Maths.insert("Q2",q1);
    string q;
    while (cin >> q){
        if (q == "enroll"){
            string st_name;
            string co_name;
            cout << "Enter your name:\n";
            cin >> st_name;
            cout << "Enter course name:\n";
            cin >> co_name;
            if (co_name == "Physics"){
                all_students.enroll("Physics",st_name,Physics);
            } else if (co_name == "Chemistry"){
                all_students.enroll("Chemistry",st_name,Chemistry);
            } else if (co_name == "Maths"){
                all_students.enroll("Maths",st_name,Maths);
            }
        } else if (q == "attempt"){
            string st_name, co_name, q_name, ans1,ans2,ans3,ans4;
            cout << "Enter your name:\n";
            cin >> st_name;
            cout << "Enter course name:\n";
            cin >> co_name;
            cout << "Enter the quiz name:\n";
            cin >> q_name;
            vector<string> question_paper = (all_students.get_student(st_name)).fetch_quiz(co_name,q_name);
            // Print the quiz;
            for (int i=0;i<question_paper.size();i++){
                cout << question_paper[i] << "\n";
            }
            cout << "Enter your answers\n";
            cin >> ans1 >> ans2 >> ans3 >> ans4;
            vector<string> attempt;
            attempt.push_back(ans1);
            attempt.push_back(ans2);
            attempt.push_back(ans3);
            attempt.push_back(ans4);
            string feedback = (all_students.mp[st_name]).score_attempt(co_name,q_name,attempt);
            cout << feedback << "\n";
            
        } else if (q == "feedback"){
            string st_name;
            cout << "Enter your name:\n";
            cin >> st_name;
            vector<string> all_attempts = (all_students.get_student(st_name)).get_attempts();
            for (int i=0;i<all_attempts.size();i++){
                cout << all_attempts[i] << "\n";
            }
        }
        
    }
}

