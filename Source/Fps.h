/**
* @file    Fps.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   �t���[�����[�g�w�b�_
* @par     �t���[�����[�g�w�b�_
*/

#pragma once

/** 
* @class C_Fps
* @brief �t���[�����[�g�N���X
*/
class C_Fps {
private:
    const int m_N;                      /*!< ���ς����T���v���� */
    const int m_FPS;                    /*!< �ݒ肵��FPS */

    int fps_starttime;                  /*!< ����J�n���� */
    int fps_cnt;                        /*!< �J�E���^ */
    float fps;                          /*!< fps */

    void Update();                      /*!< FPS�v�Z���� */
    void Wait();                        /*!< FPS�҂����ԏ��� */
    C_Fps(const C_Fps& obj);            /*!< �R�s�[�R���X�g���N�^�͖��� */
    C_Fps& operator=(const C_Fps& obj); /*!< ������Z�q�������� */

public:
    C_Fps(const int, const int);        /*!< �R���X�g���N�^ */
    ~C_Fps(){};                         /*!< �f�X�g���N�^ */
    void All();                         /*!< FPS�����ꊇ */
};