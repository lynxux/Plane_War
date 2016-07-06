#include "stdafx.h"
#include "MyPlane.h"
#include "resource.h"


CMyPlane::CMyPlane()
{
	int    m_nHorMotion=0;//飞机水平运行方向0->静止，1->右 -1->左
	int    m_nVerMotion=0;//飞机垂直运行方向0->静止，1->上 -1->下
	int    m_nWait=0;//发射延时
	m_ptPos.x = 500;
	m_ptPos.y = 500;
}


CMyPlane::~CMyPlane()
{

}

BOOL CMyPlane::Draw(CDC *pDC,BOOL bPause) {
	m_ptPos.y -= 12;
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CMyPlane::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_ME, RGB(0, 0, 0), PLANE_WIDTH, PLANE_HEIGHT, 0);
}

BOOL CMyPlane::Fired() {
	return true;
}


//初始化静态成员
CImageList CMyPlane::m_Images;

