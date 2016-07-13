
// PlaneWarView.cpp : CPlaneWarView ���ʵ��
//
#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "PlaneWar.h"
#endif
//#include <Winuser.h>
#include <afxwin.h>
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
//ON_WM_ERASEBKGND()
//ON_WM_ERASEBKGND()
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

	CView::OnTimer(nIDEvent);
	//TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

    CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CDC cdc;//�ڴ滺��CDC
	CBitmap *cacheBitmap= new CBitmap;//�ڴ��г��ص���ʱͼ�񻺳�λͼ
    cdc.CreateCompatibleDC(pDC);//�õ�ǰ�豸CDC��ʼ������CDC  
	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//��pDC��λ����ͼ�Ĺ�ϵ��cdc�������λ����ͼ�У�������֮����һ���Խ�����λͼ�������Ļ
	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	//�滻cdcԭ���Ļ�����Ϊ����λͼ������cdc��������ݾ�д���˻���λͼ��
	CDC cdc1;
	cdc1.CreateCompatibleDC(pDC);

	//��������
	CBitmap back;
	back.LoadBitmapW(IDB_background);
	CBitmap *old = cdc1.SelectObject(&back);
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &cdc1, 0, 0, 1024, 768, SRCCOPY);



	short key;
	key = GetKeyState(87);
	if ((key & 0x80) != 0) {
		myplane.SetVerMotion(-1);
	}
	key = GetKeyState(83);
	if ((key & 0x80) != 0) {
		myplane.SetVerMotion(1);
	}
	key = GetKeyState(65);
	if ((key & 0x80) != 0) {
		myplane.SetHorMotion(-1);
	}
	key = GetKeyState(68);
	if ((key & 0x80) != 0) {
		myplane.SetHorMotion(1);
	}

	//��ӱ���ͼƬ
	/*CDC *pDC = GetDC();
	CRect rect;
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CRect rctClient;
	GetClientRect(rctClient);
	CBitmap bitmap2;
	bitmap2.LoadBitmapW(IDB_background);
	CBitmap *pbmpOld = dcMem.SelectObject(&bitmap2);
	pDC->StretchBlt(0, 0, rctClient.Width(), rctClient.Height(), &dcMem, 0, 0, 1024, 768, SRCCOPY);
*/
	myplane.Draw(&cdc, false);


	////��ʼ����  �л�����
	if (nIDEvent == 4) {
		//EnemyList.AddTail(new CEnemy(1000));
		EnemyList.AddTail(new CEnemy(400));
		EnemyList.AddTail(new CEnemy(-200));
	}
	else if (nIDEvent == 5) {
		EnemyList.AddTail(new CEnemy(0));
	}
	POSITION pos = EnemyList.GetHeadPosition();
	POSITION pos2;
	while (pos != NULL) {
		pos2 = pos;
		CEnemy *_enemy = (CEnemy *)EnemyList.GetNext(pos);
		if (_enemy->GetPoint().y >1000 ) {
		    EnemyList.RemoveAt(pos2);
			delete(_enemy);
		}
		else {
			_enemy->Draw(&cdc, false);
			//�л��ӵ�����
			if (nIDEvent == 3&&(_enemy->GetPoint().x-myplane.GetPoint().x<600)&& (_enemy->GetPoint().x - myplane.GetPoint().x>-600))
				BallList.AddTail(new CBall(_enemy->GetPoint().x + 40, _enemy->GetPoint().y + 45, 0));
				}
			}


	POSITION bpos = BombList.GetHeadPosition();
	POSITION bpos2;
	while (bpos != NULL) {
		bpos2 = bpos;
		CBomb *_bomb = (CBomb *)BombList.GetNext(bpos);
		if (_bomb->GetPoint().y < -10) {
			BombList.RemoveAt(bpos2);
			delete(_bomb);
		}
		else {
			_bomb->Draw(&cdc, false);
		}
	}

	//�ҵ��ӵ��򵽵л�
	POSITION mybpos = BombList.GetHeadPosition();
	POSITION mybpos2;
	while (mybpos != NULL) {
		mybpos2 = mybpos;
		CBomb *_mybpos = (CBomb *)BombList.GetNext(mybpos);
		POSITION e_pos = EnemyList.GetHeadPosition();
		POSITION e_pos2;
		while (e_pos != NULL) {
			e_pos2 = e_pos;
		    CEnemy *_e_pos = (CEnemy *)EnemyList.GetNext(e_pos);
			CRect explo;
			if (explo.IntersectRect(_mybpos->GetRect(), _e_pos->GetRect()) != 0) {
				//��ըЧ��
				ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 30, _e_pos->GetPoint().y + 30));
				ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 45, _e_pos->GetPoint().y + 10));
				ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 15, _e_pos->GetPoint().y + 50));
				ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 5, _e_pos->GetPoint().y + 50));
				ExploList.AddTail(new CExplosion(_e_pos->GetPoint().x + 5, _e_pos->GetPoint().y + 30));
				BombList.RemoveAt(mybpos2);
			    delete(_mybpos);
				//_mybpos = NULL;
				EnemyList.RemoveAt(e_pos2);
				delete(_e_pos);
				break;
		    }
	    }

     }

	//�л��ӵ�����
	POSITION ebpos = BallList.GetHeadPosition();
	POSITION ebpos2;
	while (ebpos != NULL) {
		ebpos2 = ebpos;
		CBall *_ebpos = (CBall *)BallList.GetNext(ebpos);
		CRect exp;
		if (exp.IntersectRect(_ebpos->GetRect(), myplane.GetRect()) != 0) {
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 15, myplane.GetPoint().y + 30));
			//delete(myplane);
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 60, myplane.GetPoint().y + 30));
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 45, myplane.GetPoint().y + 60));
			BallList.RemoveAt(ebpos2);
			delete(_ebpos);

		}
	}

	//�л�������ײ
	POSITION epos=EnemyList.GetHeadPosition();
	POSITION epos2;
	while (epos != NULL) {
		epos2 = epos;
		CEnemy *_epos = (CEnemy *)EnemyList.GetNext(epos);
		CRect ex;
		if (ex.IntersectRect(_epos->GetRect(), myplane.GetRect()) != 0) {
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 15, myplane.GetPoint().y + 30));
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 60, myplane.GetPoint().y + 30));
			ExploList.AddHead(new CExplosion(myplane.GetPoint().x + 45, myplane.GetPoint().y + 60));
			EnemyList.RemoveAt(epos2);
			delete(_epos);
			break;
		}
	}



	//CView::OnTimer(nIDEvent);

	//�л��ӵ���
	POSITION Ebulletpos = BallList.GetHeadPosition();
	POSITION Ebulletpos2;
	while (Ebulletpos != NULL) {
		Ebulletpos2 = Ebulletpos;
		CBall *_ball = (CBall *)BallList.GetNext(Ebulletpos);
		if (_ball->GetPoint().y > 1080) {
			BallList.RemoveAt(Ebulletpos2);
			delete(_ball);
		}
		else
			_ball->Draw(&cdc, false);
	}

	//��ըЧ��
	POSITION Explopos = ExploList.GetHeadPosition();
	POSITION Explopos2;
	while (Explopos != NULL) {
		Explopos2 = Explopos;
		CExplosion *_explo = (CExplosion *)ExploList.GetNext(Explopos);
		if (_explo->GetPoint().y < -10) {
			BallList.RemoveAt(Explopos2);
			delete(_explo);
		}
		else
			_explo->Draw(&cdc, false);
	}
	    
		//pDC->TextOutW(100, 200, _T("hahahah"));
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
	SetTimer(1, 1, NULL);
	SetTimer(2, 120, NULL);
	SetTimer(3, 1250, NULL);   //�л��ӵ���ʱ��
	SetTimer(4, 1000, NULL);   //�л����ֶ�ʱ����
	SetTimer(5, 2500, NULL);     //�л����ֶ�ʱ����
	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
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

	
	//�ո�����ӵ�
	if (nChar == 74) {
		//BombList.AddHead(new CBomb());
		BombList.AddTail (new CBomb(myplane.GetPoint().x+52, myplane.GetPoint().y-57,BombList.GetCount()));
	}
	/*if (nChar == VK_RETURN) {
		EnemyList.AddTail(new CEnemy());
	}*/
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
    //ReleaseDC(pDC);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}



void CPlaneWarView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	//if (nChar == VK_SPACE) {

	//	SetTimer(1, 100, NULL);
	//	//KillTimer(1);
	//}


	if (nChar == 87) {
		myplane.SetVerMotion(0);
		//myplane.SetHorMotion(0);

	}
	if (nChar == 83) {
		myplane.SetVerMotion(0);
		//myplane.SetHorMotion(0);

	}
	if (nChar == 65 ) {
		myplane.SetHorMotion(0);
		//myplane.SetVerMotion(0);
	}
	if (nChar == 68) {
		myplane.SetHorMotion(0);
		//myplane.SetVerMotion(0);
	}

	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}


