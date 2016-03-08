// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

#include "commonMacroFunction.h"

//===============define��===============
#define WINNAME (LPTSTR)(TEXT("�浹ó��"))
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 800
#define WINSIZEY 600
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p) {if(p){delete (p); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)==NULL;}}
#define SAFE_RELEASE(p) {if(p){(p)->release; (p)=NULL;}}