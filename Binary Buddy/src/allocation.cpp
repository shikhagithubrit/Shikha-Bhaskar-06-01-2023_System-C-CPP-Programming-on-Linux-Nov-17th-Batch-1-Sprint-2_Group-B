#include "allocation.h"
#include <cmath>
#include <fstream>

// creation of give_fitter function in allocation class

var allocation::give_fitter(var value)
{
    if (value == 1)
    {
        return 2;
    }
    return pow(2, ceil(log(value) / log(2)));
}

// creation of give_slots function in allocation class

vector<node *> allocation::give_slots(var space, var fitter)
{
    var number_of_slots = 2;
    if (space != fitter)
    {
        number_of_slots = 1 + (log(space / fitter) / log(2));
    }
    vector<node *> v(number_of_slots, NULL);
    v[0] = new node(fitter);
    for (var i = 1, s = fitter; i < number_of_slots; ++i, s *= 2)
    {
        v[i] = new node(s);
    }
    return v;
}

// creation of allocate function in allocation class

bool allocation::allocate(var value) 
{
    if (m.size() == 0)
    {
        return false;
    }
    var fitter = give_fitter(value);
    for (var i = 0; i < m.size(); ++i)
    {
        if (m[i]->space == fitter && !m[i]->allocated)
        {
            m[i]->value = value;
            m[i]->allocated = true;
             ofstream fout("info.log", ios::app);
            fout << "Operation: ALLOCATION"  << endl;
            cout << "Operation: ALLOCATION"  << endl;
            fout.close();
            return true;
        }
    }
    for (auto itr = m.begin(); itr != m.end(); ++itr)
    {
        node *temp = *itr;
        if (!temp->allocated && temp->space > fitter)
        {
            auto slots = give_slots(temp->space, fitter);

            // Division of slots

            slots[0]->value = value;
            slots[0]->allocated = true;
            slots[0]->startAddress = temp->startAddress;
            slots[0]->endAddress = temp->startAddress + slots[0]->space;
            for (var i = 1; i < slots.size(); ++i)
            {
                slots[i]->startAddress = slots[i - 1]->endAddress;
                slots[i]->endAddress = slots[i]->startAddress + slots[i]->space;
            }
            auto prev_itr = itr;
            --prev_itr;
            m.erase(itr);
            for (var i = 0; i < slots.size(); ++i)
            {
                prev_itr = m.insert(++prev_itr, slots[i]);
            }
            slots.clear();
            ofstream fout("info.log", ios::app);
            fout << "\nOperation: ALLOCATION ||"<<"\tDate TimeStamp:" << date_time  << endl;
            cout << "\nOperation: ALLOCATION"  << endl;
            fout.close();
            return true;
        }
    }
    return false;
}
