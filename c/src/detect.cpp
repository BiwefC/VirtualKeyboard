#include "detect.hpp"

Detector::Detector()
{
    cap.open(0);
    assert(cap.isOpened() && "Camera is not open!");
    capture_frame();
    w = frame.cols;
    h = frame.rows;
}

void Detector::capture_frame()
{
    cap >> frame;
    assert((!frame.empty()) && "Frame is empty!");
}

int* Detector::detect()
{
    cv::Mat image_cut[14];
    capture_frame();
    draw_lines();
    graphic();
    for (int i = 0; i < 14; i ++) {
        cv::Rect rect(line[i], UP_LINE, line[i + 1] - line[i], DOWN_LINE - UP_LINE);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,height
        image_cut[i] = cv::Mat(frame, rect);      //从img中按照rect进行切割，此时修改image_cut时image中对应部分也会修改，因此需要copy
        cv::cvtColor(image_cut[i], image_cut[i], cv::COLOR_BGR2GRAY);
        cv::threshold(image_cut[i], image_cut[i], 100, 200.0, cv::THRESH_BINARY);

        int p = cv::countNonZero(image_cut[i]);
        double rate = p * 1.0 / image_cut[i].cols / image_cut[i].rows;
        std::cout << i << ": " << p << ", " << rate << std::endl;
        flag_detect_last[i] = flag_detect[i];
        if (rate > 0.7) {
            flag_detect[i] = 1;
        }
        else {
            flag_detect[i] = 0;
        }
        if (flag_detect[i] && !flag_detect_last[i]) {
            flag_play[i] = 1;
        }
        else {
            flag_play[i] = 0;
        }
    }
    return flag_play;    
}

void Detector::draw_lines()
{
    int x1 = 0;
    int x2 = w;
    int y1 = UP_LINE;
    int y2 = UP_LINE;
    cv::Point start = cv::Point(x1, y1);
    cv::Point end = cv::Point(x2, y2);
    cv::line(frame, start, end, cv::Scalar(0, 255, 255), 2);

    x1 = DOWN_LINE;
    y1 = DOWN_LINE;
    start = cv::Point(x1, y1);
    end = cv::Point(x2, y2);
    cv::line(frame, start, end, cv::Scalar(0, 255, 255), 2);


    for (int i = 0; i < 15; i ++) {
        x1 = line[i];
        y1 = UP_LINE;
        x2 = line[i];
        y2 = DOWN_LINE;
        start = cv::Point(x1, y1);
        end = cv::Point(x2, y2);
        cv::line(frame, start, end, cv::Scalar(0, 255, 255), 2);
    }
}

void Detector::graphic()
{
    imshow("Frame", frame);
    cv::waitKey(20);
}

