
// PlaneWarView.cpp : CPlaneWarView 类的实现
//
#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

	CView::OnTimer(nIDEvent);
	//TODO: 在此添加消息处理程序代码和/或调用默认值

    CDC *pDC = GetDC();
	CRect rect;
	GetClientRect(&rect);
	CDC cdc;//内存缓冲CDC
	CBitmap *cacheBitmap= new CBitmap;//内存中承载的临时图像缓冲位图
    cdc.CreateCompatibleDC(pDC);//用当前设备CDC初始化缓冲CDC  
	cacheBitmap->CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	//绑定pDC和位缓冲图的关系，cdc先输出到位缓冲图中，输出完毕之后再一次性将缓冲位图输出到屏幕
	CBitmap *pOldBit = cdc.SelectObject(cacheBitmap);
	//替换cdc原本的缓冲区为缓冲位图，这样cdc输出的内容就写到了缓冲位图中
	CDC cdc1;
	cdc1.CreateCompatibleDC(pDC);

	//背景绘制
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

	//添加背景图片
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


	////开始遍历  敌机出现
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
			//敌机子弹出现
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

	//我的子弹打到敌机
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
				//爆炸效果
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

	//敌机子弹打到我
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

	//敌机与我相撞
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

	//敌机子弹画
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

	//爆炸效果
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
	SetTimer(1, 1, NULL);
	SetTimer(2, 120, NULL);
	SetTimer(3, 1250, NULL);   //敌机子弹定时器
	SetTimer(4, 1000, NULL);   //敌机出现定时器快
	SetTimer(5, 2500, NULL);     //敌机出现定时器慢
	CMyPlane::LoadImage();
	CEnemy::LoadImage();
	CBomb::LoadImage();
	CBall::LoadImage();
	CExplosion::LoadImage();
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

	
	//空格出现子弹
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
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


