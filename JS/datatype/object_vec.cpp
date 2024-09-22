#include <memory>
#include <iostream>
#include <vector>
#include <random>

class base
{
public:
    virtual void print()
    {
        std::cout << "base " << std::endl;
    }
};
class derived : public base
{
public:
    void print() override
    {
        std::cout << "derived : value -> " << data << std::endl;
    }
    double data;
};

using Object = std::vector<std::unique_ptr<base>>;
using Object_Inherit = std::vector<std::unique_ptr<derived>>;

int main(void)
{
    const int size = 10;
    Object object;
    Object_Inherit ranObject;

    std::random_device rd;
    std::mt19937 machine(rd());
    std::uniform_real_distribution<double> urf(1,100);
    for (size_t i = 0; i < size; i++)
    {
        ranObject.push_back(std::make_unique<derived>());
        ranObject[i].get()->data = urf(machine);
    }

    for (size_t i = 0; i < size; i++)
    {
        object.push_back(std::make_unique<derived>());
        object[i] = std::move(ranObject[i]);
    }

    for (const std::unique_ptr<base> &ptr : object)
        ptr.get()->print();
    // std::cout<<"Hello world!"<<std::endl;

    return 0;
}
