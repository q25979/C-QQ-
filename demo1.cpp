#include <windows.h>
#include <string>
#include <iostream>

// 命名空间
using namespace std;

// 函数声明
void OpenQQ();		// 打开QQ
void SelectQQ();	// 查找QQ
bool AddFriend();	// 添加好友

// 入口函数
void main()
{	
	OpenQQ();
}

// 打开QQ
void OpenQQ()
{
	// 根据窗口名获取窗口句柄
	HWND hd = FindWindow(NULL, "QQ");
	
	// 获取QQ窗口大小
	RECT rect;
	GetWindowRect(hd, &rect);
	int w = rect.right - rect.left;
	int h = rect.bottom - rect.top;
	
	// 获取桌面的大小
	HWND desktopHd = GetDesktopWindow();
	RECT desktopRect;
	GetWindowRect(desktopHd, &desktopRect);
	
	// 判断窗口是否还在活动中
	int isActive = IsWindowEnabled(hd);
	if (isActive) {
		cout <<"程序正常运行中..."<<endl;
		
		// 判断窗口是否已经打开了
		if (!IsWindowVisible(hd)) ShowWindow(hd, SW_SHOW);
		
		// 移动窗口
		MoveWindow(hd, desktopRect.right-w-10, 10, w, h, false);
		Sleep(1000);

		// 获取鼠标当前位置
		POINT point;
		GetCursorPos(&point);
		//ShowCursor(false);	// 隐藏鼠标
		SetCursorPos(rect.left+55, rect.bottom-20); // 设置鼠标位置
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		SetCursorPos(point.x, point.y);		// 返回原先位置
		ShowCursor(true);	// 显示鼠标
		
		// 调用查找QQ
		SelectQQ();
		
	} else {
		MessageBox( NULL , TEXT("程序已经停止运行") , TEXT("提示") , MB_ICONSTOP|MB_OK);
	}
}

// 查找QQ
void SelectQQ()
{
	HWND hd = FindWindow(NULL, "查找");

	// 判断查找QQ界面是否已经可见
	if (!IsWindowVisible(hd)) {
		cout <<"查找QQ界面正在启动中..."<<endl;

		bool isOpen = false;	// 查找QQ界面已经打开
		while (!isOpen) {
			hd = FindWindow(NULL, "查找");
			if (IsWindowVisible(hd)) isOpen = true;
		}
	}
	cout <<"查找QQ界面打开成功！"<<endl;
	// 获取窗口大小
	RECT rect;
	GetWindowRect(hd, &rect);
	Sleep(4*1000);	// 缓存4s
	
	// 鼠标先放到输入框上
	POINT point;
	GetCursorPos(&point);
	SetCursorPos(rect.left+100, rect.top+100); // 设置鼠标位置
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);		// 返回原先位置
	
	// 模拟键盘事件
	string qq = "2884854966";
	for (int i=0; i<qq.length(); i++) {
		int key = qq[i] + 48;
		keybd_event(key, 0, 0, 0);
		keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
	}

	// 点击查询
	SetCursorPos(rect.left+650, rect.top+115);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);

	// 点击添加好友
	Sleep(1500);
	SetCursorPos(rect.left+128, rect.top+307);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);

	Sleep(500);
	if (!AddFriend()) return ;

	// 点击清除输入的QQ号
	SetCursorPos(rect.left+462, rect.top+98);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

// 添加好友界面
bool AddFriend()
{
	HWND hd = FindWindow(NULL, "小涩 - 添加好友");

	// 判断添加好友界面是否已经显示
	if (!hd) return false;
	
	// 获取窗口大小
	RECT rect;
	GetWindowRect(hd, &rect);

	// 点击下一步,连续点击两次
	SetCursorPos(rect.right-125, rect.bottom-20);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(1000);

	SetCursorPos(rect.right-125, rect.bottom-20);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(2000);
		
	// 关闭/完成
	SetCursorPos(rect.right-45, rect.bottom-20);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(500);

	return true;
}
