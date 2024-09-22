#include <memory>
#include <iostream>
#include <array>
class base 
{
    public:
    virtual void print()
    {
        std::cout << "base "<<std::endl;    
    }
};
class derived : public base 
{
    public:
    void print() override
    {
        std::cout << "derived "<<std::endl;    
    }
};

using Object = std::array<std::unique_ptr<base>,10>;

int main(void)
{
    Object object{};

    for (Object::iterator it = object.begin(); it != object.end(); it++){
        *it = std::make_unique<derived>();
    }  

    for (const std::unique_ptr<base>& ptr : object)
        ptr.get()->print();
        // std::cout<<"Hello world!"<<std::endl;

    return 0;
}
