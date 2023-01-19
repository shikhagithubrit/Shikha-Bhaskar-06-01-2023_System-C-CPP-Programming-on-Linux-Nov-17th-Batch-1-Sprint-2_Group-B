#include "display.h"
#include <fstream>



// creation of display function in ShowData class

void ShowData::display()
{
    cout << "\n THE BLOCKS IN MEMORY\n"
         << endl;
    for (auto i : m)
    {
        var rem = 0;
        if (i->allocated)
        {
            rem = i->space - i->value;
        }
        ofstream fout("info.log", ios::app);
        fout << "start:" << i->startAddress << "\t|"
             << "\tsize:" << i->space << "\t|"
             << "\tValue:" << i->value << "\t|"
             << "\trem:" << rem << "\t|"
             << "\tEnd:" << i->endAddress << "\n";
        cout << "start:" << i->startAddress << "\t|"
             << "\tsize:" << i->space << "\t|"
             << "\tValue:" << i->value << "\t|"
             << "\trem:" << rem << "\t|"
             << "\tEnd:" << i->endAddress << "\n";
        fout.close();

    }

    cout << "\nDate TimeStamp:\n"<< date_time << endl;
    cout << "\n** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** \n";
}
