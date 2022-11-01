/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 8B
I wrote a program that inverts the colors only in the right half of the picture.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"

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

if (ostr.fail()) 
{
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

void invertRightHalf(int image[MAX_H][MAX_W], int height, int width){
int centerX=width/2;

for(int h=0;h<height;h++){
for(int w=centerX;w<width;w++){

image[h][w]=255-image[h][w];
}
}
}

int main() {
int img[MAX_H][MAX_W];
int h, w;

readImage(img, h, w);
invertRightHalf(img, h , w); 
writeImage(taskB.pgm, h, w); 

return 0;

}
