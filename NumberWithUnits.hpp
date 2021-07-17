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
        NumberWithUnits(double val, std::string type);

        static double conversion(std::string first_unit, std::string second_unit, double value);
        static void multicasting(const std::string &str1, const std::string &str2); 

        static void read_units(std::ifstream &file_name);
        //overloading operators
        NumberWithUnits operator+ (const NumberWithUnits& a )const;
        NumberWithUnits &operator+ ();
        NumberWithUnits operator-(const NumberWithUnits& a)const;
        NumberWithUnits &operator- ();
      
        NumberWithUnits& operator++();
        NumberWithUnits& operator++(int n);//postfix
        NumberWithUnits& operator--();
        NumberWithUnits& operator--(int n);//postfix

        bool operator== (const NumberWithUnits& a)const;
        bool operator!= (const NumberWithUnits& a)const;
        bool operator<= (const NumberWithUnits& a)const;
        bool operator< (const NumberWithUnits& a)const;
        bool operator> (const NumberWithUnits& a)const;
        bool operator>= (const NumberWithUnits& a)const;

        NumberWithUnits operator* ( double b);
        friend NumberWithUnits operator* (const double a, const NumberWithUnits& b);
        
        NumberWithUnits& operator*= (const NumberWithUnits& a);
        NumberWithUnits& operator-= (const NumberWithUnits& a);
        NumberWithUnits& operator+= (const NumberWithUnits& a);
        friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& a);
        friend std::istream& operator>> (std::istream& is, NumberWithUnits& a);
    };
}


 