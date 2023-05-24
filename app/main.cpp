#include <iostream>

#include "func.hpp"

using namespace std;

int main()
{
    cout << "Hello, world!" << "\n";

    cout << "ret is : " << my_func1(0) << "\n";

    my_func2();
    my_func3("../../app/lena.jpg");

    return 0;
}
