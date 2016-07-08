
// PlaneWarView.h : CPlaneWarView 类的接口
//

#pragma once
#include "MyPlane.h"
#include "Enemy.h"
#include "Bullet.h"

class CPlaneWarView : public CView
{
protected: // 仅从序列化创建
	CPlaneWarView();
	DECLARE_DYNCREATE(CPlaneWarView)

// 特性
public:
	CPlaneWarDoc* GetDocument() const;

// 操作
public:
	int i;
	int j;
	int k;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CPlaneWarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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
	CMyPlane myplane;
	CEnemy enemy;
	//CBomb bomb(CEnemy);
	CObList EnemyList;
	CObList BombList;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // PlaneWarView.cpp 中的调试版本
inline CPlaneWarDoc* CPlaneWarView::GetDocument() const
   { return reinterpret_cast<CPlaneWarDoc*>(m_pDocument); }
#endif

