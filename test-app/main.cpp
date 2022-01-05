#include <iostream>
#include "../include/notify.hpp"


int main() {
    Notify n("testapp");
    std::cout << n.SendNotify("test!") << std::endl;
    return 0;
}
