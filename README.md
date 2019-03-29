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
* camdevid : camera device id or path. Ex) "/dev/video0" or 0
* frameno : the number of frame to capture.
