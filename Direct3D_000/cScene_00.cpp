#include "stdafx.h"
#include "cScene_00.h"


cScene_00::cScene_00()
{
}


cScene_00::~cScene_00()
{
}

void cScene_00::Init()
{
	m_VerticesLocal[0] = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
	m_VerticesLocal[1] = D3DXVECTOR3( 0.5f, 0.5f, 0.0f);
	m_VerticesLocal[2] = D3DXVECTOR3( 0.5f, 0.5f, 0.0f);
	m_VerticesLocal[3] = D3DXVECTOR3( 0.5f, -0.5f, 0.0f);
	m_VerticesLocal[4] = D3DXVECTOR3( 0.5f, -0.5f, 0.0f);
	m_VerticesLocal[5] = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	m_VerticesLocal[6] = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	m_VerticesLocal[7] = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);

	m_Angle = m_x = m_y = m_z = 0.0f;
}

void cScene_00::Release()
{
}

void cScene_00::Update(float timeDelta)
{
	//�ޱ� �� ����(�ʴ� 90���� ȸ��)
	m_Angle += (90.f * ONE_RAD) * timeDelta;

	//�ޱ� ���� ���� ȸ�� ��� �غ�
	D3DXMATRIXA16 matRotation;
	D3DXVECTOR3 axis(0, 0, 1);	//+z�� = ���������� ȸ�� / (0, 0, -1) �ϸ� -z�� = �������� ȸ��
	D3DXMatrixRotationAxis(&matRotation, &axis, m_Angle);

	//ȸ�� ��� �غ�
	for (int i = 0; i < 8; ++i)
	{
		D3DXVec3TransformNormal(
			&m_VerticesFinal[i],
			&m_VerticesLocal[i],
			&matRotation);
	}

	//�̵� ��� �غ�
	D3DXMATRIXA16 matTranslation;	

	if (KEY_MGR->IsStayDown(VK_LEFT))
	{
		m_x -= 0.02f;
	}
	else if (KEY_MGR->IsStayDown(VK_RIGHT))
	{
		m_x += 0.02f;
	}
	else if (KEY_MGR->IsStayDown(VK_UP))
	{
		m_y -= 0.02f;
	}
	else if (KEY_MGR->IsStayDown(VK_DOWN))
	{
		m_y += 0.02f;
	}

	D3DXMatrixTranslation(&matTranslation, m_x, m_y, m_z);

	for (int i = 0; i < 8; ++i)
	{
		D3DXVec3TransformCoord(
			&m_VerticesFinal[i],
			&m_VerticesFinal[i],
			&matTranslation);
	}
}

void cScene_00::Render(HDC hdc)
{
	this->DrawVerticesLine(hdc, m_VerticesFinal, 8);
}

void cScene_00::DrawVerticesLine(HDC hdc, D3DXVECTOR3 * pVertices, int size)
{
	for (int i = 0; i < size; ++i)
	{
		//������ ��ġ�� ȭ�� ��ġ�� ��ȯ�ؾ� �Ѵ�.
		POINT pt;
		pt.x = (int)(((pVertices[i].x + 1.f) * 0.5f) * WINSIZE_X);
		pt.y = (int)(((pVertices[i].y + 1.f) * 0.5f) * WINSIZE_Y);
		
		if (i % 2 == 0)
		{
			MoveToEx(hdc, pt.x, pt.y, NULL);
		}
		else
		{
			LineTo(hdc, pt.x, pt.y);
		}
	}
}
