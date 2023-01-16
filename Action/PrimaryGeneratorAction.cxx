#include "Action/PrimaryGeneratorAction.hxx"

namespace EcoMugG4Test::Action {

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event) {
    for (int i = 0; i < 1000; ++i) {
        fCosmicRayMuonGenerator.GeneratePrimaryVertex(event);
    }
}

} // namespace EcoMugG4Test::Action
