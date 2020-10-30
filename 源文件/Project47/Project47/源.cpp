#include<windows.h>
#include<stdio.h>
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
RECT  rect;//保存窗口区域
POINT pt;  // 鼠标的点坐标

int main()
{
	/*char exepath[300];
	GetModuleFileName(NULL, exepath, sizeof(exepath));

	MessageBox(NULL, exepath, "", NULL);
	char path[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
	HKEY hkey;
	RegOpenKey(HKEY_CURRENT_USER, path, &hkey);
	RegSetValueEx(hkey, "faker", 0, REG_SZ, (unsigned char*)"C:\\Users\\86137\\Documents\\Visual Studio 2013\\Projects\\faker\\Debug faker", 400);
	*/

	int  wnd_x;
	int  wnd_y;
	HWND hwnd;
	HDC disDC = CreateDC(L"DISPLAY", 0, 0, 0);
	int screenW = GetDeviceCaps(disDC, HORZRES);
	int screenH = GetDeviceCaps(disDC, VERTRES);

	while (1)
	{
		hwnd = GetForegroundWindow();
		GetWindowRect(hwnd, &rect);
		GetCursorPos(&pt);
		if (pt.x >= rect.left && pt.x <= rect.right &&
			pt.y >= rect.top && pt.y <= rect.bottom)
		{

			wnd_x = rand() % (screenW - 400);
			wnd_y = rand() % (screenW - 400);
			MoveWindow(hwnd, wnd_x, wnd_y, 400, 400, true);
		}
	}

	return 0;
}