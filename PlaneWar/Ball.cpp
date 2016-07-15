#include "stdafx.h"
#include "Ball.h"


CBall::CBall(int x, int y, int nMontion)
{

	CBall::m_ptPos.x = x;
	CBall::m_ptPos.y = y;
	m_nMotion = 0;
}


CBall::~CBall()
{
}

BOOL CBall::Draw(CDC* pDC, BOOL bPause) {
	CBall::m_ptPos.y += 6;


	return m_Images.Draw(pDC, 0, CBall::m_ptPos, ILD_NORMAL);

}

BOOL CBall::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_EBullet, RGB(238, 243, 250), BALL_WIDTH, BALL_HEIGHT, 1);
}

//初始化静态成员
CImageList CBall::m_Images;

