#include "Action/RunAction.hxx"

#include "G4AnalysisManager.hh"

#include <filesystem>

namespace EcoMugG4Test::Action {

void RunAction::BeginOfRunAction(const G4Run*) {
    const auto analysisManager = G4AnalysisManager::Instance();

    std::filesystem::create_directory("EcoMugG4Test_result");
    analysisManager->OpenFile("EcoMugG4Test_result/spectrum.root");

    analysisManager->CreateNtuple("BallHit", "BallHit");
    analysisManager->CreateNtupleFColumn("energy");
    analysisManager->CreateNtupleFColumn("theta");
    analysisManager->CreateNtupleFColumn("phi");
    analysisManager->CreateNtupleSColumn("particle");
    analysisManager->FinishNtuple();
}

void RunAction::EndOfRunAction(const G4Run*) {
    const auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
}

} // namespace EcoMugG4Test::Action
