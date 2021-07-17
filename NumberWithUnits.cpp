#include "NumberWithUnits.hpp"
#include <iostream>
using namespace ariel;

using namespace std;
namespace ariel{
    const double EPS = 0.001;
    static map<string, map<string, double>> con_map; 

    NumberWithUnits::NumberWithUnits(double val, string type){
        if ( val == 0){
            throw "invalid value";
        }
        if( con_map.find(type) == con_map.end()){
            throw "invalid unit";
        }
        this -> val = val;
        this -> type = type;
    }



    double NumberWithUnits::conversion(string first_unit, string second_unit, double value){
        if ( first_unit == second_unit){
            return value;
        }
        if (con_map[second_unit].find(first_unit) == con_map[second_unit].end()){
            throw "cant compare diffrent types!,error";
        }
        double ans = (value * con_map[second_unit][first_unit]);
        return ans;

    }
    void NumberWithUnits::multicasting(const string &str1, const string &str2){
        for ( auto &p: con_map[str1]){
            double cast = con_map[str2][str1] * p.second;
            con_map[str2][str1] = cast;
            con_map[str1][str2] = 1/cast;
        }

    }


    void NumberWithUnits::read_units(ifstream &file_name){
        string first, second, eq;
        double num1=0, num2=0;
        while(!file_name.eof()){
            file_name >> num1 >> first >> eq >> num2 >> second;
            con_map[first][second] = num2;
            con_map[second][first] = num1/num2;
            multicasting(first, second);
            multicasting(second,first);
        }
    };
            //overloading operators
    NumberWithUnits NumberWithUnits::operator+ (const NumberWithUnits &a)const {
        if ( this -> type.compare(a.type) == 0){
            NumberWithUnits ans(this->val + a.val, this -> type);
            return ans;
        }
        else{
            throw "error";
        }
    }
        NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& a)const{
                if ( this -> type.compare(a.type) == 0){
            NumberWithUnits ans(this->val - a.val, this -> type);
            return ans;
        }
        else{
            throw "error";
        }
        }
        NumberWithUnits &NumberWithUnits::operator+(){
            return *this;
        }
        NumberWithUnits &NumberWithUnits::operator-(){
            this -> val = this -> val * (-1);
            return *this;
        }
      
        NumberWithUnits& NumberWithUnits::operator++(){
            this -> val = this -> val +1;
            return *this;
        }
        NumberWithUnits& NumberWithUnits::operator++(int n){//postfix
              this -> val = this -> val +1;
            return *this;
        }
        NumberWithUnits& NumberWithUnits::operator--(){
             this -> val = this -> val -1;
             return *this;
        }
        NumberWithUnits& NumberWithUnits::operator--(int n){//postfix
             this -> val = this -> val -1;
             return *this;
        }

        bool NumberWithUnits::operator== (const NumberWithUnits& a)const{
            if (this -> type.compare(a.type) == 0 && abs(this -> val - a.val) < EPS){
                return true;
            }
            return false;

        }
        bool  NumberWithUnits::operator!= (const NumberWithUnits& a)const{
            if (!(this -> type.compare(a.type) == 0 && abs(this -> val - a.val) < EPS)){
                return true;
            }
            return false;

        }
        
        bool NumberWithUnits::operator<= (const NumberWithUnits& a)const{
            if( this -> val <= a.val && (this -> type.compare(a.type) == 0)){
                return true;
            }
            return false;
        }
        bool NumberWithUnits::operator< (const NumberWithUnits& a)const{
                if( this -> val < a.val && (this -> type.compare(a.type) == 0)){
                return true;
            }
            return false;
        }
        bool NumberWithUnits::operator> (const NumberWithUnits& a)const{
            if( this -> val > a.val && (this -> type.compare(a.type) == 0)){
                return true;
            }
            return false;
        }
        bool NumberWithUnits::operator>= (const NumberWithUnits& a)const{
            if ( this -> val >= a.val && (this -> type.compare(a.type) == 0)){
                return true;
            }
            return false;
        }
        NumberWithUnits operator*(const double a, const NumberWithUnits& b){
            if (a != 0){
                NumberWithUnits ans(b.val * a, b.type);
                return ans;
            }
            else {
                throw "you mustnt multiply by 0";
            }
        }
        NumberWithUnits NumberWithUnits::operator* ( double b){
            if (b != 0){
                NumberWithUnits ans(this -> val*b, this -> type);
                return ans;
            }
            else{  
                throw "you mustnt multiply by 0";
        }
        }


        
        NumberWithUnits& NumberWithUnits::operator*= (const NumberWithUnits& a){
            if( this -> type.compare(a.type) == 0){
                this -> val = this -> val * a.val;
                return *this;
            }
            else{
                throw "error";
            }
        }
        NumberWithUnits& NumberWithUnits::operator-= (const NumberWithUnits& a){
            if( this -> type.compare(a.type) == 0){
                this -> val = this -> val - a.val;
                return *this;
            }
            else{
                throw "error";
            }
        }
        NumberWithUnits& NumberWithUnits::operator+= (const NumberWithUnits& a){
            if( this -> type.compare(a.type) == 0){
                this -> val = this -> val + a.val;
                return *this;
            }
            else{
                throw "error";
            }
        }
        ostream& operator<< (ostream& os, const NumberWithUnits& a){
            return (os<<a.val << '[' << a.type << ']');
        }
        istream& operator>> (istream& is, NumberWithUnits& a){
            double input_val = 0;
            string input_type ;
            char c = '\0';
            is >> input_val >> c;
            while (c != ']'){
                if (c != '['){
                    input_type.insert(input_type.end(),c);
                }
                is >> c;
            }
            if (con_map.count(input_type) > 0){
                a.val = input_val;
                a.type = input_type;
            }
            else{
                throw "wrong types";
            }
            return is;

        }
 }

