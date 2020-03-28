//
// Created by LiuYang on 2020/3/27.
//

#ifndef TIME_TIME_H
#define TIME_TIME_H
#include <iostream>
#include <iomanip>


class Time
{
public:
    Time(int h = 0, int m = 0, int s = 0):hour(h), minute(m), second(s){}
    Time operator+(int s);
    Time operator-(int s);
    friend std::ostream &operator<<(std::ostream &os, const Time &t);
    Time operator++();
    Time operator--();
    Time operator++(int);
    Time operator--(int);
private:
    int hour, minute, second;
};

Time Time::operator+(int s)
{
    Time t = *this;
    t.second += s;
    if(t.second >= 60)
    {
        t.minute += t.second / 60;
        t.second %= 60;
    }
    if(t.minute >= 60)
    {
        t.hour += t.minute / 60;
        t.minute %= 60;
    }
    return t;
}

Time Time::operator-(int s)
{
    Time t = *this;
    t.second -= s;
    if(t.second < 0)
    {
        t.minute -= (abs(t.second) / 60 + 1);
        t.second += (abs(t.second) / 60 + 1) * 60;
    }
    if(t.minute < 0)
    {
        t.hour -= (abs(t.minute) / 60 + 1);
        t.minute += (abs(t.minute) / 60 + 1) * 60;
    }
    return t;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    os << t.hour << ':' ;
    os << std::setw(2) << std::setfill('0') << t.minute << ':';
    os << std::setw(2) << std::setfill('0') << t.second;
    return os;
}

Time Time::operator++()
{
    *this = *this + 1;
    return *this;
}

Time Time::operator++(int i)
{
    Time t = *this;
    ++*this;
    return t;
}

Time Time::operator--()
{
    *this = *this - 1;
    return *this;
}

Time Time::operator--(int i)
{
    Time t = *this;
    --*this;
    return t;
}


#endif //TIME_TIME_H
