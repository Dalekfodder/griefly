#pragma once

#include "Mob.h"
#include "core/objects/Interface.h"
#include "representation/ViewInfo.h"

class LoginInterface: public InterfaceBase
{
    friend FastSerializer& operator<<(FastSerializer& file, LoginInterface& interf);
    friend FastDeserializer& operator>>(FastDeserializer& file, LoginInterface& interf);
public:
    void Init();

    virtual void HandleClick(const QString& place) override {}
    virtual void Draw() override;
    virtual unsigned int hash() const override;
private:
    ViewInfo view_;
};

FastSerializer& operator<<(FastSerializer& file, LoginInterface& interf);
FastDeserializer& operator>>(FastDeserializer& file, LoginInterface& interf);

inline unsigned int hash(const LoginInterface& i)
{
    return i.hash();
}

namespace kv
{

class LoginMob : public Mob
{
public:
    DECLARE_SAVEABLE(LoginMob, Mob);
    REGISTER_CLASS_AS(LoginMob);
    LoginMob();

    virtual void AfterWorldCreation() override;

    virtual void MindExit() override;
    virtual void MindEnter() override;
    virtual void GenerateInterfaceForFrame() override;
    virtual void ProcessMessage(const Message& msg) override;

    virtual void Process() override;

    virtual Position GetPosition() const override
    {
        return Position();
    }

    virtual InterfaceBase* GetInterface() override { return &interface_; }

    virtual void CalculateVisible(VisiblePoints* visible_list) const override;
private:
    LoginInterface KV_SAVEABLE(interface_);
};
END_DECLARE(LoginMob);

}
