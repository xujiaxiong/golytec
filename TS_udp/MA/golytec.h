/* golytec.h  - some type defines for windows */

/* modification history
-----------------------

01a 2015/12/21 星期一 10:19:54    create by frank
*/


#ifndef __INCGOLYTEC
#define __INCGOLYTEC


#ifdef __cplusplus
extern "C" {
#endif


// 包含常用头文件
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <process.h>
#include <math.h>



/* return status values */
#define OK      0
// 注意： windows系统默认的定义 ERROR为0
#undef  ERROR
#define ERROR        (-1)


/* timeout defines */
#define NO_WAIT     0
#define WAIT_FOREVER    (-1)


/* common macros */

#define MSB(x)  (((x) >> 8) & 0xff)   /* most signif byte of 2-byte integer */
#define LSB(x)  ((x) & 0xff)          /* least signif byte of 2-byte integer*/
#define MSW(x) (((x) >> 16) & 0xffff) /* most signif word of 2-word integer */
#define LSW(x) ((x) & 0xffff)         /* least signif byte of 2-word integer*/

/* swap the MSW with the LSW of a 32 bit integer */
#define WORDSWAP(x) (MSW(x) | (LSW(x) << 16))

#define LLSB(x) ((x) & 0xff)        /* 32bit word byte/word swap macros */
#define LNLSB(x) (((x) >> 8) & 0xff)
#define LNMSB(x) (((x) >> 16) & 0xff)
#define LMSB(x)  (((x) >> 24) & 0xff)
#define LONGSWAP(x) ((LLSB(x) << 24) | \
             (LNLSB(x) << 16)| \
             (LNMSB(x) << 8) | \
             (LMSB(x)))

#define OFFSET(structure, member)   /* byte offset of member in structure*/\
        ((int) &(((structure *) 0) -> member))

#define MEMBER_SIZE(structure, member)  /* size of a member of a structure */\
        (sizeof (((structure *) 0) -> member))

#define NELEMENTS(array)        /* number of elements in an array */ \
        (sizeof (array) / sizeof ((array) [0]))

#define FOREVER for (;;)

//#define isascii(c)  ((unsigned) (c) <= 0177)
//#define toascii(c)  ((c) & 0177)

#define FAST    register
#define IMPORT  extern
#define LOCAL   static

#define  DLL_EXPORT     extern "C" __declspec(dllexport)

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif


#ifndef INOUT
#define INOUT
#endif


typedef int BOOL;
//typedef char INT8;
typedef unsigned char UINT8;
typedef short INT16;
typedef unsigned short UINT16;
typedef long double LDOUBLE;

typedef HANDLE SEM_ID;
typedef HANDLE PIPE_ID;
typedef HANDLE WD_ID;
typedef HANDLE SM_ID;
typedef HANDLE COM_ID;




// 下面的这些为windows系统常用类型定义，在windows系统中已定义，这里供参考方便
#ifndef _WINDOWS_

typedef void *PVOID;
typedef PVOID HANDLE;
typedef int BOOL;
typedef unsigned long DWORD;
typedef HANDLE HBITMAP;
typedef HANDLE HDC;
typedef int HFILE;
typedef HANDLE HHOOK;
typedef HANDLE HICON;
typedef HANDLE HINSTANCE;
typedef HANDLE HKEY;
typedef HINSTANCE HMODULE;
typedef HANDLE HWND;
typedef unsigned char BYTE;
typedef BYTE BOOLEAN;
typedef unsigned short WORD;
typedef int INT32;
typedef unsigned int UINT32;
typedef long long INT64;
typedef unsigned long long UINT64;
typedef __nullterminated CONST CHAR *LPCSTR;
#ifdef UNICODE
 typedef LPCWSTR LPCTSTR;
#else
 typedef LPCSTR LPCTSTR;
#endif
typedef CONST WCHAR *LPCWSTR;
typedef HANDLE *LPHANDLE;
typedef CHAR *LPSTR;
#ifdef UNICODE
 typedef LPWSTR LPTSTR;
#else
 typedef LPSTR LPTSTR;
#endif
typedef void *LPVOID;
#ifdef UNICODE
 typedef WCHAR TCHAR;
#else
 typedef char TCHAR;
#endif

#define MAX_PATH          256

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif


#ifndef OPTIONAL
#define OPTIONAL
#endif

#define INFINITE            0xFFFFFFFF  // Infinite timeout



#define INVALID_HANDLE_VALUE  (HANDLE)-1


#endif // _WINDOWS_



// TIMERPROC == FUNCPTR

#ifdef __cplusplus
typedef int     (*FUNCPTR) (...);     /* ptr to function returning int */
typedef void    (*VOIDFUNCPTR) (...); /* ptr to function returning void */
typedef double    (*DBLFUNCPTR) (...);  /* ptr to function returning double*/
typedef float     (*FLTFUNCPTR) (...);  /* ptr to function returning float */
#else
typedef int     (*FUNCPTR) ();     /* ptr to function returning int */
typedef void    (*VOIDFUNCPTR) (); /* ptr to function returning void */
typedef double    (*DBLFUNCPTR) ();  /* ptr to function returning double*/
typedef float     (*FLTFUNCPTR) ();  /* ptr to function returning float */
#endif      /* _cplusplus */



#ifdef __cplusplus
}
#endif


#endif /* __INCGOLYTEC */

