/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 8C
I wrote a program that draws a white box exactly in the middle of the picture. 
The dimensions of the box should be 50% by 50% of the original picture’s width and height.
*/

#include <iostream>
#include "imageio.h"
#include <cassert>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width) 
{
char c;
int x;
ifstream instr;
instr.open("image1.pgm");

instr >> c;
assert(c == 'P');
instr >> c;
assert(c == '2');

while ((instr>>ws).peek() == '#') {
instr.ignore(4096, '\n');
}

instr >> width;
instr >> height;
assert(width <= MAX_W);
assert(height <= MAX_H);
int max;
instr >> max;
assert(max == 255);

for (int row = 0; row < height; row++)
for (int col = 0; col < width; col++)

instr >> image[row][col];
instr.close();
return;
}

void writeImage(int image[MAX_H][MAX_W], int height, int width) {
ofstream ostr;
ostr.open("outImage.pgm");

if (ostr.fail()) {
cout << "Unable to write file\n";
exit(1);

};
ostr << "P2" << endl;
ostr << width << ' ';
ostr << height << endl;
ostr << 255 << endl;

for (int row = 0; row < height; row++) {
for (int col = 0; col < width; col++) {

assert(image[row][col] < 256);
assert(image[row][col] >= 0);
ostr << image[row][col] << ' ';
ostr << endl;

}
}
ostr.close();
return;
}

int main() {
int img[MAX_H][MAX_W];
int h, w;

readImage(img, h, w); 
int box[MAX_H][MAX_W];

for(int row = 0; row < h; row++) {
for(int col = 0; col < w; col++) {
if( (row >= h/4 && row < 3*h/4) && ( col >= w/4 && col < 3*w/4) )
{
box[row][col] = 255;
}
else
{
box[row][col] = img[row][col];
}
}
}

writeImage(taskC.pgm, h, w);
return 0;
}
