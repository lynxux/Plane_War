#include "stdafx.h"
#include "MyPlane.h"


CMyPlane::CMyPlane()
{
	m_nHorMotion=0;//飞机水平运行方向0->静止，1->右 -1->左
	m_nVerMotion=0;//飞机垂直运行方向0->静止，1->上 -1->下
	m_nWait=0;//发射延时
	m_ptPos.x = 500;
	m_ptPos.y = 500;
}


CMyPlane::~CMyPlane()
{

}

BOOL CMyPlane::Draw(CDC *pDC,BOOL bPause) {
	


    m_ptPos.x += m_nHorMotion * 30;
	m_ptPos.y += m_nVerMotion * 30;
	CString s;
	s.Format(_T("现在坐标（%d,%d）"), m_ptPos.x, m_ptPos.y);
	//s.Format(_T("现在坐标（%d,%d）"), m_nHorMotion, m_nVerMotion);
	//pDC->SetBkMode(TRANSPARENT);
	pDC->TextOutW(20, 20, s);
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CMyPlane::LoadImage() {
	return CGameObject::LoadImage(m_Images, 318, RGB(255,255,255), PLANE_WIDTH, PLANE_HEIGHT, 1);
}

BOOL CMyPlane::Fired() {
	return true;
}


//初始化静态成员
CImageList CMyPlane::m_Images;

