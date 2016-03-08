// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

#include "commonMacroFunction.h"

//===============define문===============
#define WINNAME (LPTSTR)(TEXT("충돌처리"))
#define WINSTARTX 100
#define WINSTARTY 100
#define WINSIZEX 800
#define WINSIZEY 600
#define WINSTYLE WS_CAPTION | WS_SYSMENU

#define SAFE_DELETE(p) {if(p){delete (p); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)==NULL;}}
#define SAFE_RELEASE(p) {if(p){(p)->release; (p)=NULL;}}