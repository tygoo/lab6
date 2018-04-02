#include<string.h>
#include "student.h"
#include <iostream>
using namespace std;
/*
нэр (public хандалтын түвшинтэй тэмдэгтийн цуваа хадгалах хаяган хувьсагч)
оюутны дугаар(private хандалтын түвшинтэй тэмдэгтийн цуваа хадгалах хаяган хувьсагч)
курс (public хандалтын түвшинтэй эерэг бүхэл тоо)
голч (private хандалтын түвшинтэй 0-4 хооронд байх бутархай тоо)
тоо (private хандалтын түвшинтэй хэдэн объект үүссэн байгааг тоолох статик гишүүн өгөгдөл)
*/
//----------------------------------------------------
/*
Классын функц:
анхдагч байгуулагч: нэр, дугаарт санах ой нөөцөлж хоосон утга онооно, курсэд 1, голчид 0 гэсэн утга онооно.
параметертэй байгуулагч: 4 гишүүн өгөгдөлд параметерээр утга авч онооно
хуулагч байгуулагч: өөр объектийг хуулж үүснэ. ингэхдээ хаяган хувьсагч дээр гардаг асуудлыг бодолцох хэрэгтэй.
хуулагч функц: өөр объектийн утгыг дуудаж байгаа объектод хуулна
оюутныг курсээр нь харьцуулах (bool greatThan(student &), bool lessThan(student &), bool isEqual(student &))
оюутны нэрээр харьцуулах (bool before(student &), bool after(student &))
гишүүн өгөгдөл тус бүрийн утгыг буцаах, утга оноох get, set функцууд
устгагч функц: нөөцөлсөн санах ойг чөлөөл
статик гишүүн өгөгдлийг хэвлэх
*/
student::student(char n[] = "", unsigned int c = 1, char id[] ="", float avr = 0){
    set_all_data(n, c, id,avr);
    objectCount++;
}
student:: student(const student &obj){
}
void student::set_all_data(char *_name, unsigned int _c, char *_id, float _avr){
    set_name(_name);
    set_id(_id);
    set_course(_c);
    set_avr(_avr);
}
void student::set_name(char *name_){
    name = new char[strlen(name_) + 1];
    strcpy(name , name_);
}
void student::set_id(char *id_){
    student_id = new char[strlen(id_) + 1];
    strcpy(student_id, id_);
}
void student::set_course(unsigned int c_){
    course = c_;
}
void student::set_avr(float avr_){
    average = avr_;
}
void student::copy_data(student &obj){
    student_id = new char[strlen(obj.get_id()) + 1];
    strcpy(student_id, obj.get_id());
    course = obj.get_course();
    average = obj.get_avr();
}
char* student::get_name(){
    return name;
}
char* student::get_id(){
    return student_id;
}
int student:: get_course(){
    return course;
}
float student:: get_avr(){
    return average;
}
bool student::greatThan(student &obj){
    if(course > obj.course){
        return true;
    }
    else{
        return false;
    }
}
bool student::lessThan(student &obj){
    if(course < obj.course){
        return true;
    }
    else{
        return false;
    }
}
bool student::isEqual(student &obj){
    if(course == obj.course){
        return true;
    }
    else{
        return false;
    }
}
bool student::before(student &obj){
    if(strcmp(name, obj.name) < 0){
        return true;
    }
    else{
        return false;
    }
}
bool student::after(student &obj){
    if(strcmp(name, obj.name) > 0){
        return true;
    }
    else{
        return false;
    }
}
int student::get_obj_count(){
    return objectCount;
}
void student::change_value(student &obj){
    char *n;
    char *_id_;
    unsigned int _course;
    float _average;

    n = name;
    _id_ = student_id;
    _course = course;
    _average = average;

    name = obj.name;
    student_id = obj.student_id;
    course = obj.course;
    average = obj.average;

    obj.name = n;
    obj.student_id = _id_;
    obj.course = _course;
    obj.average = _average;
}
student::~student(){
delete name;
delete student_id;
}
int student::objectCount = 0;
