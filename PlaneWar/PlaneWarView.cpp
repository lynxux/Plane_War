
// PlaneWarView.cpp : CPlaneWarView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CPlaneWarView ����/����

CPlaneWarView::CPlaneWarView()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlaneWarView ����

void CPlaneWarView::OnDraw(CDC* pDC)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->Rectangle(10, 10, 200, 200);   //���þ���
	CBrush brush;
	brush.CreateSolidBrush(RGB(90, 184, 137));
	pDC->SelectObject(&brush);
	pDC->Rectangle(10, 10, 300, 300);

	//CRect rect;  //����������Ļ
	//GetClientRect(&rect);
	//pDC->Rectangle(rect);

	pDC->SetBkMode(TRANSPARENT);  //���ñ���Ϊ͸��
	pDC->TextOutW(50, 50, _T("LINK")); //��������

    //��������
	CFont font;
	font.CreateFontW(50, 25, 100, 100, FW_NORMAL, 1, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, _T("Arial"));
	pDC->SelectObject(&font);
	CFont *oldfont = pDC->SelectObject(&font);
	pDC->TextOutW(100, 100, _T("Network Engineer"));


	//��ֱ��
	CPen pen;
	pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	pDC->SelectObject(&pen);
	pDC->MoveTo(30, 50);
	pDC->LineTo(100, 400);

	pDC->SelectObject(oldfont);   //
	pDC->TextOutW(300, 300, _T("Software Engineer"));

	CRect rect;  //����������Ļ
	GetClientRect(&rect);
	pDC->Rectangle(rect);

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_ME);//��ӵ�ͼƬ
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


// CPlaneWarView ���

#ifdef _DEBUG
void CPlaneWarView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarDoc* CPlaneWarView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarDoc)));
	return (CPlaneWarDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarView ��Ϣ�������


void CPlaneWarView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = GetDC();
	//i++;
	CString s;
	s.Format(_T("%d"), i++);
	pDC->TextOutW(50, 90,s);
	//myplane.Draw(pDC, TRUE);

	/*CRect rect;	           //��һ��ˢ��ʹ�ɻ��ƶ��ķ���//���������˸  //˫���壿����
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

	// TODO:  �ڴ������ר�õĴ�������

	//��Ӷ�ʱ������������������������������������������������������������������������������������������������
	SetTimer(1, 15, NULL);
	myplane.LoadImage();
	//SetTimer(1, 3000, NULL);
	//SetTimer(2, 5000, NULL);
	return 0;
}


void CPlaneWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDC *pDC = GetDC();
	CString s;
	s.Format(_T("%d"), nChar);
	pDC->TextOutW(50, 150, s);


	if (nChar == VK_SPACE) {
		//CRect rect;  //����������Ļ
		//GetClientRect(&rect);
		//pDC->Rectangle(rect);
		KillTimer(1);
	}


	if (nChar == VK_LEFT) {
		//ˢ�����ɻ�����ı�
		CRect rect;  //����������Ļ
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
		CRect rect;  //����������Ļ
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
		CRect rect;  //����������Ļ
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
		CRect rect;  //����������Ļ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if (nChar == VK_SPACE) {

		SetTimer(1, 1000, NULL);
		//KillTimer(1);
	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
