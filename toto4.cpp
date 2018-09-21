#include <Windows.h>
#include <memory.h>
#include "macros.h"
#include "graphic.h"
#include "sys.h"
#include "audio.h"
#include "input.h"
#include "file.h"
#include "types.h"
#include "gx.h"
#include "3DDisplay.h"
#include "mathFP.h"
#include "resman.h"
/*==============================================================================================================*/
/*==============================================================================================================*/
PROFILER_INC;
/*==============================================================================================================*/
/*==============================================================================================================*/
extern IMAGE		bb;
extern IMAGE		fb;
/*==============================================================================================================*/
/*==============================================================================================================*/
void main(void)
{
	PTFILE	fichier;
  MSG msg;
	PROFILER_DEC;
	PROFILER_INIT;

	SYS_Init(L"Test", L"TestClass");
	AUD_Init(8, 1, 22050);
	VID_Init();
	INP_Init();
	V3D_Init();
	RM_Init();

	RM_Allocate(RMI_WAVE_ST, 1);
	RM_Allocate(RMI_WAVE_DATA_8, 150 KB);

	fichier= FS_CreateFile(L"\\Data\\Test.wav", GENERIC_READ);
	AUD_InitWaveSound(CUR_WAVESOUND, CUR_WAVE_DATA_8, fichier);
	FS_CloseFile(fichier);

	AUD_WavePlay(&AR_WAVESOUND[0], SND_PLAYLOOP);

	while(!INP_IsKeyDown(KEY_ANY_KEY)){
		PROFILER_BEFORE;
		INP_Update;
		TRAP_MSG(msg);
		VID_Clear(&bb, CLR_ZERO, 0);
		V3D_Clear();
		VID_Flip();
		PROFILER_AFTER(L"One Loop : ", L"\r\n");
	}

	AUD_WaveStop(0);

	RM_Quit();
	V3D_Quit();
	INP_Quit();
	VID_Quit();
	AUD_Quit();
	SYS_Quit();
}
/*==============================================================================================================*/
/*==============================================================================================================*/
