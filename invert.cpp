/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 8A
I wrote a program that inverts all colors, so white shades become black, and black become white
*/

#include <iostream>
#include <image1.jpg>
using namespace std;

int main()
{
Mat();
Mat image = imread("image1.jpg");
imshow("original",image);

for(int i=0;i<image->rows;i++)
{
for (int j=0;i<image->cols;j++)
{
image.at<uchar>(i , j) = (255 - image.at<uchar>(i , j ));
}
}

writeImage("taskA.pgm");
  
imshow("Transformed",image);

return 0;

}
