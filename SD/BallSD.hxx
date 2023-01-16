#pragma once

#include "G4VSensitiveDetector.hh"

#include "Hit/BallHit.hxx"

namespace EcoMugG4Test::SD {

class BallSD final : public G4VSensitiveDetector {
public:
    BallSD(const G4String& name);

    void Initialize(G4HCofThisEvent* hitCollection) override;
    G4bool ProcessHits(G4Step* step, G4TouchableHistory*) override;
    void EndOfEvent(G4HCofThisEvent*) override;

private:
    Hit::BallHitsCollection* fHitsCollection;
};

} // namespace EcoMugG4Test::SD
