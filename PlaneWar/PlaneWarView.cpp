
// PlaneWarView.cpp : CPlaneWarView ���ʵ��
//
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PlaneWar.h"
#endif
#include <Winuser.h>
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
//	ON_WM_ERASEBKGND()
//	ON_WM_PAINT()
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




    //pDC->Rectangle(10, 10, 200, 200);   //���þ���
	//CBrush brush;
	//brush.CreateSolidBrush(RGB(90, 184, 137));
	//pDC->SelectObject(&brush);
	//pDC->Rectangle(10, 10, 300, 300);
    ////CRect rect;  //����������Ļ
	////GetClientRect(&rect);
	////pDC->Rectangle(rect);
    //pDC->SetBkMode(TRANSPARENT);  //���ñ���Ϊ͸��
	//pDC->TextOutW(50, 50, _T("LINK")); //��������
    //��������
	//CFont font;
	//font.CreateFontW(50, 25, 100, 100, FW_NORMAL, 1, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, _T("Arial"));
	//pDC->SelectObject(&font);
	//CFont *oldfont = pDC->SelectObject(&font);
	//pDC->TextOutW(100, 100, _T("Network Engineer"));
    ////��ֱ��
	//CPen pen;
	//pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	//pDC->SelectObject(&pen);
	//pDC->MoveTo(30, 50);
	//pDC->LineTo(100, 400);
	//CRect rect;  //����������Ļ
	//GetClientRect(&rect);
	//pDC->Rectangle(rect);

	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_ME);//��ӵ�ͼƬ
	//CImageList imglist;
	//imglist.Create(124, 97, ILC_COLOR32 | ILC_MASK, 1,0);
	//imglist.Add(&bitmap, RGB(0,0,0));
	//CPoint pt(400, 400);
	//imglist.Draw(pDC, 0, pt, ILD_TRANSPARENT);
	
	//myplane.Draw(pDC,TRUE);

	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_ME);//��ӵ�ͼƬ
	//CImageList imglist;
	//imglist.Create(124, 97, ILC_COLOR32 | ILC_MASK, 1,0);
	//imglist.Add(&bitmap, RGB(255,255,255));
	//CPoint pt(100, 100);
	//imglist.Draw(pDC, 0, pt, ILD_NORMAL);
	//pDC->TextOutW(30, 100, _T("1111"));
	



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
	//CDC *pDC = GetDC();
	//CDC cdc;//�ڴ滺��CDC
	//CRect rect;
	//CBitmap *cacheBitmap = new CBitmap;//�ڴ��г��ص���ʱͼ�񻺳�λͼ
	//cdc.CreateCompatibleDC(pDC);//�õ�ǰ�豸CDC��ʼ������CDC  

	//cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	////��pDC��λ����ͼ�Ĺ�ϵ��cdc�������λ����ͼ�У�������֮����һ���Խ�����λͼ�������Ļ

	//CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);


	////��ӱ���ͼƬ
	////CDC *pDC = GetDC();
	//CDC dcMem;
	//dcMem.CreateCompatibleDC(pDC);
 //   CRect rctClient;
	//GetClientRect(rctClient);
	//CBitmap bitmap2;
	//bitmap2.LoadBitmapW(IDB_background);
	//CBitmap *pbmpOld = dcMem.SelectObject(&bitmap2);
	//cdc.StretchBlt(0, 0, rctClient.Width(), rctClient.Height(), &dcMem, 0, 0, 1024, 768, SRCCOPY);





	CRect rect;
	CDC *pDC = GetDC();
	CDC cdc;//�ڴ滺��CDC
	CBitmap *cacheBitmap = new CBitmap;//�ڴ��г��ص���ʱͼ�񻺳�λͼ
	cdc.CreateCompatibleDC(pDC);//�õ�ǰ�豸CDC��ʼ������CDC  

	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//��pDC��λ����ͼ�Ĺ�ϵ��cdc�������λ����ͼ�У�������֮����һ���Խ�����λͼ�������Ļ

	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	//�滻cdcԭ���Ļ�����Ϊ����λͼ������cdc��������ݾ�д���˻���λͼ��
	CDC cdc1;
	cdc1.CreateCompatibleDC(pDC);

	// �������ƣ�����δ���ƣ�
	CBitmap back;
	back.LoadBitmapW(IDB_background);
	CBitmap *old = cdc1.SelectObject(&back);
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &cdc1, 0, 0, 1024, 768, SRCCOPY);
	//�������ƣ�����δ���ƣ�




	myplane.Draw(pDC,true);
	//enemy.Draw(pDC, TRUE);
	//bomb.Draw(pDC, TRUE);

	
	short key;
	key = GetKeyState(VK_UP);
	if ((key & 0x80)!=0) {
		myplane.SetVerMotion(-1);
	}
	key = GetKeyState(VK_DOWN);
	if ((key & 0x80)!=0) {
		myplane.SetVerMotion(1);
	}
    key = GetKeyState(VK_LEFT);
    if ((key & 0x80)!=0) {
	    myplane.SetHorMotion(-1);
	}
	key = GetKeyState(VK_RIGHT);
    if ((key & 0x80)!=0) {
		myplane.SetHorMotion(1);
	}



//��ʼ����  �л�����
	POSITION pos = EnemyList.GetHeadPosition();
	POSITION pos2;
	while (pos != NULL) {
		pos2 = pos;
		CEnemy *_enemy = (CEnemy *)EnemyList.GetNext(pos);
		if (_enemy->GetPoint().y < 0) {
			EnemyList.RemoveAt(pos2);
			delete(_enemy);
		}
		else {
			_enemy->Draw(pDC, false);
			//��ײ���
			CRect rect;
			int irect = rect.IntersectRect(_enemy->GetRect(), myplane.GetRect());
			if (irect != 0) {
				//pDC->SetBkMode(TRANSPARENT);
				//pDC->TextOutW(20, 50, _T("������"));
			}
		}
	}


	//�ӵ�����
	POSITION bpos = BombList.GetHeadPosition();
	POSITION bpos2;
	while (bpos != NULL) {
		bpos2 = bpos;
		CBomb *_bomb = (CBomb *)BombList.GetNext(bpos);
		if (_bomb->GetPoint().y < 0) {
			BombList.RemoveAt(bpos2);
			delete(_bomb);
		}
		else {
			_bomb->Draw(pDC, false);
			//CRect rect;
			//int irect = rect.IntersectRect(_bomb->GetRect(), enemy.GetRect());
			//if (irect != 0) {
				//pDC->SetBkMode(TRANSPARENT);
				//pDC->TextOutW(20, 200, _T("��ը����������������"));
			//}
		}
	}




	CView::OnTimer(nIDEvent);
	//switch(nIDEvent)
	//{
	//case 1: 
	//{
	//	POSITION bpos = BombList.GetHeadPosition();
	//	POSITION bpos2;
	//	while (bpos != NULL) {
	//		bpos2 = bpos;
	//		CBomb *_bomb = (CBomb *)BombList.GetNext(bpos);
	//		if (_bomb->GetPoint().y < 0) {
	//			BombList.RemoveAt(bpos2);
	//			delete(_bomb);
	//		}
	//		else {
	//			_bomb->Draw(pDC, false);
	//			//CRect rect;
	//			//int irect = rect.IntersectRect(_bomb->GetRect(), enemy.GetRect());
	//			//if (irect != 0) {
	//			//pDC->SetBkMode(TRANSPARENT);
	//			//pDC->TextOutW(20, 200, _T("��ը����������������"));
	//			//}
	//		}
	//	}
	//  }
	//  break;
	//case 2: 
	//{
	//	EnemyList.AddHead(new CEnemy);

	//	//for (int i = 0; i < 2; i++)
	//		//EnemyList.AddHead(new CEnemy);
	//	//PositionEnemy += 10;
	//	POSITION pos = EnemyList.GetHeadPosition();
	//	POSITION pos2;
	//	while (pos != NULL) {
	//		pos2 = pos;
	//		CEnemy *_enemy = (CEnemy *)EnemyList.GetNext(pos);
	//		if (_enemy->GetPoint().y < 0) {
	//			EnemyList.RemoveAt(pos2);
	//			delete(_enemy);
	//		}
	//		else {
	//			_enemy->Draw(pDC, false);
	//			//��ײ���
	//			CRect rect;
	//			int irect = rect.IntersectRect(_enemy->GetRect(), myplane.GetRect());
	//			if (irect != 0) {
	//				pDC->SetBkMode(TRANSPARENT);
	//				pDC->TextOutW(20, 50, _T("������"));
	//			}
	//		}
	//	}
	//  }
	//  break;
	//}

	//����������cdc�е��������͵�һ��������pDC�У����������Ļ��
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//�ͷŶ���cdc
	cdc.DeleteDC();
	//�ͷŻ���λͼ
	cacheBitmap->DeleteObject();
	//�ͷ�һ��pDC
	ReleaseDC(pDC);

}


int CPlaneWarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������


	//��Ӷ�ʱ������������������������������������������������������������������������������������������������
	SetTimer(1, 100, NULL);
	//SetTimer(2, 3000, NULL);



	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	return 0;
}

//�ɻ��Ŀո����ҿ���
void CPlaneWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//CDC *pDC = GetDC();  //��ʾ����
	//CString s;
	//s.Format(_T("%d"), nChar);
	//pDC->TextOutW(50, 150, s);


	//if (nChar == VK_SPACE) {
	//	//CRect rect;  //����������Ļ
	//	//GetClientRect(&rect);
	//	//pDC->Rectangle(rect);
	//	KillTimer(1);
	//}

	//Enter���ֵл�
	if (nChar == VK_RETURN)
	{
		//for(int i=0;;i++)
		//int n = rand() % 100;
		for(int i=0;i<=5;i++)
		EnemyList.AddHead(new CEnemy);

	}
	
	//�ո�����ӵ�
	if (nChar == VK_SPACE) {
		//BombList.AddHead(new CBomb());
		BombList.AddHead (new CBomb(myplane.GetPoint().x+52, myplane.GetPoint().y-57));
	}


	//if (nChar == VK_UP) {
	//	myplane.SetVerMotion(-1);
	//	myplane.SetHorMotion(0);
	//}
	//if (nChar == VK_DOWN) {
	//	myplane.SetVerMotion(1);
	//    myplane.SetHorMotion(0);
	//}
	//if (nChar == VK_LEFT) {
	//	myplane.SetHorMotion(-1);
	//	//myplane.SetVerMotion(0);
	//}
	//if (nChar == VK_RIGHT) {
	//	myplane.SetHorMotion(1);
	//	//myplane.SetVerMotion(0);
	//}

	/*if (nChar == VK_LEFT) {
		j-=12;
	}
	else if (nChar == VK_RIGHT) {
		j+=12;
	}
	else if (nChar == VK_UP) {
		k-=12;
    }
	else if (nChar == VK_DOWN) {
		k+=12;
    }*/

    //ReleaseDC(pDC);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CPlaneWarView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	if (nChar == VK_SPACE) {

		SetTimer(1, 100, NULL);
		//KillTimer(1);
	}


	if (nChar == VK_UP) {
		myplane.SetVerMotion(0);
		//myplane.SetHorMotion(0);

	}
	if (nChar == VK_DOWN) {
		myplane.SetVerMotion(0);
		//myplane.SetHorMotion(0);

	}
	if (nChar == VK_LEFT) {
		myplane.SetHorMotion(0);
		//myplane.SetVerMotion(0);
	}
	if (nChar == VK_RIGHT) {
		myplane.SetHorMotion(0);
		//myplane.SetVerMotion(0);
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}



