#include "stdafx.h"
#include "Boss1.h"
#include <afxwin.h>

CBoss1::CBoss1() {
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss1::m_ptPos.x = 0;
	CBoss1::m_ptPos.y = 0;
	CBoss1::blood1 = 800;
}

CBoss1::CBoss1(int x)
{
	//CRect rect;
	m_nMotion = 0;
	m_nImgIndex = 0;
	m_V = 0;
	m_nWait = 0;
	CBoss1::m_ptPos.x = rand() % 1800 + x + 0;
	CBoss1::m_ptPos.y = 0;
	CBoss1::blood1 = 800;

}


CBoss1::~CBoss1()
{
}


BOOL CBoss1::Draw(CDC *pDC, BOOL bPause) {
 
	if(poi==0)
	    CBoss1::m_ptPos.x += 4;
	else if(poi!=0)
		CBoss1::m_ptPos.x -= 4;

	return m_Images.Draw(pDC, 0, CBoss1::m_ptPos, ILD_NORMAL);
}

BOOL CBoss1::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Boss1, RGB(255, 255, 255), Boss1_WIDTH, Boss1_HEIGHT, 0);
}

BOOL CBoss1::Fired() {
	return true;
}

//初始化静态成员
CImageList CBoss1::m_Images;
int CBoss1::poi = 0;