#include "stdafx.h"
#include "Boss1Bullet2.h"


CBoss1Bullet2::CBoss1Bullet2(int x, int y)
{

	CBoss1Bullet2::m_ptPos.x = x;
	CBoss1Bullet2::m_ptPos.y = y;
}


CBoss1Bullet2::~CBoss1Bullet2()
{
}

BOOL CBoss1Bullet2::Draw(CDC* pDC, BOOL bPause) {
	
	CBoss1Bullet2::m_ptPos.y +=6;

	return m_Images.Draw(pDC, 0, CBoss1Bullet2::m_ptPos, ILD_NORMAL);

}

BOOL CBoss1Bullet2::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_BossBullet2, RGB(255, 255, 255), BossBALL2_WIDTH, BossBALL2_HEIGHT, 1);
}

//初始化静态成员
CImageList CBoss1Bullet2::m_Images;
