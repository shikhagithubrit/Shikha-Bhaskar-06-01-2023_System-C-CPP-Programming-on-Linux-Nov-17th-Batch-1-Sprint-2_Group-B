#ifndef DEALLOCATION_CPP_H
#define DEALLOCATION_CPP_H

 #include "allocation.h"

class deallocation 
{
public:
    bool buddies(node *a, node *b);
    void check_merge();
    bool deallocate(var address);
};

#endif