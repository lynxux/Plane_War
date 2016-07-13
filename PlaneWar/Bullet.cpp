#include "stdafx.h"
#include "Bullet.h"



CBomb::CBomb(int x,int y,int z)
{
	CBomb::m_ptPos.x = x;
	CBomb::m_ptPos.y = y;
	num = z;
}


CBomb::~CBomb()
{
}

BOOL CBomb::Draw(CDC* pDC, BOOL bPause) {
	CBomb::m_ptPos.y -= 7;
	//num++;
	//CString s;
	//s.Format(_T("ÏÖÔÚ×ø±ê£¨%d,%d,%d£©"), CBomb::m_ptPos.x, CBomb::m_ptPos.y,num);
	//pDC->TextOutW(CBomb::m_ptPos.x, CBomb::m_ptPos.y+20, s);
	return m_Images.Draw(pDC, 0, CBomb::m_ptPos, ILD_NORMAL);
}

BOOL CBomb::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Bullet, RGB(255, 255, 255), BOMB_WIDTH, BOMB_HEIGHT, 1);
}


CImageList CBomb::m_Images;
