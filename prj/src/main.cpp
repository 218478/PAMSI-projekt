#include "Conversion.h"

#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace cv;

int main() {
	Mat image;
	image = imread( "panda.bmp", 1 );

	if ( !image.data ) {
		std::cerr << "No image data" << std::endl;
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE );
	imshow("Display Image", image);

	Mat grey;  // grey will become grey
	cvtColor(imageg, grey, CV_BGR2GRAY);

	cv::Mat masked;
	image.copyTo(masked, image);
	// int count_black = cv::countNonZero(masked == 0);
	// int count_white = cv::countNonZero(masked == 255);
	// std::cout << "Biale pixele: " << count_white << std::endl;
	// std::cout << "Czarne pixele: " << count_black << std::endl;
	std::cout << masked[0][0] << std::endl;
	waitKey(0);

	return 0;
}
