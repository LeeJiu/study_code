#pragma once
class cScene_00
{
private:
	D3DXVECTOR3		m_VerticesLocal[8];	//���� 8��(���� ������)
	D3DXVECTOR3		m_VerticesFinal[8];	//���� 8��(��ȯ�� ��ģ ������)
	float			m_Angle;
	float			m_x, m_y, m_z;

public:
	cScene_00();
	~cScene_00();

	void Init();
	void Release();
	void Update(float timeDelta);
	void Render(HDC hdc);

private:
	void DrawVerticesLine(HDC hdc, D3DXVECTOR3* pVertices, int size);
};

