#pragma once

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,      //리소스로부터 생성
		LOAD_FILE,              //파일로부터 생성
		LOAD_EMPTY,             //걍 생성
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

		tagImageInfo( )
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
	//생성과 동시에 멤버이니셜 라이즈로 초기화 해주는 변수들
	LPIMAGE_INFO    _imageInfo;        //이미지 정보
	CHAR*           _fileName;         //이미지 경로 이름

	BOOL            _trans;             //투명배경이냐?
	COLORREF        _transColor;       //투명컬러키
	
	BLENDFUNCTION	_blendFunc;			//알파 블렌드를 위한 정보
	LPIMAGE_INFO	_blendImage;		//알파 블렌드를 사용하기 위한 이미지 정보



public:
	image( );
	~image( );

	//빈 비트맵 이미지 만든다
	HRESULT init( int width, int height );

	//리소스로부터 읽어본다
	HRESULT init( const DWORD resID, int width, int height,	BOOL trans, COLORREF transColor);

	//이미지 설정 (파일로 읽어옴)
	HRESULT init( const char* fileName, int width, int height, BOOL trans, COLORREF transColor);

	//삭제
	void release( void );

	//투명 키값(RGB값) 셋팅 == 특정 색상을 그리지 않는다
	void setTransColor(BOOL trans, COLORREF transColor);

	//렌더
	void render( HDC hdc, int destX, int destY );
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	//알파 렌더
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//DC얻어오기
	inline HDC getMemDC( void ) { return _imageInfo->hMemDC; }
};
