#ifndef ALLOCATION_CPP_H
#define ALLOCATION_CPP_H
 #include "buddy.h"

class allocation {
    public:
    var give_fitter(var value);
    vector<node *> give_slots(var space, var fitter);
    bool allocate(var value);

};

#endif