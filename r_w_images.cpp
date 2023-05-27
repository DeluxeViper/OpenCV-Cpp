#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main(int argc, char *argv[]) {
  Mat color = imread("../lena.jpg");
  Mat gray = imread("../lena.jpg", cv::IMREAD_GRAYSCALE);
  // Check for invalid input
  if (!color.data) {
    cout << "Could not open or find the image";
    return -1;
  }
  // Write images
  imwrite("lenaGray.jpg", gray);

  // Get same pixel with opencv function
  int myRow = color.cols - 1;
  int myCol = color.rows - 1;

  try {
    cv::Vec3b pixel = color.at<Vec3b>(myCol, myRow);
    cout << "Pixel value (B, G, R): (" << (int)pixel[0] << "," << (int)pixel[1]
         << "," << (int)pixel[2] << endl;
  } catch (int e) {
    cout << "An exception occurred: " << e << "\n";
  }

  // Show images
  imshow("Lena BGR", color);
  imshow("Lena Gray", gray);

  // wait for any key press
  waitKey(0);
  return 0;
}
