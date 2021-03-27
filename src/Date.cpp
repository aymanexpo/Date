#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {
    this->d_ = 1;
    this->m_ = 1;
    this->y_ = 1970;
}

Date::Date(const Date &date) {
    this->d_ = date.d_;
    this->m_ = date.m_;
    this->y_ = date.y_;
}

Date::Date(int y, int m, int d) {
    if (y%400==0) {
        if(m==2&&(d>29||d<1)){
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
        else if(((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&(d<0||d>31)))
        {
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
        else if (((m == 4 || m == 6 || m ==9 || m == 11) && (d < 0 || d>30)))
        {
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
    }
    else if (y%400 != 0)
    {
        if (m == 2 && (d > 28 || d < 1)) {
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
        else if (((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d < 0 || d>31)))
        {
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
        else if (((m == 4 || m == 6 || m == 9 || m == 11) && (d < 0 || d>30)))
        {
            cerr << "*** Erreur : " << d_ << "/" << m_ << "/ " << y_ << " date fausse" << endl;
        }
    }
    else
    {
        this->d_ = d;
        this->m_ = m;
        this->y_ = y;
    }
}

Date::~Date() {
}

Date &Date::decr() {
    if (this->d_ > 1) {
        this->d_ -= 1;
    }
    else if (this->d_ == 1) {
        if (this->m_ == 3 && this->y_ % 400 == 0) {
            this->d_ = 29;
            this->m_ -= 1;
        }
        else if (this->m_ == 3 && this->y_ % 400 != 0) {
            this->d_ = 28;
            this->m_ -= 1;
        }
        else {
            if (this->m_ == 1) {
                this->d_ = 31;
                this->m_ = 12;
                this->y_ -= 1;
            }
            else if (this->m_ == 5 || this->m_ == 7 || this->m_ == 10 || this->m_ == 12) {
                this->d_ = 30;
                this->m_ -= 1;
            }
            else if (this->m_ == 2 || this->m_ == 4 || this->m_ == 8 || this->m_ == 9 || this->m_ == 11) {
                this->d_ = 31;
                this->m_ -= 1;
            }
        }
    }
    return *this;
}

Date &Date::incr() {
    if (this->d_ == 31 && (this->m_ == 1 || this->m_ == 3 || this->m_ == 5 || this->m_ == 7 || this->m_ == 8 || this->m_ == 10 || this->m_ == 12)) {
        if (this->m_ == 12) {
            this->d_ = 1;
            this->m_ = 1;
            this->y_ += 1;
        }
        else{
            this->d_ = 1;
            this->m_ += 1;
        }
    }
    else if (this->d_ == 30 && (this->m_ == 4 || this->m_ == 6 || this->m_ == 9 || this->m_ == 11)) {
        this->d_ = 1;
        this->m_ += 1;
    }
    else if (this->m_ == 2 && this->y_ % 400 == 0 && this->d_ == 29) {
        this->d_ = 1;
        this->m_ += 1;
    }
    else if (this->m_ == 2 && this->y_ % 400 != 0 && this->d_ == 28) {
        this->d_ = 1;
        this->m_ += 1;
    }
    else
    {
        this->d_ += 1;
    }
    return *this;
}

void Date::print() {
    if (this->d_<10) {
        if (this->m_ < 10){ 
            std::cout << "0" << this->d_ << "/" << "0" << this->m_ << "/" << this->y_ << endl; 
        }
        else {
            std::cout << "0" << this->d_ << "/" << this->m_ << "/" << this->y_ << endl;
        }
    }
    else {
        std::cout << this->d_ << "/" << this->m_ << "/" << this->y_ << endl;
    }
}
