#include "stdafx.h"
#include "Enemy_little.h"


CEnemy_little::CEnemy_little() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CEnemy_little::m_ptPos.x = 0+rand()%1900;
	CEnemy_little::m_ptPos.y = 0+rand()%70;
}


CEnemy_little::~CEnemy_little()
{
}


BOOL CEnemy_little::Draw(CDC *pDC, BOOL bPause) {
	//CRect rect;
	//int h = rectClient.Height();


	//srand((unsigned)time(NULL));
	//int n = rand()%1000;
	//m_ptPos.x += n;
	CEnemy_little::m_ptPos.y += 5;
	return m_Images.Draw(pDC, 0, CEnemy_little::m_ptPos, ILD_NORMAL);
}

BOOL CEnemy_little::LoadImage() {
	return CGameObject::LoadImage(m_Images, 334, RGB(238, 243, 250), 60, 47, 0);
}

BOOL CEnemy_little::Fired() {
	return true;
}

//初始化静态成员
CImageList CEnemy_little::m_Images;
