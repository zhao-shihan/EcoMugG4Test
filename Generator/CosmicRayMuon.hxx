#pragma once

#include "G4VPrimaryGenerator.hh"

#include "EcoMug/EcoMug.h"

class G4MuonPlus;
class G4MuonMinus;

namespace Generator {

/// @brief brief description A generator generates surface muon beam.
class CosmicRayMuon final : public G4VPrimaryGenerator {
public:
    CosmicRayMuon();

    void GeneratePrimaryVertex(G4Event* event) override;

private:
    const G4MuonPlus* const fMuonPlus;
    const G4MuonMinus* const fMuonMinus;
    EcoMug fEcoMug;
};

} // namespace Generator
