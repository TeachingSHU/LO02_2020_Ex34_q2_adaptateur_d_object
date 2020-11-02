#include "mylog.h"
#include "evenement.h"

//void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,const string& s){
//    evts<<TIME::Evt1jDur(d,s,h,TIME::Duree(0));
//}

// Avec gestion d'exceptions :

void MyLog::addEvt(const TIME::Date& d, const TIME::Horaire& h,const string& s){
    if (evts.begin()!=evts.end()){

        TIME::Agenda::iterator it = evts.end();
        it--;

        const TIME::Evt1jDur& lastEvent=dynamic_cast<const TIME::Evt1jDur&>(*(it));

        if (d < lastEvent.getDate() || (d == lastEvent.getDate() && h < lastEvent.getHoraire())) {
            throw LogError("Addition of a posterior event");
        }
    }

    evts<<TIME::Evt1jDur(d,s,h,TIME::Duree(0));
}



void MyLog::displayLog(std::ostream& f) const{
    for(TIME::Agenda::const_iterator it=evts.cbegin(); it!=evts.cend(); it++) {
        f<<dynamic_cast<const TIME::Evt1j&>(*it).getDate() << " - "
         <<dynamic_cast<const TIME::Evt1jDur&>(*it).getHoraire()
         <<":"<<(*it).getDescription()<<"\n";
    }
}

