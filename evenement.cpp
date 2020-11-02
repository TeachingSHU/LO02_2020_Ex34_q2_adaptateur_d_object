#include "evenement.h"

using namespace TIME;
using namespace std;


string Evt1j::toString() const{
    stringstream f;
    f<<"***** Evt ********"<<"\n";
    f<<"Date="<<getDate()<<" objet="<<getDescription()<<"\n";
    return f.str();
}

string Evt1jDur::toString() const{
    stringstream f;
    f<<Evt1j::toString()<<"debut="<<debut<<" duree="<<duree<<"\n";
    return f.str();
}

string Rdv::toString() const{
    stringstream f;
    f<<Evt1jDur::toString()<<"personne="<<personne<<" lieu="<<lieu<<"\n";
    return f.str();
}

string EvtPj::toString() const{
    stringstream f;
    f<<"***** Evt ********"<<"\n";
    f<<"Date debut="<<getDateDebut()<<" Date fin="
    <<getDateFin()<<" objet="<<getDescription()<<"\n";
    return f.str();
}

ostream& operator<<(ostream& f, const TIME::Evt& e){
    e.afficher(f);
    return f;
}

Agenda& Agenda::operator<<(const Evt& e) {
    events.push_back(e.clone());
    return *this;
}

void Agenda::afficher(std::ostream& f) const {
    /*
    for(unsigned int i = 0 ; i < events.size() ; i++) {
        events[i]->afficher(f);
    } */


    for(vector<Evt *>::const_iterator it = events.begin() ;
         it != events.end() ;
         it++) {
             (*it)->afficher(f);
    }

}

