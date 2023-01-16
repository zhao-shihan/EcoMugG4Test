#include "SD/BallSD.hxx"

#include "G4AnalysisManager.hh"
#include "G4Gamma.hh"
#include "G4HCofThisEvent.hh"
#include "G4SDManager.hh"
#include "G4Step.hh"
#include "G4String.hh"

#include <vector>

#include "Hit/BallHit.hxx"

namespace EcoMugG4Test::SD {

BallSD::BallSD(const G4String& name) :
    G4VSensitiveDetector(name) {
    collectionName.insert(name + "HC");
}

void BallSD::Initialize(G4HCofThisEvent* hitsCollectionOfThisEvent) {
    fHitsCollection = new Hit::BallHitsCollection(SensitiveDetectorName, collectionName[0]);
    const auto hitsCollectionID = G4SDManager::GetSDMpointer()->GetCollectionID(fHitsCollection);
    hitsCollectionOfThisEvent->AddHitsCollection(hitsCollectionID, fHitsCollection);
}

G4bool BallSD::ProcessHits(G4Step* step, G4TouchableHistory*) {
    const auto track = step->GetTrack();
    const auto particle = track->GetDefinition();
    if (step->IsFirstStepInVolume() and track->GetCurrentStepNumber() > 1 and   // is coming from outside, and
        (particle->GetPDGCharge() != 0 or particle == G4Gamma::Definition())) { // is a charged particle or gamma
        const auto hit = new Hit::BallHit;
        hit->SetEnergy(track->GetTotalEnergy());
        hit->SetTheta(track->GetMomentum().theta());
        hit->SetPhi(track->GetMomentum().phi());
        hit->SetParticle(particle->GetParticleName());
        fHitsCollection->insert(hit);
        return true;
    } else {
        return false;
    }
}

void BallSD::EndOfEvent(G4HCofThisEvent*) {
    const auto analysisManager = G4AnalysisManager::Instance();
    for (auto&& hit : std::as_const(*fHitsCollection->GetVector())) {
        analysisManager->FillNtupleFColumn(0, hit->GetEnergy());
        analysisManager->FillNtupleFColumn(1, hit->GetTheta());
        analysisManager->FillNtupleFColumn(2, hit->GetPhi());
        analysisManager->FillNtupleSColumn(3, G4String(hit->GetParticle()));
        analysisManager->AddNtupleRow();
    }
}

} // namespace EcoMugG4Test::SD
