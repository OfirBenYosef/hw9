#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>
#include "string.h"
#include <cstdbool>
#include "input.h"
using namespace std;


int main(int argc, char **argv){
    if(check_args(argc,argv)){
        return 0; 
    }
    String the_rule(argv[1]);
    String *rule;
    size_t size;
    /* separate the field name from the rule */
    the_rule.split("=",&rule,&size);
    /* if the filed name fits to ip, check if the packets fits thr rule*/
    if((rule[0].trim().equals("src-ip")) || 
        (rule[0].trim().equals("dst-ip"))){
        Ip ip_rule(the_rule.trim());
        ip_rule.set_value(rule[1].trim());
        parse_input(ip_rule);

    }
    /* if the filed name fits to port, check if the packets fits thr rule*/
    if((rule[0].trim().equals("dst-port"))||
        (rule[0].trim().equals("src-port"))){
        Port port_rule(the_rule.trim());
        port_rule.set_value(rule[1].trim());
        parse_input(port_rule);

    }
    delete[] rule;
    return 0;
}