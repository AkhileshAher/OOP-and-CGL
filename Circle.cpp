#include <iostream>
#include <cmath>
#include <graphics.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int xmin, ymin, xmax, ymax;
    float xmid, ymid, r, sidex, sidey;

    // Input from user
    cout << "Enter xmin and ymin: ";
    cin >> xmin >> ymin;
    cout << "Enter xmax and ymax: ";
    cin >> xmax >> ymax;

    cout << "xmin: " << xmin << ", ymin: " << ymin << endl;
    cout << "xmax: " << xmax << ", ymax: " << ymax << endl;

    // Calculate midpoints and dimensions
    xmid = (xmin + xmax) / 2.0;
    ymid = (ymin + ymax) / 2.0;
    sidex = xmax - xmin;
    sidey = ymax - ymin;

    // Calculate radius to fit within the rectangle
    r = min(sidex, sidey) / 4.0;  // Adjusted for proportional size
    cout << "Circle radius: " << r << endl;

    // Initialize graphics
    initgraph(&gd, &gm, NULL);

    // Draw rectangle
    line(xmin, ymin, xmax, ymin); // Top
    line(xmin, ymax, xmax, ymax); // Bottom
    line(xmin, ymin, xmin, ymax); // Left
    line(xmax, ymin, xmax, ymax); // Right

    // Draw diagonals from center to rectangle edges
    line(xmin, ymid, xmid, ymin); // Top-left diagonal
    line(xmid, ymin, xmax, ymid); // Top-right diagonal
    line(xmax, ymid, xmid, ymax); // Bottom-right diagonal
    line(xmid, ymax, xmin, ymid); // Bottom-left diagonal

    // Draw circle at the center
    circle(xmid, ymid, r);

    // Pause to view the result
    delay(5000);

    // Close graphics system
    closegraph();
    return 0;
}
