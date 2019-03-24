# Webcam-performance-analyzing-tool

* Simple video capture program
* Evaluate average frame rate (fps) of camera device

## Dependency
 
* Opencv
* In case of Fedora, to install opencv
```
sudo dnf install opencv-devel
```

## Build
```
g++ main.cpp -o cv `pkg-config opencv --libs`
```
