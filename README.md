# Webcam-performance-analyzing-tool

* Simple video capture program.
* Evaluate average frame rate (fps) of camera device.

## Dependency
 
* Opencv
* In case of Fedora, to install opencv.
```
sudo dnf install opencv-devel
```

## Build
```
g++ main.cpp -o cv `pkg-config opencv --libs`
```

## How to use

```
./cv [width] [height] [camdevid] [frameno]
```
* width : width of video resolution.
* height : height of video resolution.
* camdevid : camera device id. path=/dev/video[N] and insert N.
* frameno : the number of frame to capture.
