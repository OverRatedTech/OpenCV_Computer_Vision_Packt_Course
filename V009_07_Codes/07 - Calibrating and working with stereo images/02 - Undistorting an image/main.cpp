#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char * argv[])
{
FileStorage fs("out_camera_data.yml", FileStorage::READ);

Mat camera_matrix, distortion_coefficients;

fs["camera_matrix"] >> camera_matrix;
fs["distortion_coefficients"] >> distortion_coefficients;

if(argc < 2)
	{
	std::cout << "Usage: " << argv[0] << " image" << std::endl;
	return -1;
	}

string filename(argv[1]);
Mat image = imread(filename);
Mat undistortedImage;

undistort(image, undistortedImage, camera_matrix, distortion_coefficients);

imwrite("undistorted_" + filename, undistortedImage);

return 0;
}
