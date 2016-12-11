//
//  Battle.h
//  6chefs2
//
//  Created by Kohei Asami on 2016/11/23.
//
//

#ifndef Battle_h
#define Battle_h

#include "define.h"

class BattleData;
class EventTask;
class MapObject;
class MapObjectList;
class DungeonSceneManager;

class Battle : public Node
{
// クラスメソッド
public:
    CREATE_FUNC_WITH_TWO_PARAM(Battle, BattleData*, DungeonSceneManager*);
    
// インスタンス変数
private:
    BattleData* _data { nullptr };
    MapObject* _mainCharacter { nullptr };
    Vector<MapObject*> _targetObjects {};
    EventTask* _eventTask { nullptr };
    
// インスタンスメソッド
private:
    Battle();
    ~Battle();
    bool init(BattleData* data, DungeonSceneManager* manager);
    bool isAllTargetDestroyed() const;
    bool isMainCharacterDestroyed() const;
    
public:
    void update(float delta) override;
};

#endif /* Battle_hpp */
