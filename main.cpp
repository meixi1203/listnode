#include "list.h"

int main(int argc,char** argv)
{
    MyList list1("1 2 3 4 5");
    MyList list2;
    list2<<"6 7 8 9 10";
    std::cout << list1 << std::endl;
    std::cout << list2 << std::endl;
    MyList list3 = list1+list2;
    std::cout << list3 << std::endl;
    std::cout << (-list3) << std::endl;
    list3.add_node(0);
    std::cout << list3 << std::endl;

    for (auto it = list1.begin(); it != list1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}