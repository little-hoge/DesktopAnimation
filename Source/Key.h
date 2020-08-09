/**
* @file    Key.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   フレームレート関連ヘッダ
* @par     フレームレート関連ヘッダ
*/

#pragma once
#include "Singleton.h"

/** 
* @class C_Key
* @brief キークラス
*/
class C_Key : public C_Singleton< C_Key > {
    friend C_Singleton< C_Key >;

private:
    static const int KEYNUM = 256;          // キーの最大数
    int key[KEYNUM];                        // キーが押されているフレーム数を格納する
    C_Key();                                // コンストラクタ
    ~C_Key(){};                             // デストラクタ
    C_Key( const C_Key& obj );              // コピーコンストラクタ
    C_Key& operator = ( const C_Key& obj ); // 代入演算子（のオーバーライド）

public:
    static const int KEYCHECK = 10;
    int GetKey( int );
    int Update();                   // キー入力更新処理
};