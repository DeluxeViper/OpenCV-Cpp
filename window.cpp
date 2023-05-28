#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;

int main(int argc, const char **argv) {
  // Read images
  Mat lena = imread("../lena.jpg");
  // Checking if Lena image has been loaded
  if (!lena.data) {
    cout << "Lena image missing" << endl;
    return -1;
  }

  // Create windows
  namedWindow("Lena", WINDOW_NORMAL);

  // Move window
  moveWindow("Lena", 10, 10);

  // Show image
  imshow("Lena", lena);

  // Resize window, only non autosize
  resizeWindow("Lena", 512, 512);

  // wait for any key press
  waitKey(0);

  // Destroy the windows
  destroyWindow("Lena");
}
