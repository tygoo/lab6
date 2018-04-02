#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include "student.cpp"
class student {
public:
    char *name;
    unsigned int course;
private:
    char *student_id;
    float average;
    static int objectCount;
public:
    student(char*, unsigned int, char*, float);
    ~student();
    student(const student &);
    void copy_data(student &);
    void set_all_data(char *, unsigned int, char*, float);
    char* get_name();
    char* get_id();
    int get_course();
    float get_avr();
    void set_name(char*);
    void set_id(char*);
    void set_course(unsigned int);
    void set_avr(float);
    bool greatThan(student &);
    bool lessThan(student &);
    bool isEqual(student &);
    bool before(student &);
    bool after(student &);
    int get_obj_count();
    void change_value(student &);
};

#endif // LAB6_H_INCLUDED
