
// PlaneWarView.h : CPlaneWarView ��Ľӿ�
//

#pragma once
#include "MyPlane.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Ball.h"
#include "Explosion.h"
#include "Enemy_little.h"
#include "Ball_litlle.h"
#include "Boss1.h"
#include "Boss1Bullet1.h"
#include "Boss1Bullet2.h"
#include "Bullet1.h"
#include "Expl_big.h"

class CPlaneWarView : public CView
{
protected: // �������л�����
	CPlaneWarView();
	DECLARE_DYNCREATE(CPlaneWarView)

// ����
public:
	CPlaneWarDoc* GetDocument() const;

// ����
public:
	int i;
	int j;
	int k;
	int bgsp;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CPlaneWarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	CMyPlane *myplane=new CMyPlane;
	//CBoss1 *boss1 = new CBoss1;
	//CEnemy enemy;
	CObList EnemyList;
	CObList BombList;
	CObList BallList;
	CObList ExploList;
	CObList Enemy_little_List;
	CObList Enemy_ball_little;
	CObList BossBullet1List;
	CObList BossBullet2List;
	CObList Bomb1List;
	CObList Expl_bigList;
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg void OnPaint();
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // PlaneWarView.cpp �еĵ��԰汾
inline CPlaneWarDoc* CPlaneWarView::GetDocument() const
   { return reinterpret_cast<CPlaneWarDoc*>(m_pDocument); }
#endif

