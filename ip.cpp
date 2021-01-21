#include "ip.h"
#include <iostream>
#include <cstring>
#include "string.h"
#define MAX_INT 4294967295;

Ip::Ip(String pattern)
: Field(pattern,IP),low(0),high(0){}

bool Ip::set_value(String val){
    const char *the_make = "/";
    size_t size;
    String *ip_out;
    val.split(the_make,&ip_out,&size);
    if(size !=2 ){
        delete[] ip_out;
        return false;
    }
    else{
        int get_mask =ip_out[1].to_integer();
        String *ip;
        const char *dot =".";
        ip_out[0].split(dot,&ip,&size);
        unsigned int seg=0;
        for (int i = 0; i < SEGMENTS; i++){
            seg = seg + (ip[i].to_integer()<< (24-8*i)); 
        }
        unsigned int mask = MAX_INT;
        if (get_mask){
            mask=(mask<<(32-get_mask));
            low=(seg & mask);
            high=(seg |(~mask));
        }
        else{
            low=0;
            high=MAX_INT;
        }
        
        delete[] ip;
        delete[] ip_out;
        return true;
    }

}

bool Ip::match_value(String val) const{
        String *ip;
        const char *dot =".";
        size_t size;
        val.split(dot,&ip,&size);
        unsigned int seg=0;
        for (int i = 0; i < SEGMENTS; i++){
            seg = seg + ((ip[i].to_integer()) << (24-8*i)); 
        } 
        if((seg <= high) && (seg >= low)){
            delete[] ip;
            return true;
        }
        delete[] ip;
        return false;
}