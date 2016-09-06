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
namedWindow("Resized Image");
namedWindow("Rotated Image");

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
//display first image
imshow("Image", image);
}




void processImage()
{
int interpolation = INTER_AREA; //INTER_CUBIC;//INTER_LANCZOS4;//INTER_LINEAR;//INTER_NEAREST;
resize(image, processedImage, Size(200, 200), 0, 0, interpolation);
imshow("Resized Image", processedImage);

double angle = 30.0;
double scale = 0.7;
Point2f imageCenter = Point2f(image.cols/2., image.rows/2.);
Mat rotationMat = getRotationMatrix2D(imageCenter, angle, scale);
warpAffine( image, processedImage, rotationMat, image.size() );
imshow("Rotated Image", processedImage);

}




