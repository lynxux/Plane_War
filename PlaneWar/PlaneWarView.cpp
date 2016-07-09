
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
//	ON_WM_ERASEBKGND()
//	ON_WM_PAINT()
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

	//CBitmap bitmap;
	//bitmap.LoadBitmapW(IDB_ME);//添加的图片
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
	//CDC *pDC = GetDC();
	//CDC cdc;//内存缓冲CDC
	//CRect rect;
	//CBitmap *cacheBitmap = new CBitmap;//内存中承载的临时图像缓冲位图
	//cdc.CreateCompatibleDC(pDC);//用当前设备CDC初始化缓冲CDC  

	//cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	////绑定pDC和位缓冲图的关系，cdc先输出到位缓冲图中，输出完毕之后再一次性将缓冲位图输出到屏幕

	//CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);


	////添加背景图片
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
	CDC cdc;//内存缓冲CDC
	CBitmap *cacheBitmap = new CBitmap;//内存中承载的临时图像缓冲位图
	cdc.CreateCompatibleDC(pDC);//用当前设备CDC初始化缓冲CDC  

	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//绑定pDC和位缓冲图的关系，cdc先输出到位缓冲图中，输出完毕之后再一次性将缓冲位图输出到屏幕

	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	//替换cdc原本的缓冲区为缓冲位图，这样cdc输出的内容就写到了缓冲位图中
	CDC cdc1;
	cdc1.CreateCompatibleDC(pDC);

	// 背景绘制（初级未完善）
	CBitmap back;
	back.LoadBitmapW(IDB_background);
	CBitmap *old = cdc1.SelectObject(&back);
	cdc.StretchBlt(0, 0, rect.Width(), rect.Height(), &cdc1, 0, 0, 1024, 768, SRCCOPY);
	//背景绘制（初级未完善）




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



//开始遍历  敌机出现
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
				//pDC->SetBkMode(TRANSPARENT);
				//pDC->TextOutW(20, 50, _T("翻车辣"));
			}
		}
	}


	//子弹出现
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
	//			//pDC->TextOutW(20, 200, _T("爆炸啦啊啊啊啊啊啊啊"));
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
	//			//碰撞检测
	//			CRect rect;
	//			int irect = rect.IntersectRect(_enemy->GetRect(), myplane.GetRect());
	//			if (irect != 0) {
	//				pDC->SetBkMode(TRANSPARENT);
	//				pDC->TextOutW(20, 50, _T("翻车辣"));
	//			}
	//		}
	//	}
	//  }
	//  break;
	//}

	//将二级缓冲cdc中的数据推送到一级级缓冲pDC中，即输出到屏幕中
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &cdc, 0, 0, SRCCOPY);
	//释放二级cdc
	cdc.DeleteDC();
	//释放缓冲位图
	cacheBitmap->DeleteObject();
	//释放一级pDC
	ReleaseDC(pDC);

}


int CPlaneWarView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码


	//添加定时器！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	SetTimer(1, 100, NULL);
	//SetTimer(2, 3000, NULL);



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
	if (nChar == VK_RETURN)
	{
		//for(int i=0;;i++)
		//int n = rand() % 100;
		for(int i=0;i<=5;i++)
		EnemyList.AddHead(new CEnemy);

	}
	
	//空格出现子弹
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



