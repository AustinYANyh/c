#include<stdio.h>
#include<stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <time.h>


int main()
{
	initgraph(680, 480);

	loadimage(NULL, _T("D:\\txt.jpg"), 680, 480);


	MOUSEMSG m;		// 定义鼠标消息

	while (true)
	{
		// 获取一条鼠标消息
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// 鼠标移动的时候什么也不做
			break;

		case WM_LBUTTONDOWN:
			// 画一个圆
			circle(m.x - 5, m.y - 5, 15);
			break;

		case WM_RBUTTONUP:
			return 0;	// 按鼠标右键退出程序
		}
	}

	_getch();
	closegraph();

}