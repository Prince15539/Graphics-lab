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


void plotCirclePoints(int xc, int yc, int x, int y) {
    if (yc + y >= 0 && yc + y < HEIGHT && xc + x >= 0 && xc + x < WIDTH) grid[yc + y][xc + x] = '*';
    if (yc + y >= 0 && yc + y < HEIGHT && xc - x >= 0 && xc - x < WIDTH) grid[yc + y][xc - x] = '*';
    if (yc - y >= 0 && yc - y < HEIGHT && xc + x >= 0 && xc + x < WIDTH) grid[yc - y][xc + x] = '*';
    if (yc - y >= 0 && yc - y < HEIGHT && xc - x >= 0 && xc - x < WIDTH) grid[yc - y][xc - x] = '*';
    if (yc + x >= 0 && yc + x < HEIGHT && xc + y >= 0 && xc + y < WIDTH) grid[yc + x][xc + y] = '*';
    if (yc + x >= 0 && yc + x < HEIGHT && xc - y >= 0 && xc - y < WIDTH) grid[yc + x][xc - y] = '*';
    if (yc - x >= 0 && yc - x < HEIGHT && xc + y >= 0 && xc + y < WIDTH) grid[yc - x][xc + y] = '*';
    if (yc - x >= 0 && yc - x < HEIGHT && xc - y >= 0 && xc - y < WIDTH) grid[yc - x][xc - y] = '*';
}

// Midpoint Circle Drawing Algorithm
void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 1 - r;
    plotCirclePoints(xc, yc, x, y);
    
    while (x < y) {
        x++;
        if (d < 0) {
            d += 2 * x + 1;
        } else {
            y--;
            d += 2 * (x - y) + 1;
        }
        plotCirclePoints(xc, yc, x, y);
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
    int radius;
    cout << "Enter the Radius of the circle: ";
    cin >> radius;
    int xc = WIDTH / 2, yc = HEIGHT / 2;
    drawCircle(xc, yc, radius);
    displayGrid();
    return 0;
}

