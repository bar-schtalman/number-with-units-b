#include "NumberWithUnits.hpp"
#include <iostream>
#include <math.h>
using namespace std;
namespace ariel{
    const double EPS = 0.001;
    static map<std::string,map<std::string,double>> map;
    NumberWithUnits::NumberWithUnits(double val, string type){
        // if(val != 0){
        //     // throw {
        //     //     invalid_argument("error, 0 isnt a real value!");
        //     // }
        // }
        this -> val = val;
        this -> type = type;
    }
    void NumberWithUnits::read_units(std::ifstream& file_name){
        double num1 = 0 , num2 = 0;
        string str1 , str2, eq;
        while(file_name >> num1 >> str1 >> eq >> num2 >> str2){
            map[str1][str2] = num2;
            map[str1][str2] = 1/num2;

            for(auto& [key,value]:map[str1]){
                map[str2][key] = num1 * value;
                map[key][str2] = 1 / (num1 * value);
            }
            for(auto& [key,value]:map[str2]){
                map[str1][key] = num2 * value;
                map[key][str1] = 1 / (num2 * value);
            }
        }
    };
    // unari
    NumberWithUnits NumberWithUnits::operator+(){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator-(){
        this -> val = - this -> val;
        return *this;
    }
    // add operators
    NumberWithUnits NumberWithUnits::operator+ (const NumberWithUnits& a ){
        if (!connected(*this,a)){
            throw invalid_argument("cant add "+ this -> type + " and "+a.type); 
        }
            NumberWithUnits b(this -> val + map[this -> type][a.type]*a.val, this -> type);
            return b;
        }
    NumberWithUnits& NumberWithUnits::operator++(){
        this -> val ++;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){
        NumberWithUnits a(this -> val ++ , this -> type);
        return a;
    }
    NumberWithUnits& operator+= (const NumberWithUnits& a){
        if (connected(*this , a)){
            this -> val = this -> val + map[this -> type][a.type] * a.val;
            return *this;
        }
        throw invalid_argument("cant add "+ this -> type + " and "+a.type);
    }
    // subtraction operators
    NumberWithUnits NumberWithUnits::operator- (const NumberWithUnits& a ,const NumberWithUnits& b){
                if (connected(a,b)){
            NumberWithUnits c(a.val - map[a.type][b.type]*b.val, a.type);
            return c;
        }
        throw invalid_argument("cant substruct "+ a.type + " and "+b.type);            
    }
    NumberWithUnits& operator-= (const NumberWithUnits& a){
            NumberWithUnits n(this -> val, this -> type);
             if (connected(n , a)){
            this -> val = this -> val - map[this -> type][a.type] * a.val;
            return *this;
        }
        throw invalid_argument("cant substruct "+ this -> type + " and "+a.type);
    }

    NumberWithUnits& NumberWithUnits::operator--(){
        this -> val --;
        return *this;
    }
        NumberWithUnits& NumberWithUnits::operator--(int){
        NumberWithUnits a(this -> val --, this -> type);
        return a;
    }
    // multiply operators
    NumberWithUnits& operator*=(double n){
        this -> val *= n;
        return *this;
    }
     NumberWithUnits NumberWithUnits::operator* (const NumberWithUnits& a, double b){
        NumberWithUnits temp(a.val * b, a.type); 
        return temp;
    }
    NumberWithUnits NumberWithUnits::operator* (double a, const NumberWithUnits& b){
        return b*a;
    }
    //boolean oprators
    bool operator== (const NumberWithUnits& a, const NumberWithUnits& b){
        if(connected (a,b)){
            return (a.val == map[a.type][b.type]* b.val)
        }
        throw invalid_argument("error cant compare bitween diffrents unit types");
    }

    bool operator!= (const NumberWithUnits& a, const NumberWithUnits& b){
        return !(a == b);
        }
    bool operator< (const NumberWithUnits& a, const NumberWithUnits& b){
        if(connected(a,b)){
            return (a.val < map[a.type][b.type] * b.val);
        }
        throw invalid_argument("error cant compare bitween diffrents unit types");
    }

    bool operator> (const NumberWithUnits& a, const NumberWithUnits& b){
            if(connected(a,b)){
            return (a.val > map[a.type][b.type] * b.val);
        }
        throw invalid_argument("error cant compare bitween diffrents unit types");
    }

    bool operator<= (const NumberWithUnits& a, const NumberWithUnits& b){
        return (a < b || a == b) ;
        }
    
    bool operator>= (const NumberWithUnits& a, const NumberWithUnits& b){
        return  (a > b || a == b) ;}
    
    // input & output operators
    ostream& operator<< (ostream& os, const NumberWithUnits& a){
        os << a.val << '[' << a.type << ']'; 
        return os;
    }
    istream& operator>> (istream& is, NumberWithUnits& a){
        char s ;
        is >> a.val >> s >> a.type;
        return is;
    }
    bool NumberWithUnits::connected(const NumberWithUnits& a, const NumberWithUnits& b){
        if(map.find(a.type) != map.end() && map[a.type].find(b.type != map[a.type].end()){
            return true;
        }
        return false;
    }
 }

