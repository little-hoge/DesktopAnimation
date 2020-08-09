/**
* @file    Effect.h
* @date    2013/05/30
* @author  little
* @version 1.0
* @brief   �G�t�F�N�g�w�b�_
* @par     �G�t�F�N�g�w�b�_
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
    int Init();               /*!< ���������� */
    void Set( float, float ); /*!< �`��Z�b�g */
    void Draw();              /*!< �`�揈��   */
    void Free();              /*!< �J������   */
};

#define EFFECT_MAX (5000)

// �������J��
#define SAFE_RELEASE(x)      if ( x != NULL ){ x->Release(); x = NULL; }