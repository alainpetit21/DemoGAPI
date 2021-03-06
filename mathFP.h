#ifndef _MATHFP_H_
#define _MATHFP_H_
/*==============================================================================================================*/
/*==============================================================================================================*/
#include "types.h"
/*==============================================================================================================*/
/*==============================================================================================================*/
#define FPP					10
#define IFP(x)			((x)<<FPP)
#define FP_ONE			IFP(1)
#define FPMUL(x,y)	(((x)*(y))>>FPP)
#define FPDIV(x,y)	(((x)<<FPP)/(y))
#define FP(x)				((int)((x)*FP_ONE+0.5f))
/*==============================================================================================================*/
/*==============================================================================================================*/
extern int Sin[256];
extern int Cos[256];
/*==============================================================================================================*/
/*==============================================================================================================*/
#undef sin
#undef cos
#define sin(x) Sin[x]
#define cos(x) Cos[x]
/*==============================================================================================================*/
/*==============================================================================================================*/
typedef struct tagMATRIX
{
  union{
    int m[4][4];
    int l[16];
    struct {
      int m11,m12,m13,m14
      , m21,m22,m23,m24
      , m31,m32,m33,m34
      , m41,m42,m43,m44;
    };
  };
}MATRIX;
/*==============================================================================================================*/
/*==============================================================================================================*/
#define math_Identity(pM)															\
	memset((pM), 0x0, sizeof(s32)*16);									\
	(pM)->m11= (pM)->m22= (pM)->m33= (pM)->m44= FP_ONE;
#define math_GetX(pM, pVec)	\
(														\
	(pVec)[0]= (pM)->l[0];		\
	(pVec)[1]= (pM)->l[4];		\
	(pVec)[2]= (pM)->l[8];		\
)														\
	pVec;
#define math_GetY(pM, pVec)	\
(														\
	(pVec)[0]= (pM)->l[1];		\
	(pVec)[1]= (pM)->l[5];		\
	(pVec)[2]= (pM)->l[9];		\
)														\
	pVec;
#define math_GetZ(pM, pVec)	\
(														\
	(pVec)[0]= (pM)->l[2];		\
	(pVec)[1]= (pM)->l[6];		\
	(pVec)[2]= (pM)->l[10];		\
)														\
	pVec;
#define math_Translate(pM, x, y, z)	\
	(pM)->l[3] += (x);								\
	(pM)->l[7] += (y);								\
	(pM)->l[11]+= (z);
/*==============================================================================================================*/
void	math_RotateX(MATRIX* _this, s32 a_X);
void	math_RotateY(MATRIX* _this, s32 a_Y);
void	math_RotateZ(MATRIX* _this, s32 a_Z);
void	math_Concat(MATRIX* _this, MATRIX* aM2);
void	math_Rotate(MATRIX* _this, s32 a_RX, s32 a_RY, s32 a_RZ);
/*==============================================================================================================*/
/*==============================================================================================================*/
#endif	// _MATHFP_H_
