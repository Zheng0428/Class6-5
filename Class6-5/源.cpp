#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat grayMat;
	cv::Mat srcMat = cv::imread("D:\\a\\lena_rot.jpg", 1);
	if (srcMat.empty())  return -1;
	cvtColor(srcMat, grayMat,CV_BGR2GRAY);
	int srcX_1, srcY_1, srcX_2, srcY_2, srcX_3, srcY_3, srcX_4, srcY_4 = 0;
	int height = grayMat.rows;
	int width = grayMat.cols;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (j == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_1 = j;
				srcY_1 = i;
			}
			if (i == width - 1 && grayMat.at<uchar>(j, i) < 250) {
				srcX_2 = j;
				srcY_2 = i;
			}
			if (i == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_3 = j;
				srcY_3 = i;
			}
			if (i == 0 && grayMat.at<uchar>(j, i) < 250) {
				srcX_3 = j;
				srcY_3 = i;
			}
			if (j == height - 1 && grayMat.at<uchar>(j, i) < 250) {
				srcX_4 = j;
				srcY_4 = i;
			}
		}
	}
	cv::Point2f src_pt[] = {
		cv::Point2f(srcY_1,srcX_1),
		cv::Point2f(srcY_2,srcX_2),
		cv::Point2f(srcY_3,srcX_3),
		cv::Point2f(srcY_4,srcX_4)
	};
	//变换后的四点坐标
	cv::Point2f dst_pt[] = {
		cv::Point2f(0,0),
		cv::Point2f(width - 1,0),
		cv::Point2f(0,height - 1),
		cv::Point2f(width - 1,height - 1)
	};
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
} 