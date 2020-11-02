#ifndef MYLOG_H_INCLUDED
#define MYLOG_H_INCLUDED

#include "log.h"
#include "evenement.h"


class MyLog : public Log {
private:
    TIME::Agenda evts;
public:
    void addEvt(const TIME::Date& d, const TIME::Horaire& h, const string& s);
    void displayLog(std::ostream& f) const;
};

/*
class MyLog : public Log, private TIME::Agenda {
public:
    void addEvt(const TIME::Date& d, const TIME::Horaire& h, const string& s);
    void displayLog(std::ostream& f) const;
};
*/

#endif // MYLOG_H_INCLUDED
