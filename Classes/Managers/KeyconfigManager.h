//
//  KeyconfigManager.h
//  6chefs2
//
//  Created by Kohei Asami on 2016/03/12.
//
//

#ifndef KeyconfigManager_h
#define KeyconfigManager_h

#include "define.h"

class KeyconfigMenuLayer;

class KeyconfigManager
{
// エイリアス
private:
    using Keyconfig = map<EventKeyboard::KeyCode, Key>;
    
// 定数
public:
    enum struct EnterKeyType
    {
        SPACE,
        Z,
        ENTER,
        
        SIZE
    };
    
    enum struct DashKeyType
    {
        LEFT_SHIFT,
        RIGHT_SHIFT,
        
        SIZE
    };
    
    enum struct CursorKeyType
    {
        ARROW,
        WASD,
        
        SIZE
    };
private:
    static const map<EnterKeyType, string> EnterKeyTypeToStr;
    static const map<DashKeyType, string> DashKeyTypeToStr;
    static const map<CursorKeyType, string> CursorKeyTypeToStr;
    static const map<EnterKeyType, EventKeyboard::KeyCode> enterKeys; // 決定キー
    static const map<DashKeyType, EventKeyboard::KeyCode> dashKeys;  // ダッシュキー
    static const map<CursorKeyType, Keyconfig> cursorKeys;             // 方向キー
    
// クラスメソッド
public:
    static KeyconfigManager* getInstance();
    static void destroy();
    
// インスタンス変数
private:
    Keyconfig keyconfig {};
    KeyconfigMenuLayer* menuLayer { nullptr };
    EnterKeyType enterKeyType { EnterKeyType::SIZE };
    DashKeyType dashKeyType { DashKeyType::SIZE };
    CursorKeyType cursorKeyType { CursorKeyType::SIZE };
    
// シングルトンであるためにprivateに
private:
    KeyconfigManager();												// コンストラクタ
    KeyconfigManager(const KeyconfigManager& other);				// デストラクタ
    KeyconfigManager& operator = (const KeyconfigManager& other);	// 代入演算子
    ~KeyconfigManager();											// デストラクタ
// インスタンスメソッド
public:
    void setEnterKey(const EnterKeyType keyType);
    void setDashKey(const DashKeyType keyType);
    void setCursorKey(const CursorKeyType keyType);
    Key convertKeyCode(const EventKeyboard::KeyCode keyCode) const;
    bool isKeyconfigOpened() const;
    void openKeyconfigMenu(function<void()> onClose);
    string typeToDispName(const EnterKeyType keyType);
    string typeToDispName(const DashKeyType keyType);
    string typeToDispName(const CursorKeyType keyType);
    EnterKeyType getEnterKeyType() const {return this->enterKeyType;};
    DashKeyType getDashKeyType() const {return this->dashKeyType;};
    CursorKeyType getCursorKeyType() const {return this->cursorKeyType;};
};

#endif /* KeyconfigManager_h */
