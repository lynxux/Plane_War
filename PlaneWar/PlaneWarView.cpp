
// PlaneWarView.cpp : CPlaneWarView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CPlaneWarView ����/����

CPlaneWarView::CPlaneWarView()
{
	// TODO: �ڴ˴���ӹ������

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

void CPlaneWarView::OnDraw(CDC* /*pDC*/)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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
