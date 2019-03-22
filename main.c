#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <stdio.h>

static void calc_fps(int start_time, end_time, int frame_no)
{
        /* calcuate fps and print result */
}

int main(int argc, char** argv)
{
        int CAM_ID = 0;
        unsigned int frame_no = 0;
        unsigned int threshold = 50000;
        doubke width, height;
        /* FIXME : replace type. ex. time_t... */
        int start_time, end_time;

        IplImage* image = NULL;
        /* receive camera device path as input of this program */
        CvCapture* cap = cvCaptureFromCAM(CAM_ID);

        if(cap == NULL){
                printf("Can't open the CAM(%d)\n",CAM_ID);
                return -1;
        }

        width = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH);
        height = cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT);
        printf("size = [%f, %f]\n",width, height);

        /* FIXME : check supported resolution */
        cvNamedWindow("CAM_Window", 0);
        cvResizeWindow("CAM_Window", 1280, 720);

        /* FIXME : set the current time */
        start_time = 0;
        while(1){
                if (frame_no > threshold)
                        break;

                image = cvQueryFrame(cap);
                cvShowImage("CAM_Window", image);
                frame_no++;
        }
        /* FIXME : set the current time */
        end_time = 0;

        calc_fps(start_time, end_time, frame_no);

        cvDestroyWindow("CAM_Window");

        return 0;
}