#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

Mat img;
int blurAmount = 15;
bool applyGray = false;
bool applyBlur = false;
bool applySobel = false;

// Trackbar call back function
static void onChange(int pos, void *userInput);

// Mouse callback
static void onMouse(int event, int x, int y, int, void *userInput);

// Initialize buttons
static void createButtons();

void applyFilters() {
  Mat result;
  img.copyTo(result);

  if (applyGray) {
    cvtColor(result, result, COLOR_BGR2GRAY);
  }
  if (applyBlur) {
    blur(result, result, Size(5, 5));
  }
  if (applySobel) {
    Sobel(result, result, CV_8U, 1, 1);
  }
  imshow("Lena", result);
}

void grayCallback(int state, void *userData) {
  applyGray = true;
  applyFilters();
}

void bgrCallback(int state, void *userData) {
  applyGray = false;
  applyFilters();
}

void blurCallback(int state, void *userData) {
  applyBlur = (bool)state;
  applyFilters();
}

void sobelCallback(int state, void *userData) {
  applySobel = !applySobel;
  applyFilters();
}

int main(int argc, const char **argv) {
  // Read images
  img = imread("../lena.jpg");
  // Checking if Lena image has been loaded
  if (!img.data) {
    cout << "Lena image missing" << endl;
    return -1;
  }

  // Create windows
  namedWindow("Lena", WINDOW_NORMAL);

  // Move window
  moveWindow("Lena", 10, 10);

  // Overlay shows up at the top of the window
  displayOverlay("Lena", "Overlay 5secs", 5000);

  // Status bar shows up at bottom of window
  displayStatusBar("Lena", "Statusbar 5secs", 5000);

  createButtons();
  // Show image
  imshow("Lena", img);

  // Create a trackbar
  cv::createTrackbar("Lena", "Lena", &blurAmount, 30, onChange, &img);

  cv::setMouseCallback("Lena", onMouse, &img);

  // Call onChange to init
  onChange(blurAmount, &img);

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

static void createButtons() {
  // create Buttons for the control panel
  createButton("Blur", blurCallback, NULL, QT_CHECKBOX, 0);

  createButton("Gray", grayCallback, NULL, QT_RADIOBOX, 0);
  createButton("RGB", bgrCallback, NULL, QT_RADIOBOX, 1);

  createButton("Sobel", sobelCallback, NULL, QT_PUSH_BUTTON, 0);
}
