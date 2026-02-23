#include <iostream>     // modern C+
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    randomize();

    while (!kbhit())
    {
        cleardevice();
        
        // Draw rain
        for (int i = 0; i < 100; i++)
        {
            int x = random(getmaxx());
            int y = random(getmaxy() - 60);  // Avoid drawing rain on the road
            setcolor(LIGHTBLUE);
            line(x, y, x, y + 5);
        }

        // Draw road
        setfillstyle(SOLID_FILL, DARKGRAY);
        bar(0, getmaxy() - 60, getmaxx(), getmaxy());

        // Draw car
        setcolor(random(14) + 1);  // Random color (1-14, avoiding black)
        setfillstyle(SOLID_FILL, getcolor());
        
        // Car body
        fillellipse(getmaxx() / 2, getmaxy() - 40, 30, 10);
        
        // Car top
        line(getmaxx() / 2 - 20, getmaxy() - 40, getmaxx() / 2 - 10, getmaxy() - 55);
        line(getmaxx() / 2 - 10, getmaxy() - 55, getmaxx() / 2 + 10, getmaxy() - 55);
        line(getmaxx() / 2 + 10, getmaxy() - 55, getmaxx() / 2 + 20, getmaxy() - 40);
        
        // Wheels
        setfillstyle(SOLID_FILL, BLACK);
        fillellipse(getmaxx() / 2 - 20, getmaxy() - 30, 8, 8);
        fillellipse(getmaxx() / 2 + 20, getmaxy() - 30, 8, 8);

        delay(100);
    }

    closegraph();
}

