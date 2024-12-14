#include <iostream>
#include <graphics.h>
using namespace std;

typedef struct coordinate {
    int x;
    int y;
    char code[4];
} PT;

void drawWindow() {
    setcolor(WHITE);
    rectangle(150, 100, 450, 350); // Draw clipping window
}

void drawLine(PT p1, PT p2) {
    setcolor(YELLOW);
    line(p1.x, p1.y, p2.x, p2.y); // Draw a line
}

PT setCode(PT p) {
    PT temp = p;
    temp.code[0] = (p.y < 100) ? '1' : '0'; // Top
    temp.code[1] = (p.y > 350) ? '1' : '0'; // Bottom
    temp.code[2] = (p.x > 450) ? '1' : '0'; // Right
    temp.code[3] = (p.x < 150) ? '1' : '0'; // Left
    return temp;
}

int visibility(PT p1, PT p2) {
    int flag = 0;
    for (int i = 0; i < 4; i++) {
        if (p1.code[i] != '0' || p2.code[i] != '0') {
            flag = 2; // Partially visible
        }
        if (p1.code[i] == p2.code[i] && p1.code[i] == '1') {
            return 1; // Completely invisible
        }
    }
    if (flag == 0) return 0; // Completely visible
    return 2; // Partially visible
}

void checkAndClipLine(PT p1, PT p2) {
    p1 = setCode(p1);
    p2 = setCode(p2);

    int vis = visibility(p1, p2);

    switch (vis) {
        case 0:
            cout << "Line is completely visible.\n";
            setcolor(GREEN);
            drawLine(p1, p2);
            break;

        case 1:
            cout << "Line is completely invisible.\n";
            break;

        case 2:
            cout << "Line is partially visible (clipping required).\n";
            setcolor(RED);
            drawLine(p1, p2);
            break;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawWindow();

    PT p1, p2;

    // Test Case 1
    p1.x = 100; p1.y = 100;
    p2.x = 300; p2.y = 300;
    checkAndClipLine(p1, p2);

    // Test Case 2
    p1.x = 50; p1.y = 50;
    p2.x = 500; p2.y = 400;
    checkAndClipLine(p1, p2);

    delay(5000);
    closegraph();
    return 0;
}
