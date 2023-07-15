#include <bits/stdc++.h>
#include <graphics.h>
#include <conio.h>
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")
using namespace std;
double bx=650,by=300,dx=-1,dy,s=300,cn;
int yy;
void init()
{
	initgraph(800,600);
	setbkcolor(WHITE);
	cleardevice();
	settextcolor(RED);
	settextstyle(50, 0, _T("黑体"));
	outtextxy(300,200,"电子乒乓");
	settextcolor(BLUE);
	settextstyle(30, 0, _T("楷体"));
	outtextxy(310,300,"按任意键继续");
	getch();
}
void f1()
{
	while(bx<=1000&&bx>=-200)
	{
		MOUSEMSG m;
		m=GetMouseMsg();
		if(m.y<50)
		{
			yy=50;
		}
		else if(m.y>550)
		{
			yy=550;
		}
		else
		{
			yy=m.y;
		}
	}
}
void p()
{
	BeginBatchDraw();
	cleardevice();
	setlinestyle(PS_DASH,5);
	setlinecolor(BLUE);
	line(400,100,400,500);
	setfillcolor(RED);
	solidrectangle(720,yy-50,740,yy+50);
	solidrectangle(80,s-50,60,s+50);
	bx+=dx;
	by+=dy;
	if(bx==710&&by>=yy-50&&by<=yy+50)
	{
		cn++;
		dx=-dx;
		dy=(double)rand()/RAND_MAX-0.2;
		if(cn<=10)
		{
			s=dy*620+by;
			if(s<0)
			{
				s=-s;
			}
			else if(s>600)
			{
				s=1200-s;
			}
			if(s<50)
			{
				s=50;
			}
			else if(s>550)
			{
				s=550;
			}
		}
	}
	if(bx==90&&by>=s-50&&by<=s+50)
	{
		dx=-dx;
		dy=(double)rand()/RAND_MAX-0.2;
	}
	if(by<=0||by>=600)
	{
		dy=-dy;
	}
	setfillcolor(CYAN);
	solidcircle(bx,by,10);
	FlushBatchDraw();
}
int main()
{
	srand(time(0));
	dy=(double)rand()/RAND_MAX-0.2;
	init();
	cleardevice();
	setlinestyle(PS_DASH,5);
	setlinecolor(BLUE);
	line(400,100,400,500);
	setfillcolor(RED);
	solidrectangle(720,250,740,350);
	solidrectangle(80,250,60,350);
	setfillcolor(CYAN);
	solidcircle(650,300,10);
	outtextxy(310,50,"按任意键发球");
	getch();
	s=dy*540+300;
	if(s<0)
	{
		s=-s;
	}
	else if(s>600)
	{
		s=1200-s;
	}
	if(s<50)
	{
		s=50;
	}
	else if(s>550)
	{
		s=550;
	}
	thread t1(f1);
	t1.detach();
	while(bx<=1000&&bx>=-200)
	{
		p();
	}
	if(bx>1000)
	{
		outtextxy(350,50,"你输了！");
	}
	else
	{
		outtextxy(350,50,"你赢了！");
	}
	outtextxy(310,500,"按任意键退出");
	FlushBatchDraw();
	getch();
	closegraph();
	return 0;
}
