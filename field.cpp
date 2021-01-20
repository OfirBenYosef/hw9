#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>
#include "string.h"

Field::Field(String pattern, field_type type){
    this->pattern=pattern;
    this->type=type;
}
Field::Field(String pattern){
    this->pattern=pattern;
    this->type=GENERIC;
}

Field::~Field(){}

field_type Field:: get_type() const{
    return type;
}
bool Field::set_value(String val){
    String trimed_string=val.trim();
    switch(type)
    {
        case IP:
            return((Ip*)this)->set_value(trimed_string);
        break;
        case PORT:
            return((Port*)this)->set_value(trimed_string);
        break;
        default:
            return false;
        
    }
    return false;
}
bool Field::match_value(String val) const{
        switch(type)
    {
        case IP:
            return((Ip*)this)->match_value(val);
        break;
        case PORT:
            return((Port*)this)->match_value(val);
        break;
        default:
            return false;
        
    }
    return false;

}

bool Field::match(String packet){
    String trimed_string =packet.trim();
    const char *pattern_splitter = "=";
    const char *packet_splitter = ",=";
    String *output_pattern;
    String *output_packet;
    size_t size=0;
    bool is_match=false;
    pattern.split(pattern_splitter,&output_pattern,&size);
    trimed_string.split(packet_splitter,&output_packet,&size);
    String the_rule=output_pattern[0];
    for(int i=0;i<(size-1);i++){
        if(output_packet[i].equals(the_rule)){
           is_match = match_value(output_packet[i+1]);
        }
        else{
            is_match=is_match;
        }
    }
    delete [] output_pattern;
    delete [] output_packet;
    return is_match;
}

