/*
 
Title of the Assignment: Write C++ program to draw the following pattern. Use the DDA line and
Bresenham‘s circle drawing algorithm. Apply the concept of encapsulation.

*/

#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;

class Draw {
private:
    int xmin, ymin, xmax, ymax;
    float xmid, ymid, temp, sidey, sidex, radius;

public:
    void getInput();
    void calculateDimensions();
    void drawPattern();
    void ddaLine(int x1, int y1, int x2, int y2);
    void bresenhamCircle(int xc, int yc, float r);
};

void Draw::getInput() {
    cout << "Enter xmin and ymin: ";
    cin >> xmin >> ymin;
    cout << "Enter xmax and ymax: ";
    cin >> xmax >> ymax;

    cout << "xmin: " << xmin << ", ymin: " << ymin << endl;
    cout << "xmax: " << xmax << ", ymax: " << ymax << endl;
}

void Draw::calculateDimensions() {
    xmid = (xmin + xmax) / 2.0;
    ymid = (ymin + ymax) / 2.0;
    sidex = xmax - xmin;
    sidey = ymax - ymin;

    // Calculate radius as a proportion of the diagonal
    temp = sqrt(sidex * sidex + sidey * sidey);
    radius = min(sidex, sidey) / 4.0; // Radius is a fraction of the smaller dimension

    cout << "Radius (r): " << radius << endl;
}

void Draw::drawPattern() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Draw rectangle boundary
    ddaLine(xmin, ymin, xmax, ymin);
    ddaLine(xmin, ymax, xmax, ymax);
    ddaLine(xmin, ymin, xmin, ymax);
    ddaLine(xmax, ymin, xmax, ymax);

    // Draw diagonals from rectangle center
    ddaLine(xmin, ymid, xmid, ymin);
    ddaLine(xmid, ymin, xmax, ymid);
    ddaLine(xmax, ymid, xmid, ymax);
    ddaLine(xmid, ymax, xmin, ymid);

    // Draw circle at the center
    bresenhamCircle(xmid, ymid, radius);

    delay(5000); // Pause to view the result
    closegraph();
}

void Draw::ddaLine(int x1, int y1, int x2, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }
}

void Draw::bresenhamCircle(int xc, int yc, float r) {
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main() {
    Draw obj;
    obj.getInput();
    obj.calculateDimensions();
    obj.drawPattern();

    return 0;
}
