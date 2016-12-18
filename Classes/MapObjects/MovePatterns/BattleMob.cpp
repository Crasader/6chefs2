//
//  BattleMob.cpp
//  6chefs2
//
//  Created by Kohei Asami on 2016/12/11.
//
//

#include "MapObjects/MovePatterns/BattleMob.h"

#include "MapObjects/MovePatterns/Chaser.h"

#include "MapObjects/Character.h"
#include "MapObjects/MapObjectList.h"
#include "MapObjects/DetectionBox/CollisionDetector.h"
#include "MapObjects/DetectionBox/CollisionBox.h"

#include "MapObjects/Command/AttackCommand.h"

// コンストラクタ
BattleMob::BattleMob() { FUNCLOG }

// デストラクタ
BattleMob::~BattleMob()
{
    FUNCLOG
    
    CC_SAFE_RELEASE_NULL(_subPattern);
}

// 初期化
bool BattleMob::init(Character* character)
{
    if (!MovePattern::init(character)) return false;
    
    _subPattern = Chaser::create(character);
    CC_SAFE_RETAIN(_subPattern);
    _subPattern->setSpeedRatio(0.5f);
    
    return true;
}


#pragma mark -
#pragma mark Interface
void BattleMob::start()
{
    MovePattern::start();
    
    if (_subPattern) _subPattern->start();
}

void BattleMob::pause()
{
    MovePattern::pause();
    
    if (_subPattern) _subPattern->pause();
}

void BattleMob::resume()
{
    MovePattern::resume();
    
    if (_subPattern) _subPattern->resume();
}

void BattleMob::onPartyMoved()
{
    if (_subPattern) _subPattern->onPartyMoved();
}

bool BattleMob::canGoToNextMap() const
{
    return false;
}

void BattleMob::update(float delta)
{
    Point forwardGridPos1 { _chara->getGridPosition() + _chara->getDirection().getGridVec2() };
    Point forwardGridPos2 { _chara->getGridPosition() + _chara->getDirection().getGridVec2() * 2 };
    
    if (_chara->getCollision()->intersectsGrid(this->getMainCharacter()->getCollision(), forwardGridPos1) ||
        _chara->getCollision()->intersectsGrid(this->getMainCharacter()->getCollision(), forwardGridPos2)) {
        if (!_chara) return;
        _chara->clearCommandQueue();
        AttackCommand* command { AttackCommand::create() };
        command->setName("attack");
        command->setCallback([this](Character* character){ this->start(); });
        _chara->pushCommand(command);
    }
}
