/**
* @file    Load.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   ���[�h�֘A�\�[�X
* @par     ���[�h�֘A�\�[�X
*/

#include <DxLib.h>
#include "Object.h"
#include "Define.h"
#include "Resource.h"

/**
* �O���[�o���ϐ�
*/
int img[TYPE_MAX*COLOR_NUM]; // �摜
int collision;


/**
* �K�v�f�ރ��[�h
*/
int Load()
{
    int baseimg[TYPE_MAX];
    const int color[] = { 
        255,   0,   0,  // ��
        0,   255,   0,  // ��
        0,     0, 255,  // ��
        255, 255,   0,  // ��
        255,   0, 255,  // ��
        0,   255, 255,  // ��
    };

    // ���[�h
    if ( ( collision = MV1LoadModel( "media/Texture/collision.mv1" ) ) == -1 ) return -1;
    MV1SetPosition( collision, VGet( 0.0f, 0.0f, 0.0f ) );// ���łɔz�u
    MV1SetupCollInfo( collision );                        // �����蔻�萶��

    if ( ( LoadDivGraphToResource ( MAKEINTRESOURCE( ID_BASEIMG ), "BASE", TYPE_MAX, 6, 5, BASE_SIZE_X, BASE_SIZE_Y, baseimg )) == -1 ) return -1;

    // �F�Ⴂ����
    for ( int loop_T = 0; loop_T < TYPE_MAX; loop_T++ ){
        for ( int loop_C = 0; loop_C < COLOR_NUM; loop_C++ ){
            img[loop_T+loop_C*TYPE_MAX] = MakeScreen( BASE_SIZE_X, BASE_SIZE_Y, true ); // �O���t�B�b�N�n���h���쐬
            SetDrawScreen( img[loop_T+loop_C*TYPE_MAX] );                               // �`���Z�b�g
            SetDrawBright( color[loop_C*3], color[loop_C*3+1], color[loop_C*3+2]);      // �`��P�x���Z�b�g
            DrawGraph( 0, 0, baseimg[loop_T], true );                                   // �`��
        }
    }

    SetDrawScreen( DX_SCREEN_BACK );                                     // ����ʃZ�b�g
    SetDrawBright( 255, 255, 255 );                                      // �`��P�x���f�t�H���g
    for ( int i=0; i<TYPE_MAX; i++ ) DeleteGraph(baseimg[i]);            // �S�~�|��

    return 0;
}


/**
* �Y���F�摜�n���h����Ԃ�
*/
int GetImg( int color )
{
    if ( color >= 156 )  DebugBreak();
    return img[color];
}


/**
* �R���W�����n���h����Ԃ�
*/
int GetCollision()
{
    return collision;
}