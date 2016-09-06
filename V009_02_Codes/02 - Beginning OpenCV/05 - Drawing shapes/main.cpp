#include <opencv2/opencv.hpp>

using namespace cv;

//main functions
void processImage();
void displayGraphics();

//image
Mat image = imread("lena.jpg");

int main(int argc, char *argv[])
{
namedWindow("Image");
processImage();
displayGraphics();
waitKey(0);
return 0;
}


void displayGraphics()
{
imshow("Image", image);
}




void processImage()
{
//BGR format
Scalar blue(150, 0, 0); 
Scalar green(0, 200, 0); 
Scalar white(220, 220, 220);
int thickness = 2;
int lineType = CV_AA;

Point eye1(266, 266);
Point eye2(330, 266);
int eyeRadius = 20;

Point faceCenter(290, 280);
Size faceSize(80, 110);
int faceAngle = 15;

string theText = "A face and two eyes";
int font = FONT_HERSHEY_SIMPLEX;
int fontScale = 1;
int fontThickness = 1;
int fontBaseline = 0;
Point fontStart(100, 100);

Size textSize = getTextSize(theText, font, fontScale, fontThickness, &fontBaseline);
Point P1 = fontStart;
Point P2 = fontStart;
P1.y -= textSize.height;
P2.x += textSize.width;
Point border(20, 20);
P1 -= border;
P2 += border;
Point fontMiddle = fontStart;
fontMiddle.x += textSize.width/2;

//start drawing...
circle(image, eye1, eyeRadius, green, thickness, lineType);
circle(image, eye2, eyeRadius, green, thickness, lineType);
ellipse(image, faceCenter, faceSize, faceAngle, 0, 360, green, thickness, lineType);
line(image, fontMiddle, faceCenter, blue, thickness, lineType);
rectangle(image, P1, P2, blue, -1, lineType);
putText(image, theText, fontStart, font, fontScale, white, thickness, lineType);	
}




