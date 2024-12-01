#include <iostream>
#include <Santa.h>

int main() 
{
    try 
    {
        Santa santa1("Santa Claus", "Wooden sleigh");

        santa1.addElf("Max");
        santa1.addElf("Hera");
        santa1.addElf("Toby");

        std::cout<<"\nSanta 1 details:\n";
        santa1.displayElves();
        santa1.deliverGifts({"Mara", "Dan", "Iasmina"});

        //copy constructor
        Santa santa2 = santa1;
        santa2.addElf("Ela");

        std::cout << "\nSanta 2 details (copied from Santa 1):\n";
        santa2.displayElves();
        santa2.deliverGifts({"Lex", "Laura"});

        //operatorul de atribuire
        Santa santa3("Saint Nicholas", "Metal sleigh");
        santa3 = santa1;

        std::cout << "\nSanta 3 details (assigned from Santa 1):\n";
        santa3.displayElves();
        santa3.deliverGifts({"Ada", "Iulia"});

        std::cout<<"\n";
    } 
    catch (const std::exception &ex) 
    {
        std::cerr<<"Error: "<<ex.what()<<"\n";
    }

    return 0;
}
