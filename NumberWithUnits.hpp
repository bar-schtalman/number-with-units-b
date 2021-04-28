#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

namespace ariel {
    class NumberWithUnits{
        private:
            
            double val;
            std::string type;
        public:
            double getNum() const{
                return val;
        }
        
            std::string getUnit() const{
                return type;
        }
        bool connected(const NumberWithUnits& a, const NumberWithUnits& b);
        
            NumberWithUnits(double val, std::string type);
            static void read_units(std::ifstream &file_name);
            //overloading operators
            NumberWithUnits operator+ (const NumberWithUnits& a );
            NumberWithUnits operator+ ();
            NumberWithUnits& operator++();
            NumberWithUnits operator++(int n);
            friend NumberWithUnits operator-(const NumberWithUnits& a, const NumberWithUnits& b);

            NumberWithUnits operator-();
            NumberWithUnits& operator--();
            NumberWithUnits operator--(int);

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


 