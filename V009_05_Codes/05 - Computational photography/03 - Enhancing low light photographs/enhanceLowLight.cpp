#include <opencv2/opencv.hpp>

using namespace cv;

//main functions
void processImage();
void displayGraphics();

//images
Mat image;
Mat processedImage;

int main(int argc, char *argv[])
{
//create a window
namedWindow("Image");
namedWindow("Processed Image");

//load the image
if(argc > 1)
	image = imread(argv[1]);	
else
	image = imread("lena.jpg");	

if(image.empty())
	exit(1);


processImage();
displayGraphics();

waitKey(0);


//no need to release memory
return 0;
}




void displayGraphics()
{
//display both images
imshow("Image", image);
imshow("Processed Image", processedImage);
}




void processImage()
{
vector<Mat> colors;
split(image, colors);
equalizeHist(colors[0], colors[0]);
equalizeHist(colors[1], colors[1]);
equalizeHist(colors[2], colors[2]);
merge(colors, processedImage);
}




