/**
* @file    Singleton.h
* @date    2013/05/13
* @author  little
* @version 1.0
* @brief   シングルトンテンプレート
* @par     シングルトンテンプレート
*/

#pragma once

template<class T>
class C_Singleton {

protected:
    C_Singleton(){};                                  /*!< コンストラクタ */
    virtual ~C_Singleton(){};                         /*!< デストラクタ */

public:
    static T* Inst()
    {
        static T inst;                                /*!< インスタンスを静的に生成 */
        return &inst;                                 /*!< インスタンスのアドレスを返す */
    };

private:
    C_Singleton( const C_Singleton &obj );            /*!< コピーコンストラクタ無効 */
    C_Singleton& operator= ( const C_Singleton &obj );/*!< 代入演算子無効 */
    static T* inst;
};
