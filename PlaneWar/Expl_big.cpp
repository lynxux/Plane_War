#include "stdafx.h"
#include "Expl_big.h"

CExpl_big::CExpl_big(int x, int y)
{
	CExpl_big::m_ptPos.x = x;
	CExpl_big::m_ptPos.y = y;
	m_nProcess = 0;
}


CExpl_big::~CExpl_big()
{
}

BOOL CExpl_big::Draw(CDC *pDC, BOOL bPause) {


	return m_Images.Draw(pDC, m_nProcess++, CExpl_big::m_ptPos, ILD_NORMAL);

}
BOOL CExpl_big::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_Expl_big, RGB(0, 0, 0), EXPLOSION1_WIDTH, EXPLOSION1_HEIGHT, 8);
}

CImageList CExpl_big::m_Images;
