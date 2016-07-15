#include "stdafx.h"
#include "Bullet1.h"


CBullet1::CBullet1(int x, int y, int z)
{
	CBullet1::m_ptPos.x = x;
	CBullet1::m_ptPos.y = y;
	dir1 = z;
}


CBullet1::~CBullet1()
{
}

BOOL CBullet1::Draw(CDC* pDC, BOOL bPause) {
	if(dir1==0)
		CBullet1::m_ptPos.y -= 7;
	if (dir1 == 1) {
		CBullet1::m_ptPos.y -= 7;
		CBullet1::m_ptPos.x -= 7;
	}
	if (dir1 == -1) {
		CBullet1::m_ptPos.y -= 7;
		CBullet1::m_ptPos.x += 7;
	}
	return m_Images.Draw(pDC, 0, CBullet1::m_ptPos, ILD_NORMAL);
}

BOOL CBullet1::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Bullet1, RGB(255, 255, 255), BOMB1_WIDTH, BOMB1_HEIGHT, 1);
}


CImageList CBullet1::m_Images;