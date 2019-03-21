/*******************************************************************************
Copyright (c) 2011-2013, Zhejiang Uniview Technologies Co., Ltd. All rights reserved.
--------------------------------------------------------------------------------
                              imos_public.h

  Project Code: IMOS PLAT
   Module Name: BP
  Date Created: 2008-08-28
        Author: wuxianmin/04253
   Description: ����ƽ̨����ͷ�ļ�

--------------------------------------------------------------------------------
  Modification History
  DATE        NAME             DESCRIPTION
--------------------------------------------------------------------------------
  YYYY-MM-DD

*******************************************************************************/
#ifndef _IMOS_PUBLIC_H_
#define _IMOS_PUBLIC_H_

#ifdef  __cplusplus
extern "C"{
#endif

/* ����ѡ�� */
#if defined(WIN32)
    #if defined(IMOS_EXPORTS_DLL)
        #define IMOS_EXPORT  __declspec( dllexport )
    #else
        #if defined(IMOS_AS_STATIC_LIB)
            #define IMOS_EXPORT
        #else
            #define IMOS_EXPORT  __declspec( dllimport )
        #endif
    #endif
#else
    #define IMOS_EXPORT
#endif

/* ������׼����Լ�� */
#ifdef WIN32
    #define STDCALL         __stdcall
#else
    #ifdef i386
        #define STDCALL         __attribute__((stdcall))
	#else
	    #define STDCALL
    #endif
#endif

/* ���������Ͷ��� */

/** @brief 8λ�з������� */
#ifndef CHAR
typedef char CHAR;
#endif

/** @brief 8λ�޷������� */
#ifndef UCHAR
typedef unsigned char UCHAR;
#endif

/** @brief 16λ�з������� */
#ifndef SHORT
typedef short SHORT;
#endif

/** @brief 16λ�޷������� */
#ifndef USHORT
typedef unsigned short USHORT;
#endif


/* ����ѡ�� */
    /** @brief 32λ�з������� */
    #ifndef LONG
    typedef long LONG;
    #endif

/** @brief 32λ�޷������� */
    #ifndef ULONG
    typedef unsigned long ULONG;
    #endif

/** @brief 32λ�з������� */

#ifdef _lint
    typedef int LONG_32;
    typedef unsigned int ULONG_32;
    typedef unsigned int BOOL_T;

#else
#if defined(WIN32)

typedef long LONG_32;
typedef unsigned long ULONG_32;
typedef unsigned long BOOL_T;

#else
    typedef int LONG_32;
    typedef unsigned int ULONG_32;
    typedef unsigned int BOOL_T;
#endif
#endif

#ifdef _WIN64
typedef unsigned long long ULONG_REAL;
typedef long long LONG_REAL;
#else
typedef unsigned long ULONG_REAL;
typedef long LONG_REAL;
#endif

#ifdef _WIN64
typedef unsigned long long IMOS_uintptr_t;
#else
typedef unsigned long IMOS_uintptr_t;
#endif


/** @brief 64λ�з������� */
#ifndef DLONG
#if defined (_MSC_VER)
typedef __int64 DLONG;
#else
typedef long long DLONG;
#endif
#endif

/** @brief 64λ�޷������� */
#ifndef DULONG
#if defined (_MSC_VER)
typedef unsigned __int64 DULONG;
#else
typedef unsigned long long DULONG;
#endif
#endif

/** @brief ˫������������ */
#ifndef DOUBLE
typedef double DOUBLE;
#endif

/** @brief ������������ */
#ifndef FLOAT
typedef float FLOAT;
#endif


#ifndef SIZE_T
#ifndef WIN32
    /** @brief ��ʾ������������ */
    typedef  long SIZE_T;
#else
    /** @brief ��ʾ������������ */
    #ifndef _WIN64
    typedef unsigned long SIZE_T;
    #endif
#endif
#endif

/** @brief ��ʾʱ���������� */
#ifndef TIME_T
typedef long TIME_T;
#endif

/** @brief VOID�� */
#define VOID                            void

/** @brief ��ʾͨ�þ������ */
#ifndef HANDLE
typedef VOID* HANDLE;
#endif

/** @brief IMOS ID �������� */
#ifndef IMOS_ID
typedef DULONG IMOS_ID;
#endif

/** @brief ͨ�þ������ IMOS_HANDLE */
#ifndef IMOS_HANDLE
#if defined (WIN32)
	typedef HANDLE IMOS_HANDLE;
#else
	typedef long IMOS_HANDLE;
#endif
#endif

/** @brief �����������Ͷ��� */
#define IN
#define OUT
#define INOUT

/** @brief ͨ��״̬�� */
#define OK                              0UL
#define ERR                             1UL

/** @brief IMOS��̹淶����ֵ */
#ifndef BOOL_TRUE
#define BOOL_TRUE                       ((BOOL_T) 1)
#endif

#ifndef BOOL_FALSE
#define BOOL_FALSE                      ((BOOL_T) 0)
#endif

/* Begin: Added by zhouquanwei/z01364, 2015-08-18 for ONVIF ���н���״̬��� */
/* BOOL_T �� ULONG_32 ��ͬ������3��ʾ */
#ifndef BOOL_INVALID
#define BOOL_INVALID                      ((BOOL_T) 3)
#endif
/* End: Added by zhouquanwei/z01364, 2015-08-18 for ONVIF ���н���״̬��� */

#ifdef  __cplusplus
}
#endif /* end of __cplusplus */

#endif /* _IMOS_PUBLIC_H_ */
