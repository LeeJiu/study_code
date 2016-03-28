class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,      //���ҽ��κ��� ����
		LOAD_FILE,              //���Ϸκ��� ����
		LOAD_EMPTY,             //�� ����
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int width;
		int height;
		BYTE loadType;

		tagImageInfo( )		//����ü ������ �ʱ�ȭ
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	} IMAGE_INFO, *LPIMAGE_INFO;

private:
	//������ ���ÿ� ����̴ϼ� ������� �ʱ�ȭ ���ִ� ������
	LPIMAGE_INFO      _imageInfo;        //�̹��� ����
	CHAR*             _fileName;         //�̹��� ��� �̸�

	BOOL              _trans;            //��������̳�?
	COLORREF          _transColor;       //�����÷�Ű


public:
	image( );
	~image( );

	//�� ��Ʈ�� �̹��� �����
	HRESULT init( int width, int height );

	//���ҽ��κ��� �о��
	HRESULT init( const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE );

	//�̹��� ���� (���Ϸ� �о��)
	HRESULT init( const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE );

	//����
	void release( void );

	//���� Ű��(RGB��) ���� == Ư�� ������ �׸��� �ʴ´�
	void setTransColor(BOOL trans, COLORREF transColor);

	//����
	void render( HDC hdc, int destX, int destY );

	/*=============���� ����� �� ����=============*/
	void render2(HDC hdc, RECT * drawRc, int idx);

	//DC������
	inline HDC getMemDC( void ) { return _imageInfo->hMemDC; }
};