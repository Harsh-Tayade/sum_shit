#include <conio.h>
#include <vector>
#include <graphics.h>
#include <direct.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

int lenght = 2;
int lenghtmax = 6; 

int x1 = 30;
int y = 170; 

char direc = '-';
char last = '-';

bool playing = true; 

int fruitx;
int fruity;
bool eaten = false; 

int bfruitx;
int bfruity;
bool beaten = false;

vector<int> snakex;
vector<int> snakey; 
int SnakeColor=15;

int i = 3;
int imax = 0; 

char score[50];
int score1; 
int speed_control=0;

void fruit();
void bfruit();
void graphic();
void move();
void start();
void update(); 
void restart();

void start()
{
    sprintf(score, "SCORE : %d ", score1);

    srand(time(NULL));
    initwindow(1050, 1062, "Snake");

    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(0, 0, 1020, 30);
    floodfill(5, 5, GREEN);

    setcolor(WHITE);
    //settextstyle(8,HORIZ_DIR,40);
    outtextxy(500, 0, score);

    fruitx = rand() % 34;
    fruity = rand() % 34;
    fruity = fruity * 30;
    fruitx = fruitx * 30;
    
    if(fruity == 0){
        fruity = fruity+30;
    }
    

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 30, fruity + 30);
    floodfill(fruitx + 15, fruity + 15, RED);
}

void update() 
{

    sprintf(score, "SCORE : %d ", score1);
    if (speed_control<60)
    {
        speed_control=score1*2;
    }
    
    Sleep(80-speed_control);
    snakex.push_back(x1);
    snakey.push_back(y); 
    fruit();
    move();
    graphic();

}

void move() 
{
    if (kbhit())    direc = getch();

    if (direc == 'w' && last == 's' || direc == 'W' && last == 'S' || direc == 38 && last == 40) direc = last;

    if (direc == 'a' && last == 'd' || direc == 'A' && last == 'D' || direc == 37 && last == 39) direc = last;

    if (direc == 's' && last == 'w' || direc == 'S' && last == 'W' || direc == 40 && last == 38 ) direc = last;

    if (direc == 'd' && last == 'a' || direc == 'D' && last == 'A' || direc == 39 && last == 37) direc = last;

    last = direc;

    if (direc == 's' || direc == 'S' || direc == 40)   y = y + 30;
    if (direc == 'a' || direc == 'A' || direc == 37)   x1 = x1 - 30;
    if (direc == 'w' || direc == 'W' || direc == 38)   y = y - 30;
    if (direc == 'd' || direc == 'D' || direc == 39)   x1 = x1 + 30;
}

void graphic() 
{
    cleardevice();

    setcolor(BLUE);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(0, 0, 1050, 30);			
    floodfill(5, 5, BLUE);

    setcolor(WHITE);
    outtextxy(30, 0, score); 

    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(fruitx, fruity, fruitx + 30, fruity + 30); 
    floodfill(fruitx + 15, fruity + 15, RED);
    
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x1, y, x1 + 30, y + 30); 
    floodfill(x1 + 15, y + 15, WHITE);

    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    rectangle(bfruitx, bfruity, bfruitx + 10, bfruity + 10); 
    floodfill(bfruitx + 5, bfruitx + 5, CYAN);


    for (int lenght = lenghtmax; lenght > 0; lenght--)
    {
        setcolor(SnakeColor);
        setfillstyle(SOLID_FILL, SnakeColor);
        rectangle(snakex[i], snakey[i], snakex[i] + 30, snakey[i] + 30); 
        floodfill(snakex[i] + 15, snakey[i] + 15, SnakeColor);
        i--;
    }

    imax++;
    i = imax;

}

void restart()
{
  // Reset all relevant variables to their initial values
  lenght = 1;
  lenghtmax = 2;
  x1 = 30;
  y = 170;
  direc = '-';
  last = '-';
  playing = true;
  fruitx = 0;
  fruity = 0;
  bfruitx = 0;
  bfruity = 0;
  eaten = false;
  beaten = false;
  snakex.clear();
  snakey.clear();
  SnakeColor = 15;
  i = 1;
  imax = 0;
  score1 = 0;
  sprintf(score, "SCORE : %d ", score1);
  

  fruitx = rand() % 34;
  fruity = rand() % 34;
  fruity = fruity * 10;
  fruitx = fruitx * 10;
  
  if(fruity == 0)
  {
    fruity = fruity + 10;
  }
  
  bfruitx = rand() % 34;
  bfruity = rand() % 34;
  bfruity = bfruity * 10;
  bfruitx = bfruitx * 10;
  
  if(bfruity == 0)
  {
    bfruity = bfruity + 10;
  }
}


void fruit() 
{
    if (x1 == fruitx && y == fruity)
    eaten = true;

    if (eaten == true)
    {
        eaten = false;
        lenghtmax++;
        score1++;
        lenght = lenghtmax;
        fruitx = rand() % 34;
        fruity = rand() % 34;
        fruity = fruity * 10;
        fruitx = fruitx * 10; 
        SnakeColor = rand() % 15 + 1;

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (fruitx == snakex[i] && fruity == snakey[i])
            {
                fruitx = rand() % 34;
                fruity = rand() % 34;
                fruity = fruity * 10;
                fruitx = fruitx * 10; 
            }

            i--;
        }

        if (fruity == 0)
        {
            fruity = 10;
        }

        i = imax;

        setcolor(RED);
        setfillstyle(SOLID_FILL, RED);
        rectangle(fruitx, fruity, fruitx + 10, fruity + 10); 
        floodfill(fruitx + 5, fruitx + 5, RED);
    }
}

void bfruit() 
{
    if (x1 == bfruitx && y == bfruity)
    beaten = true;

    if (beaten == true)
    {
        beaten = false;
        lenghtmax--;
        score1--;
        lenght = lenghtmax;
        bfruitx = rand() % 34;
        bfruity = rand() % 34;
        bfruity = bfruity * 10;
        bfruitx = bfruitx * 10; 
        SnakeColor = CYAN;

        for (lenght = lenghtmax; lenght >= 0; lenght--)
        {
            if (bfruitx == snakex[i] && bfruity == snakey[i])
            {
                bfruitx = rand() % 34;
                bfruity = rand() % 34;
                bfruity = bfruity * 10;
                bfruitx = bfruitx * 10; 
            }

            i--;
        }

        if (bfruity == 0)
        {
            bfruity = 10;
        }

        i = imax;

        setcolor(CYAN);
        setfillstyle(SOLID_FILL, CYAN);
        rectangle(bfruitx, bfruity, bfruitx + 10, bfruity + 10); 
        floodfill(bfruitx + 5, bfruitx + 5, CYAN);
    }
}

int main()
{
    start();
    while(true){
        while (playing == true)
        {
            update();

            if (x1 >= 1020 || x1 < 0 || y >= 1020 || y < 30) 
            {
                playing = false; 
            }

            if (lenghtmax > 9 || direc != '-' && direc != 'w' && direc != 'a' && direc != 's' && direc != 'd' && direc != 'W' && direc != 'A' && direc != 'S' && direc != 'D' && direc != 37 && direc != 38 && direc != 39 && direc != 40)
            {
                for (lenght = lenghtmax; lenght >= 0; lenght--)
                {
                    if (x1 == snakex[i] && y == snakey[i])
                    {
                        playing = false; 
                    }

                    i--;
                }

                i = imax;
            }
        }

        if (playing == false)
        {
            cleardevice();
            setcolor(WHITE);
            outtextxy(70, 170, "YOU LOST, FINAL ");
            outtextxy(188, 170, score);
            Sleep(500);
            getch();
            cleardevice();
            outtextxy(80,170,"Press any key to continue");
            Sleep(500);
            char re_start = getch();
            if (re_start) 
                restart();
            
        }
    }
    getch();
    return 0;
}