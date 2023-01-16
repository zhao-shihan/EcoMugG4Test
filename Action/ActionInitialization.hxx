#pragma once

#include "G4VUserActionInitialization.hh"

namespace EcoMugG4Test::Action {

class ActionInitialization final : public G4VUserActionInitialization {
public:
    void Build() const override;
};

} // namespace EcoMugG4Test::Action
