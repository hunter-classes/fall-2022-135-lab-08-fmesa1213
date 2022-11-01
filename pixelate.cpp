/*
Author: Frida Mesa
Course: CSCI-135
Instructor: Micheal Zamansky
Assignment: Lab 8F
I wrote a program that pixelates the input image.
*/

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <math.h>
#include "imageio.h"

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
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
return 0;
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
int out[MAX_H][MAX_W];

float avg = 0;
for(int row = 0; row < h; row = row+2) {
for(int col = 0; col < w; col=col+2) {
avg = (float)(img[row][col] + img[row][col + 1] + img[row + 1][col] + img[row + 1][col + 1]) / 4;
out[row][col] = (int)round(avg);
out[row][col + 1] = (int)round(avg);
out[row + 1][col] = (int)round(avg);
out[row + 1][col + 1] = (int)round(avg);
}
}

writeImage(taskF.pgm, h, w);
return 0;
}
