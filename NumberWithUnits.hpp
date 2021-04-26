#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

namespace ariel {
    class NumberWithUnits{
        private:
       
        public:
        double val;
        std::string type;
        NumberWithUnits(double val, std::string type){};
        static void read_units(std::ifstream &file_name);
        //overloading operators
        friend NumberWithUnits operator+ (const NumberWithUnits& a ,const NumberWithUnits& b);
        friend NumberWithUnits operator+ (const NumberWithUnits& a);
        NumberWithUnits& operator++();
        NumberWithUnits& operator++(int n);
        friend NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b);

        friend NumberWithUnits operator- (const NumberWithUnits& a);
        NumberWithUnits& operator--();

        friend bool operator== (const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator!= (const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<= (const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator< (const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator> (const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>= (const NumberWithUnits& a, const NumberWithUnits& b);

        friend NumberWithUnits operator* (const NumberWithUnits& a, double b);
        friend NumberWithUnits operator* (double a, const NumberWithUnits& b);
        NumberWithUnits& operator*=(double n);
        NumberWithUnits& operator-= (const NumberWithUnits& a);
        NumberWithUnits& operator+= (const NumberWithUnits& a);
        friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& a);
        friend std::istream& operator>> (std::istream& is, NumberWithUnits& a);
    };
}


 