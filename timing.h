#ifndef TIMING_H_INCLUDED
#define TIMING_H_INCLUDED

#include<string>
#include<cstring>
#include<iostream>


using  namespace  std;

namespace TIME
{
    class Date
    {
    public:
        int year, month, day;
        Date(int y, int m, int d): year(y), month(m), day(d)
        {
//            cout << "Construction of Date" << endl;
        }

        string toString() const
        {
            return std::to_string(year)
            + " "
            + std::to_string(month)
            + " "
            + std::to_string(day);
        }

        bool operator < (const Date & d) const{
            if(this->month < d.month && this->year < d.year && this->day < d.day) {
                return true;
            }
            else {
                return false;
            }
        }


        bool operator == (const Date & d) const {
            if(this->month == d.month && this->year == d.year && this->day == d.day) {
                return true;
            }
            else {
                return false;
            }
        }

        ~Date()
        {
//            std::cout << "Deconstruciton of Date" << std::endl;
        }
    };

    class Duree
    {
    public:
        int duree;
        Duree(int d): duree(d){
//            cout << "Construction of Duree" << endl;
        }

        string toString() const
        {
            return std::to_string(duree);
        }

        ~Duree()
        {
//            std::cout << "Deconstruciton of Duree" << std::endl;
        }

    };

    class Horaire
    {
    public:
        int hour, minute;
        Horaire(int h, int m):hour(h), minute(m){
//            cout << "Construction of Horaire" << endl;
        }

        string toString() const
        {
            return std::to_string(hour)
                   + " "
                   + std::to_string(minute);
        }


        bool operator < (const Horaire & h) const{
            if(this->hour < h.hour && this->minute < h.minute) {
                return true;
            }
            else {
                return false;
            }
        }

        ~Horaire()
        {
//            std::cout << "Deconstruciton of Horaire" << std::endl;
        }
    };

    inline std::ostream & operator<<(std::ostream & F, const Date & d) {
        string s = std::to_string(d.year)
                   + "/"
                   + std::to_string(d.month)
                   + "/"
                   + std::to_string(d.day);
        F << s;
        return F;
    }

    inline std::ostream & operator<<(std::ostream & F, const Duree & d) {
        string s = std::to_string(d.duree) + " minutes";
        F << s;
        return F;
    }

    inline std::ostream & operator<<(std::ostream & F, const Horaire & h) {
        string s = std::to_string(h.hour)
                   + ":"
                   + std::to_string(h.minute);
        F << s;
        return F;
    }


}

#endif // TIMING_H_INCLUDED
