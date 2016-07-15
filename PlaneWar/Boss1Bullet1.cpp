#include "stdafx.h"
#include "Boss1Bullet1.h"


CBoss1Bullet1::CBoss1Bullet1(int x, int y, int z)
{

	CBoss1Bullet1::m_ptPos.x = x;
	CBoss1Bullet1::m_ptPos.y = y;
	dir = z;
}


CBoss1Bullet1::~CBoss1Bullet1()
{
}

BOOL CBoss1Bullet1::Draw(CDC* pDC, BOOL bPause) {
	if(dir == 2)
	    CBoss1Bullet1::m_ptPos.y += 6;
	else if (dir == 1) {
		CBoss1Bullet1::m_ptPos.y += 6;
		CBoss1Bullet1::m_ptPos.x -= 6;
	}
	else if (dir == -1) {
		CBoss1Bullet1::m_ptPos.y += 6;
		CBoss1Bullet1::m_ptPos.x += 6;
	}


	return m_Images.Draw(pDC, 0, CBoss1Bullet1::m_ptPos, ILD_NORMAL);

}

BOOL CBoss1Bullet1::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_BossBullet1, RGB(255, 255, 255), BossBALL1_WIDTH, BossBALL1_HEIGHT, 1);
}

//初始化静态成员
CImageList CBoss1Bullet1::m_Images;
