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
        int camdev_id;
        int frame_no = 0;
        int frame_end;
        double width, height;
        double fps;
        Mat frame1;

        if (argc < 5) {
                perror("Too small input arguments\n"
                        "Insert [resolution_width] [resolution_height] [camdev_id] [frame_no]\n"
                        "Resolution width : ex, 4096 for 4K video\n"
                        "Resolution height : ex, 2160 for 4K video\n"
                        "Camdev_id : camera device id. path=/dev/video[N] (N is id)\n"
                        "Frame_no : the number of frame to capture\n");
                return 0;
        } else if (argc > 5) {
                perror("Too many input arguments.\n"
                        "Insert [resolution_width] [resolution_height] [camdev_id] [frame_no]\n"
                        "Resolution width : ex, 4096 for 4K video\n"
                        "Resolution height : ex, 2160 for 4K video\n"
                        "Camdev_id : camera device id. path=/dev/video[N] (N is id)\n"
                        "Frame_no : the number of frame to capture\n");
                return 0;
        }

        width = stod(argv[1]);
        height = stod(argv[2]);
        camdev_id = stoi(argv[3]);
        frame_end = stoi(argv[4]);

        VideoCapture cap(camdev_id);
        if (!cap.isOpened()) {
                perror("Can't open the CAM\n");
                return 0;
        }

        cap.set(CV_CAP_PROP_FRAME_WIDTH, width);
        cap.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	cout << "width: " << width << "\n";
	cout << "height: " << height << "\n";

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
