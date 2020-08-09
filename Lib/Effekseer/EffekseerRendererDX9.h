
#ifndef	__EFFEKSEERRENDERER_BASE_PRE_H__
#define	__EFFEKSEERRENDERER_BASE_PRE_H__

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------
#include <Effekseer.h>

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace EffekseerRenderer
{
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
class Renderer;

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#endif	// __EFFEKSEERRENDERER_PRE_BASE_H__

#ifndef	__EFFEKSEERRENDERER_RENDERER_H__
#define	__EFFEKSEERRENDERER_RENDERER_H__

//----------------------------------------------------------------------------------
// Include
//----------------------------------------------------------------------------------

#include <d3d9.h>
#include <d3dx9.h>

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
namespace EffekseerRenderer
{
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
/**
	@brief	�`��N���X
*/
class Renderer
{
protected:
	Renderer() {}
	virtual ~Renderer() {}

public:
	/**
		@brief	�f�o�C�X���X�g�������������Ɏ��s����B
	*/
	virtual void OnLostDevice() = 0;

	/**
		@brief	�f�o�C�X�����Z�b�g���ꂽ���Ɏ��s����B
	*/
	virtual void OnResetDevice() = 0;

	/**
		@brief	�C���X�^���X�𐶐�����B
		@param	device	[in]	DirectX�̃f�o�C�X
		@param	squareMaxCount	[in]	�ő�`��X�v���C�g��
		@return	�C���X�^���X
	*/
	static Renderer* Create( LPDIRECT3DDEVICE9 device, int32_t squareMaxCount );

	/**
		@brief	���̃C���X�^���X��j������B
	*/
	virtual void Destory() = 0;

	/**
		@brief	�`����J�n���鎞�Ɏ��s����B
	*/
	virtual bool BeginRendering() = 0;

	/**
		@brief	�`����I�����鎞�Ɏ��s����B
	*/
	virtual bool EndRendering() = 0;

	/**
		@brief	�f�o�C�X���擾����B
	*/
	virtual LPDIRECT3DDEVICE9 GetDevice() = 0;

	/**
		@brief	�ő�`��X�v���C�g�����擾����B
	*/
	virtual int32_t GetSquareMaxCount() const = 0;

	/**
		@brief	���C�g�̕������擾����B
	*/
	virtual const ::Effekseer::Vector3D& GetLightDirection() const = 0;

	/**
		@brief	���C�g�̕�����ݒ肷��B
	*/
	virtual void SetLightDirection( ::Effekseer::Vector3D& direction ) = 0;

	/**
		@brief	���C�g�̐F���擾����B
	*/
	virtual const ::Effekseer::Color& GetLightColor() const = 0;

	/**
		@brief	���C�g�̐F��ݒ肷��B
	*/
	virtual void SetLightColor( ::Effekseer::Color& color ) = 0;

	/**
		@brief	���C�g�̊����̐F���擾����B
	*/
	virtual const ::Effekseer::Color& GetLightAmbientColor() const = 0;

	/**
		@brief	���C�g�̊����̐F��ݒ肷��B
	*/
	virtual void SetLightAmbientColor( ::Effekseer::Color& color ) = 0;

	/**
		@brief	���e�s����擾����B
	*/
	virtual const ::Effekseer::Matrix44& GetProjectionMatrix() const = 0;

	/**
		@brief	���e�s���ݒ肷��B
	*/
	virtual void SetProjectionMatrix( const ::Effekseer::Matrix44& mat ) = 0;

	/**
		@brief	�J�����s����擾����B
	*/
	virtual const ::Effekseer::Matrix44& GetCameraMatrix() const = 0;

	/**
		@brief	�J�����s���ݒ肷��B
	*/
	virtual void SetCameraMatrix( const ::Effekseer::Matrix44& mat ) = 0;

	/**
		@brief	�J�����v���W�F�N�V�����s����擾����B
	*/
	virtual ::Effekseer::Matrix44& GetCameraProjectionMatrix() = 0;

	/**
		@brief	�X�v���C�g�����_���[�𐶐�����B
	*/
	virtual ::Effekseer::SpriteRenderer* CreateSpriteRenderer() = 0;

	/**
		@brief	���{�������_���[�𐶐�����B
	*/
	virtual ::Effekseer::RibbonRenderer* CreateRibbonRenderer() = 0;

	/**
		@brief	�����O�����_���[�𐶐�����B
	*/
	virtual ::Effekseer::RingRenderer* CreateRingRenderer() = 0;

	/**
		@brief	���f�������_���[�𐶐�����B
	*/
	virtual ::Effekseer::ModelRenderer* CreateModelRenderer() = 0;

	/**
		@brief	�W���̃e�N�X�`���Ǎ��N���X�𐶐�����B
	*/
	virtual ::Effekseer::TextureLoader* CreateTextureLoader( ::Effekseer::FileInterface* fileInterface = NULL ) = 0;

	/**
		@brief	�W���̃��f���Ǎ��N���X�𐶐�����B
	*/
	virtual ::Effekseer::ModelLoader* CreateModelLoader( ::Effekseer::FileInterface* fileInterface = NULL ) = 0;
};

//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
/**
	@brief	���f��
*/
class Model : public Effekseer::Model
{
private:

public:
	IDirect3DVertexBuffer9*		VertexBufferPtr;
	IDirect3DIndexBuffer9*		IndexBufferPtr;
	int32_t						VertexCount;
	int32_t						FaceCount;
	int32_t						ModelCount;

	Model( uint8_t* data, int32_t size )
		: Effekseer::Model	( data, size )
		, VertexBufferPtr	( NULL )
		, IndexBufferPtr	( NULL )
		, VertexCount		( 0 )
		, FaceCount			( 0 )
		, ModelCount		( 0 )
	{
	}

	virtual ~Model()
	{
		ES_SAFE_RELEASE( VertexBufferPtr );
		ES_SAFE_RELEASE( IndexBufferPtr );
	}
};


//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
}
//----------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------
#endif	// __EFFEKSEERRENDERER_RENDERER_H__