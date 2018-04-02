#include <iostream>
#include "student.h"
#include <string>
/*
    student(char*, unsigned int, char*, float);
    ~student();
    student(const student &);
    copy_data(student &);
    set_all_data(char *, unsigned int, char*, float);
    get_name();
    get_id();
    get_course();
    get_avr();
    set_name(char*);
    set_id(char*);
    set_course(unsigned int);
    set_avr(float);
    greatThan(student &);
    lessThan(student &);
    isEqual(student &);
    before(student &);
    after(student &);
    get_obj_count();
*/
using namespace std;
main(){
      int n;
    char *nme;
    char *id;
    unsigned int crs;
    float ave;
    cout << "how much student?" << "\n";
    cin >> n;
    student student[n];
//-------------------------------------- SET VALUE --------------------------------------
    for(int i = 0; i < n; i++){
        cout << "------------------------------------------------------------" << "\n";
        cout << "STUDENT NUMBER  -  " << i+1 << "\n";
        cout << "Enter "<< i+1 <<"student name:" << "\n";
        nme = new char[30];
        cin  >> nme;
        cout << "Enter "<< i+1 <<"student id:" << "\n";
        id = new char[20];
        cin >> id;
        cout << "Enter student level:" << "\n";
        cin >> crs;
        cout << "Enter student average: /it must between 0 and 4 float number/" << "\n";
        cin >> ave;
        student[i].set_all_data(nme,crs,id,ave);
    }
//--------------------------------------- SORT BY NAME ------------------------------------------------
    int temp = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(strcmp(student[i].get_name(), student[j].get_name()) < 0 && i != j){
                student[i].change_value(student[j]);
            }
        }
    }
//-------------------------------------- GET VALUE --------------------------------------------------
    for(int i = 0; i < n; i++){
        cout << "   " << student[i].get_name();
        cout << "   " <<student[i].get_id();
        cout << "   " <<student[i].get_course();
        cout << "   " <<student[i].get_avr() << "\n";
    }
//------------------------------------ SORT BY AVE -------------------------------------
    cout << "-----------------SORT BY NAME---------------------" << "\n";
    header();
    int tmp = 0;
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(student[i].get_avr() > student[j].get_avr() & i!=j){
                student[i].change_value(student[j]);
            }
        }
    }
    cout << "-----------------SORT BY AVERAGE---------------------" << "\n";
    header();
        for(int i = 0; i < n; i++){
        cout << "   " << student[i].get_name();
        cout << "   " <<student[i].get_id();
        cout << "   " <<student[i].get_course();
        cout << "   " <<student[i].get_avr() << "\n";
    }
    cout << "------------------ TOTAL STUDENT --------------------" << "\n";
    cout << student[1].get_obj_count() << "\n";
}
void header(){
    cout << "   NAME";
    cout << "   ID";
    cout << "   LEVEL";
    cout << "   AVERAGE" << "\n";
}
