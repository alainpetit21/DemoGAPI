#include <Windows.h>
#include <memory.h>
#include "macros.h"
#include "graphic.h"
#include "sys.h"
#include "input.h"
#include "file.h"
#include "types.h"
#include "gx.h"
#include "3DDisplay.h"
#include "mathFP.h"
#include "resman.h"
PROFILER_INC;

extern IMAGE		bb;
extern IMAGE		fb;

MATRIX			mat;

void main(void)
{
  int rotX=0;int posX=-20;
  int rotY=0;int posY=150;int posZ=500;
  MSG msg;
  int i= 100;
  int incX= 1, incY= 1;
  int posCX=0;
  int posCY=0;
  int x= 0, y=0;

  PROFILER_DEC;
  PROFILER_INIT;

  SYS_Init(L"Test", L"TestClass");
  VID_Init();
  INP_Init();
  V3D_Init();
  RM_Init();

  RM_Allocate(RMI_IMAGE, 1);
  RM_Allocate(RMI_PIXEL, (2*256*256));
  RM_Allocate(RMI_MESH_3DS, 1);
  RM_Allocate(RMI_VERTEX, 10000);

  V3D_SetRendererStage(RST_TEXT);
  V3D_LoadMesh3DS(CUR_MESH_3DS, CUR_VERTEX, L"\\Data\\Zero.3DS");
  VID_LoadTGA(CUR_IMAGE, CUR_PIXEL, L"\\Data\\cloud.tga");
  V3D_MeshSetTexture(&AR_MESH_3DS[0], &AR_IMAGE[0]);

	i= 1000;
	PROFILER_BEFORE;
	while(i--){
		math_Identity(&mat);	
		math_Rotate(&mat, 192, rotY, 0);
		math_Translate(&mat, IFP(posX), IFP(posY), IFP(posZ));
	}
	PROFILER_AFTER(_T"New Math Operations: ", L"\r\n");
	MessageBox(0, buf, 0, 0);
/**/
	while(!INP_IsKeyDown(KEY_ANY_KEY)){
		TRAP_MSG(msg);
		VID_Clear(&bb, CLR_ZERO, 0);
		V3D_Clear();

		VID_Blt(&bb, 0, 0, 240, 256, BLT_COPY, &AR_IMAGE[0], 0, 0, 240, 256);

		math_Identity(&mat);	
		math_Rotate(&mat, 192, rotY, 0);
		math_Translate(&mat, IFP(posX), IFP(posY), IFP(posZ));

		PROFILER_BEFORE;
		V3D_ProcessMesh3DS(&mat, &AR_MESH_3DS[0]);
  	V3D_DrawMesh3DS(&AR_MESH_3DS[0]);
		PROFILER_AFTER(L"One Loop : ", L"\r\n");

		if((++rotY)>=255) rotY= 0;
		VID_Flip();
	}
/**/
	RM_Quit();
	V3D_Quit();
	INP_Quit();
	VID_Quit();
	SYS_Quit();
}

void main2(void)
{
  int rotX=238;int posX=0;
  int rotY=0;int posY=0;int posZ=3;
  MSG msg;
  int i= 1;
  int incX= 1, incY= 1;
  int posCX=0;
  int posCY=0;
  int x= 0, y=0;

  PROFILER_DEC;
  PROFILER_INIT;

  SYS_Init(L"Test", L"TestClass");
  VID_Init();
  INP_Init();
  V3D_Init();
  RM_Init();

  RM_Allocate(RMI_IMAGE, 1);
  RM_Allocate(RMI_PIXEL, 256*256);
  RM_Allocate(RMI_VERTEX2, 16);
  RM_Allocate(RMI_TEXCOORD2, 16);
  RM_Allocate(RMI_TRIANGLES2, 18);

  V3D_SetRendererStage(RST_TEXT);
  VID_LoadTGA(CUR_IMAGE, CUR_PIXEL, L"\\Data\\cloud.tga");

  AR_VERTEX2[0].orig[0]= IFP(-2);	AR_VERTEX2[0].orig[1]= IFP(-2);	AR_VERTEX2[0].orig[2]= 0;
  AR_VERTEX2[1].orig[0]= IFP(-1);	AR_VERTEX2[1].orig[1]= IFP(-2);	AR_VERTEX2[1].orig[2]= 0;
  AR_VERTEX2[2].orig[0]= IFP( 0);	AR_VERTEX2[2].orig[1]= IFP(-2);	AR_VERTEX2[2].orig[2]= 0;
  AR_VERTEX2[3].orig[0]= IFP( 1);	AR_VERTEX2[3].orig[1]= IFP(-2);	AR_VERTEX2[3].orig[2]= 0;
  AR_VERTEX2[4].orig[0]= IFP(-2);	AR_VERTEX2[4].orig[1]= IFP(-1);	AR_VERTEX2[4].orig[2]= 0;
  AR_VERTEX2[5].orig[0]= IFP(-1);	AR_VERTEX2[5].orig[1]= IFP(-1);	AR_VERTEX2[5].orig[2]= 0;
  AR_VERTEX2[6].orig[0]= IFP( 0);	AR_VERTEX2[6].orig[1]= IFP(-1);	AR_VERTEX2[6].orig[2]= 0;
  AR_VERTEX2[7].orig[0]= IFP( 1);	AR_VERTEX2[7].orig[1]= IFP(-1);	AR_VERTEX2[7].orig[2]= 0;
  AR_VERTEX2[8].orig[0]= IFP(-2);	AR_VERTEX2[8].orig[1]= IFP( 0);	AR_VERTEX2[8].orig[2]= 0;
  AR_VERTEX2[9].orig[0]= IFP(-1);	AR_VERTEX2[9].orig[1]= IFP( 0);	AR_VERTEX2[9].orig[2]= 0;
  AR_VERTEX2[10].orig[0]= IFP( 0);	AR_VERTEX2[10].orig[1]= IFP( 0);AR_VERTEX2[10].orig[2]= 0;
  AR_VERTEX2[11].orig[0]= IFP( 1);	AR_VERTEX2[11].orig[1]= IFP( 0);AR_VERTEX2[11].orig[2]= 0;
  AR_VERTEX2[12].orig[0]= IFP(-2);	AR_VERTEX2[12].orig[1]= IFP( 1);AR_VERTEX2[12].orig[2]= 0;
  AR_VERTEX2[13].orig[0]= IFP(-1);	AR_VERTEX2[13].orig[1]= IFP( 1);AR_VERTEX2[13].orig[2]= 0;
  AR_VERTEX2[14].orig[0]= IFP( 0);	AR_VERTEX2[14].orig[1]= IFP( 1);AR_VERTEX2[14].orig[2]= 0;
  AR_VERTEX2[15].orig[0]= IFP( 1);	AR_VERTEX2[15].orig[1]= IFP( 1);AR_VERTEX2[15].orig[2]= 0;

  AR_TEXCOORD2[0].m_U1= IFP(0);		AR_TEXCOORD2[0].m_V1= IFP(0);
  AR_TEXCOORD2[1].m_U1= IFP(64);	AR_TEXCOORD2[1].m_V1= IFP(0);
  AR_TEXCOORD2[2].m_U1= IFP(128);	AR_TEXCOORD2[2].m_V1= IFP(0);
  AR_TEXCOORD2[3].m_U1= IFP(256);	AR_TEXCOORD2[3].m_V1= IFP(0);
  AR_TEXCOORD2[4].m_U1= IFP(0);		AR_TEXCOORD2[4].m_V1= IFP(64);
  AR_TEXCOORD2[5].m_U1= IFP(64);	AR_TEXCOORD2[5].m_V1= IFP(64);
  AR_TEXCOORD2[6].m_U1= IFP(128);	AR_TEXCOORD2[6].m_V1= IFP(64);
  AR_TEXCOORD2[7].m_U1= IFP(256);	AR_TEXCOORD2[7].m_V1= IFP(64);
  AR_TEXCOORD2[8].m_U1= IFP(0);		AR_TEXCOORD2[8].m_V1= IFP(128);
  AR_TEXCOORD2[9].m_U1= IFP(64);	AR_TEXCOORD2[9].m_V1= IFP(128);
  AR_TEXCOORD2[10].m_U1=IFP(128);	AR_TEXCOORD2[10].m_V1= IFP(128);
  AR_TEXCOORD2[11].m_U1=IFP(256);	AR_TEXCOORD2[11].m_V1= IFP(128);
  AR_TEXCOORD2[12].m_U1=IFP(0);		AR_TEXCOORD2[12].m_V1= IFP(256);
  AR_TEXCOORD2[13].m_U1=IFP(64);	AR_TEXCOORD2[13].m_V1= IFP(256);
  AR_TEXCOORD2[14].m_U1=IFP(128);	AR_TEXCOORD2[14].m_V1= IFP(256);
  AR_TEXCOORD2[15].m_U1=IFP(256);	AR_TEXCOORD2[15].m_V1= IFP(256);


  AR_TRIANGLES2[0].idxVertex[0]= 0;		AR_TRIANGLES2[0].idxTexCoor[0]= 0;		
  AR_TRIANGLES2[0].idxVertex[1]= 1;		AR_TRIANGLES2[0].idxTexCoor[1]= 1;		
  AR_TRIANGLES2[0].idxVertex[2]= 4;		AR_TRIANGLES2[0].idxTexCoor[2]= 4;		
  AR_TRIANGLES2[1].idxVertex[0]= 4;		AR_TRIANGLES2[1].idxTexCoor[0]= 4;		
  AR_TRIANGLES2[1].idxVertex[1]= 1;		AR_TRIANGLES2[1].idxTexCoor[1]= 1;		
  AR_TRIANGLES2[1].idxVertex[2]= 5;		AR_TRIANGLES2[1].idxTexCoor[2]= 5;		
  AR_TRIANGLES2[2].idxVertex[0]= 1;		AR_TRIANGLES2[2].idxTexCoor[0]= 1;		
  AR_TRIANGLES2[2].idxVertex[1]= 2;		AR_TRIANGLES2[2].idxTexCoor[1]= 2;		
  AR_TRIANGLES2[2].idxVertex[2]= 5;		AR_TRIANGLES2[2].idxTexCoor[2]= 5;		
  AR_TRIANGLES2[3].idxVertex[0]= 5;		AR_TRIANGLES2[3].idxTexCoor[0]= 5;		
  AR_TRIANGLES2[3].idxVertex[1]= 2;		AR_TRIANGLES2[3].idxTexCoor[1]= 2;		
  AR_TRIANGLES2[3].idxVertex[2]= 6;		AR_TRIANGLES2[3].idxTexCoor[2]= 6;		
  AR_TRIANGLES2[4].idxVertex[0]= 2;		AR_TRIANGLES2[4].idxTexCoor[0]= 2;		
  AR_TRIANGLES2[4].idxVertex[1]= 3;		AR_TRIANGLES2[4].idxTexCoor[1]= 3;		
  AR_TRIANGLES2[4].idxVertex[2]= 6;		AR_TRIANGLES2[4].idxTexCoor[2]= 6;		
  AR_TRIANGLES2[5].idxVertex[0]= 6;		AR_TRIANGLES2[5].idxTexCoor[0]= 6;		
  AR_TRIANGLES2[5].idxVertex[1]= 3;		AR_TRIANGLES2[5].idxTexCoor[1]= 3;		
  AR_TRIANGLES2[5].idxVertex[2]= 7;		AR_TRIANGLES2[5].idxTexCoor[2]= 7;		
  AR_TRIANGLES2[6].idxVertex[0]= 4;		AR_TRIANGLES2[6].idxTexCoor[0]= 4;		
  AR_TRIANGLES2[6].idxVertex[1]= 5;		AR_TRIANGLES2[6].idxTexCoor[1]= 5;		
  AR_TRIANGLES2[6].idxVertex[2]= 8;		AR_TRIANGLES2[6].idxTexCoor[2]= 8;		
  AR_TRIANGLES2[7].idxVertex[0]= 8;		AR_TRIANGLES2[7].idxTexCoor[0]= 8;		
  AR_TRIANGLES2[7].idxVertex[1]= 5;		AR_TRIANGLES2[7].idxTexCoor[1]= 5;		
  AR_TRIANGLES2[7].idxVertex[2]= 9;		AR_TRIANGLES2[7].idxTexCoor[2]= 9;		
  AR_TRIANGLES2[8].idxVertex[0]= 5;		AR_TRIANGLES2[8].idxTexCoor[0]= 5;		
  AR_TRIANGLES2[8].idxVertex[1]= 6;		AR_TRIANGLES2[8].idxTexCoor[1]= 6;		
  AR_TRIANGLES2[8].idxVertex[2]= 9;		AR_TRIANGLES2[8].idxTexCoor[2]= 9;		
  AR_TRIANGLES2[9].idxVertex[0]= 9;		AR_TRIANGLES2[9].idxTexCoor[0]= 9;		
  AR_TRIANGLES2[9].idxVertex[1]= 6;		AR_TRIANGLES2[9].idxTexCoor[1]= 6;		
  AR_TRIANGLES2[9].idxVertex[2]= 10;	AR_TRIANGLES2[9].idxTexCoor[2]= 10;	
  AR_TRIANGLES2[10].idxVertex[0]= 6;	AR_TRIANGLES2[10].idxTexCoor[0]= 6;	
  AR_TRIANGLES2[10].idxVertex[1]= 7;	AR_TRIANGLES2[10].idxTexCoor[1]= 7;	
  AR_TRIANGLES2[10].idxVertex[2]= 10;	AR_TRIANGLES2[10].idxTexCoor[2]= 10;	
  AR_TRIANGLES2[11].idxVertex[0]= 10;	AR_TRIANGLES2[11].idxTexCoor[0]= 10;	
  AR_TRIANGLES2[11].idxVertex[1]= 7;	AR_TRIANGLES2[11].idxTexCoor[1]= 7;	
  AR_TRIANGLES2[11].idxVertex[2]= 11;	AR_TRIANGLES2[11].idxTexCoor[2]= 11;	
  AR_TRIANGLES2[12].idxVertex[0]= 8;	AR_TRIANGLES2[12].idxTexCoor[0]= 8;	
  AR_TRIANGLES2[12].idxVertex[1]= 9;	AR_TRIANGLES2[12].idxTexCoor[1]= 9;	
  AR_TRIANGLES2[12].idxVertex[2]= 12;	AR_TRIANGLES2[12].idxTexCoor[2]= 12;	
  AR_TRIANGLES2[13].idxVertex[0]= 12;	AR_TRIANGLES2[13].idxTexCoor[0]= 12;	
  AR_TRIANGLES2[13].idxVertex[1]= 9;	AR_TRIANGLES2[13].idxTexCoor[1]= 9;	
  AR_TRIANGLES2[13].idxVertex[2]= 13;	AR_TRIANGLES2[13].idxTexCoor[2]= 13;	
  AR_TRIANGLES2[14].idxVertex[0]= 9;	AR_TRIANGLES2[14].idxTexCoor[0]= 9;	
  AR_TRIANGLES2[14].idxVertex[1]= 10;	AR_TRIANGLES2[14].idxTexCoor[1]= 10;	
  AR_TRIANGLES2[14].idxVertex[2]= 13;	AR_TRIANGLES2[14].idxTexCoor[2]= 13;	
  AR_TRIANGLES2[15].idxVertex[0]= 13;	AR_TRIANGLES2[15].idxTexCoor[0]= 13;	
  AR_TRIANGLES2[15].idxVertex[1]= 10;	AR_TRIANGLES2[15].idxTexCoor[1]= 10;	
  AR_TRIANGLES2[15].idxVertex[2]= 14;	AR_TRIANGLES2[15].idxTexCoor[2]= 14;	
  AR_TRIANGLES2[16].idxVertex[0]= 10;	AR_TRIANGLES2[16].idxTexCoor[0]= 10;	
  AR_TRIANGLES2[16].idxVertex[1]= 11;	AR_TRIANGLES2[16].idxTexCoor[1]= 11;	
  AR_TRIANGLES2[16].idxVertex[2]= 14;	AR_TRIANGLES2[16].idxTexCoor[2]= 14;	
  AR_TRIANGLES2[17].idxVertex[0]= 14;	AR_TRIANGLES2[17].idxTexCoor[0]= 14;	
  AR_TRIANGLES2[17].idxVertex[1]= 11;	AR_TRIANGLES2[17].idxTexCoor[1]= 11;	
  AR_TRIANGLES2[17].idxVertex[2]= 15;	AR_TRIANGLES2[17].idxTexCoor[2]= 15;	

  while(!INP_IsKeyDown(KEY_HELP)){
		PROFILER_BEFORE;
		INP_Update;
		TRAP_MSG(msg);
		VID_Clear(&bb, CLR_ZERO, 0);
		V3D_Clear();

		math_Identity(&mat);	
		math_Rotate(&mat, 0, 0, rotX);
		math_Translate(&mat, IFP(posX), IFP(posY), IFP(posZ));

		V3D_ProcessVX2(&mat, AR_VERTEX2, 16);
		for(int j=0;j<i;++j)
			V3D_DrawPrimitiveIDX(&AR_TRIANGLES2[j], AR_VERTEX2, AR_TEXCOORD2, AR_IMAGE, 1, 16);

		if(INP_IsKeyDown(KEY_UP))	posZ--;
		if(INP_IsKeyDown(KEY_DOWN))	posZ++;
		if(INP_IsKeyDown(KEY_RIGHT))rotX--;
		if(INP_IsKeyDown(KEY_LEFT))	rotX++;
		if(INP_IsKeyDownAB(KEY_OK))		i++;
		if(INP_IsKeyDownAB(KEY_FIRE))	i--;

		if(i>18)i=0;
		if(i<0)i=18;
		rotX&= 0xFF;
		if(posZ==1)posZ=2;
		VID_Flip();
		PROFILER_AFTER(L"One Loop : ", L"\r\n");
	}

	RM_Quit();
	V3D_Quit();
	INP_Quit();
	VID_Quit();
	SYS_Quit();
}
