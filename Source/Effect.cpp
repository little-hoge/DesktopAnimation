/**
* @file    Effect.cpp
* @date    2013/05/30
* @author  little
* @version 1.0
* @brief   エフェクトソース
* @par     エフェクトソース
*/

#include "Effect.h"
#include "Main.h"
#include "Load.h"

/**
* コンストラクタ
*/
C_Effect::C_Effect() {

};


/**
* デストラクタ
*/
C_Effect::~C_Effect() {
    Free();
};


/**
* 初期化処理
*/
int C_Effect::Init()
{
    // 描画用インスタンスの生成
    g_renderer = EffekseerRenderer::Renderer::Create( (LPDIRECT3DDEVICE9)GetUseDirect3DDevice9(), EFFECT_MAX );

    // エフェクト管理用インスタンスの生成
    g_manager = Effekseer::Manager::Create( EFFECT_MAX );

    // 描画用インスタンスから描画機能を設定
    g_manager->SetSpriteRenderer( g_renderer->CreateSpriteRenderer() );
    g_manager->SetRibbonRenderer( g_renderer->CreateRibbonRenderer() );
    g_manager->SetRingRenderer  ( g_renderer->CreateRingRenderer()   );
    g_manager->SetModelRenderer ( g_renderer->CreateModelRenderer()  );

    // 描画用インスタンスからテクスチャの読込機能を設定
    // 独自拡張可能、現在はファイルから読み込んでいる。
    g_manager->SetTextureLoader( g_renderer->CreateTextureLoader() );
    g_manager->SetModelLoader  ( g_renderer->CreateModelLoader()   );

    //座標系の指定(LH=左手座標系,RH=右手座標系)
    g_manager->SetCoordinateSystem(Effekseer::COORDINATE_SYSTEM_LH);

    // 投影行列を設定(プロジェクション行列)
    //float ovY：カメラの視野角
    //float aspect：画面サイズ アスペクト比 (空間の高さを幅で割った値)
    //float zn：カメラの Near  クリップ面(カメラからこの値より近いポリゴンは描画されない)
    //float zf：カメラの Far   クリップ面(カメラからこの値より遠いポリゴンは描画されない)
    g_renderer->SetProjectionMatrix(
        Effekseer::Matrix44().PerspectiveFovLH( GetCameraFov(), (float)SCREEN_X / (float)SCREEN_Y, GetCameraNear(), GetCameraFar()) );

    // カメラ行列を設定(ビュー行列)(Effekseer)
    // Vector3D：eye カメラの位置(視点)
    // Vector3D：at  ターゲットの位置
    // Vector3D：up  カメラの上方向
    g_renderer->SetCameraMatrix(
        Effekseer::Matrix44().LookAtLH( 
        Effekseer::Vector3D( 0.0f,  0.0f, -50.0f ),
        Effekseer::Vector3D( 0.0f,  0.0f,   0.0f ), 
        Effekseer::Vector3D( 0.0f,  1.0f,   0.0f )) );

    // エフェクトの読込
    g_effect = Effekseer::Effect::Create( g_manager, (const EFK_CHAR*)L"media/e.efk" );

    // 読み込み失敗
    if ( g_effect == NULL ) return 1;
    return 0;
}


/**
* 描画セット処理
*/
void C_Effect::Set( float pos_x, float pos_y )
{
    VECTOR Pos_S, Pos_E;
    MV1_COLL_RESULT_POLY Hit_s;

    // ローカル座標からワールド座標検索用行列
    Pos_S = ConvScreenPosToWorldPos( VGet( pos_x, pos_y, 0.0f ) );
    Pos_E = ConvScreenPosToWorldPos( VGet( pos_x, pos_y, 1.0f ) );

    // モデルと線分との当たり判定
    Hit_s = MV1CollCheck_Line( GetCollision(), -1, Pos_S, Pos_E );

    // エフェクト再生
    if ( Hit_s.HitFlag ) g_manager->Play( C_Effect::Inst()->g_effect, Hit_s.HitPosition.x, Hit_s.HitPosition.y, Hit_s.HitPosition.z );
}


/**
* 描画処理
*/
void C_Effect::Draw()
{
    RenderVertex();               // 頂点バッファに溜まった頂点データを吐き出す
    g_manager->Update();          // 更新処理
    g_renderer->BeginRendering(); // 描画開始処理
    g_manager->Draw();            // 描画
    g_renderer->EndRendering();   // 描画終了
}


/**
* 開放処理
*/
void C_Effect::Free()
{
    // エフェクトの破棄
    SAFE_RELEASE( g_effect );

    g_manager->Destroy();   // エフェクト管理用インスタンスを破棄
    g_renderer->Destory();  // 描画用インスタンスを破棄

}


// メモ
// Vector受け渡し
Effekseer::Vector3D C_Effect::DXLtoEFK( DxLib::VECTOR v )
{
    return Effekseer::Vector3D( v.x, v.y, v.z );
}

////エフェクト調整
    //g_manager->SetLocation( efk_handle, 0.0f, 0.0f, 0.0f );// 位置
    //g_manager->SetRotation( efk_handle, Effekseer::Vector3D(0.0f,0.0f,0.0f), 0.0f );// 回転
    //g_manager->SetScale   ( efk_handle, 0.0f, 0.0f, 0.0f );// 倍率