#ifndef DATETYPE_CPP
#define DATETYPE_CPP
#include "DateType.h"
#include <iostream>
using namespace std;

static int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
static string monthName[]={"Error", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

Date::Date(int d, int m, int y)
{
    if(m<1 || m>12)
        throw string("Invalid month.");
    else if(d<1 || d>daysInMonth[m])
        throw string("Invalid day.");
    else if(y<1583)
        throw string("Invalid year.");

    year=y;
    day=d;
    month=m;
}
int Date::getMonth()
{
    return month;
}
string Date::getMonthAsString()
{
    return monthName[month];
}
int Date::getYear()
{
    return year;
}
int Date::getDay()
{
    return day;
}
Relation Date::ComparedTo(Date aDate)
{
    if(year < aDate.year)
        return LESS;
    else if(year > aDate.year)
        return GREATER;
    else if(month < aDate.month)
        return LESS;
    else if(month > aDate.month)
        return GREATER;
    else if(day < aDate.day)
        return LESS;
    else if(day > aDate.day)
        return GREATER;
    else
        return EQUAL;
}
Date Date::Adjust(int daysAway)
{
    int d=day+daysAway;
    int m=month;
    int y=year;
    int daysInThisMonth;
    bool finished=false;

    while(!finished)
    {
        daysInThisMonth=daysInMonth[m];
        if(m==2)
            if( y%4==0 && !(y%100)==0 || (y%400==0))
                daysInThisMonth++;

        if(d <= daysInThisMonth)
            finished=true;
        else{
            d-=daysInThisMonth;
            m=(m%12)+1;
            if(m==1)
                y++;
        }
    }
    Date returnDate(d,m,y);

    return returnDate;
}
#endif // DATETYPE_CPP
