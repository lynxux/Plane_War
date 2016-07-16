#include "stdafx.h"
#include "Boss3.h"
#include <afxwin.h>

CBoss3::CBoss3() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss3::m_ptPos.x = 0;
	CBoss3::m_ptPos.y = 0;
	CBoss3::blood1 = 1400;
}

CBoss3::CBoss3(int x)
{
	//CRect rect;
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss3::m_ptPos.x = rand() % 1800 + x + 0;
	CBoss3::m_ptPos.y = 0;
	CBoss3::blood1 = 1400;

}


CBoss3::~CBoss3()
{
}


BOOL CBoss3::Draw(CDC *pDC, BOOL bPause) {

	if (poi == 0)
		CBoss3::m_ptPos.x += 4;
	else if (poi != 0)
		CBoss3::m_ptPos.x -= 4;

	return m_Images.Draw(pDC, 0, CBoss3::m_ptPos, ILD_NORMAL);
}

BOOL CBoss3::LoadImage() {
	return CGameObject::LoadImage(m_Images, 359, RGB(255, 255, 255), Boss3_WIDTH, Boss3_HEIGHT, 0);
}

BOOL CBoss3::Fired() {
	return true;
}

//初始化静态成员
CImageList CBoss3::m_Images;
int CBoss3::poi = 0;
