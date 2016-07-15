#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss1Bullet1 :public CGameObject
{
public:
	CBoss1Bullet1(int x, int y, int z);
	~CBoss1Bullet1(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();


	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BossBALL1_WIDTH, m_ptPos.y + BossBALL1_HEIGHT));
	}
private:
	static const int BossBALL1_HEIGHT = 20;
	static const int BossBALL1_WIDTH = 20;
	static CImageList m_Images;
	int    dir;
};
