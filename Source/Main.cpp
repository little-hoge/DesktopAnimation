/**
* @file    Main.cpp
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   メインヘッダ
* @par     メインヘッダ
*/

#include <DxLib.h>
#include <crtdbg.h>
#include <time.h>
#include "Main.h"
#include "Load.h"
#include "Key.h"
#include "Fps.h"
#include "Object.h"
#include "Time.h"
#include "Effect.h"


/**
* 必須ループ処理
*/
int MainLoop()
{
    if ( ProcessMessage()        != 0 ) return -1; // プロセス処理がエラー時-1
    if ( ClearDrawScreen()       != 0 ) return -1; // 画面クリア処理がエラー時-1
    if ( C_Key::Inst()->Update() != 0 ) return -1; // 入力情報更新 ESC入力時-1
    return 0;
}


//********************************************************************************//
//　◎メイン関数　
//********************************************************************************//
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
    // メモリリーク検出
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    // 初期設定処理
    if ( SetUseBackBufferTransColorFlag( TRUE )     !=        0               // ウインドウの透過色モード
        || ChangeWindowMode( TRUE )                 !=  DX_CHANGESCREEN_OK    // ウィンドウモード
        || SetOutApplicationLogValidFlag( false )   !=        0               // ログ出力しない
        || SetGraphMode( SCREEN_X, SCREEN_Y, 32 )   !=  DX_CHANGESCREEN_OK    // 画面設定
        || SetMainWindowText( TITLE_STR )           !=        0               // ウィンドウタイトル
        || SetAlwaysRunFlag( TRUE )                 !=        0               // 非アクティブでも処理
        || SetUseDirectInputFlag( TRUE )            !=        0               // 非アクティブでキー入手
        || DxLib_Init()                             !=        0               // ＤＸライブラリ初期化
        || Load()                                   !=        0               // 画像読み込み
        || SetCameraNearFar( 1.0f, 20000.0f )       !=        0               // エフェクト初期設定
        || C_Effect::Inst()->Init()                 !=        0               // エフェクトマネージャ生成
        ){
            MessageBox( NULL, _T("ライブラリの初期化に失敗しました"), _T("エラー"), MB_OK );
            return -1; 
    }

    // ウィンドウ手前表示
    HWND hWnd = GetMainWindowHandle();
    SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

    //
    srand( (unsigned)time(NULL) );
    C_Object obj;
    C_Fps fps(30,60);

    // カメラの設定(DxLib)
    SetCameraPositionAndTargetAndUpVec(
        VGet( 0.0f, 0.0f, -50.0f ),   
        VGet( 0.0f, 0.0f,   0.0f ),   
        VGet( 0.0f, 1.0f,   0.0f )    );

    // メインループ
    while ( MainLoop() == 0 ){
        obj.Break();            // 破壊
        obj.Draw();             // 描画
        obj.Update();           // 更新

       // MV1DrawModel( collision ) ; 描画しない

        C_Effect::Inst()->Draw();
        fps.All();           // FPS描画制御処理
    }

    DxLib_End();
    return 0;
}