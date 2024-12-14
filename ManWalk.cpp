#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    int xm, x, y;

    for (xm = 1; xm < 200; xm += 5) {
        line(0, 400, 639, 400); // Ground line
        circle(30 + xm, 280, 20); // Moving circle
        line(30 + xm, 300, 30 + xm, 350); // Stick body
        line(30 + xm, 330, 70 + xm, 330); // Arms

        if (xm % 2 == 0) {
            line(30 + xm, 350, 25 + xm, 400); // Right leg forward
            line(30 + xm, 350, 10 + xm, 400); // Left leg forward
        } else {
            line(30 + xm, 350, 25 + xm, 400); // Right leg backward
            line(30 + xm, 350, 50 + xm, 400); // Left leg backward
        }

        line(70 + xm, 250, 70 + xm, 330); // Stick object
        pieslice(80 + xm, 250, 180, 0, 20); // Object pieslice

        for (int i = 0; i < 300; i++) {
            x = rand() % 800;
            y = rand() % 600;
            outtextxy(x, y, ";"); // Random characters
        }

        delay(100); // Adjusted delay for smooth animation
        cleardevice(); // Clear the screen for the next frame
    }

    getch();
    closegraph();
    return 0;
}
