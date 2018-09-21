#ifndef _AUDIO_H_
#define _AUDIO_H_
/*==============================================================================================================*/
/*==============================================================================================================*/
#include "types.h"
#include "file.h"
/*==============================================================================================================*/
/*==============================================================================================================*/
#define	SND_PLAYONCE	0
#define SND_PLAYLOOP	1
/*==============================================================================================================*/
/*==============================================================================================================*/
typedef struct tagWAVESOUND{
  ui32	dwDataSize;
  ui32	dwDataLeft;
  ui32	nPlayingMode;
  ui32	lPosition;
  void*	pData;
}WAVESOUND;
/*==============================================================================================================*/
void	AUD_Init(i32 bps, i32 channels, i32 khz);
long	AUD_Trap(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void	AUD_Quit(void);
void	AUD_InitWaveSound(WAVESOUND **pSnd, uchar** p_mem, PTFILE pWaveFile);
void	AUD_WavePlay(WAVESOUND *pSnd, i32 nMode);
void	AUD_WavePause(WAVESOUND *pWaveSnd, ulong* lpdwPos);
void	AUD_WaveResume(WAVESOUND *pWaveSnd, ulong* lpdwPos, short nMode);
void	AUD_WaveStop(WAVESOUND *pWaveSnd);
void	AUD_WaveGetStatus(WAVESOUND *pWaveSnd, long *plStatus);
void	AUD_WaveGetVolume(WAVESOUND *pWaveSnd, long *lVolume);
void	AUD_WaveSetVolume(WAVESOUND *pWaveSnd, long lVolume);
void	AUD_UnInitWaveSound(WAVESOUND *pWaveSnd);
void	AUD_SetMasterVolume(long lVolume);
void	AUD_GetMasterVolume(long* lVolume);
/*==============================================================================================================*/
#endif /*_AUDIO_H_*/
