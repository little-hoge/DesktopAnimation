/**
* @file    Key.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   フレームレート関連ヘッダ
* @par     フレームレート関連ヘッダ
*/

#include <DxLib.h>
#include "Key.h"

/**
* コンストラクタ
*/
C_Key::C_Key() {
    memset(key, 0, sizeof(key));
};


/**
* キー入力更新処理
*/
int C_Key::Update()
{
    char tmpkey[KEYNUM];                                            // 現在のキーの入力状態を格納する
    GetHitKeyStateAll( tmpkey );                                    // 全てのキーの入力状態を得る

    for ( int cnt = 0; cnt < KEYNUM; cnt++ ){ 
        if ( tmpkey[cnt] != 0 ){                                    // キーコードに対応するキーが押されていたら
            if ( key[cnt] >= KEYCHECK ) key[cnt]++;                 // 入力され続けた時
            else                        key[cnt] = KEYCHECK;        // 入力された時定数を入れる
        } else {
            if ( key[cnt] >= KEYCHECK ) key[cnt] = KEYCHECK-1;      // 最初はなされた時入力受付時間を入れる
            else if ( key[cnt] > 0 )    key[cnt]--;                 // 押されていない時０まで減らす
        }
    }
    return GetKey(KEY_INPUT_ESCAPE);                                   // エスケープキーで終了
}


/**
* 特定キーコードを返す処理
*/
int C_Key::GetKey( int keycode )
{
    return key[keycode];
}