#include "stdafx.h"
#include "MyPlane.h"


CMyPlane::CMyPlane()
{
	m_nHorMotion=0;//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	m_nVerMotion=0;//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	m_nWait=0;//������ʱ
	m_ptPos.x = 500;
	m_ptPos.y = 500;
}


CMyPlane::~CMyPlane()
{

}

BOOL CMyPlane::Draw(CDC *pDC,BOOL bPause) {
	


    m_ptPos.x += m_nHorMotion * 20;
	m_ptPos.y += m_nVerMotion * 20;
	CString s;
	s.Format(_T("�������꣨%d,%d��"), m_ptPos.x, m_ptPos.y);
	//s.Format(_T("�������꣨%d,%d��"), m_nHorMotion, m_nVerMotion);
	//pDC->SetBkMode(TRANSPARENT);
	pDC->TextOutW(20, 20, s);
	return m_Images.Draw(pDC, 0, m_ptPos, ILD_NORMAL);
}

BOOL CMyPlane::LoadImage() {
	return CGameObject::LoadImage(m_Images, IDB_ME, RGB(0,0,0), PLANE_WIDTH, PLANE_HEIGHT, 0);
}

BOOL CMyPlane::Fired() {
	return true;
}


//��ʼ����̬��Ա
CImageList CMyPlane::m_Images;

