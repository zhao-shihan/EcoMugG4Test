#include "Generator/CosmicRayMuon.hxx"

#include "G4Event.hh"
#include "G4MuonMinus.hh"
#include "G4MuonPlus.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"

namespace Generator {

CosmicRayMuon::CosmicRayMuon() :
    G4VPrimaryGenerator(),
    fMuonPlus(G4MuonPlus::Definition()),
    fMuonMinus(G4MuonMinus::Definition()),
    fEcoMug() {
    fEcoMug.SetUseHSphere();                     // half-spherical surface generation
    fEcoMug.SetHSphereRadius(1 * m);             // half-sphere radius
    fEcoMug.SetHSphereCenterPosition({0, 0, 0}); // (x,y,z) position of the center of the half-sphere
}

void CosmicRayMuon::GeneratePrimaryVertex(G4Event* event) {
    fEcoMug.Generate();

    std::array<double, 3> p;
    fEcoMug.GetGenerationMomentum(p);
    (p[0] *= GeV, p[1] *= GeV, p[2] *= GeV);
    const auto primaryParticle = fEcoMug.GetCharge() > 0 ?
                                     new G4PrimaryParticle(fMuonPlus, p[0], p[1], p[2]) :
                                     new G4PrimaryParticle(fMuonMinus, p[0], p[1], p[2]);

    const auto& [x, y, z] = fEcoMug.GetGenerationPosition();
    const auto primaryVertex = new G4PrimaryVertex({x, y, z}, 0);
    primaryVertex->SetPrimary(primaryParticle);

    event->AddPrimaryVertex(primaryVertex);
}

} // namespace Generator
