#include <cv.h>
#include <highgui.h>
#include <stdio.h>

//main functions
void processImage();
void displayGraphics();

//images
IplImage *image=NULL;
IplImage *processedImage=NULL;


int main(int argc, char *argv[])
{
//create a window
cvNamedWindow("Image");
cvNamedWindow("Processed Image");

//load the image
if(argc > 1)
	image = cvLoadImage(argv[1]);	
else
	image = cvLoadImage("lena.jpg");	

if(!image)
	exit(1);


processImage();
displayGraphics();

cvWaitKey(0);


if(image)
	cvReleaseImage(&image);
if(processedImage)
	cvReleaseImage(&processedImage);

cvDestroyAllWindows();

return 0;
}




void displayGraphics()
{
//display both images
cvShowImage("Image", image);
cvShowImage("Processed Image", processedImage);
}




void processImage()
{
int x,y;
unsigned char R, G, B;
processedImage = cvCloneImage(image);

for(y = 0; y < processedImage->height; y++)
 for(x = 0; x < processedImage->width; x++)
 {
  //Get the B value
  B = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 0];
  //Assign the B complement
  ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 0] = 255 - B;

  //Get the G value
  G = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 1];
  //Assign the G complement
  ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 1] = 255 - G;

  //Get the R value
  R = ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2];
  //Assign the R complement
  ((uchar *)(processedImage->imageData + y*processedImage->widthStep))[x*processedImage->nChannels + 2] = 255 - R;
 }
}




