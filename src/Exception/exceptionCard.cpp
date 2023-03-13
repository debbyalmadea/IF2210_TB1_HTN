#include "exceptionCard.hpp"

using namespace std;

string ExceptionCard::message[] = {
    "Eittss kamu tidak memiliki kartu ABLITY ", 
    "Oopss, kartu ABILITY tersebut telah dimatikan sebelumnya, kamu tidak bisa memakai ABILITY ",
    "Kartu ABILITY pemain itu sudah dipakai sebelumnya. " ,
    "Waduuh, ternyata semua pemain sudah memakai kartu ABILITY. Yah, kamu kena sendiri, kemampuan kamu jadi abilityless. "
    };

ExceptionCard::ExceptionCard(int id, string cardName) : Exception(id), cardName(cardName) {};

ExceptionCard::ExceptionCard (const ExceptionCard& other) : Exception(other), cardName(other.cardName) {};

void ExceptionCard::print() const {
    cout << message[this->ID] ;

    if(this->ID == 0 || this->ID == 1) {
        cout << this->cardName <<  endl << "Silahkan lakukan perintah lain." << endl;
    }
    else if(this->ID == 2 || this->ID == 3) {
        cout << "Yah, sayang kartu ini kamu terbuang sia-sia." << endl;
    }
};

string ExceptionCard::getCardName() const { return this->cardName; }