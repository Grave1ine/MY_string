#include "MyString.h"
#include <iostream>
#include <map>
/*
std::map<int, int> test_dict =
{
    {1,2},
    {2,3},
    {3,2}
};
*/
int main()
{
    /*
    for(auto &[key, val]: test_dict)
    {
        std::cout << key << ":" << val << std::endl;
    }*/
    String A1;
    String A2(A1);
    String A3(std::move(A2));
    A1.push_back('f');
    A1.push_back('Q');
    std::cout << "\t" << A1[1] << std::endl;
    String A4("Hellow world");
    //std::cout << A4 << std::endl;
    std::cout << A4.get_C_str() << std::endl;//возврат строки
    A4.concatenation(" and space");
    A4.concatenation(A1);
    std::cout << A4 << std::endl;
    return 0;
}
