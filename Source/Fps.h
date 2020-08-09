/**
* @file    Fps.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   フレームレートヘッダ
* @par     フレームレートヘッダ
*/

#pragma once

/** 
* @class C_Fps
* @brief フレームレートクラス
*/
class C_Fps {
private:
    const int m_N;                      /*!< 平均を取るサンプル数 */
    const int m_FPS;                    /*!< 設定したFPS */

    int fps_starttime;                  /*!< 測定開始時刻 */
    int fps_cnt;                        /*!< カウンタ */
    float fps;                          /*!< fps */

    void Update();                      /*!< FPS計算処理 */
    void Wait();                        /*!< FPS待ち時間処理 */
    C_Fps(const C_Fps& obj);            /*!< コピーコンストラクタは無効 */
    C_Fps& operator=(const C_Fps& obj); /*!< 代入演算子も無効に */

public:
    C_Fps(const int, const int);        /*!< コンストラクタ */
    ~C_Fps(){};                         /*!< デストラクタ */
    void All();                         /*!< FPS処理一括 */
};