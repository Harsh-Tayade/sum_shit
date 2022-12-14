#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

void room(int ch)
{
    while(true)
    {
        switch(ch)
        {
            char c;
            case 0:                                 //starting area
                circle(60,70,69);

                c=getch();

                if(c=='w'||c=='W')
                {
                    cleardevice();
                    room(1);
                }
                else if(c=='d'||c=='D')
                {
                    cleardevice();
                    room(2);
                }
                else if(c=='s'||c=='S')
                {
                    cleardevice();
                    room(3);
                }
                else if(c=='a'||c=='A')
                {
                    cleardevice();
                    room(4);
                }
            break;
            case 1:
                rectangle(80,90,100,110);
                c=getch();
                if(c=='c'||c=='C')
                {
                    cleardevice();
                    room(0);
                }
                if(c=='w'||c=='W')
                {
                   cleardevice();
                   room(1);
                }
                else if(c=='a'||c=='A')
                {
                    cleardevice();
                    room(2);
                }
                else if(c=='s'||c=='S')
                {
                    cleardevice();
                    room(3);
                }
                else if(c=='d'||c=='D')
                {
                    cleardevice();
                    room(4);
                }
            break;

            case 2:
                rectangle(80,90,100,110);
                c=getch();
                if(c=='c'||c=='C')
                {
                    cleardevice();
                    room(0);
                }
                else if(c=='w'||c=='W')
                {
                    cleardevice();
                    room(1);
                }
                else if(c=='a'||c=='A')
                {
                    cleardevice();
                    room(3);
                }
                else if(c=='s'||c=='S')
                {
                    cleardevice();
                    room(4);
                }
            break;

            case 3:
                circle(400,320,650);
                c=getch();
                if(c=='c'||c=='C')
                {
                    cleardevice();
                    room(0);
                }
                else if(c=='w'||c=='W')
                {
                    cleardevice();
                    room(1);
                }
                else if(c=='a'||c=='A')
                {
                    cleardevice();
                    room(2);
                }
                else if(c=='s'||c=='S')
                {
                    cleardevice();
                    room(4);
                }
                else if(c=='d'||c=='D'){
                    cleardevice();
                    room(1);
                }
            break;

            case 4:
                rectangle(320,420,640,840);
                c=getch();
                if(c=='c'||c=='C')
                {
                    cleardevice();
                    room(0);
                }
                else if(c=='w'||c=='W')
                {
                    cleardevice();
                    room(1);
                }
                else if(c=='a'||c=='A')
                {
                    cleardevice();
                    room(2);
                }
                else if(c=='s'||c=='S')
                {
                    cleardevice();
                    room(3);
                }
                else if(c=='d'||c=='D'){
                    cleardevice();
                    room(1);
                }
            break;

            default:
                settextstyle(6,4,1);
                setcolor(CYAN);
                outtextxy(400,400,"NULL");
            break;

        }
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    initwindow(1600,900);
    room(0);
    getch();
    delay(50000);
    closegraph();
    delay(50000);
    return 0;
}
