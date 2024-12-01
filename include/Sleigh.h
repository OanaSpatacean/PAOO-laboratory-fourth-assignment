#include <iostream>
#include <string>
#include <vector>

class Sleigh 
{
    private:
        std::string type;

    public:
        Sleigh(const std::string &type) : type(type) 
        {
            std::cout<<"Sleigh of type "<<type<<" created.\n";
        }
        
        ~Sleigh() 
        {
            std::cout<<"Sleigh of type "<<type<<" destroyed.\n";
        }

        Sleigh(const Sleigh &other) : type(other.type) 
        {
            std::cout<<"Sleigh copied.\n";
        }

        Sleigh& operator=(const Sleigh& other) 
        {
            if (this != &other) 
            {
                type = other.type;
                std::cout<<"Sleigh assigned.\n";
            }

            return *this;
        }

        void display() 
        {
            std::cout<<"Sleigh type: "<<type<<"\n";
        }
};