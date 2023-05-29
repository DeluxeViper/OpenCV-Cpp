# OpenCV-Cpp

My attempt at learning OpenCV with C++

My learning journey through OpenCV with C++ by following the O'Reilly book "Building Computer Vision Projects with OpenCV 4 and C++ by David Millan Escriva, Prateek Joshi, Vinicius G. Mendonca, Roy Shilkrot"

### Setup steps

1. Create a /build directory within project
2. Run "cmake -Bbuild" within the source directory
3. cd into the build directory
4. Run "make <make_target>" (ie. make_target could be sample) to create executables

### OpenCV cmake command for MacOS

Run this command in the build folder within your opencv folder:

```
cmake -DCMAKE_BUILD_TYPE=Release -DBUILD_EXAMPLES=ON -DWITH_QT=ON -D BUILD_ZLIB=OFFOPEN -DOPENCV_GENERATE_PKGCONFIG=YES -D WITH_OPENEXR=OFF -D BUILD_opencv_python2=OFF -DOPENCV_EXTRA_MODULES_PATH=/fullpath/opencv-4.7.0/opencv_contrib-4.7.0/modules ../opencv-4.7.0
```
