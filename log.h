#if !defined(LOG_H)
#define LOG_H
#include "timing.h"
#include<iostream>

class Log {
    public:
        virtual void addEvt(const TIME::Date& d, const TIME::Horaire& h, const std::string & s)=0;
        virtual void displayLog(std::ostream& f) const=0;
};

/* Interface de exception
class exception {
public:
exception () noexcept;
exception (const exception&) noexcept;
exception& operator= (const exception&) noexcept;
virtual ~exception();
virtual const char* what() const noexcept;
}
*/

class LogError : public std::exception {
    std::string info;
public:
    LogError(const char* s) noexcept:info(s){}
    const char* what() const noexcept { return info.c_str(); }
};




#endif
