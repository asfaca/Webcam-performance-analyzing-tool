#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace cv;
using namespace chrono;

int main(int argc, char **argv)
{
        int CAM_ID = 0;
        unsigned int frame_no = 0;
        unsigned int frame_end = 300;
        double width = 1920;
        double height = 1080;
        double fps;
        Mat frame1;

        VideoCapture cap(CAM_ID);
        if (!cap.isOpened()) {
                perror("Can't open the CAM\n");
                return -1;
        }

        cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);

        auto start = system_clock::now();
        while(1) {
                if (frame_no > frame_end)
                        break;

                cap >> frame1;

                frame_no++;
        }
        auto end = system_clock::now();

        duration<double> elapsed_seconds = end - start;
        cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

        fps = frame_end / (double)elapsed_seconds.count();
        cout << "FPS: " << fps << "\n";

        return 0;
}
