#pragma once

#include "G4VUserDetectorConstruction.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

namespace EcoMugG4Test::Action {

class DetectorConstruction final : public G4VUserDetectorConstruction {
public:
    G4VPhysicalVolume* Construct() override;
    void ConstructSDandField() override;
};

} // namespace EcoMugG4Test::Action
