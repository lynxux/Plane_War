
// PlaneWarView.cpp : CPlaneWarView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneWar.h"
#endif

#include "PlaneWarDoc.h"
#include "PlaneWarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneWarView

IMPLEMENT_DYNCREATE(CPlaneWarView, CView)

BEGIN_MESSAGE_MAP(CPlaneWarView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPlaneWarView 构造/析构

CPlaneWarView::CPlaneWarView()
{
	// TODO: 在此处添加构造代码

}

CPlaneWarView::~CPlaneWarView()
{
}

BOOL CPlaneWarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneWarView 绘制

void CPlaneWarView::OnDraw(CDC* /*pDC*/)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}

void CPlaneWarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPlaneWarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPlaneWarView 诊断

#ifdef _DEBUG
void CPlaneWarView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarDoc* CPlaneWarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarDoc)));
	return (CPlaneWarDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarView 消息处理程序
