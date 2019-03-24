#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
        int CAM_ID = 0;
        unsigned int frame_no = 0;
        unsigned int frame_end = 90;
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


        namedWindow("CAM_Window", 0);
        resizeWindow("CAM_Window", width, height);

        auto start = chrono::system_clock::now();
        while(1) {
                if (frame_no > frame_end)
                        break;

                cap >> frame1;
                imshow("CAM_Window", frame1);
                if (waitKey(30) >= 0)
                        break;

                frame_no++;
        }
        auto end = chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

        fps = frame_end / (double)elapsed_seconds.count();
        cout << "FPS: " << fps << "\n";

        destroyWindow("CAM_Window");
        return 0;
}