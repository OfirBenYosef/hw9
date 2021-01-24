#include "string.h"
#include "field.h"
#include "port.h"
  /**
   *C'tor
   */
Port::Port(String pattern)
:Field(pattern,PORT){}
/**
 * @brif get the ports and convert it to int
 * set range 
 *is success return true else return false
 *@param cut_rule - only the port of val, size - the num of sub str
 */
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
/**
 *@brif get the port of val and convert it to int 
 *check if the port is between range[0] and range[1]
 *return true if the port is match 
 *else return false
 *@ptr - the port of val
 */
bool Port:: match_value(String val) const{
    int prt=val.to_integer();
    if((prt <= range[1]) && (prt >= range[0])){
        return true;
    }
    return false;
}


