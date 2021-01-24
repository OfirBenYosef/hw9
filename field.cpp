#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>
#include "string.h"

/* Field(String pattern, field_type type) default constructor */
Field::Field(String pattern, field_type type){
    this->pattern=pattern;
    this->type=type;
}
/*Ftring(String pattern) - copy constructor*/
Field::Field(String pattern){
    this->pattern=pattern;
    this->type=GENERIC;
}

/* destructor */
Field::~Field(){}

/* returnes 0 if the field type is ip or 1 if it's port*/
field_type Field:: get_type() const{
    return type;
}
/* defines the set of valid values for the field according to it's type*/
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
/* returns true if val fits the values */
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
/* returns true iff the packet fits the fields rule*/
bool Field::match(String packet){
    String trimed_string =packet.trim();
    if (!(&trimed_string)){
        return false;
    }
    const char *pattern_splitter = "=";
    const char *packet_splitter = ",=";
    String *output_pattern;
    String *output_packet;
    size_t size=0;
    bool is_match=false;
    /* split the packet and the pattern, 
     * separate the field name from the rule */
    pattern.split(pattern_splitter,&output_pattern,&size);
    trimed_string.split(packet_splitter,&output_packet,&size);
    if (0==size){
        return false;
    }
    String the_rule=output_pattern[0];
    /* cheks if there is field in the packets which fits the rule*/
    for(int i=0;i<(int)(size-1);i++){
        if(output_packet[i].equals(the_rule)){
           is_match = match_value(output_packet[i+1]);
           break;
        }
        else{
            is_match=is_match;
        }
    }
    delete [] output_pattern;
    delete [] output_packet;
    return is_match;
}

