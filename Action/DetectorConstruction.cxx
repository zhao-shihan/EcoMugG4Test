#include "Action/DetectorConstruction.hxx"

#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4Orb.hh"
#include "G4PhysicalConstants.hh"
#include "G4PVPlacement.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

#include "SD/BallSD.hxx"

namespace EcoMugG4Test::Action {

G4VPhysicalVolume* DetectorConstruction::Construct() {
    const auto checkOverlaps = true;
    const auto nist = G4NistManager::Instance();

    const auto solidWorld = new G4Box("World",
                                      1 * m,
                                      1 * m,
                                      1 * m);
    const auto logicWorld = new G4LogicalVolume(solidWorld,
                                                nist->FindOrBuildMaterial("G4_AIR"),
                                                "World");
    const auto physicalWorld = new G4PVPlacement({},
                                                 logicWorld,
                                                 "World",
                                                 nullptr,
                                                 false,
                                                 0,
                                                 checkOverlaps);

    const auto solidBall = new G4Orb("Ball",
                                     10 * cm);
    const auto logicBall = new G4LogicalVolume(solidBall,
                                               nist->FindOrBuildMaterial("G4_WATER"),
                                               "Ball");
    const auto physBall = new G4PVPlacement({},
                                            logicBall,
                                            "Ball",
                                            logicWorld,
                                            false,
                                            0,
                                            checkOverlaps);

    return physicalWorld;
}

void DetectorConstruction::ConstructSDandField() {
    const auto ballSD = new SD::BallSD("BallSD");
    G4SDManager::GetSDMpointer()->AddNewDetector(ballSD);
    SetSensitiveDetector("Ball", ballSD);
}

} // namespace EcoMugG4Test::Action
