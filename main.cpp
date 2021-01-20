#include "field.h"
#include "ip.h"
#include "port.h"
#include <iostream>
#include <cstring>
#include "string.h"
#include <Cstdbool>
#include "input.h"
using namespace std;
int main(int argc, char **argv){
   /* if(check_args(argc,argv)){
        return error_code;
    }*/
    String the_rule(argv[1]);
    String *rule;
    size_t size;
    the_rule.split("=",&rule,&size);
    if((rule[0].trim().equals("src-ip")) || (rule[0].trim().equals("des-ip"))){
        Ip ip_rule(the_rule);
        ip_rule.set_value(rule[1]);
        parse_input(ip_rule);

    }
    if((rule[0].trim().equals("dst-port"))||(rule[0].trim().equals("src-port"))){
        Port port_rule(the_rule);
        port_rule.set_value(rule[1]);
        parse_input(port_rule);

    }
    delete[] rule;
    return 0;
}