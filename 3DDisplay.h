#ifndef _3D_DISPLAY_H_
#define _3D_DISPLAY_H_
/*==============================================================================================================*/
/*==============================================================================================================*/
#include "types.h"
#include "3D.h"
#include "graphic.h"
#include "mathFP.h"
/*==============================================================================================================*/
/*==============================================================================================================*/
enum{
  REN_SOFTWARE= 0x0,
  REN_D3D3		= 0x1,
  REN_D3D5		= 0x2,
  REN_D3D6		= 0x3,
  REN_D3D7		= 0x4,
  REN_D3D8		= 0x5,
  REN_OPENGL	= 0x6,
};
enum{
  RST_POINT		= 0x0,
  RST_LINES		= 0x1,
  RST_FLAT		= 0x2,
  RST_TEXT		= 0x3,
};
enum{
  ANI_NEAREST	= 0x0,
  ANI_LINEAR	= 0x1,
};
/*==============================================================================================================*/
/*==============================================================================================================*/
typedef void (*DRAWER)(VX*, IMAGE*, ui32);
typedef void (*DRAWER_IB)(VX2*, TRI2*, TC2*, IMAGE*, ui32, ui32);
typedef void (*PROCESSOR)(MATRIX*, VX*, ui32, ui32);
/*==============================================================================================================*/
/*==============================================================================================================*/
typedef struct tagM3DS{
  VX*			m_vbStart;
  i32			m_vbNb;
  IMAGE*	m_tex;	
}M3DS;
/*==============================================================================================================*/
typedef struct tagMMD2{
  VX2*		m_vbStart;
  i32			m_vbNb;
  TRI2*		m_ibStart;
  i32			m_ibNb;
  TC2*		m_tbStart;
  i32			m_tbNb;
  IMAGE*	m_tex;
  i32			m_cptFrame;
  i32			m_nNbFrame;
  i32			m_nFps;
}MMD2;
/*==============================================================================================================*/
/*==============================================================================================================*/
#define V3D_MeshSetTexture(mesh, tex)	(mesh)->m_tex	= tex;
#define V3D_MeshMD2SetFPS(mesh, nFps)	(mesh)->m_nFps= nFps;
void V3D_LoadMesh3DS(M3DS** , VX** , string);
void V3D_LoadMeshMD2(MMD2** , VX2** , TRI2** , TC2** , string);
void V3D_Init(void);
void V3D_Quit(void);
void V3D_SetRenderer(i32);
void V3D_SetRendererStage(i32);
void V3D_SetAnimatorStage(i32);
void V3D_Clear(void);
void V3D_ProcessVX(MATRIX* , VX* , s32 );
void V3D_ProcessVX2(MATRIX* , VX2* , s32 );
void V3D_ProcessMesh3DS(MATRIX* , M3DS* );
void V3D_ProcessMeshMD2(MATRIX* , MMD2* );
void V3D_DrawPrimitive(VX* , IMAGE* , u32 );
void V3D_DrawPrimitiveIDX(TRI2* , VX2* , TC2* , IMAGE* , u32 , u32);				
void V3D_DrawMesh3DS(M3DS* );
void V3D_DrawMeshMD2(MMD2* );
/*==============================================================================================================*/
/*==============================================================================================================*/
#endif // _3D_DISPLAY_H_
