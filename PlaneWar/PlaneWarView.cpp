
// PlaneWarView.cpp : CPlaneWarView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "PlaneWar.h"
#endif

#include "resource.h"
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
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()

// CPlaneWarView 构造/析构

CPlaneWarView::CPlaneWarView()
{
	// TODO: 在此处添加构造代码
	//SetTimer(0, 1000, NULL);
	i = 0;
	j = 400;
	k = 400;
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

void CPlaneWarView::OnDraw(CDC* pDC)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->Rectangle(10, 10, 200, 200);   //设置矩形
	CBrush brush;
	brush.CreateSolidBrush(RGB(90, 184, 137));
	pDC->SelectObject(&brush);
	pDC->Rectangle(10, 10, 300, 300);

	//CRect rect;  //矩形填满屏幕
	//GetClientRect(&rect);
	//pDC->Rectangle(rect);

	pDC->SetBkMode(TRANSPARENT);  //设置背景为透明
	pDC->TextOutW(50, 50, _T("LINK")); //设置文字

    //设置字体
	CFont font;
	font.CreateFontW(50, 25, 100, 100, FW_NORMAL, 1, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, _T("Arial"));
	pDC->SelectObject(&font);
	CFont *oldfont = pDC->SelectObject(&font);
	pDC->TextOutW(100, 100, _T("Network Engineer"));


	//画直线
	CPen pen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	pDC->SelectObject(&pen);
	pDC->MoveTo(30, 50);
	pDC->LineTo(100, 400);

	pDC->SelectObject(oldfont);   //
	pDC->TextOutW(300, 300, _T("Software Engineer"));

	CRect rect;  //矩形填满屏幕
	GetClientRect(&rect);
	pDC->Rectangle(rect);

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_ME);//添加的图片
	CImageList imglist;
	imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1,0);
	imglist.Add(&bitmap, RGB(0,0,0));
	CPoint pt(400, 400);
	imglist.Draw(pDC, 0, pt, ILD_TRANSPARENT);
	
	myplane.Draw(pDC,TRUE);
	



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


void CPlaneWarView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	//i++;
	CString s;
	s.Format(_T("%d"), i++);
	pDC->TextOutW(50, 90,s);
	//myplane.Draw(pDC, TRUE);

	/*CRect rect;	           //另一种刷屏使飞机移动的方法//但会出现闪烁  //双缓冲？？？
	GetClientRect(&rect);
	pDC->Rectangle(rect);
    CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_ME);
	CImageList imglist;
	imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1, 0);
	imglist.Add(&bitmap, RGB(0, 0, 0));
	CPoint pt(j, k);
	imglist.Draw(pDC, 0, CPoint(j, k), ILD_TRANSPARENT);*/
	CRect rect;
	GetClientRect(&rect);
	pDC->Rectangle(rect);
	if (myplane.GetPoint().y<-60)
		myplane.SetPoint(500);
	myplane.Draw(pDC,TRUE);



	CView::OnTimer(nIDEvent);
	//switch (nIDEvent) {
	//case 0: i = i - 100;
	//case 1: i = i + 100;
	//case 2: i = i+1;
	//}
}


int CPlaneWarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//添加定时器！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	SetTimer(1, 15, NULL);
	myplane.LoadImage();
	//SetTimer(1, 3000, NULL);
	//SetTimer(2, 5000, NULL);
	return 0;
}


void CPlaneWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDC *pDC = GetDC();
	CString s;
	s.Format(_T("%d"), nChar);
	pDC->TextOutW(50, 150, s);


	if (nChar == VK_SPACE) {
		//CRect rect;  //矩形填满屏幕
		//GetClientRect(&rect);
		//pDC->Rectangle(rect);
		KillTimer(1);
	}


	if (nChar == VK_LEFT) {
		//刷屏，飞机坐标改变
		CRect rect;  //矩形填满屏幕
		GetClientRect(&rect);
		pDC->Rectangle(rect);
		j-=12;
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ME);
		CImageList imglist;
		imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1, 0);
		imglist.Add(&bitmap, RGB(0, 0, 0));
		CPoint pt(j, k);
		imglist.Draw(pDC, 0, CPoint(j, k), ILD_TRANSPARENT);

		 //KillTimer(0);
	}
	else if (nChar == VK_RIGHT) {
		CRect rect;  //矩形填满屏幕
		GetClientRect(&rect);
		pDC->Rectangle(rect);
		j+=12;
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ME);
		CImageList imglist;
		imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1, 0);
		imglist.Add(&bitmap, RGB(0, 0, 0));
		CPoint pt(j, k);
		imglist.Draw(pDC, 0, CPoint(j, k), ILD_TRANSPARENT);

	}
	else if (nChar == VK_UP) {
		CRect rect;  //矩形填满屏幕
		GetClientRect(&rect);
		pDC->Rectangle(rect);
		k-=12;
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ME);
		CImageList imglist;
		imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1, 0);
		imglist.Add(&bitmap, RGB(0, 0, 0));
		CPoint pt(j, k);
		imglist.Draw(pDC, 0, CPoint(j, k), ILD_TRANSPARENT);

	}
	else if (nChar == VK_DOWN) {
		CRect rect;  //矩形填满屏幕
		GetClientRect(&rect);
		pDC->Rectangle(rect);
		k+=12;
		CBitmap bitmap;
		bitmap.LoadBitmapW(IDB_ME);
		CImageList imglist;
		imglist.Create(50, 60, ILC_COLOR8 | ILC_MASK, 1, 0);
		imglist.Add(&bitmap, RGB(0, 0, 0));
		CPoint pt(j, k);
		imglist.Draw(pDC, 0, CPoint(j , k), ILD_TRANSPARENT);

	}
    ReleaseDC(pDC);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPlaneWarView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	if (nChar == VK_SPACE) {

		SetTimer(1, 1000, NULL);
		//KillTimer(1);
	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
