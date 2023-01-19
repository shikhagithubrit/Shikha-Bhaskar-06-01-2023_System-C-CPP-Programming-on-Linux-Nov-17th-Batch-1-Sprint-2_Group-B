#include "menu.h"
#include <fstream>
#include <cmath>

// creation of menu function in menubar class

void menubar::menu()
 {

    ofstream ferror("error.log", ios::app);  // open file in append mode
    cout << "\n====================================================================================\n";
    cout << "\n                           BINARY BUDDY ALGORITHM                                   \n";
    cout << "\n====================================================================================\n";
    cout << "\n The Amount of memory we reserve will be in power of 2^x (For Example: 2^10 = 1024)";
    cout << "\nEnter the value of x (x<32): ";
    cin >> MEMORY;
    if (MEMORY >= 32)
    {
        ferror <<"Error: Memory value is huge (x >= 32), program terminated"<<" || Date TimeStamp:" << date_time<< endl;
        cout << "Date TimeStamp:" << date_time  <<"Memory value is huge (x >= 32), program terminated\n"<< endl;
           exit(0);
       cout << "\n======================================================================================\n";
    }

    MEMORY = (var)pow(2, MEMORY);
    m.emplace_back(new node(MEMORY));  // insert the element in vector
    m[0]->startAddress = 0;
    m[0]->endAddress = m[0]->startAddress + m[0]->space;

    while (true)
    {
        int c;
        cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
        cout << "\n Press: [1] Allocate  [2] Deallocate  [3] Exit -> ";
 
        cin >> c;
        var value = 0;
       
        switch (c)
        {
        case 1:
            cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
            cout << "\n Enter the amount of memory to allocate (= Block Value): ";

            cin >> value;
        
            if (value == 0)
            {
                 cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";

                 ferror <<"Error: Zero(0) cannot be allocated"<<" || Date TimeStamp:" << date_time<< "\n";
                 cout <<"Date TimeStamp:" << date_time  <<"Error: Zero(0) cannot be allocated\n"<< endl;
                
                 break;
            }
            if (!allocate(value))    // calling of allocate function
            {
                cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
                ferror <<"Error: Memory insufficient or space is not availabe"<<" || Date TimeStamp:" << date_time<<"\n";
               
                cout << "Date TimeStamp:" << date_time  <<"Error: Memory insufficient or space is not available\n"<< endl;
               
                break;
            }
            cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
            cout << "\n THE BLOCKS IN MEMORY\n"
                 << endl;
            display();   // calling of display function
            break;
        case 2:
            cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
            cout << "\n Enter the start address of block to deallocate (Start): ";
            cin >> value;
            if (!deallocate(value))    // calling of deallocate function
            {   cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **\n";
             ferror<<"Error: Block is not allocated at given address"<<" || Date TimeStamp:" << date_time  <<"\n";
             cout << "Date TimeStamp:" << date_time  <<"Error: Block is not allocated at given address\n"<< endl;
             
                break;
            }
           
            cout << "\n THE BLOCKS IN MEMORY\n"<< endl;

            display();    // calling of display function
            break;
        case 3:
            cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
            ferror.close(); // close a file
            exit(0);
        default:
            cout << "\n Error: Invalid input" << endl;
        }
    }
}
