#pragma once

#include "G4THitsCollection.hh"
#include "G4VHit.hh"

#include "Utility/FixedString.hxx"

namespace EcoMugG4Test::Hit {

using Utility::ShortString;

class BallHit final : public G4VHit {
public:
    const auto& GetEnergy() const { return fEnergy; }
    const auto& GetTheta() const { return fTheta; }
    const auto& GetPhi() const { return fPhi; }
    const auto& GetParticle() const { return fParticle; }

    void SetEnergy(double val) { fEnergy = val; }
    void SetTheta(double val) { fTheta = val; }
    void SetPhi(double val) { fPhi = val; }
    void SetParticle(auto&& p) { fParticle = std::forward<decltype(p)>(p); }

    bool operator==(const BallHit& rhs) { return this == &rhs; }

private:
    double fEnergy;
    double fTheta;
    double fPhi;
    ShortString fParticle;
};

using BallHitsCollection = G4THitsCollection<BallHit>;

} // namespace EcoMugG4Test::Hit
