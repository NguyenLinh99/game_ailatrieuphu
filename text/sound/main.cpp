#include <iostream>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main()
{
    PlaySound(TEXT("bb.wav"), NULL, SND_SYNC);
    return 0;
}
