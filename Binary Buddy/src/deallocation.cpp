#include "deallocation.h"
#include <cmath>
#include <fstream>

// creation of buddies function in deallocation class

bool deallocation::buddies(node *a, node *b)
{
    var add = MEMORY * 2;
    if (floor((add + a->startAddress) / (2 * a->space)) == floor((add + b->startAddress) / (2 * b->space)))
    {
        return true;
    }
    return false;
}

// creation of check_merge function in deallocation class

void deallocation::check_merge()
{
    auto itr = m.begin(), prev_itr = itr;
    ++itr;
    while (itr != m.end())
    {
        auto prevNode = *prev_itr, currNode = *itr;
        if (prevNode->allocated || currNode->allocated || (prevNode->space != currNode->space) || !buddies(prevNode, currNode))
        {
            prev_itr = itr;
            ++itr;
            continue;
        }
        prevNode->space *= 2;
        prevNode->endAddress = prevNode->startAddress + prevNode->space;
        m.erase(itr);
        prev_itr = m.begin();
        itr = prev_itr;
        ++itr;
    }
}

// creation of deallocate function in deallocation class

bool deallocation::deallocate(var address)
{
    if (address >= MEMORY)
    {
        return false;
    }
    for (auto i : m)
    {
        if (address == i->startAddress && !i->allocated)
        {
            return false;
        }
        if (address == i->startAddress)
        {
            i->allocated = false;
            i->value = 0;
            check_merge();
            ofstream fout("info.log", ios::app);
            fout << "\nOperation: DELLOCATION ||"<<"\tDate TimeStamp:" << date_time  << endl;
            //fout << "Date TimeStamp:" << date_time << endl;
            cout << "\nOperation: DeLLOCATION"  << endl;
            fout.close();
            return true;
        }
    }
    return false;
}
