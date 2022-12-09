/* 
 * File:  date.h
 * Author: Ting Yin Sha
 * Created on November 3, 2022, 3:02 PM
 * Project: class specification
 */

#ifndef DATE_H
#define DATE_H


class Date{
private:
    int month;
    int day;
    int year;       
public:
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth()const;
    int getDay() const;
    int getYear() const;
    void printDate();
    
};


#endif /* DATE_H */

