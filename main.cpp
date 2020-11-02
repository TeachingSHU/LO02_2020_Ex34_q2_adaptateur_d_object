#include <iostream>
#include "evenement.h"
using namespace std;
using namespace TIME;


int main(){

    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");

    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(10));
    Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");

    Evt1j* pt1= &e1; Evt1j* pt2=&e2; Evt1j* pt3=&e3; Evt1j* pt4=&e4;
    Evt1j& ref1=e1; Evt1j& ref2=e2; Evt1j& ref3=e3; Evt1j& ref4=e4;

    Rdv* pt=dynamic_cast<Rdv*>(pt1); if (pt) pt->afficher();
    pt=dynamic_cast<Rdv*>(pt2); if (pt) pt->afficher();
    pt=dynamic_cast<Rdv*>(pt3); if (pt) pt->afficher();
    // seule la conversion suivante renverra un pointeur non nul
    pt=dynamic_cast<Rdv*>(pt4); if (pt) pt->afficher();
    try { Rdv& r1=dynamic_cast<Rdv&>(ref1); r1.afficher(); }
    catch(bad_cast& e) { std::cout<<e.what()<<"\n"; }
    try { Rdv& r2=dynamic_cast<Rdv&>(ref2); r2.afficher(); }
    catch(bad_cast& e) { std::cout<<e.what()<<"\n"; }
    try { Rdv& r3=dynamic_cast<Rdv&>(ref3); r3.afficher(); }
    catch(bad_cast& e) { std::cout<<e.what()<<"\n"; }
    // seule la conversion suivante ne déclenchera pas d’exception
    try { Rdv& r4=dynamic_cast<Rdv&>(ref4); r4.afficher(); }
    catch(bad_cast& e) { std::cout<<e.what()<<"\n"; }


    /*
    Evt1j e1(Date(4,10,1957),"Spoutnik");
    Evt1j e2(Date(11,6,2013),"Shenzhou");
    Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(10));
    Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    */

    /*
    Agenda a;

    a << e1 << e2 << e3 << e4;
    a.afficher(std::cout);
    */

    /*
    e1.afficher();
    e2.afficher();
    e3.afficher();
    e4.afficher();
    */

    // Quel type de ligature ? Pourquoi ? Que faire ?
    // Grace a la ligature dynamique -> nous profitons du polymorphisme
    // On appelle la methode de l'objets d'origine (virtual)
    /*
    Evt1j* pt1= &e1;
    Evt1j* pt2=&e2;
    Evt1j* pt3=&e3;
    Evt1j* pt4=&e4;

    pt1->afficher();
    pt2->afficher();
    pt3->afficher();
    pt4->afficher();*/

    /*
    cout << e1 << endl;
    cout << e3 << endl;
    cout << e4 << endl;
    */

    /*
    Rdv* pt5= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt5->afficher();
    delete pt5;

    Evt1j* pt6= new Rdv(Date(12,11,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
    pt6->afficher();
    delete pt6;
    */





    return 0;
}


