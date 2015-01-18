#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"

#include "TMVAGui.C"

#if not defined(__CINT__) || defined(__MAKECINT__)
// needs to be included when makecint runs (ACLIC)
#include "TMVA/Factory.h"
#include "TMVA/Tools.h"
#endif

void Train( TString myMethodList = "" ){

	// This loads the library
	TMVA::Tools::Instance();

	std::cout << std::endl;
	std::cout << "==> Start TMVAClassification" << std::endl;

	// Create a ROOT output file where TMVA will store ntuples, histograms, etc.
	TString outfileName( "TMVA.root" );
	TFile* outputFile = TFile::Open( outfileName, "RECREATE" );
	
	// Create a factory object to interact with any type of Machine Learning method
	TMVA::Factory *factory = new TMVA::Factory( "TMVAClassification", outputFile,	"!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D:AnalysisType=Classification" );
	
	
	//Describe which variables the ML methods will use:
	
	
	//factory->AddVariable( "myvar1 := var1+var2", 'F' );
	//factory->AddVariable( "var3", "Variable 3", "units", 'F' );

	factory->AddVariable( "Jet.PT", 'F' );	
	factory->AddVariable( "Jet.Eta", 'F' );
	factory->AddVariable( "Jet.Phi" , 'F' );
	factory->AddVariable( "Jet.Mass", 'F' );
	factory->AddVariable( "Jet.Ntrk", 'F' );
	factory->AddVariable( "Jet.EhadOverEem", 'F' );

	factory->AddVariable( "MissingET.Phi", 'F' );
	factory->AddVariable( "MissingET.MET", 'F' );
	
	//Incorporating knowledge of physics:
	//factory->AddVariable( "myvar1 := MissingET.MET/sqrt(Jet.PT)", 'F' );
	//factory->AddVariable( "myvar2 := MissingET.Phi - Jet.Phi", 'F' );
	
	
	//Turn Madgraph pgs event files in to ROOT TTrees
	TString signalfname = "~/seminar/signalulul/Events/run_01/tag_1_pgs_events.root";
	TString bgfname = "~/seminar/bgwj/Events/run_02/tag_1_pgs_events.root";
	gSystem->Load("~/MG5_aMC_v2_2_2/ExRootAnalysis/libExRootAnalysis.so");
	
	TFile *signalinput = TFile::Open( signalfname );
	TFile *bginput = TFile::Open( bgfname );
	
	TTree *signal     = (TTree*)signalinput->Get("LHCO;1");
	TTree *background = (TTree*)bginput->Get("LHCO;1");

	//Add Signal and Background TTrees with global weights set to 1
	Double_t signalWeight     = 1.0;
	Double_t backgroundWeight = 1.0;
	factory->AddSignalTree( signal, signalWeight);
	factory->AddBackgroundTree( background, backgroundWeight );

	// Apply cut to Background tree since a lower limit for squark production is known
	TCut mycuts = "MissingET.MET>100"; 
	TCut mycutb = "MissingET.MET>100";

	// Tell the factory how to use the training and testing events
	factory->PrepareTrainingAndTestTree( mycuts, mycutb, "nTrain_Signal=0:nTrain_Background=0:SplitMode=Random:NormMode=NumEvents:!V" );

	// ---- Book MVA methods
	// Please lookup the various method configuration options at http://tmva.sourceforge.net/optionRef.html
	
	
	//1-Layer variations:
	factory->BookMethod( TMVA::Types::kMLP, "1Layer5Nodes", 	"NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=5:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "1Layer10Nodes",	"NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=10:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "1Layer15Nodes", 	"NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=15:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "1Layer20Nodes", 	"NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=20:TestRate=5:!UseRegulator" );
	
	//multi layer variations:
	factory->BookMethod( TMVA::Types::kMLP, "1Layers8NodesEach", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=N:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "2Layers8NodesEach", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=N,N:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers8NodesEach", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=N,N,N:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "4Layers8NodesEach", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=N,N,N,N:TestRate=5:!UseRegulator" );
	
	//distributed variations (15):
	factory->BookMethod( TMVA::Types::kMLP, "3Layers15Decrease", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=7,5,3:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers15Increase", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=3,5,7:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers15Constant", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=5,5,5:TestRate=5:!UseRegulator" );
	
	//distributed variations (24):
	factory->BookMethod( TMVA::Types::kMLP, "3Layers24Decrease", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=11,8,5:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers24Increase", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=5,8,11:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers24Constant", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=8,8,8:TestRate=5:!UseRegulator" );
	
	//distributed variations (33):
	factory->BookMethod( TMVA::Types::kMLP, "3Layers33Decrease", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=14,11,8:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers33Increase", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=8,11,14:TestRate=5:!UseRegulator" );
	factory->BookMethod( TMVA::Types::kMLP, "3Layers33Constant", "NeuronType=sigmoid:VarTransform=N:NCycles=600:HiddenLayers=11,11,11:TestRate=5:!UseRegulator" );
	
	
	// factory->OptimizeAllMethods("SigEffAt001","Scan");
	factory->OptimizeAllMethods("ROCIntegral","FitGA");

	// --------------------------------------------------------------------------------------------------

	// Train MVAs using the set of training events
	factory->TrainAllMethods();

	// ---- Evaluate all MVAs using the set of test events
	factory->TestAllMethods();

	// ----- Evaluate and compare performance of all configured MVAs
	factory->EvaluateAllMethods();

	// --------------------------------------------------------------

	// Save the output
	outputFile->Close();

	std::cout << "==> Wrote root file: " << outputFile->GetName() << std::endl;
	std::cout << "==> TMVAClassification is done!" << std::endl;

	delete factory;

	// Launch the GUI for the root macros
	//if (!gROOT->IsBatch()) TMVAGui( outfileName );
}
