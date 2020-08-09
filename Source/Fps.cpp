/**
* @file    Fps.cpp
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   フレームレートソース
* @par     フレームレートソース
*/

#include <DxLib.h>
#include "Fps.h"


/**
* コンストラクタ
*/
C_Fps::C_Fps(const int FPS, const int N ) :
 m_FPS(FPS),
 m_N(N)
{
    fps_cnt = 0;
    fps     = 0; 
};


/**
* FPS計算処理
*/
void C_Fps::Update()
{
    if ( fps_cnt == 0 ) fps_starttime = GetNowCount(); // 1フレーム目なら時刻を記憶
    if ( fps_cnt == m_N ){                             // 60フレーム目なら平均を計算する
        int nowtime = GetNowCount();
        fps = 1000.f/( (nowtime-fps_starttime)/(float)m_N );
        fps_cnt = 0;
        fps_starttime = nowtime;
    }
    fps_cnt++;
}


/**
* FPS待機処理
*/
void C_Fps::Wait()
{
    int tooktime = GetNowCount() - fps_starttime;   // かかった時間
    int waittime = fps_cnt*1000/m_FPS - tooktime;   // 待つべき時間
    if ( waittime > 0 ) Sleep( waittime );          // 待機
}


/**
* FPS処理
*/
void C_Fps::All()
{
    Update();      // FPS更新
    ScreenFlip();  // 裏画面データを表画面へ反映
    Wait();        // FPS待機処理
}
