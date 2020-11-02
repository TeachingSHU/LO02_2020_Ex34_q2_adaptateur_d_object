//
// Created by lunde on 2020/11/1.
//

#ifndef LO02_2020_EX34_MYLOG_H
#define LO02_2020_EX34_MYLOG_H

#include "log.h"
#include "evenement.h"


class MyLog : public Log {
private:
    Agenda evts;
public:
    void addEvt(const TIME::Date& d, const TIME::Horaire& h, const string& s);
    void displayLog(std::ostream& f) const;
};





#endif //LO02_2020_EX34_MYLOG_H
