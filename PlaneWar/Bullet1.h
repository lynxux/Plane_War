#pragma once
#include "GameObject.h"
#include "resource.h"
class CBullet1 :public CGameObject
{
public:
	CBullet1(int x, int y, int z);
	~CBullet1(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();


	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 27, m_ptPos.y + BOMB1_HEIGHT));
	}
private:
	static const int BOMB1_HEIGHT = 47;
	static const int BOMB1_WIDTH = 27;
	static CImageList m_Images;
	int dir1;
};
