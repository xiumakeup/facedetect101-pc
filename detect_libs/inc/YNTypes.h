/*----------------------------------------------------------------------------------------------
*
* This file is XIUSDK's property. It contains XIUSDK's trade secret, proprietary and
* confidential information.
*
* The information and code contained in this file is only for authorized XIUSDK employees
* to design, create, modify, or review.
*
* DO NOT DISTRIBUTE, DO NOT DUPLICATE OR TRANSMIT IN ANY FORM WITHOUT PROPER AUTHORIZATION.
*
* If you are not an intended recipient of this file, you must not copy, distribute, modify,
* or take any action in reliance on it.
*
* If you have received this file in error, please immediately notify XIUSDK and
* permanently delete the original and any copy of any file and any printout thereof.
*
*---------------------------------------------------------------------------------------------*/
/*****************************************************************************
Copyright:    www.xiusdk.cn(all rights reserved)
File name:    YNTypes.h
Description:  �����ؼ��㶨λ
Author:       xiusdk
Version:      V1.2
qq group:     567648913(��Ⱥ��ȡ������Ϣ)
*****************************************************************************/
#ifndef YN_TYPES_H_
#define YN_TYPES_H_


#ifdef _MSC_VER
#	ifdef __cplusplus
#		ifdef YN_STATIC_LIB
#			define YN_SDK_API  extern "C"
#		else
#			ifdef YN_SDK_EXPORTS
#				define YN_SDK_API extern "C" __declspec(dllexport)
#			else
#				define YN_SDK_API extern "C" __declspec(dllimport)
#			endif
#		endif
#	else
#		ifdef YN_STATIC_LIB
#			define YN_SDK_API
#		else
#			ifdef YN_SDK_EXPORTS
#				define YN_SDK_API __declspec(dllexport)
#			else
#				define YN_SDK_API __declspec(dllimport)
#			endif
#		endif
#	endif
#else /* _MSC_VER */
#	ifdef __cplusplus
#		ifdef YN_SDK_EXPORTS
#			define YN_SDK_API extern "C" __attribute__((visibility ("default")))
#		else
#			define YN_SDK_API extern "C"
#		endif
#	else
#		ifdef YN_SDK_EXPORTS
#			define YN_SDK_API __attribute__((visibility ("default")))
#		else
#			define YN_SDK_API
#		endif
#	endif
#endif

///== handle declearation
typedef void YNVOID;
typedef YNVOID* YNHandle;

///== result declearation
typedef int YNRESULT;


#define YN_OK (0)                       // ��������
#define YN_E_INVALID_ARG (-1)           // ��Ч����
#define YN_E_HANDLE (-2)                // �������
#define YN_E_OUT_OF_MEMORY (-3)         // �ڴ治��
#define YN_E_FAIL (-4)                  // �ڲ�����
#define YN_E_DEF_NOT_FOUND (-5)         // ����ȱʧ
#define YN_E_INVALID_PIXEL_FORMAT (-6)  // ͼ���ʽ��֧��
#define YN_E_FILE_NOT_FOUND (-7)        // ģ���ļ�������
#define YN_E_FILE_NOT_INITIALIZED (-8)  // ģ���ļ�δ��ʼ��
#define YN_E_FILE_INVALID_FORMAT (-9)   // ģ���ļ���ʽ��֧��
#define YN_E_FILE_EXPIRE (-10)           // ģ���ļ�����
#define YN_E_INVALID_APPID (-11)        // ��������
#define YN_E_INVALID_AUTH (-12)         // ���ܲ�֧��
#define YN_E_AUTH_EXPIRE (-13)          // ���ܹ���

// ʹ�õ��̻߳�˫�߳�
#define YN_MOBILE_ALIGN_SINGLE_THREAD        0x00000000
#define YN_MOBILE_ALIGN_MULTI_THREAD         0x00000010  

/// st pixel format definition
typedef enum {
	YN_PIX_FMT_GRAY8,   // Y    1        8bpp ( ��ͨ��8bit�Ҷ����� )
	YN_PIX_FMT_YUV420P, // YUV  4:2:0   12bpp ( 3ͨ��, һ������ͨ��, ������ΪU������V����ͨ��, ����ͨ������������ )
	YN_PIX_FMT_NV12,    // YUV  4:2:0   12bpp ( 2ͨ��, һ��ͨ��������������ͨ��, ��һͨ��ΪUV�������� )
	YN_PIX_FMT_NV21,    // YUV  4:2:0   12bpp ( 2ͨ��, һ��ͨ��������������ͨ��, ��һͨ��ΪVU�������� )
	YN_PIX_FMT_BGRA8888,// BGRA 8:8:8:8 32bpp ( 4ͨ��32bit BGRA ���� )
	YN_PIX_FMT_BGR888,  // BGR  8:8:8   24bpp ( 3ͨ��24bit BGR ���� )
	YN_PIX_FMT_RGBA8888,// BGRA 8:8:8:8 32bpp ( 4ͨ��32bit RGBA ���� )
	YN_PIX_FMT_RGB888,  // BGR  8:8:8   24bpp ( 3ͨ��24bit RGB ���� )
} YN_PIXEL_FORMAT;


typedef enum {
	YN_CLOCKWISE_ROTATE_0 = 0,  // ͼ����Ҫת��
	YN_CLOCKWISE_ROTATE_90 = 1, // ͼ����Ҫ˳ʱ����ת90��
	YN_CLOCKWISE_ROTATE_180 = 2,// ͼ����Ҫ˳ʱ����ת180��
	YN_CLOCKWISE_ROTATE_270 = 3 // ͼ����Ҫ˳ʱ����ת270��
} YN_ROTATION_TYPE;


#define MAX_PTS_SIZE 101

typedef struct {
	float x;
	float y;
} YNPoint2f;

typedef struct {
	YNPoint2f pts[MAX_PTS_SIZE];
	int ptsSize;
} YNShape;

typedef struct{
	int left;
	int top;
	int right;
	int bottom;
} YNRect;

typedef struct {
	YNRect rect;            ///< �����沿�ľ�������
	float score;            ///< ���Ŷ�
	YNShape shape;          ///< ����101�ؼ��������
	int yaw;                ///< ˮƽת�ǣ���ʵ������������
	int pitch;              ///< �����ǣ���ʵ�������ϸ�����
	int roll;               ///< ��ת�ǣ���ʵ������������
	int ID;                 ///< faceID: ÿ����⵽������ӵ��Ψһ��faceID���������ٶ�ʧ�Ժ����±���⵽������һ���µ�faceID
} YNFaces;


#endif//YN_TYPES_H_