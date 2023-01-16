#pragma once

#include "G4VUserPrimaryGeneratorAction.hh"

#include "Generator/CosmicRayMuon.hxx"

namespace EcoMugG4Test::Action {

class PrimaryGeneratorAction final : public G4VUserPrimaryGeneratorAction {
public:
    void GeneratePrimaries(G4Event* event) override;

private:
    Generator::CosmicRayMuon fCosmicRayMuonGenerator;
};

} // namespace EcoMugG4Test::Action
