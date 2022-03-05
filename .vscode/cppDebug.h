#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#define COLOR_FORE_RED 0x0c
#define COLOR_FORE_GREEN 0x0a
#define COLOR_FORE_BLUE 0x09
#define COLOR_FORE_MAGE 0x0d
#define COLOR_FORE_YELLOW 0x0e
#define COLOR_FORE_CYAN 0x03
#define COLOR_FORE_GRAY 0x08
#define COLOR_FORE_WHITE 0x0f
#define COLOR_DEFAULT 0x07
#define COLOR_BACK_RED 0xcf
#define COLOR_BACK_GREEN 0x2f
#define COLOR_BACK_BLUE 0x9f
#define COLOR_BACK_MAGE 0xdf
#define COLOR_BACK_YELLOW 0x6f
#define COLOR_BACK_CYAN 0x3f
#define COLOR_BACK_GRAY 0x8f
#define COLOR_BACK_DARK 0x7f
int CL_Timer;

__attribute__((constructor)) void beforeMain()
{
    system("chcp 65001"); //切换字符集
    system("cls");
    CL_Timer = clock();
}
__attribute__((destructor)) void afterMain()
{
    printf("\n\n--- 程序运行了 %d 毫秒并退出了 (≧∇≦)\n", (clock() - CL_Timer));
    system("pause");
}
