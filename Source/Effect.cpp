/**
* @file    Effect.cpp
* @date    2013/05/30
* @author  little
* @version 1.0
* @brief   �G�t�F�N�g�\�[�X
* @par     �G�t�F�N�g�\�[�X
*/

#include "Effect.h"
#include "Main.h"
#include "Load.h"

/**
* �R���X�g���N�^
*/
C_Effect::C_Effect() {

};


/**
* �f�X�g���N�^
*/
C_Effect::~C_Effect() {
    Free();
};


/**
* ����������
*/
int C_Effect::Init()
{
    // �`��p�C���X�^���X�̐���
    g_renderer = EffekseerRenderer::Renderer::Create( (LPDIRECT3DDEVICE9)GetUseDirect3DDevice9(), EFFECT_MAX );

    // �G�t�F�N�g�Ǘ��p�C���X�^���X�̐���
    g_manager = Effekseer::Manager::Create( EFFECT_MAX );

    // �`��p�C���X�^���X����`��@�\��ݒ�
    g_manager->SetSpriteRenderer( g_renderer->CreateSpriteRenderer() );
    g_manager->SetRibbonRenderer( g_renderer->CreateRibbonRenderer() );
    g_manager->SetRingRenderer  ( g_renderer->CreateRingRenderer()   );
    g_manager->SetModelRenderer ( g_renderer->CreateModelRenderer()  );

    // �`��p�C���X�^���X����e�N�X�`���̓Ǎ��@�\��ݒ�
    // �Ǝ��g���\�A���݂̓t�@�C������ǂݍ���ł���B
    g_manager->SetTextureLoader( g_renderer->CreateTextureLoader() );
    g_manager->SetModelLoader  ( g_renderer->CreateModelLoader()   );

    //���W�n�̎w��(LH=������W�n,RH=�E����W�n)
    g_manager->SetCoordinateSystem(Effekseer::COORDINATE_SYSTEM_LH);

    // ���e�s���ݒ�(�v���W�F�N�V�����s��)
    //float ovY�F�J�����̎���p
    //float aspect�F��ʃT�C�Y �A�X�y�N�g�� (��Ԃ̍����𕝂Ŋ������l)
    //float zn�F�J������ Near  �N���b�v��(�J�������炱�̒l���߂��|���S���͕`�悳��Ȃ�)
    //float zf�F�J������ Far   �N���b�v��(�J�������炱�̒l��艓���|���S���͕`�悳��Ȃ�)
    g_renderer->SetProjectionMatrix(
        Effekseer::Matrix44().PerspectiveFovLH( GetCameraFov(), (float)SCREEN_X / (float)SCREEN_Y, GetCameraNear(), GetCameraFar()) );

    // �J�����s���ݒ�(�r���[�s��)(Effekseer)
    // Vector3D�Feye �J�����̈ʒu(���_)
    // Vector3D�Fat  �^�[�Q�b�g�̈ʒu
    // Vector3D�Fup  �J�����̏����
    g_renderer->SetCameraMatrix(
        Effekseer::Matrix44().LookAtLH( 
        Effekseer::Vector3D( 0.0f,  0.0f, -50.0f ),
        Effekseer::Vector3D( 0.0f,  0.0f,   0.0f ), 
        Effekseer::Vector3D( 0.0f,  1.0f,   0.0f )) );

    // �G�t�F�N�g�̓Ǎ�
    g_effect = Effekseer::Effect::Create( g_manager, (const EFK_CHAR*)L"media/e.efk" );

    // �ǂݍ��ݎ��s
    if ( g_effect == NULL ) return 1;
    return 0;
}


/**
* �`��Z�b�g����
*/
void C_Effect::Set( float pos_x, float pos_y )
{
    VECTOR Pos_S, Pos_E;
    MV1_COLL_RESULT_POLY Hit_s;

    // ���[�J�����W���烏�[���h���W�����p�s��
    Pos_S = ConvScreenPosToWorldPos( VGet( pos_x, pos_y, 0.0f ) );
    Pos_E = ConvScreenPosToWorldPos( VGet( pos_x, pos_y, 1.0f ) );

    // ���f���Ɛ����Ƃ̓����蔻��
    Hit_s = MV1CollCheck_Line( GetCollision(), -1, Pos_S, Pos_E );

    // �G�t�F�N�g�Đ�
    if ( Hit_s.HitFlag ) g_manager->Play( C_Effect::Inst()->g_effect, Hit_s.HitPosition.x, Hit_s.HitPosition.y, Hit_s.HitPosition.z );
}


/**
* �`�揈��
*/
void C_Effect::Draw()
{
    RenderVertex();               // ���_�o�b�t�@�ɗ��܂������_�f�[�^��f���o��
    g_manager->Update();          // �X�V����
    g_renderer->BeginRendering(); // �`��J�n����
    g_manager->Draw();            // �`��
    g_renderer->EndRendering();   // �`��I��
}


/**
* �J������
*/
void C_Effect::Free()
{
    // �G�t�F�N�g�̔j��
    SAFE_RELEASE( g_effect );

    g_manager->Destroy();   // �G�t�F�N�g�Ǘ��p�C���X�^���X��j��
    g_renderer->Destory();  // �`��p�C���X�^���X��j��

}


// ����
// Vector�󂯓n��
Effekseer::Vector3D C_Effect::DXLtoEFK( DxLib::VECTOR v )
{
    return Effekseer::Vector3D( v.x, v.y, v.z );
}

////�G�t�F�N�g����
    //g_manager->SetLocation( efk_handle, 0.0f, 0.0f, 0.0f );// �ʒu
    //g_manager->SetRotation( efk_handle, Effekseer::Vector3D(0.0f,0.0f,0.0f), 0.0f );// ��]
    //g_manager->SetScale   ( efk_handle, 0.0f, 0.0f, 0.0f );// �{��