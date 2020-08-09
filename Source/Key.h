/**
* @file    Key.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   �t���[�����[�g�֘A�w�b�_
* @par     �t���[�����[�g�֘A�w�b�_
*/

#pragma once
#include "Singleton.h"

/** 
* @class C_Key
* @brief �L�[�N���X
*/
class C_Key : public C_Singleton< C_Key > {
    friend C_Singleton< C_Key >;

private:
    static const int KEYNUM = 256;          // �L�[�̍ő吔
    int key[KEYNUM];                        // �L�[��������Ă���t���[�������i�[����
    C_Key();                                // �R���X�g���N�^
    ~C_Key(){};                             // �f�X�g���N�^
    C_Key( const C_Key& obj );              // �R�s�[�R���X�g���N�^
    C_Key& operator = ( const C_Key& obj ); // ������Z�q�i�̃I�[�o�[���C�h�j

public:
    static const int KEYCHECK = 10;
    int GetKey( int );
    int Update();                   // �L�[���͍X�V����
};