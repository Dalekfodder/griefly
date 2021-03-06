#pragma once

#include <QVector>

#include "Idptr.h"
#include "Object.h"

#include "SaveableOperators.h"

namespace kv
{

const int FORCE_UNIT = 100;

class Movable;

class PhysicsEngine : public Object
{
public:
    DECLARE_SAVEABLE(PhysicsEngine, Object);
    REGISTER_CLASS_AS(PhysicsEngine);

    PhysicsEngine();
    void AfterWorldCreation() override;

    void ProcessPhysics();

    void Add(IdPtr<Movable> movable);

    // TODO: base force vector value for movement on 1 tile should more than 1.
    // So force vectors values should be scaled up
    static Dir ProcessForceTick(Vector* force, Dir main, Dir secondary, qint32* error, int friction, int mass);
    static void ApplyForce(Vector* force, Dir* main, Dir* secondary, qint32* error, const Vector& addition);
private:
    void Clear();

    QVector<IdPtr<Movable>> KV_SAVEABLE(under_force_);
    // TODO: remove with Clear function
    QVector<IdPtr<Movable>> KV_SAVEABLE(to_add_);
};
END_DECLARE(PhysicsEngine);

}
