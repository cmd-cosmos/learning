#include <stdio.h>
#include <windows.h>

int main(void)
{
    HDC hdc = GetDC(NULL);

    for (int i = 0; i < 100000; i++)
    {
        SetPixel(hdc, 10, 10, RGB(255, 0, 0));
        Sleep(1);
    }
    ReleaseDC(NULL, hdc);
    return 0;
}