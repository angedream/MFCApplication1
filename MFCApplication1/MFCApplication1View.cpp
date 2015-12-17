// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面 
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和 
// MFC C++ 库软件随附的相关电子文档。  
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。  
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问 
// http://go.microsoft.com/fwlink/?LinkId=238214。
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// MFCApplication1View.cpp : CMFCApplication1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CHtmlView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(32788, &CMFCApplication1View::On32788)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCApplication1View, CHtmlView)
	DISP_FUNCTION(CMFCApplication1View, "Func1", Func1, VT_EMPTY, VTS_I4 VTS_I4)
END_DISPATCH_MAP()

// CMFCApplication1View 构造/析构

BOOL CMFCApplication1View::Func1(int a, int b)
{
	CString str;
	str.Format(L"%d,%d",a,b);
	//MessageBox(str);
	return 0;
}

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: 在此处添加构造代码
	EnableAutomation();

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("file://C:/Users/zilong/Documents/Visual Studio 2015/Projects/MFCApplication1/MFCApplication1/NvHtml/cggl.htm"),NULL,NULL);
	//别忘了#include <MsHTML.h>
	//m_WebBrowser是一个WebBrowser的Activex控件对象。
	

}


// CMFCApplication1View 打印


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}


void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCApplication1View 诊断

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View 消息处理程序
HRESULT CMFCApplication1View::OnGetExternal(LPDISPATCH *lppDispatch)
{
	*lppDispatch = GetIDispatch(TRUE);
	return S_OK;
}

void CMFCApplication1View::On32788()
{
	// TODO: 在此添加命令处理程序代码

	CComQIPtr<IHTMLDocument2> spDoc = (IHTMLDocument2 *)GetHtmlDocument();
	CComDispatchDriver spScript;
	spDoc->get_Script(&spScript);

	CComVariant var1 = 10, var2 = 20, varRet;
	spScript.Invoke2(L"Add", &var1, &var2, &varRet);
	
}
