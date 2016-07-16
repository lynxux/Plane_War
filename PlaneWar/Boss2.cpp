#include "stdafx.h"
#include "Boss2.h"
#include <afxwin.h>

CBoss2::CBoss2() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss2::m_ptPos.x = 0;
	CBoss2::m_ptPos.y = 0;
	CBoss2::blood1 = 800;
}

CBoss2::CBoss2(int x)
{
	//CRect rect;
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss2::m_ptPos.x = rand() % 1800 + x + 0;
	CBoss2::m_ptPos.y = 0;
	CBoss2::blood1 = 1000;

}


CBoss2::~CBoss2()
{
}


BOOL CBoss2::Draw(CDC *pDC, BOOL bPause) {

	if (poi == 0)
		CBoss2::m_ptPos.x += 4;
	else if (poi != 0)
		CBoss2::m_ptPos.x -= 4;

	return m_Images.Draw(pDC, 0, CBoss2::m_ptPos, ILD_NORMAL);
}

BOOL CBoss2::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Boss2, RGB(255, 255, 255), Boss2_WIDTH, Boss2_HEIGHT, 0);
}

BOOL CBoss2::Fired() {
	return true;
}

//初始化静态成员
CImageList CBoss2::m_Images;
int CBoss2::poi = 0;