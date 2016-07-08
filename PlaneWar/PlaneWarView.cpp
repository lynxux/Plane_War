
// PlaneWarView.cpp : CPlaneWarView 类的实现
//
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	ON_WM_ERASEBKGND()
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




    //pDC->Rectangle(10, 10, 200, 200);   //设置矩形
	//CBrush brush;
	//brush.CreateSolidBrush(RGB(90, 184, 137));
	//pDC->SelectObject(&brush);
	//pDC->Rectangle(10, 10, 300, 300);
    ////CRect rect;  //矩形填满屏幕
	////GetClientRect(&rect);
	////pDC->Rectangle(rect);
    //pDC->SetBkMode(TRANSPARENT);  //设置背景为透明
	//pDC->TextOutW(50, 50, _T("LINK")); //设置文字
    //设置字体
	//CFont font;
	//font.CreateFontW(50, 25, 100, 100, FW_NORMAL, 1, 1, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DECORATIVE, _T("Arial"));
	//pDC->SelectObject(&font);
	//CFont *oldfont = pDC->SelectObject(&font);
	//pDC->TextOutW(100, 100, _T("Network Engineer"));
    ////画直线
	//CPen pen;
	//pen.CreatePen(PS_DASH, 1, RGB(0, 0, 0));
	//pDC->SelectObject(&pen);
	//pDC->MoveTo(30, 50);
	//pDC->LineTo(100, 400);
	//CRect rect;  //矩形填满屏幕
	//GetClientRect(&rect);
	//pDC->Rectangle(rect);

	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_ME);//添加的图片
	//CImageList imglist;
	//imglist.Create(124, 97, ILC_COLOR32 | ILC_MASK, 1,0);
	//imglist.Add(&bitmap, RGB(0,0,0));
	//CPoint pt(400, 400);
	//imglist.Draw(pDC, 0, pt, ILD_TRANSPARENT);
	
	//myplane.Draw(pDC,TRUE);
	



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


	//添加背景图片
	CDC *pDC = GetDC();
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
    CRect rctClient;
	GetClientRect(rctClient);
	CBitmap bitmap2;
	bitmap2.LoadBitmapW(IDB_background);
	CBitmap *pbmpOld = dcMem.SelectObject(&bitmap2);
	pDC->StretchBlt(0, 0, rctClient.Width(), rctClient.Height(), &dcMem, 0, 0, 1024, 768, SRCCOPY);


	myplane.Draw(pDC,TRUE);
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



	//开始遍历  敌机出现
	//POSITION pos = EnemyList.GetHeadPosition();
	//POSITION pos2;
	//while (pos != NULL) {
	//	pos2 = pos;
	//	CEnemy *_enemy = (CEnemy *)EnemyList.GetNext(pos);
	//	if (_enemy->GetPoint().y < 0) {
	//		EnemyList.RemoveAt(pos2);
	//		delete(_enemy);
	//	}
	//	else {
	//		_enemy->Draw(pDC, false);
	//		//碰撞检测
	//		CRect rect;
	//		int irect = rect.IntersectRect(_enemy->GetRect(), myplane.GetRect());
	//		if (irect != 0) {
	//			pDC->SetBkMode(TRANSPARENT);
	//			pDC->TextOutW(20, 50, _T("翻车辣"));
	//		}
	//	}
	//}


	//子弹出现
	//POSITION bpos = BombList.GetHeadPosition();
	//POSITION bpos2;
	//while (bpos != NULL) {
	//	bpos2 = bpos;
	//	CBomb *_bomb = (CBomb *)BombList.GetNext(bpos);
	//	if (_bomb->GetPoint().y < 0) {
	//		BombList.RemoveAt(bpos2);
	//		delete(_bomb);
	//	}
	//	else {
	//		_bomb->Draw(pDC, false);
	//		//CRect rect;
	//		//int irect = rect.IntersectRect(_bomb->GetRect(), enemy.GetRect());
	//		//if (irect != 0) {
	//			//pDC->SetBkMode(TRANSPARENT);
	//			//pDC->TextOutW(20, 200, _T("爆炸啦啊啊啊啊啊啊啊"));
	//		//}
	//	}
	//}



	CView::OnTimer(nIDEvent);
	switch(nIDEvent)
	{
	case 1: 
	{
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
				//pDC->TextOutW(20, 200, _T("爆炸啦啊啊啊啊啊啊啊"));
				//}
			}
		}
	  }
	  break;
	case 2: 
	{
		EnemyList.AddHead(new CEnemy);
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
				//碰撞检测
				CRect rect;
				int irect = rect.IntersectRect(_enemy->GetRect(), myplane.GetRect());
				if (irect != 0) {
					pDC->SetBkMode(TRANSPARENT);
					pDC->TextOutW(20, 50, _T("翻车辣"));
				}
			}
		}
	  }
	  break;
	}

}


int CPlaneWarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	//添加定时器！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	SetTimer(1, 100, NULL);
	SetTimer(2, 1000, NULL);



	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	return 0;
}

//飞机的空格，左右控制
void CPlaneWarView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CDC *pDC = GetDC();  //显示按键
	//CString s;
	//s.Format(_T("%d"), nChar);
	//pDC->TextOutW(50, 150, s);


	//if (nChar == VK_SPACE) {
	//	//CRect rect;  //矩形填满屏幕
	//	//GetClientRect(&rect);
	//	//pDC->Rectangle(rect);
	//	KillTimer(1);
	//}

	//Enter出现敌机
	//if (nChar == VK_RETURN)
	//{
	//	//for(int i=0;;i++)
	//	EnemyList.AddHead(new CEnemy);

	//}
	
	//空格出现子弹
	if (nChar == VK_SPACE) {
		//BombList.AddHead(new CBomb());
		BombList.AddHead (new CBomb(myplane.GetPoint().x+52, myplane.GetPoint().y-67));
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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


BOOL CPlaneWarView::OnEraseBkgnd(CDC* pDC)
{
	
	return true;
	//这里一定要用return true，如果用自动生成的，会调用基类，把画出来的覆盖，就什     么结果也没有了
	//return CView::OnEraseBkgnd(pDC);
}
