#include "G4RunManagerFactory.hh"
#include "G4SteppingVerbose.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"

#include "Action/ActionInitialization.hxx"
#include "Action/DetectorConstruction.hxx"
#include "Action/PhysicsList.hxx"

using namespace EcoMugG4Test;

int main(int argc, char** argv) {
    G4int precision = 4;
    G4SteppingVerbose::UseBestUnit(precision);

    const auto runManager = G4RunManagerFactory::CreateRunManager(G4RunManagerType::MT);

    runManager->SetUserInitialization(new Action::DetectorConstruction);
    runManager->SetUserInitialization(new Action::PhysicsList);
    runManager->SetUserInitialization(new Action::ActionInitialization);

    if (argc == 1) {
        G4UIExecutive uiExecutive(argc, argv);
        G4VisExecutive visExecutive;
        visExecutive.Initialize();
        G4UImanager::GetUIpointer()->ApplyCommand("/control/execute init_vis.mac");
        uiExecutive.SessionStart();
    } else {
        G4UImanager::GetUIpointer()->ApplyCommand(G4String("/control/execute ").append(argv[1]));
    }

    delete runManager;
}
