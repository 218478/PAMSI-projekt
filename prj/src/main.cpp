#include "Conversion.h"

#include <iostream>
#include <string>
// #include <boost/gil/gil_all.hpp>
// using namespace boost::gil;

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

	waitKey(0);

	return 0;
}
