#include <windows.h>
#include <string>
#include <iostream>

// �����ռ�
using namespace std;

// ��������
void OpenQQ();		// ��QQ
void SelectQQ();	// ����QQ
bool AddFriend();	// ��Ӻ���

// ��ں���
void main()
{	
	OpenQQ();
}

// ��QQ
void OpenQQ()
{
	// ���ݴ�������ȡ���ھ��
	HWND hd = FindWindow(NULL, "QQ");
	
	// ��ȡQQ���ڴ�С
	RECT rect;
	GetWindowRect(hd, &rect);
	int w = rect.right - rect.left;
	int h = rect.bottom - rect.top;
	
	// ��ȡ����Ĵ�С
	HWND desktopHd = GetDesktopWindow();
	RECT desktopRect;
	GetWindowRect(desktopHd, &desktopRect);
	
	// �жϴ����Ƿ��ڻ��
	int isActive = IsWindowEnabled(hd);
	if (isActive) {
		cout <<"��������������..."<<endl;
		
		// �жϴ����Ƿ��Ѿ�����
		if (!IsWindowVisible(hd)) ShowWindow(hd, SW_SHOW);
		
		// �ƶ�����
		MoveWindow(hd, desktopRect.right-w-10, 10, w, h, false);
		Sleep(1000);

		// ��ȡ��굱ǰλ��
		POINT point;
		GetCursorPos(&point);
		//ShowCursor(false);	// �������
		SetCursorPos(rect.left+55, rect.bottom-20); // �������λ��
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		SetCursorPos(point.x, point.y);		// ����ԭ��λ��
		ShowCursor(true);	// ��ʾ���
		
		// ���ò���QQ
		SelectQQ();
		
	} else {
		MessageBox( NULL , TEXT("�����Ѿ�ֹͣ����") , TEXT("��ʾ") , MB_ICONSTOP|MB_OK);
	}
}

// ����QQ
void SelectQQ()
{
	HWND hd = FindWindow(NULL, "����");

	// �жϲ���QQ�����Ƿ��Ѿ��ɼ�
	if (!IsWindowVisible(hd)) {
		cout <<"����QQ��������������..."<<endl;

		bool isOpen = false;	// ����QQ�����Ѿ���
		while (!isOpen) {
			hd = FindWindow(NULL, "����");
			if (IsWindowVisible(hd)) isOpen = true;
		}
	}
	cout <<"����QQ����򿪳ɹ���"<<endl;
	// ��ȡ���ڴ�С
	RECT rect;
	GetWindowRect(hd, &rect);
	Sleep(4*1000);	// ����4s
	
	// ����ȷŵ��������
	POINT point;
	GetCursorPos(&point);
	SetCursorPos(rect.left+100, rect.top+100); // �������λ��
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);		// ����ԭ��λ��
	
	// ģ������¼�
	string qq = "2884854966";
	for (int i=0; i<qq.length(); i++) {
		int key = qq[i] + 48;
		keybd_event(key, 0, 0, 0);
		keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
	}

	// �����ѯ
	SetCursorPos(rect.left+650, rect.top+115);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);

	// �����Ӻ���
	Sleep(1500);
	SetCursorPos(rect.left+128, rect.top+307);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	SetCursorPos(point.x, point.y);

	Sleep(500);
	if (!AddFriend()) return ;

	// �����������QQ��
	SetCursorPos(rect.left+462, rect.top+98);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

// ��Ӻ��ѽ���
bool AddFriend()
{
	HWND hd = FindWindow(NULL, "Сɬ - ��Ӻ���");

	// �ж���Ӻ��ѽ����Ƿ��Ѿ���ʾ
	if (!hd) return false;
	
	// ��ȡ���ڴ�С
	RECT rect;
	GetWindowRect(hd, &rect);

	// �����һ��,�����������
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
		
	// �ر�/���
	SetCursorPos(rect.right-45, rect.bottom-20);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(10);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(500);

	return true;
}
