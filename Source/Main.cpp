/**
* @file    Main.cpp
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   ���C���w�b�_
* @par     ���C���w�b�_
*/

#include <DxLib.h>
#include <crtdbg.h>
#include <time.h>
#include "Main.h"
#include "Load.h"
#include "Key.h"
#include "Fps.h"
#include "Object.h"
#include "Time.h"
#include "Effect.h"


/**
* �K�{���[�v����
*/
int MainLoop()
{
    if ( ProcessMessage()        != 0 ) return -1; // �v���Z�X�������G���[��-1
    if ( ClearDrawScreen()       != 0 ) return -1; // ��ʃN���A�������G���[��-1
    if ( C_Key::Inst()->Update() != 0 ) return -1; // ���͏��X�V ESC���͎�-1
    return 0;
}


//********************************************************************************//
//�@�����C���֐��@
//********************************************************************************//
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    // ���������[�N���o
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    // �����ݒ菈��
    if ( SetUseBackBufferTransColorFlag( TRUE )     !=        0               // �E�C���h�E�̓��ߐF���[�h
        || ChangeWindowMode( TRUE )                 !=  DX_CHANGESCREEN_OK    // �E�B���h�E���[�h
        || SetOutApplicationLogValidFlag( false )   !=        0               // ���O�o�͂��Ȃ�
        || SetGraphMode( SCREEN_X, SCREEN_Y, 32 )   !=  DX_CHANGESCREEN_OK    // ��ʐݒ�
        || SetMainWindowText( TITLE_STR )           !=        0               // �E�B���h�E�^�C�g��
        || SetAlwaysRunFlag( TRUE )                 !=        0               // ��A�N�e�B�u�ł�����
        || SetUseDirectInputFlag( TRUE )            !=        0               // ��A�N�e�B�u�ŃL�[����
        || DxLib_Init()                             !=        0               // �c�w���C�u����������
        || Load()                                   !=        0               // �摜�ǂݍ���
        || SetCameraNearFar( 1.0f, 20000.0f )       !=        0               // �G�t�F�N�g�����ݒ�
        || C_Effect::Inst()->Init()                 !=        0               // �G�t�F�N�g�}�l�[�W������
        ){
            MessageBox( NULL, _T("���C�u�����̏������Ɏ��s���܂���"), _T("�G���["), MB_OK );
            return -1; 
    }

    // �E�B���h�E��O�\��
    HWND hWnd = GetMainWindowHandle();
    SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    //
    srand( (unsigned)time(NULL) );
    C_Object obj;
    C_Fps fps(30,60);

    // �J�����̐ݒ�(DxLib)
    SetCameraPositionAndTargetAndUpVec(
        VGet( 0.0f, 0.0f, -50.0f ),   
        VGet( 0.0f, 0.0f,   0.0f ),   
        VGet( 0.0f, 1.0f,   0.0f )    );

    // ���C�����[�v
    while ( MainLoop() == 0 ){
        obj.Break();            // �j��
        obj.Draw();             // �`��
        obj.Update();           // �X�V

       // MV1DrawModel( collision ) ; �`�悵�Ȃ�

        C_Effect::Inst()->Draw();
        fps.All();           // FPS�`�搧�䏈��
    }

    DxLib_End();
    return 0;
}