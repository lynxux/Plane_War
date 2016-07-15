#pragma once
#include "GameObject.h"
#include "resource.h"
class CEnemy_little :public CGameObject
{
public:
	CEnemy_little();
	//CEnemy_little(int x);
	~CEnemy_little(void);
	//static int PositionEnemy;
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMY1_WIDTH, m_ptPos.y + ENEMY1_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//�Ƿ���Կ������ӵ�
	BOOL Fired();
private:
	static const int ENEMY1_HEIGHT = 47;
	static const int ENEMY1_WIDTH = 60;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
					 //ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
};

