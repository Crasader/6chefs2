//
//  DungeonCameraSceneData.h
//  LastSupper
//
//  Created by Kohei Asami on 2015/11/28.
//
//

#ifndef DungeonCameraScene_h
#define DungeonCameraScene_h

#include "Datas/Scene/DungeonSceneData.h"

class DungeonCameraSceneData : public DungeonSceneData
{
// クラスメソッド
public:
    CREATE_FUNC_WITH_PARAM(DungeonCameraSceneData, const Location&)
    
// インスタンス変数
private:
    int _targetId { etoi(ObjectID::UNDIFINED) };
    rapidjson::Value _eventJson {};
    
// インスタンスメソッド
private:
    DungeonCameraSceneData();
    ~DungeonCameraSceneData();
    bool init(const Location& location);

public:
    void setTargetId(const int objId);
    int getTargetId() const;
    
    void setEventJson(rapidjson::Value& json);
    rapidjson::Value& getEventJson();
};

#endif /* DungeonCameraScene_h */
