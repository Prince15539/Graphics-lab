#include <iostream>
using namespace std;

const int WIDTH = 40;
const int HEIGHT = 20;

char grid[HEIGHT][WIDTH];

// Initialize the grid with spaces
void initializeGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';  
        }
    }
}

void plotEllipsePoints(int xc, int yc, int x, int y) {
    if (yc + y >= 0 && yc + y < HEIGHT && xc + x >= 0 && xc + x < WIDTH) grid[yc + y][xc + x] = '*';
    if (yc + y >= 0 && yc + y < HEIGHT && xc - x >= 0 && xc - x < WIDTH) grid[yc + y][xc - x] = '*';
    if (yc - y >= 0 && yc - y < HEIGHT && xc + x >= 0 && xc + x < WIDTH) grid[yc - y][xc + x] = '*';
    if (yc - y >= 0 && yc - y < HEIGHT && xc - x >= 0 && xc - x < WIDTH) grid[yc - y][xc - x] = '*';
}

// Midpoint Ellipse Drawing Algorithm
void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    float dx = 2 * ry * ry * x;
    float dy = 2 * rx * rx * y;
    float d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    float d2 = 0;
    
    // Region 1 (when the slope is less than 1)
    while (dx < dy) {
        plotEllipsePoints(xc, yc, x, y);
        x++;
        dx += 2 * ry * ry;
        if (d1 < 0) {
            d1 += dx + (ry * ry);
        } else {
            y--;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }
    
    // Region 2 (when the slope is greater than 1)
    d2 = (ry * ry) * ((x + 0.5) * (x + 0.5)) + (rx * rx) * ((y - 1) * (y - 1)) - (rx * rx * ry * ry);
    while (y >= 0) {
        plotEllipsePoints(xc, yc, x, y);
        y--;
        dy -= 2 * rx * rx;
        if (d2 > 0) {
            d2 += (rx * rx) - dy;
        } else {
            x++;
            dx += 2 * ry * ry;
            d2 += dx - dy + (rx * rx);
        }
    }
}

// Display the grid
void displayGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    initializeGrid();
    
    // Example: Draw an ellipse with center at (20, 10), rx=15, ry=8
    drawEllipse(20, 10, 15, 8);
    
    displayGrid();
    return 0;
}

