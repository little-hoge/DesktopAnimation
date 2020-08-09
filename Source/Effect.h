/**
* @file    Effect.h
* @date    2013/05/30
* @author  little
* @version 1.0
* @brief   エフェクトヘッダ
* @par     エフェクトヘッダ
*/

#pragma once
#include <DxLib.h>
#include "Singleton.h"

//----------------------------------------------------------------------------//
//	
//----------------------------------------------------------------------------//
#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib" )
#pragma comment(lib, "d3dx9.lib" )


#include <Effekseer.h>
#include <EffekseerRendererDX9.h>

#if _DEBUG
#pragma comment(lib, "Effekseer.Debug.lib" )
#pragma comment(lib, "EffekseerRendererDX9.Debug.lib" )
#else
#pragma comment(lib, "Effekseer.Release.lib" )
#pragma comment(lib, "EffekseerRendererDX9.Release.lib" )
#endif

/**
* @class C_Effect
*/
class C_Effect : public C_Singleton< C_Effect > {
public:
    Effekseer::Manager             *g_manager ; 
    EffekseerRenderer::Renderer    *g_renderer; 
    Effekseer::Effect              *g_effect  ;

    Effekseer::Vector3D DXLtoEFK( DxLib::VECTOR v );

public:
    C_Effect();
    ~C_Effect();
    int Init();               /*!< 初期化処理 */
    void Set( float, float ); /*!< 描画セット */
    void Draw();              /*!< 描画処理   */
    void Free();              /*!< 開放処理   */
};

#define EFFECT_MAX (5000)

// メモリ開放
#define SAFE_RELEASE(x)      if ( x != NULL ){ x->Release(); x = NULL; }