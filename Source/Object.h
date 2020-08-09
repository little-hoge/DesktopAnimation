/**
* @file    Object.h
* @date    2013/05/31
* @author  little
* @version 1.0
* @brief   �I�u�W�F�N�g�w�b�_
* @par     �I�u�W�F�N�g�w�b�_
*/

#pragma once
#include "Define.h"

/** 
* @class C_Object
* @brief �I�u�W�F�N�g�N���X
*/
class C_Object {

private:
    static const int OBJ_MAX     = 50;
    typedef struct s_data {
        float pos_x, pos_y;
        double angle;
        float speed;
        E_color color;
        bool hp;
        E_keytype keytype;
    };
    s_data data[OBJ_MAX];
    
public:
    C_Object();
    ~C_Object(){};
    void Create();
    void Update();
    void Draw();
    void Break();
};