#include <windows.h>
#include "sys.h"
#include "audio.h"
#include "graphic.h"
#include "input.h"
#include "macros.h"
#include "types.h"
/*==============================================================================================================*/
/*==============================================================================================================*/
extern void main(void);
/*==============================================================================================================*/
/*==============================================================================================================*/
WNDCLASS	wc;
__int64		gFreq;
HINSTANCE	ghInstance	=0;
HWND			ghWnd				=0;
wchar_t		*ghAppName	=0;
wchar_t		*ghClassName=0;
/*==============================================================================================================*/
/*==============================================================================================================*/
long FAR PASCAL 
WindowProc(HWND hWnd, UINT message,	WPARAM wParam, LPARAM lParam)
{
  INP_Trap(hWnd, message, wParam, lParam);
	AUD_Trap(hWnd, message, wParam, lParam);
	
  if(message == WM_DESTROY){
      PostQuitMessage(0);
      return 0;
	}else{
      return ::DefWindowProc(hWnd, message, wParam, lParam);
  }
}
/*==============================================================================================================*/
int pascal 
WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPWSTR lpCmdLine,int c)
{
  ghInstance= hInstance;
  main();
  return 0;
}
/*==============================================================================================================*/
void SYS_Init(wchar_t* p_appName, wchar_t* p_className)
{
  if(ghWnd= FindWindow(ghAppName= p_appName, ghClassName= p_className)){
    SetForegroundWindow(ghWnd);
    return;
  }

  wc.style				= CS_HREDRAW | CS_VREDRAW ;
  wc.lpfnWndProc	= (WNDPROC)WindowProc;
  wc.cbClsExtra		= 0;
  wc.cbWndExtra		= 0;
  wc.hIcon				= 0;
  wc.hInstance		= ghInstance;
  wc.hCursor			= NULL;
  wc.hbrBackground= (HBRUSH)  GetStockObject(WHITE_BRUSH);
  wc.lpszMenuName = NULL;
  wc.lpszClassName= ghClassName;

  VERIFY(RegisterClass(&wc), _T"Can't Register Class");
  VERIFY(ghWnd= CreateWindow(
									ghClassName, ghAppName, 
									WS_VISIBLE, CW_USEDEFAULT,	
									CW_USEDEFAULT, 
									CW_USEDEFAULT, 
									CW_USEDEFAULT,	NULL, NULL, 
									ghInstance, NULL ),
									_T"Can't Create Window");

  VERIFY(QueryPerformanceFrequency((LARGE_INTEGER*)&gFreq), _T"No HW clock");

	ShowWindow((HWND)ghWnd, SW_SHOWNORMAL);
	UpdateWindow((HWND)ghWnd);
}
/*==============================================================================================================*/
void SYS_Quit()
{
}
/*==============================================================================================================*/
/*==============================================================================================================*/
