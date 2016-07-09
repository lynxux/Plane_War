#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	CRect rect;
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	m_ptPos.x = 0+ rand()%2000;
	m_ptPos.y = 0+rand()%500;
}


CEnemy::~CEnemy()
{
}


BOOL CEnemy::Draw(CDC *pDC, BOOL bPause) {
	CRect rect;
	//int h = rectClient.Height();


	//srand((unsigned)time(NULL));
	//int n = rand()%1000;
	///m_ptPos.x += n;
	m_ptPos.y += 10 ;
	//CString s;
	//s.Format(_T("h（%d,%d）"), rect.Height(), rect.Height());
	//pDC->TextOutW(20, 300, s);
	//if (m_ptPos.y > (h / 3)) {
	//	m_ptPos.y += 5;
	//	m_ptPos.x += 5;
	//}
	//else m_ptPos.y += 10;

	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CEnemy::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Enemy, RGB(238,243,250), ENEMY_WIDTH, ENEMY_HEIGHT, 0);
}

BOOL CEnemy::Fired() {
	return true;
}

//初始化静态成员
CImageList CEnemy::m_Images;
//static const int PositionEnemy = 100;
