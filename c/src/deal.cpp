#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap;
    cap.open(0); //打开摄像头
    if(!cap.isOpened()){
        std::cout<< "Not open!" << std::endl;
        return 1;
    }
    Mat image;
    int flag_play[14] = {0};
    int flag_play_last[14] = {0};


    while(1) {
        cap >> image;
        if(image.empty()){
            std::cout<< "image is empty" << std::endl;
            break;
        }
        int w = image.cols;
        int h = image.rows;
        cout << w << ',' << h << endl;

        #define CUT_RATE 5.1
        #define UP_LINE  1700 / CUT_RATE
        #define DOWN_LINE  2000 / CUT_RATE
        int line[15] = {340, 550, 740, 930, 1100, 1270, 1450, 1620, 1780, 1970, 2150, 2330, 2510, 2700, 2900};

        for (int i = 0; i < 15; i ++) {
            line[i] = (int)(line[i] / CUT_RATE);
        }

        Mat image_cut[14];

        int x1 = 0;
        int y1 = UP_LINE;
        int x2 = w;
        int y2 = UP_LINE;
        cv::Point start = cv::Point(x1, y1);
        cv::Point end = cv::Point(x2, y2);
        cv::line(image, start, end, cv::Scalar(0, 255, 255), 2);

        x1 = 0;
        y1 = DOWN_LINE;
        x2 = w;
        y2 = DOWN_LINE;
        start = cv::Point(x1, y1);
        end = cv::Point(x2, y2);
        cv::line(image, start, end, cv::Scalar(0, 255, 255), 2);


        for (int i = 0; i < 15; i ++) {
            x1 = line[i];
            y1 = UP_LINE;
            x2 = line[i];
            y2 = DOWN_LINE;
            start = cv::Point(x1, y1);
            end = cv::Point(x2, y2);
            cv::line(image, start, end, cv::Scalar(0, 255, 255), 2);
        }

        for (int i = 0; i < 14; i ++) {
            Rect rect(line[i], UP_LINE, line[i + 1] - line[i], DOWN_LINE - UP_LINE);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,height
            image_cut[i] = Mat(image, rect);      //从img中按照rect进行切割，此时修改image_cut时image中对应部分也会修改，因此需要copy
            cvtColor(image_cut[i], image_cut[i], CV_BGR2GRAY);
            threshold(image_cut[i], image_cut[i], 100, 200.0, CV_THRESH_BINARY);

            int p = countNonZero(image_cut[i]);
            double rate = p * 1.0 / image_cut[i].cols / image_cut[i].rows;
            cout << i << ": " << p << ", " << rate << endl;
            flag_play_last[i] = flag_play[i];
            if (rate > 0.7) {
                flag_play[i] = 1;
            }
            else {
                flag_play[i] = 0;
            }
            // imshow("", image_cut[i]);
            // waitKey();
            if ( (flag_play_last[i] == 0)  && (flag_play[i] == 1)) {
                switch (13-i) {
                    case 0: system("play ../mp3_14/40-C.mp3 & > /dev/null"); break;
                    case 1: system("play ../mp3_14/42-D.mp3 & > /dev/null"); break;
                    case 2: system("play ../mp3_14/44-E.mp3 & > /dev/null"); break;
                    case 3: system("play ../mp3_14/45-F.mp3 & > /dev/null"); break;
                    case 4: system("play ../mp3_14/47-G.mp3 & > /dev/null"); break;
                    case 5: system("play ../mp3_14/49-A.mp3 & > /dev/null"); break;
                    case 6: system("play ../mp3_14/51-B.mp3 & > /dev/null"); break;
                    case 7: system("play ../mp3_14/52-C.mp3 & > /dev/null"); break;
                    case 8: system("play ../mp3_14/54-D.mp3 & > /dev/null"); break;
                    case 9: system("play ../mp3_14/56-E.mp3 & > /dev/null"); break;
                    case 10: system("play ../mp3_14/57-F.mp3 & > /dev/nul"); break;
                    case 11: system("play ../mp3_14/59-G.mp3 & > /dev/nul"); break;
                    case 12: system("play ../mp3_14/61-A.mp3 & > /dev/nul"); break;
                    case 13: system("play ../mp3_14/63-B.mp3 & > /dev/nul"); break;
                }
            }
        }


        Size dsize = Size(w/4, h/4);
        Mat imagedst = Mat(dsize, CV_32S);
        resize(image, imagedst, dsize);
        imshow("", image);
        if(waitKey(20)>0)//按下任意键退出摄像头　　因电脑环境而异，有的电脑可能会出现一闪而过的情况
            break;
        usleep(20000);
    }
    return 0;
}

