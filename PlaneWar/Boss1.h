#pragma once
#include "GameObject.h"
#include "resource.h"
class CBoss1 :public CGameObject
{
public:
	CBoss1();
	CBoss1(int x);
	~CBoss1(void);
	//static int PositionEnemy;
	BOOL Draw(CDC* pDC, BOOL bPause);

	static BOOL LoadImage();

	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + Boss1_WIDTH, m_ptPos.y + Boss1_HEIGHT));
	}

	int GetMontion() const
	{
		return m_nMotion;
	}
	//��ȡѪ��
	int getblood() {
		return blood1;
	}
	//����Ѫ��
	int setblood(int x) {
		blood1 += x;
		return blood1;
	}


	//�Ƿ���Կ������ӵ�
	BOOL Fired();
	//���Ƿ�Խ��
	static int poi;
private:
	static const int Boss1_HEIGHT = 231;
	static const int Boss1_WIDTH = 400;
	static CImageList m_Images;
	int    m_nMotion;//���� 1->���� 0->ֹͣ -1->����
					 //ͼ������
	int m_nImgIndex;
	//�ٶ�
	int m_V;
	int    m_nWait;//������ʱ
	int blood1;

};

