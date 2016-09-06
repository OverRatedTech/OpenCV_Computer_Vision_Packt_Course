#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
namedWindow("Source");
namedWindow("Median Blur");
namedWindow("Gaussian Blur");

Mat image = imread("lena.jpg");
imshow("Source", image);

Size size(11, 11);

//set the region of interest (x, y, w, h)
Rect roi(200, 200, 200, 200);

Mat copiedImage = image.clone();
Mat object = copiedImage(roi);
GaussianBlur(object, object, size, 0);
imshow("Gaussian Blur", copiedImage);

copiedImage = image.clone();
object = copiedImage(roi);
medianBlur(object, object, 37);
imshow("Median Blur", copiedImage);

waitKey(0);
return 0;
}
