#pragma once

#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O
#include <iostream>
#include <unistd.h>

#define UP_LINE 333
#define DOWN_LINE 392

const int line[15] = {67, 108, 145, 182, 216, 249, 284, 318, 349, 386, 422, 457, 492, 543, 568};

class Detector
{
public:
    // function
    Detector();
    int* detect();
private:
    cv::VideoCapture cap;
    cv::Mat frame;
    int w;
    int h;
    int flag_detect[14];
    int flag_detect_last[14];
    int flag_play[14];
    // function
    void capture_frame();
    void draw_lines();
    void graphic();

};

