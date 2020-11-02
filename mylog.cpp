//
// Created by lunde on 2020/11/1.
//


#include "myLog.h"
#include "evenement.h"

using namespace TIME;

void MyLog::addEvt(const Date& d, const Horaire& h,const string& s)
{

    // Seems that the code is problematic. But the general idea should be OK.
    evts<<Evt1jDur(d,s,h,Duree(0));
}
void MyLog::displayLog(std::ostream& f) const
{
    for(Agenda::iterator it=Agenda::begin(); it!=Agenda::end(); ++it)
        f<<(*it).getDate()<<" - "<<dynamic_cast<const Evt1jDur&>(*it).getHoraire()<<":"<<(*it).getDescription()<<"\n";
}