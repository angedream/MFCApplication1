// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ������� 
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// MFCApplication1View.cpp : CMFCApplication1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(32788, &CMFCApplication1View::On32788)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CMFCApplication1View, CHtmlView)
	DISP_FUNCTION(CMFCApplication1View, "Func1", Func1, VT_EMPTY, VTS_I4 VTS_I4)
END_DISPATCH_MAP()

// CMFCApplication1View ����/����

BOOL CMFCApplication1View::Func1(int a, int b)
{
	CString str;
	str.Format(L"%d,%d",a,b);
	//MessageBox(str);
	return 0;
}

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: �ڴ˴���ӹ������
	EnableAutomation();

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void CMFCApplication1View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("file://C:/Users/zilong/Documents/Visual Studio 2015/Projects/MFCApplication1/MFCApplication1/NvHtml/cggl.htm"),NULL,NULL);
	//������#include <MsHTML.h>
	//m_WebBrowser��һ��WebBrowser��Activex�ؼ�����
	

}


// CMFCApplication1View ��ӡ


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


// CMFCApplication1View ���

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View ��Ϣ�������
HRESULT CMFCApplication1View::OnGetExternal(LPDISPATCH *lppDispatch)
{
	*lppDispatch = GetIDispatch(TRUE);
	return S_OK;
}

void CMFCApplication1View::On32788()
{
	// TODO: �ڴ���������������

	CComQIPtr<IHTMLDocument2> spDoc = (IHTMLDocument2 *)GetHtmlDocument();
	CComDispatchDriver spScript;
	spDoc->get_Script(&spScript);

	CComVariant var1 = 10, var2 = 20, varRet;
	spScript.Invoke2(L"Add", &var1, &var2, &varRet);
	
}
