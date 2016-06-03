#include "stdafx.h"
#include "commandScene.h"


commandScene::commandScene()
{
}


commandScene::~commandScene()
{
}

HRESULT commandScene::init()
{
	_str = "�ƹ��͵� ����";

	_fCommandClear = 2.5f;
	_fCommandTime = 0.0f;

	return S_OK;
}

void commandScene::release()
{
}

void commandScene::update()
{
	if ( KEYMANAGER->isStayKeyDown( VK_LEFT ) )
	{
		_str = "�������� ����";
	}
	if ( KEYMANAGER->isStayKeyDown( VK_RIGHT ) )
	{
		_str = "���������� ����";
	}
	if ( KEYMANAGER->isStayKeyDown( VK_UP ) )
	{
		_str = "�� ����";
	}
	if ( KEYMANAGER->isStayKeyDown( VK_DOWN ) )
	{
		_str = "�Ʒ� ����";
	}

	if ( KEYMANAGER->isOnceKeyDown( VK_LEFT ) )
	{
		_vCommand.push_back( key_left );
	}

	if ( KEYMANAGER->isOnceKeyDown( VK_RIGHT ) )
	{
		_vCommand.push_back( key_right );
	}
	if ( KEYMANAGER->isOnceKeyDown( VK_UP ) )
	{
		_vCommand.push_back( key_up );
	}
	if ( KEYMANAGER->isOnceKeyDown( VK_DOWN ) )
	{
		_vCommand.push_back( key_down );
	}


	command();
}

void commandScene::render()
{
	TextOut( getMemDC(), 100, 100, _str.c_str(), _str.length() );
}

void commandScene::command()
{
	if ( _vCommand.size() > 0 ) _fCommandTime += 0.1f;
	if ( _fCommandTime > _fCommandClear )
	{
		_fCommandTime = 0.f;
		_vCommand.clear();
	}

	if ( _vCommand.size() == 0 ) _str = "�����ֳ�";

	if ( _vCommand.size() > 1 ) if ( _vCommand[0] == key_left && _vCommand[1] == key_left ) _str = "���� �뽬 �ϳ�";
	if ( _vCommand.size() > 1 ) if ( _vCommand[0] == key_right && _vCommand[1] == key_right ) _str = "������ �뽬 �ϳ�";
	if ( _vCommand.size() > 1 ) if ( _vCommand[0] == key_up && _vCommand[1] == key_up ) _str = "���� �ϳ�";
	if ( _vCommand.size() > 1 ) if ( _vCommand[0] == key_down && _vCommand[1] == key_down ) _str = "������";
	if ( _vCommand.size() > 1 ) if ( _vCommand[0] == key_left && _vCommand[1] == key_right ) _str = "�͸����� �ϳ�";

	if ( _vCommand.size() > 2 ) if ( _vCommand[0] == key_left && _vCommand[1] == key_down && _vCommand[2] == key_right ) _str = "�Ƶ���!!!";
}
