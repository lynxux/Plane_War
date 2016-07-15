#pragma once
#include "GameObject.h"
#include "resource.h"
class CExpl_big :public CGameObject
{
public:
	CExpl_big(int x, int y);
	~CExpl_big(void);

	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION1_WIDTH, m_ptPos.y + EXPLOSION1_WIDTH));
	}
private:
	//炸弹的图片列表
	static CImageList m_Images;
	//图像索引的步进计数
	int   m_nProcess;
public:
	static const int  EXPLOSION1_WIDTH = 66;
	static const int  EXPLOSION1_HEIGHT = 66;
};
