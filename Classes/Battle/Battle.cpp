//
//  Battle.cpp
//  6chefs2
//
//  Created by Kohei Asami on 2016/11/23.
//
//

#include "Battle/Battle.h"

#include "Battle/BattleData.h"

#include "Managers/DungeonSceneManager.h"

#include "MapObjects/MapObjectList.h"
#include "MapObjects/Party.h"
#include "MapObjects/Status/HitPoint.h"

#include "Tasks/EventTask.h"

// コンストラクタ
Battle::Battle() { FUNCLOG }

// デストラクタ
Battle::~Battle()
{
    FUNCLOG
    
    CC_SAFE_RELEASE_NULL(_data);
}

// 初期化
bool Battle::init(BattleData* data, DungeonSceneManager* manager)
{
    if (!Node::init()) return false;
    if (!data) return false;
    
    CC_SAFE_RETAIN(data);
    _data = data;
    
    MapObjectList* objectList { manager->getMapObjectList() };
    
    for (int objectId : data->getTargetObjectIds()) {
        MapObject* object { objectList->getMapObject(objectId) };
        if (object) _targetObjects.pushBack(object);
    }
    
    _mainCharacter = objectList->getParty()->getMainCharacter();
    
    if (!_mainCharacter) return false;
    
    _eventTask = manager->getEventTask();
    
    return true;
}

bool Battle::isAllTargetDestroyed() const
{
    for (MapObject* obj : _targetObjects) {
        if (!obj->getHitPoint()->isLost()) return false;
    }
    return true;
}

bool Battle::isMainCharacterDestroyed() const
{
    return _mainCharacter->getHitPoint()->isLost();
}

void Battle::start()
{
    this->schedule(CC_SCHEDULE_SELECTOR(Battle::update), 0.5f);
}

#pragma mark -
#pragma mark Interface
void Battle::update(float delta)
{
    if (this->isAllTargetDestroyed()) {
        this->unschedule(CC_SCHEDULE_SELECTOR(Battle::update));
        _eventTask->pushEventBack(_data->getSuccessCallbackEvent());
        return;
    }
    
    if (this->isMainCharacterDestroyed()) {
        this->unschedule(CC_SCHEDULE_SELECTOR(Battle::update));
        _eventTask->pushEventBack(_data->getFailureCallbackEvent());
        return;
    }
}
