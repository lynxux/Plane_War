#include "stdafx.h"
#include "Enemy.h"


CEnemy::CEnemy() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CEnemy::m_ptPos.x = 0;
	CEnemy::m_ptPos.y = 0;
	eblood =15;
}

CEnemy::CEnemy(int x)
{
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CEnemy::m_ptPos.x = rand()%1800+x+0;
	CEnemy::m_ptPos.y = 0;
	eblood = 15;
}


CEnemy::~CEnemy()
{
}


BOOL CEnemy::Draw(CDC *pDC, BOOL bPause) {

	CEnemy::m_ptPos.y += 4 ;
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
int CEnemy::died_num =0;
