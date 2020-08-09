/**
* @file    Key.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   �t���[�����[�g�֘A�w�b�_
* @par     �t���[�����[�g�֘A�w�b�_
*/

#include <DxLib.h>
#include "Key.h"

/**
* �R���X�g���N�^
*/
C_Key::C_Key() {
    memset(key, 0, sizeof(key));
};


/**
* �L�[���͍X�V����
*/
int C_Key::Update()
{
    char tmpkey[KEYNUM];                                            // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll( tmpkey );                                    // �S�ẴL�[�̓��͏�Ԃ𓾂�

    for ( int cnt = 0; cnt < KEYNUM; cnt++ ){ 
        if ( tmpkey[cnt] != 0 ){                                    // �L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            if ( key[cnt] >= KEYCHECK ) key[cnt]++;                 // ���͂��ꑱ������
            else                        key[cnt] = KEYCHECK;        // ���͂��ꂽ���萔������
        } else {
            if ( key[cnt] >= KEYCHECK ) key[cnt] = KEYCHECK-1;      // �ŏ��͂Ȃ��ꂽ�����͎�t���Ԃ�����
            else if ( key[cnt] > 0 )    key[cnt]--;                 // ������Ă��Ȃ����O�܂Ō��炷
        }
    }
    return GetKey(KEY_INPUT_ESCAPE);                                   // �G�X�P�[�v�L�[�ŏI��
}


/**
* ����L�[�R�[�h��Ԃ�����
*/
int C_Key::GetKey( int keycode )
{
    return key[keycode];
}