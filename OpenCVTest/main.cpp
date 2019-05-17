//
//  main.cpp
//  OpenCVTest
//
//  Created by Yoshiki Izumi on 2019/05/14.
//  Copyright © 2019 Yoshiki Izumi. All rights reserved.
//

//#include <cv.h>
#include <iostream>
#include <highgui.hpp>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

int levels = 3;
static void on_trackbar(int, void*)
{
    Mat cnt_img = Mat::zeros(64, 64, CV_8UC3);
    int _levels = levels - 3;
    drawContours( cnt_img, contours, _levels <= 0 ? 3 : -1, Scalar(128,255,255),
                 3, LINE_AA, hierarchy, std::abs(_levels) );
    imshow("contours", cnt_img);
}


Mat detectFaceInImage(Mat &image,string &cascade_file){
    CascadeClassifier cascade;
    cascade.load(cascade_file);
    
    vector<Rect> faces;
    cascade.detectMultiScale(image, faces, 1.1,3,0,Size(20,20));
    
    for (int i = 0; i < faces.size(); i++){
        rectangle(image, Point(faces[i].x,faces[i].y),Point(faces[i].x + faces[i].width,faces[i].y + faces[i].height),Scalar(0,200,0),2,8);
    }
    return image;
}

int main(){
    Mat image = imread("/Users/izumiyoshiki/Desktop/startup.png");
    string filename = "/usr/local/Cellar/opencv/4.1.0_2/share/opencv4/haarcascades/haarcascade_frontalface_default.xml";
    Mat detectFaceImage = detectFaceInImage(image, filename);
    imshow("detect face",detectFaceImage);
    waitKey(0);
    
    return 0;
}
