#include "stdafx.h"
#include "MyPlane.h"


CMyPlane::CMyPlane()
{
	m_nHorMotion=0;//飞机水平运行方向0->静止，1->右 -1->左
	m_nVerMotion=0;//飞机垂直运行方向0->静止，1->上 -1->下
	m_nWait=0;//发射延时
	m_ptPos.x = 500;
	m_ptPos.y = 500;
	blood = 400;
}


CMyPlane::~CMyPlane()
{

}

BOOL CMyPlane::Draw(CDC *pDC,BOOL bPause) {
	


    CMyPlane::m_ptPos.x += m_nHorMotion * 6;
	CMyPlane::m_ptPos.y += m_nVerMotion * 6;
	//CString s;
	//s.Format(_T("血量"));
	//s.Format(_T("现在坐标（%d,%d）"), m_nHorMotion, m_nVerMotion);
	//pDC->SetBkMode(TRANSPARENT);
	//pDC->TextOutW(20, 1000, _T("血量"));

	return m_Images.Draw(pDC, 0, CMyPlane::m_ptPos, ILD_NORMAL);
}

BOOL CMyPlane::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_ME, RGB(255,255,255), PLANE_WIDTH, PLANE_HEIGHT, 1);
}

BOOL CMyPlane::Fired() {
	return true;
}


//初始化静态成员
CImageList CMyPlane::m_Images;

