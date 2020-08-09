/**
* @file    Load.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   ロード関連ソース
* @par     ロード関連ソース
*/

#include <DxLib.h>
#include "Object.h"
#include "Define.h"
#include "Resource.h"

/**
* グローバル変数
*/
int img[TYPE_MAX*COLOR_NUM]; // 画像
int collision;


/**
* 必要素材ロード
*/
int Load()
{
    int baseimg[TYPE_MAX];
    const int color[] = { 
        255,   0,   0,  // 赤
        0,   255,   0,  // 緑
        0,     0, 255,  // 青
        255, 255,   0,  // 黄
        255,   0, 255,  // 紫
        0,   255, 255,  // 水
    };

    // ロード
    if ( ( collision = MV1LoadModel( "media/Texture/collision.mv1" ) ) == -1 ) return -1;
    MV1SetPosition( collision, VGet( 0.0f, 0.0f, 0.0f ) );// ついでに配置
    MV1SetupCollInfo( collision );                        // 当たり判定生成

    if ( ( LoadDivGraphToResource ( MAKEINTRESOURCE( ID_BASEIMG ), "BASE", TYPE_MAX, 6, 5, BASE_SIZE_X, BASE_SIZE_Y, baseimg )) == -1 ) return -1;

    // 色違い生成
    for ( int loop_T = 0; loop_T < TYPE_MAX; loop_T++ ){
        for ( int loop_C = 0; loop_C < COLOR_NUM; loop_C++ ){
            img[loop_T+loop_C*TYPE_MAX] = MakeScreen( BASE_SIZE_X, BASE_SIZE_Y, true ); // グラフィックハンドル作成
            SetDrawScreen( img[loop_T+loop_C*TYPE_MAX] );                               // 描画先セット
            SetDrawBright( color[loop_C*3], color[loop_C*3+1], color[loop_C*3+2]);      // 描画輝度をセット
            DrawGraph( 0, 0, baseimg[loop_T], true );                                   // 描画
        }
    }

    SetDrawScreen( DX_SCREEN_BACK );                                     // 裏画面セット
    SetDrawBright( 255, 255, 255 );                                      // 描画輝度をデフォルト
    for ( int i=0; i<TYPE_MAX; i++ ) DeleteGraph(baseimg[i]);            // ゴミ掃除

    return 0;
}


/**
* 該当色画像ハンドルを返す
*/
int GetImg( int color )
{
    if ( color >= 156 )  DebugBreak();
    return img[color];
}


/**
* コリジョンハンドルを返す
*/
int GetCollision()
{
    return collision;
}