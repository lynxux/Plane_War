#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	m_ptPos.x = 0;
	CEnemy::m_ptPos.y = 0;
}

CEnemy::CEnemy(int x)
{
	//CRect rect;
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CEnemy::m_ptPos.x = rand()%1500+x+0;
	CEnemy::m_ptPos.y = 0;

}


CEnemy::~CEnemy()
{
}


BOOL CEnemy::Draw(CDC *pDC, BOOL bPause) {
	//CRect rect;
	//int h = rectClient.Height();


	//srand((unsigned)time(NULL));
	//int n = rand()%1000;
	//m_ptPos.x += n;
	CEnemy::m_ptPos.y += 4 ;
	//CString s;
	//s.Format(_T("h（%d,%d）"), rect.Height(), rect.Height());
	//pDC->TextOutW(20, 300, s);
	//if (m_ptPos.y > (h / 3)) {
	//	m_ptPos.y += 5;
	//	m_ptPos.x += 5;
	//}
    
	CString s;
	s.Format(_T("%d,%d"), CEnemy::m_ptPos.x, CEnemy::m_ptPos.y);
	pDC->TextOutW(10, 200, s);
	return m_Images.Draw(pDC, 0, CEnemy::m_ptPos, ILD_NORMAL);
}

BOOL CEnemy::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Enemy, RGB(0,0,0), ENEMY_WIDTH, ENEMY_HEIGHT, 0);
}

BOOL CEnemy::Fired() {
	return true;
}

//初始化静态成员
CImageList CEnemy::m_Images;
//static const int PositionEnemy = 100;
