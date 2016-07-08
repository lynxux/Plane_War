#include "stdafx.h"
#include "Bullet.h"



CBomb::CBomb(int x,int y)
{
	m_ptPos.x = x;
	m_ptPos.y = y;

}


CBomb::~CBomb()
{
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause) {
	m_ptPos.y -= 20;

	CString s;
	s.Format(_T("ÏÖÔÚ×ø±ê£¨%d,%d£©"), m_ptPos.x, m_ptPos.y);
	pDC->TextOutW(150, 150, s);
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CBomb::LoadImage() {
	return CGameObject::LoadImage(m_Images, 317, RGB(1, 1, 1), BOMB_WIDTH, BOMB_HEIGHT, 0);
}


CImageList CBomb::m_Images;
