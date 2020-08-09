/**
* @file    Fps.cpp
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   �t���[�����[�g�\�[�X
* @par     �t���[�����[�g�\�[�X
*/

#include <DxLib.h>
#include "Fps.h"


/**
* �R���X�g���N�^
*/
C_Fps::C_Fps(const int FPS, const int N ) :
 m_FPS(FPS),
 m_N(N)
{
    fps_cnt = 0;
    fps     = 0; 
};


/**
* FPS�v�Z����
*/
void C_Fps::Update()
{
    if ( fps_cnt == 0 ) fps_starttime = GetNowCount(); // 1�t���[���ڂȂ玞�����L��
    if ( fps_cnt == m_N ){                             // 60�t���[���ڂȂ畽�ς��v�Z����
        int nowtime = GetNowCount();
        fps = 1000.f/( (nowtime-fps_starttime)/(float)m_N );
        fps_cnt = 0;
        fps_starttime = nowtime;
    }
    fps_cnt++;
}


/**
* FPS�ҋ@����
*/
void C_Fps::Wait()
{
    int tooktime = GetNowCount() - fps_starttime;   // ������������
    int waittime = fps_cnt*1000/m_FPS - tooktime;   // �҂ׂ�����
    if ( waittime > 0 ) Sleep( waittime );          // �ҋ@
}


/**
* FPS����
*/
void C_Fps::All()
{
    Update();      // FPS�X�V
    ScreenFlip();  // ����ʃf�[�^��\��ʂ֔��f
    Wait();        // FPS�ҋ@����
}
