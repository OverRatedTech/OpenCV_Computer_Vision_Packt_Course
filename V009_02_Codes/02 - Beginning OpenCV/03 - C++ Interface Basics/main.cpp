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
int x,y;
Vec3b pixel;
unsigned char R, G, B;
processedImage = image.clone();

for(y = 0; y < processedImage.rows; y++)
 for(x = 0; x < processedImage.cols; x++)
 {
  //Get the pixel at (x,y)
  pixel = processedImage.at<Vec3b>(y, x);
  //get the separate colors
  B = pixel[0];
  G = pixel[1];
  R = pixel[2];
  //assign the complement to each color
  pixel[0] = 255 - B;
  pixel[1] = 255 - G;
  pixel[2] = 255 - R;
  //write the pixel back to the image
  processedImage.at<Vec3b>(y, x) = pixel;
 }
}




