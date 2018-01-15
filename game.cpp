#include "TXLib.h"

void dvizhenie(int* x, int* y, int speed, int* frame);

int main()
{
    int x = 0,
        y = 200,
        speed = 10;
    int frame = 0;

    txCreateWindow(1300, 600);
    HDC karta = txLoadImage ("карта.bmp");
    HDC terrorist = txLoadImage ("террорист.bmp");

    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txBitBlt (txDC(), 0, 0, 1500, 600, karta, 0, 0);

        dvizhenie(&x, &y, speed, &frame);

        txTransparentBlt (txDC(), x, y, 220, 320, terrorist, 220 * frame, 0, TX_WHITE);
        txSleep(100);
    }

    txDeleteDC (karta);
    txDeleteDC (terrorist);

    return 0;
}

void dvizhenie(int* x, int* y, int speed, int* frame)
{
    if (GetAsyncKeyState(VK_LEFT) and *x > 0)
    {
        *x -= speed;
        *frame -= 1;
    }
    else if (GetAsyncKeyState(VK_RIGHT) and *x < txGetExtentX())
    {
        *x += speed;
        *frame += 1;
    }

    if (GetAsyncKeyState(VK_UP) and *y > 0)
    {
        *y -= speed;
    }
    else if (GetAsyncKeyState(VK_DOWN) and *y < txGetExtentY())
    {
        *y += speed;
    }

    if (*frame > 11)
    {
        *frame = 0;
    }
    else if (*frame < 0)
    {
        *frame = 11;
    }
}