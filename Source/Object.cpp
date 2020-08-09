/**
* @file    Object.cpp
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   オブジェクトソース
* @par     オブジェクトソース
*/

#include <DxLib.h>
#include <math.h>
#include "Object.h"
#include "Load.h"
#include "Main.h"
#include "Key.h"
#include "Effect.h"

/**
* コンストラクタ
*/
C_Object::C_Object()
{
    memset(data, 0, sizeof(data));
    for ( int loop = 0; loop < OBJ_MAX; loop++ ) Create();
}


/**
* オブジェクト再生成処理
*/
void C_Object::Create()
{
    for ( int loop = 0; loop < OBJ_MAX; loop++ ){
        if ( !data[loop].hp ){
            data[loop].pos_x   = GetRand(SCREEN_X - BASE_SIZE_X) + 0.0f;
            data[loop].pos_y   = GetRand(SCREEN_Y - BASE_SIZE_Y) + 0.0f;
            data[loop].color   = (E_color)(GetRand(COLOR_NUM-1)+1);
            data[loop].hp      = true;
            data[loop].angle   = GetRand(359);
            data[loop].speed   = GetRand(5)+1 + 0.0f;
            data[loop].keytype = (E_keytype)(GetRand(TYPE_MAX-1)+1);
            break;
        }
    }
}


/**
* オブジェクト更新処理
*/
void C_Object::Update()
{
    for ( int loop = 0; loop < OBJ_MAX; loop++ ){
        if ( data[loop].hp ){
            if ( data[loop].pos_x > SCREEN_X - data[loop].speed - BASE_SIZE_X ) data[loop].angle = (GetRand(180)+90)  * (DX_PI/180);    // 右画面判定	
            if ( data[loop].pos_x < data[loop].speed )                          data[loop].angle = (GetRand(180)+270) * (DX_PI/180);    // 左画面判定
            if ( data[loop].pos_y > SCREEN_Y - data[loop].speed - BASE_SIZE_Y ) data[loop].angle = (GetRand(180)+180) * (DX_PI/180);    // 下画面判定
            if ( data[loop].pos_y < data[loop].speed )                          data[loop].angle = GetRand(180)       * (DX_PI/180);    // 上画面判定

            data[loop].pos_x += (float)cos(data[loop].angle) * data[loop].speed;
            data[loop].pos_y += (float)sin(data[loop].angle) * data[loop].speed;
        }
    }
}


/**
* オブジェクト描画処理
*/
void C_Object::Draw()
{
    // 壁判定
    for ( int loop = 0; loop < OBJ_MAX; loop++ ){
        if ( data[loop].hp ){
            int gra = (data[loop].keytype+(data[loop].color)*(TYPE_MAX))-(TYPE_MAX+1);
            DrawGraphF( (float)data[loop].pos_x, (float)data[loop].pos_y, GetImg( gra ), true );
        }
    }
}


/**
* オブジェクト破壊処理
*/
void C_Object::Break()
{
    C_Key &mKey = *C_Key::Inst();
    C_Effect &mEffect = *C_Effect::Inst();

    // 該当キーコード一つ消滅＋後１つ生成
    for ( int loop = 0; loop < OBJ_MAX; loop++ ){
        if ( data[loop].hp ){
            if ( mKey.GetKey(KEY_INPUT_A) == mKey.KEYCHECK )  if ( data[loop].keytype == A ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_B) == mKey.KEYCHECK )  if ( data[loop].keytype == B ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_C) == mKey.KEYCHECK )  if ( data[loop].keytype == C ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_D) == mKey.KEYCHECK )  if ( data[loop].keytype == D ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_E) == mKey.KEYCHECK )  if ( data[loop].keytype == E ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_F) == mKey.KEYCHECK )  if ( data[loop].keytype == F ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_G) == mKey.KEYCHECK )  if ( data[loop].keytype == G ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_H) == mKey.KEYCHECK )  if ( data[loop].keytype == H ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_I) == mKey.KEYCHECK )  if ( data[loop].keytype == I ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_J) == mKey.KEYCHECK )  if ( data[loop].keytype == J ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_K) == mKey.KEYCHECK )  if ( data[loop].keytype == K ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_L) == mKey.KEYCHECK )  if ( data[loop].keytype == L ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_M) == mKey.KEYCHECK )  if ( data[loop].keytype == M ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_N) == mKey.KEYCHECK )  if ( data[loop].keytype == N ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_O) == mKey.KEYCHECK )  if ( data[loop].keytype == O ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_P) == mKey.KEYCHECK )  if ( data[loop].keytype == P ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_Q) == mKey.KEYCHECK )  if ( data[loop].keytype == Q ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_R) == mKey.KEYCHECK )  if ( data[loop].keytype == R ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_S) == mKey.KEYCHECK )  if ( data[loop].keytype == S ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_T) == mKey.KEYCHECK )  if ( data[loop].keytype == T ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_U) == mKey.KEYCHECK )  if ( data[loop].keytype == U ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_V) == mKey.KEYCHECK )  if ( data[loop].keytype == V ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_W) == mKey.KEYCHECK )  if ( data[loop].keytype == W ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_X) == mKey.KEYCHECK )  if ( data[loop].keytype == X ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_Y) == mKey.KEYCHECK )  if ( data[loop].keytype == Y ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
            if ( mKey.GetKey(KEY_INPUT_Z) == mKey.KEYCHECK )  if ( data[loop].keytype == Z ){ data[loop].hp = false; mEffect.Set(data[loop].pos_x, data[loop].pos_y); Create(); break;}
        }
    }
}
