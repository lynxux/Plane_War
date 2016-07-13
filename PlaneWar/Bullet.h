#pragma once
#include "GameObject.h"
#include "resource.h"
class CBomb :
	public CGameObject
{
public:
	//CBomb();
	CBomb(int x, int y,int z);
	~CBomb(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();


	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + 27, m_ptPos.y + BOMB_HEIGHT));
	}
private:
	static const int BOMB_HEIGHT = 64;
	static const int BOMB_WIDTH = 27;
	static CImageList m_Images;
	int num;
};

