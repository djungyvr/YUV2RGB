#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
	cv::setUseOptimized( true );

	const int width = 1920;
	const int height = 1080;

	// Buffer size calculated by the fact that it expects 2 bytes per pixel
	const int YUV_BUFFER_SIZE = 1920*1080*2;

	char *yuvBuffer = (char*) malloc(YUV_BUFFER_SIZE);

	// Creates a 3 channel image
	cv::Mat rgbMat( height, width, CV_8UC3 );

	char *inputFileName = argv[1];
	char *outputFileName = argv[2];

	std::ifstream infile(inputFileName);

	// read file into buffer
	infile.read(yuvBuffer, YUV_BUFFER_SIZE);

	// convert buffer into a mat of 2 channels
	cv::Mat yuvMat( height, width, CV_8UC2, yuvBuffer );

	// convert the yuv image to rgb
	cv::cvtColor( yuvMat, rgbMat, CV_YUV2BGR_YUYV );

	cv::imwrite( outputFileName, rgbMat );

	// cleanup
	yuvMat.release();
	rgbMat.release();
	delete [] yuvBuffer;
	return 0;
}
