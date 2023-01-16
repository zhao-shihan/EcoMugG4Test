#include "Action/ActionInitialization.hxx"

#include "Action/PrimaryGeneratorAction.hxx"
#include "Action/RunAction.hxx"

namespace EcoMugG4Test::Action {

void ActionInitialization::Build() const {
    SetUserAction(new PrimaryGeneratorAction);
    SetUserAction(new RunAction);
}

} // namespace EcoMugG4Test::Action
