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


	MOUSEMSG m;		// ���������Ϣ

	while (true)
	{
		// ��ȡһ�������Ϣ
		m = GetMouseMsg();

		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			// ����ƶ���ʱ��ʲôҲ����
			break;

		case WM_LBUTTONDOWN:
			// ��һ��Բ
			circle(m.x - 5, m.y - 5, 15);
			break;

		case WM_RBUTTONUP:
			return 0;	// ������Ҽ��˳�����
		}
	}

	_getch();
	closegraph();

}