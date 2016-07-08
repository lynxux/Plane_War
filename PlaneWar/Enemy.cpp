#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy()
{
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	m_ptPos.x = 500;
	m_ptPos.y = 0;
}


CEnemy::~CEnemy()
{
}


BOOL CEnemy::Draw(CDC *pDC, BOOL bPause) {
	CRect rect;
	int h = rect.Height();
	m_ptPos.y += 10;


	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CEnemy::LoadImage() {
	return CGameObject::LoadImage(m_Images, 316, RGB(0,0,0), ENEMY_WIDTH, ENEMY_HEIGHT, 0);
}

BOOL CEnemy::Fired() {
	return true;
}

//初始化静态成员
CImageList CEnemy::m_Images;
