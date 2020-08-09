/**
* @file    Singleton.h
* @date    2013/05/13
* @author  little
* @version 1.0
* @brief   �V���O���g���e���v���[�g
* @par     �V���O���g���e���v���[�g
*/

#pragma once

template<class T>
class C_Singleton {

protected:
    C_Singleton(){};                                  /*!< �R���X�g���N�^ */
    virtual ~C_Singleton(){};                         /*!< �f�X�g���N�^ */

public:
    static T* Inst()
    {
        static T inst;                                /*!< �C���X�^���X��ÓI�ɐ��� */
        return &inst;                                 /*!< �C���X�^���X�̃A�h���X��Ԃ� */
    };

private:
    C_Singleton( const C_Singleton &obj );            /*!< �R�s�[�R���X�g���N�^���� */
    C_Singleton& operator= ( const C_Singleton &obj );/*!< ������Z�q���� */
    static T* inst;
};
