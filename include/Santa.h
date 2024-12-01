#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Sleigh.h"

class Santa 
{
    private:
        std::string name;
        std::vector<std::string> elves;
        //Use objects to manage resources
        std::unique_ptr<Sleigh> sleigh; //gestioneaza resursele folosind obiecte RAII (Resource Acquisition Is Initialization)
        //smart pointers pentru alocarile dinamice
    public:
        Santa(const std::string& name, const std::string& sleighType)
            : name(name), sleigh(std::make_unique<Sleigh>(sleighType)) {}

        ~Santa() 
        {
            std::cout<<"Santa "<<name<<" is done for the season.\n";
        }

        //Think carefully about copying behavior in resource-managing classes
        //copy constructor
        Santa(const Santa& other)
            : name(other.name), elves(other.elves), sleigh(std::make_unique<Sleigh>(*other.sleigh)) //smart pointers pentru alocarile dinamice
        {
            std::cout<<"Santa copied.\n";
        }

        //operator de atribuire
        Santa& operator=(const Santa& other) 
        {
            if (this != &other) 
            {
                name = other.name;
                elves = other.elves;
                sleigh = std::make_unique<Sleigh>(*other.sleigh); //smart pointers pentru alocarile dinamice
                std::cout<<"Santa assigned.\n";
            }

            return *this;
        }

        void addElf(const std::string &elfName) 
        {
            elves.push_back(elfName);
        }

        void deliverGifts(const std::vector<std::string>& children) const 
        {
            std::cout<<name<<" is delivering gifts using the sleigh:\n";

            sleigh->display();

            for (const auto& child : children) 
            {
                std::cout<<"Delivering gift to "<<child<<"!\n";
            }
        }

        void displayElves() const 
        {
            std::cout<<name<<"'s elves:\n";

            for (const auto& elf : elves) 
            {
                std::cout<<"- "<<elf<<"\n";
            }
        }
};