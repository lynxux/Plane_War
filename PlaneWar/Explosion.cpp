#include "stdafx.h"
#include "Explosion.h"


CExplosion::CExplosion(int x, int y)
{
	CExplosion::m_ptPos.x = x;
	CExplosion::m_ptPos.y = y;
	m_nProcess = 0  ; 
}


CExplosion::~CExplosion()
{
}

BOOL CExplosion::Draw(CDC *pDC, BOOL bPause) {


	return m_Images.Draw(pDC, m_nProcess++, CExplosion::m_ptPos, ILD_NORMAL);

}
BOOL CExplosion::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_explo, RGB(0, 0, 0), EXPLOSION_WIDTH, EXPLOSION_HEIGHT, 8);
}

CImageList CExplosion::m_Images;
