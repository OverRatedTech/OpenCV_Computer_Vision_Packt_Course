#include <opencv2/opencv.hpp>
using namespace cv;

vector<Point> selectedPoints;
Mat src;
void warpIt();
void zoomIt(int, void*);
int zoom = 15;

void on_mouse( int event, int x, int y, int flags, void* param )
{
    switch( event )
    {
    case CV_EVENT_LBUTTONDOWN:
        {
	//std::cout << "Pressed " << x << ", " << y << std::endl;
	selectedPoints.push_back(Point(x, y));

	Mat srcClone = src.clone();
	for(int i=0; i < selectedPoints.size(); i++)
		circle(srcClone, selectedPoints[i], 1, Scalar(0, 255, 0), 6);
	imshow("image", srcClone);

	if(selectedPoints.size() >= 4)
		{
		namedWindow("warp");
		createTrackbar("Zoom", "warp",&zoom, 100, zoomIt);
		warpIt();
		selectedPoints.clear();
		}
        }
        break;
    }
}


void zoomIt(int, void*)
{
	warpIt();
}


int main(int argc, char * argv[])
{
src = imread(argv[1], 1);
namedWindow("image");
imshow("image", src);
cvSetMouseCallback( "image", on_mouse, 0 );
std::cout << "Click on the object's corners in this order:\nTop left\nTop right\nBottom left\nBottom right" << std::endl;
while((char)waitKey(0) != 27){};
return 0;
}


void warpIt()
{
//standard pattern size
int w = 9;
int h = 6;

int objectWidth = w * (zoom + 1);
int objectHeight = h * (zoom + 1);

Point2f srcPoints[4];
srcPoints[0] = selectedPoints[0];
srcPoints[1] = selectedPoints[1];
srcPoints[2] = selectedPoints[2];
srcPoints[3] = selectedPoints[3];

Point2f dstPoints[4];
float centerX = src.cols / 2.;
float centerY = src.rows / 2.;
dstPoints[0] = Point(centerX - objectWidth/2., centerY - objectHeight/2.);
dstPoints[1] = Point(centerX + objectWidth/2., centerY - objectHeight/2.); 
dstPoints[2] = Point(centerX - objectWidth/2., centerY + objectHeight/2.);
dstPoints[3] = Point(centerX + objectWidth/2., centerY + objectHeight/2.);

Mat warpMatrix, warpedImage;

warpMatrix = getPerspectiveTransform(srcPoints, dstPoints);
warpPerspective(src, warpedImage, warpMatrix, src.size());

imshow("warp", warpedImage);
}


