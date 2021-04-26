#include "NumberWithUnits.hpp"
#include <iostream>
using namespace std;
namespace ariel{
    void NumberWithUnits::read_units(std::ifstream &file_name){};
    NumberWithUnits& NumberWithUnits::operator+= (const NumberWithUnits& a){
        return *this;
    }
    NumberWithUnits operator+ (const NumberWithUnits& a){
        return a;
    }
    NumberWithUnits& NumberWithUnits::operator++(){
        return *this;
    }
        NumberWithUnits& NumberWithUnits::operator++(int n){
        return *this;
    }
    NumberWithUnits operator- (const NumberWithUnits& a ,const NumberWithUnits& b){
        return a;
    }
    NumberWithUnits operator+ (const NumberWithUnits& a ,const NumberWithUnits& b){
        return a;
    }
    NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits& a){
        return *this;
    }
    NumberWithUnits operator- (const NumberWithUnits& a){
        return a;
    }
    NumberWithUnits& NumberWithUnits::operator--(){
        return *this;
    }
    bool operator== (const NumberWithUnits& a, const NumberWithUnits& b){
        return false;
    }
    NumberWithUnits& NumberWithUnits::operator*=(double n){
        return *this;
    }
    bool operator!= (const NumberWithUnits& a, const NumberWithUnits& b){return false;}
    bool operator<= (const NumberWithUnits& a, const NumberWithUnits& b){return false;}
    bool operator< (const NumberWithUnits& a, const NumberWithUnits& b){return false;}
    bool operator> (const NumberWithUnits& a, const NumberWithUnits& b){return false;}
    bool operator>= (const NumberWithUnits& a, const NumberWithUnits& b){return false;}
    NumberWithUnits operator* (const NumberWithUnits& a, double b){
        return a;
    }
    NumberWithUnits operator* (double a, const NumberWithUnits& b){
        return b;
    }
    ostream& operator<< (ostream& os, const NumberWithUnits& a){

        return os;
    }
    istream& operator>> (istream& is, NumberWithUnits& a){
        string s ;
        is >> a.val >> s >> a.type;
        return is;
    }

 }

