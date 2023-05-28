#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

int blurAmount = 15;

// Trackbar call back function
static void onChange(int pos, void *userInput);

// Mouse callback
static void onMouse(int event, int x, int y, int, void *userInput);

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

  // Create a trackbar
  cv::createTrackbar("Lena", "Lena", &blurAmount, 30, onChange, &lena);

  cv::setMouseCallback("Lena", onMouse, &lena);

  // Call onChange to init
  onChange(blurAmount, &lena);

  // Resize window, only non autosize
  resizeWindow("Lena", 512, 512);

  // wait for any key press
  waitKey(0);

  // Destroy the windows
  destroyWindow("Lena");

  return 0;
}

// Mouse callback
static void onMouse(int event, int x, int y, int, void *userInput) {
  if (event != EVENT_LBUTTONDOWN)
    return;

  // Get pointer to input image
  Mat *img = (Mat *)userInput;

  // Draw circle
  circle(*img, Point(x, y), 10, Scalar(0, 255, 0), 3);

  // Call on change to get blurred image
  onChange(blurAmount, img);
}

static void onChange(int pos, void *userData) {
  if (pos <= 0)
    return;

  // An aux var for result
  Mat imgBlur;
  // Retrieve pointer for input image
  Mat *img = (Mat *)userData;

  // Apply a blur filter
  blur(*img, imgBlur, Size(pos, pos));
  // Show result
  imshow("Lena", imgBlur);
}
