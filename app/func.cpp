#include <iostream>

#include <vector>

#include <boost/lambda/lambda.hpp>

#include <opencv2/opencv.hpp>

#include "func.hpp"

using namespace std;

int my_func1(int input)
{
    int ret = 0;

    if(input == 0)
    {
        ret = 10;
    }
    else
    {
        ret = 20;
    }

    return ret;
}

int my_func2()
{
    vector<int> nlist = {1, 2};
    for_each(nlist.begin(), nlist.end(), cout << (boost::lambda::_1 * 5) << " <\n");

    return 0;
}

int my_func3(const char* image_path)
{
    cv::Mat image;
    image = cv::imread(image_path);
    cv::imshow("Image", image);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
