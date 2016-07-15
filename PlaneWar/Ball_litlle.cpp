#include "stdafx.h"
#include "Ball_litlle.h"


CBall_litlle::CBall_litlle(int x, int y, int nMontion)
{

	CBall_litlle::m_ptPos.x = x;
	CBall_litlle::m_ptPos.y = y;
	m_nMotion = 0;
}


CBall_litlle::~CBall_litlle()
{
}

BOOL CBall_litlle::Draw(CDC* pDC, BOOL bPause) {
	CBall_litlle::m_ptPos.y += 9;


	return m_Images.Draw(pDC, 0, CBall_litlle::m_ptPos, ILD_NORMAL);

}

BOOL CBall_litlle::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Enemy_ball_little, RGB(238, 243, 250), BALL1_WIDTH, BALL1_HEIGHT, 1);
}

//初始化静态成员
CImageList CBall_litlle::m_Images;



