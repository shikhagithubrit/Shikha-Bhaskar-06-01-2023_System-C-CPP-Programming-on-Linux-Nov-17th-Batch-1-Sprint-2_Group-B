#ifndef BUDDY_CPP_H
#define BUDDY_CPP_H

#include <iostream>
 #include <vector>
 #include <ctime>

using namespace std;

typedef size_t var;
var MEMORY = 0;
 time_t now = time(0);
char *date_time = ctime(&now);



struct node
{
public:
    var space, value;
    bool allocated;
    var startAddress, endAddress;
    node(var space) : space(space), value(0), allocated(false) {}
    node(var space, var value) : space(space), value(value), allocated(true) {}
};

vector<node *> m;


#endif