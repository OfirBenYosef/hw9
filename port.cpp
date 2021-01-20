#include "string.h"
#include "field.h"
#include "port.h"
   // int range[2];

Port::Port(String pattern)
:Field(pattern,PORT){}

bool Port::set_value(String val){
    const char *to ="-";
    size_t size=0;
    String *cut_rule;
    val.split(to,&cut_rule,&size);
    if(size !=2 ){
        delete[] cut_rule;
        return false;
    }
    range[0]=cut_rule[0].to_integer();
    range[1]=cut_rule[1].to_integer();
    delete[] cut_rule;
    return true;
}
bool Port:: match_value(String val) const{
    int prt=val.to_integer();
    if((prt <= range[1]) && (prt >= range[0])){
        return true;
    }
    return false;
}


