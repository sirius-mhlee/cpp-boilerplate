#include <iostream>

#include <boost/lambda/lambda.hpp>

#include "func.hpp"

using namespace std;

int main()
{
    cout << "Hello, world!" << "\n";

    cout << "ret is : " << my_func(0) << "\n";

    for_each(istream_iterator<int>(cin), istream_iterator<int>(), cout << (boost::lambda::_1 * 3) << " <\n");

    return 0;
}
