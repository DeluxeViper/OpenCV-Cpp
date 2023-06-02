#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;

Mat frame;
GLfloat angle = 0.0;
GLuint texture;
VideoCapture camera;

int loadTexture() {
  if (frame.data == NULL)
    return -1;

  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, frame.cols, frame.rows) return 0;
}

void on_opengl(void *param) {
  glLoadIdentity();
  // Frame texture
  glBindTexture(GL_TEXTURE_2D, texture);

  // Rotate plane prior to drawing
  glRotatef(angle, 1.0f, 1.0f, 1.0f);

  // Create plane and set texture coordinates
  glBegin(GL_QUADS);

  // first point & coordinate texture
  glTexCoord2d(0.0, 0.0);
  glVertex2d(-1.0, -1.0);

  // 2nd point & coordinate texture
  glTexCoord2d(1.0, 0.0);
  glVertex2d(+1.0, -1.0);

  // 3rd point & coordinate texture
  glTexCoord2d(1.0, 1.0);
  glVertex2d(1.0, 1.0);

  // 4th point & coordinate texture
  glTexCoord2d(0.0, 1.0);
  glVertex2d(-1.0, 1.0);

  glEnd();
}

int main(int argc, char *argv[]) {
  // Open WebCam
  camera.open(0);

  if (!camera.isOpened())
    return -1;

  // Create new windows
  namedWindow("OpenGL Camera", WINDOW_OPENGL);

  // Enable texture
  glEnable(GL_TEXTURE_2D);
  glGenTextures(1, &texture);
  setOpenGlDrawCallback("OpenGL Camera", on_opengl);
  while (waitKey(30) != 'q') {
    camera >> frame;
    // Create first texture
    loadTexture();
    updateWindow("OpenGL Camera");
    angle = angle + 4;
  }
  // Destroy windows
  destroyWindow("OpenGL Camera");
  return 0;
}
