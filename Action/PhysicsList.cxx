#include "Action/PhysicsList.hxx"

#include "G4DecayPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4IonPhysics.hh"
#include "G4NeutronTrackingCut.hh"
#include "G4StoppingPhysics.hh"

namespace EcoMugG4Test::Action {

PhysicsList::PhysicsList() :
    G4VModularPhysicsList() {
    RegisterPhysics(new G4EmStandardPhysics_option4());
    RegisterPhysics(new G4EmExtraPhysics());
    RegisterPhysics(new G4DecayPhysics());
    RegisterPhysics(new G4HadronElasticPhysics());
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
    RegisterPhysics(new G4StoppingPhysics());
    RegisterPhysics(new G4IonPhysics());
    RegisterPhysics(new G4NeutronTrackingCut());
}

} // namespace EcoMugG4Test::Action
