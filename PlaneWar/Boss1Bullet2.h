#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss1Bullet2 :public CGameObject
{
public:
	CBoss1Bullet2(int x, int y);
	~CBoss1Bullet2(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();


	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BossBALL2_WIDTH, m_ptPos.y + BossBALL2_HEIGHT));
	}
private:
	static const int BossBALL2_HEIGHT = 88;
	static const int BossBALL2_WIDTH = 43;
	static CImageList m_Images;
	int    dir;
};

