#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include "AutoCanny/AutoCanny.h"

using namespace cv;

int main()
{
    std::cout << "Reading Lenna.png..." << std::endl;
    Mat src = imread("Lenna.png", IMREAD_COLOR);
    std::cout << "Done reading Lenna.png!" << std::endl;

    Mat dst(src.size(), CV_32FC1, Scalar::all(0));

    std::cout << "Performing AutoDirCanny on Lenna.png..." << std::endl;
    autocanny::AutoDirCanny(src, dst);
    std::cout << "Done AutoDirCanny on Lenna.png!" << std::endl;

    std::cout << "Checking result integrity..." << std::endl;
    if (countNonZero(dst) < 1) EXIT_FAILURE;

    return EXIT_SUCCESS;
}
