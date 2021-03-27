#ifndef DATE_H
#define DATE_H

class Date {
public:
    Date();
    Date(const Date &);
    Date(int, int, int);
    virtual ~Date();
    Date &decr();
    Date &incr();
    void print();
private:
    int d_;
    int m_;
    int y_;
};

#endif // DATE_H
