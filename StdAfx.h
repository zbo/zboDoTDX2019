// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include <stdio.h>
#include <tchar.h>

class KXian{
public:
	float High;
	float Low;
	float i;
};

class FXing{
public:
	KXian* First;
	KXian* Second;
	KXian* Third;
};





// TODO: 在此处引用程序需要的其他头文件



// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__1EDD32FF_DA00_4490_B90B_36DCFEF9AB45__INCLUDED_)
#define AFX_STDAFX_H__1EDD32FF_DA00_4490_B90B_36DCFEF9AB45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Insert your headers here
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#include <windows.h>

// TODO: reference additional headers your program requires here

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__1EDD32FF_DA00_4490_B90B_36DCFEF9AB45__INCLUDED_)
