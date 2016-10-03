//
//  HitPoint.cpp
//  6chefs2
//
//  Created by Kohei Asami on 2016/10/02.
//
//

#include "MapObjects/Status/HitPoint.h"

// コンストラクタ
HitPoint::HitPoint() {}

// デストラクタ
HitPoint::~HitPoint() {}

// 初期化
bool HitPoint::init(int max, function<void()> onLost)
{
    _max = max;
    _current = max;
    _onLost = onLost;
    
    return true;
}

void HitPoint::reduce(int damage)
{
    _current -= damage;
    
    if (_current > 0) return;
    
    _current = 0;
    
    if (_onLost) {
        _onLost();
    }
}
