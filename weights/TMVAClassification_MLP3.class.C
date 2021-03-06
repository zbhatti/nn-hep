// Class: ReadMLP3
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP3
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 5.34/18       [336402]
Creator        : zxb0111
Date           : Tue Dec  2 16:24:38 2014
Host           : Linux localhost.localdomain 2.6.32-431.17.1.el6.x86_64 #1 SMP Wed May 7 14:14:17 CDT 2014 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /home/zxb0111/seminar
Training events: 35264
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N,N,N" [Specification of hidden layer architecture]
NeuronType: "sigmoid" [Neuron activation function type]
VarTransform: "N" [List of variable transformations performed before training, e.g., "D_Background,P_Signal,G,N_AllClasses" for: "Decorrelation, PCA-transformation, Gaussianisation, Normalisation, each for the given class of events ('AllClasses' denotes all events of all classes, if no class indication is given, 'All' is assumed)"]
TestRate: "5" [Test for overtraining performed at each #th epochs]
BPMode: "batch" [Back-propagation learning mode: sequential or batch]
UseRegulator: "False" [Use regulator to avoid over-training]
# Default:
RandomSeed: "1" [Random seed for initial synapse weights (0 means unique seed for each run; default value '1')]
EstimatorType: "MSE" [MSE (Mean Square Estimator) for Gaussian Likelihood or CE(Cross-Entropy) for Bernoulli Likelihood]
NeuronInputType: "sum" [Neuron input function type]
V: "False" [Verbose output (short form of "VerbosityLevel" below - overrides the latter one)]
VerbosityLevel: "Default" [Verbosity level]
H: "False" [Print method-specific help message]
CreateMVAPdfs: "False" [Create PDFs for classifier outputs (signal and background)]
IgnoreNegWeightsInTraining: "False" [Events with negative weights are ignored in the training (but are included for testing and performance evaluation)]
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
LearningRate: "2.000000e-02" [ANN learning rate parameter]
DecayRate: "1.000000e-02" [Decay rate for learning parameter]
EpochMonitoring: "False" [Provide epoch-wise monitoring plots according to TestRate (caution: causes big ROOT output file!)]
Sampling: "1.000000e+00" [Only 'Sampling' (randomly selected) events are trained each epoch]
SamplingEpoch: "1.000000e+00" [Sampling is used for the first 'SamplingEpoch' epochs, afterwards, all events are taken for training]
SamplingImportance: "1.000000e+00" [ The sampling weights of events in epochs which successful (worse estimator than before) are multiplied with SamplingImportance, else they are divided.]
SamplingTraining: "True" [The training sample is sampled]
SamplingTesting: "False" [The testing sample is sampled]
ResetStep: "50" [How often BFGS should reset history]
Tau: "3.000000e+00" [LineSearch "size step"]
BatchSize: "35264" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
ConvergenceImprove: "1.000000e-30" [Minimum improvement which counts as improvement (<0 means automatic convergence check is turned off)]
ConvergenceTests: "-1" [Number of steps (without improvement) required for convergence (<0 means automatic convergence check is turned off)]
UpdateLimit: "10000" [Maximum times of regulator update]
CalculateErrors: "False" [Calculates inverse Hessian matrix at the end of the training to be able to calculate the uncertainties of an MVA value]
WeightRange: "1.000000e+00" [Take the events for the estimator calculations from small deviations from the desired value to large deviations only over the weight range]
##


#VAR -*-*-*-*-*-*-*-*-*-*-*-* variables *-*-*-*-*-*-*-*-*-*-*-*-

NVar 8
Jet.PT                        Jet.PT                        Jet.PT                        Jet.PT                                                          'F'    [4.73000001907,2147.32006836]
Jet.Eta                       Jet.Eta                       Jet.Eta                       Jet.Eta                                                         'F'    [-3.99399995804,3.99799990654]
Jet.Phi                       Jet.Phi                       Jet.Phi                       Jet.Phi                                                         'F'    [0,6.28299999237]
Jet.Mass                      Jet.Mass                      Jet.Mass                      Jet.Mass                                                        'F'    [0,251.460006714]
Jet.Ntrk                      Jet.Ntrk                      Jet.Ntrk                      Jet.Ntrk                                                        'F'    [0,77]
Jet.EhadOverEem               Jet.EhadOverEem               Jet.EhadOverEem               Jet.EhadOverEem                                                 'F'    [0,999]
MissingET.Phi                 MissingET.Phi                 MissingET.Phi                 MissingET.Phi                                                   'F'    [0,6.28299999237]
MissingET.MET                 MissingET.MET                 MissingET.MET                 MissingET.MET                                                   'F'    [3.57999992371,1585.47998047]
NSpec 0


============================================================================ */

#include <vector>
#include <cmath>
#include <string>
#include <iostream>

#ifndef IClassifierReader__def
#define IClassifierReader__def

class IClassifierReader {

 public:

   // constructor
   IClassifierReader() : fStatusIsClean( true ) {}
   virtual ~IClassifierReader() {}

   // return classifier response
   virtual double GetMvaValue( const std::vector<double>& inputValues ) const = 0;

   // returns classifier status
   bool IsStatusClean() const { return fStatusIsClean; }

 protected:

   bool fStatusIsClean;
};

#endif

class ReadMLP3 : public IClassifierReader {

 public:

   // constructor
   ReadMLP3( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP3" ),
        fNvars( 8 ),
        fIsNormalised( false )
   {      
      // the training input variables
      const char* inputVars[] = { "Jet.PT", "Jet.Eta", "Jet.Phi", "Jet.Mass", "Jet.Ntrk", "Jet.EhadOverEem", "MissingET.Phi", "MissingET.MET" };

      // sanity checks
      if (theInputVars.size() <= 0) {
         std::cout << "Problem in class \"" << fClassName << "\": empty input vector" << std::endl;
         fStatusIsClean = false;
      }

      if (theInputVars.size() != fNvars) {
         std::cout << "Problem in class \"" << fClassName << "\": mismatch in number of input values: "
                   << theInputVars.size() << " != " << fNvars << std::endl;
         fStatusIsClean = false;
      }

      // validate input variables
      for (size_t ivar = 0; ivar < theInputVars.size(); ivar++) {
         if (theInputVars[ivar] != inputVars[ivar]) {
            std::cout << "Problem in class \"" << fClassName << "\": mismatch in input variable names" << std::endl
                      << " for variable [" << ivar << "]: " << theInputVars[ivar].c_str() << " != " << inputVars[ivar] << std::endl;
            fStatusIsClean = false;
         }
      }

      // initialize min and max vectors (for normalisation)
      fVmin[0] = -1;
      fVmax[0] = 1;
      fVmin[1] = -1;
      fVmax[1] = 0.99999988079071;
      fVmin[2] = -1;
      fVmax[2] = 0.99999988079071;
      fVmin[3] = -1;
      fVmax[3] = 0.99999988079071;
      fVmin[4] = -1;
      fVmax[4] = 1;
      fVmin[5] = -1;
      fVmax[5] = 1;
      fVmin[6] = -1;
      fVmax[6] = 0.99999988079071;
      fVmin[7] = -1;
      fVmax[7] = 1;

      // initialize input variable types
      fType[0] = 'F';
      fType[1] = 'F';
      fType[2] = 'F';
      fType[3] = 'F';
      fType[4] = 'F';
      fType[5] = 'F';
      fType[6] = 'F';
      fType[7] = 'F';

      // initialize constants
      Initialize();

      // initialize transformation
      InitTransform();
   }

   // destructor
   virtual ~ReadMLP3() {
      Clear(); // method-specific
   }

   // the classifier response
   // "inputValues" is a vector of input values in the same order as the 
   // variables given to the constructor
   double GetMvaValue( const std::vector<double>& inputValues ) const;

 private:

   // method-specific destructor
   void Clear();

   // input variable transformation

   double fMin_1[3][8];
   double fMax_1[3][8];
   void InitTransform_1();
   void Transform_1( std::vector<double> & iv, int sigOrBgd ) const;
   void InitTransform();
   void Transform( std::vector<double> & iv, int sigOrBgd ) const;

   // common member variables
   const char* fClassName;

   const size_t fNvars;
   size_t GetNvar()           const { return fNvars; }
   char   GetType( int ivar ) const { return fType[ivar]; }

   // normalisation of input variables
   const bool fIsNormalised;
   bool IsNormalised() const { return fIsNormalised; }
   double fVmin[8];
   double fVmax[8];
   double NormVariable( double x, double xmin, double xmax ) const {
      // normalise to output range: [-1, 1]
      return 2*(x - xmin)/(xmax - xmin) - 1.0;
   }

   // type of input variable: 'F' or 'I'
   char   fType[8];

   // initialize internal variables
   void Initialize();
   double GetMvaValue__( const std::vector<double>& inputValues ) const;

   // private members (method specific)

   double ActivationFnc(double x) const;
   double OutputActivationFnc(double x) const;

   int fLayers;
   int fLayerSize[5];
   double fWeightMatrix0to1[9][9];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[9][9];   // weight matrix from layer 1 to 2
   double fWeightMatrix2to3[9][9];   // weight matrix from layer 2 to 3
   double fWeightMatrix3to4[1][9];   // weight matrix from layer 3 to 4

   double * fWeights[5];
};

inline void ReadMLP3::Initialize()
{
   // build network structure
   fLayers = 5;
   fLayerSize[0] = 9; fWeights[0] = new double[9]; 
   fLayerSize[1] = 9; fWeights[1] = new double[9]; 
   fLayerSize[2] = 9; fWeights[2] = new double[9]; 
   fLayerSize[3] = 9; fWeights[3] = new double[9]; 
   fLayerSize[4] = 1; fWeights[4] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -0.333637247347492;
   fWeightMatrix0to1[1][0] = 1.98495788039477;
   fWeightMatrix0to1[2][0] = 0.881614151615151;
   fWeightMatrix0to1[3][0] = 1.73118605529006;
   fWeightMatrix0to1[4][0] = -1.99948435757919;
   fWeightMatrix0to1[5][0] = -1.49041961478416;
   fWeightMatrix0to1[6][0] = -0.797479512446769;
   fWeightMatrix0to1[7][0] = 1.99615934606468;
   fWeightMatrix0to1[0][1] = -1.41224357568171;
   fWeightMatrix0to1[1][1] = -1.05590559657947;
   fWeightMatrix0to1[2][1] = -1.630443434372;
   fWeightMatrix0to1[3][1] = -0.413603108243755;
   fWeightMatrix0to1[4][1] = -1.25495329136326;
   fWeightMatrix0to1[5][1] = -0.44783057645188;
   fWeightMatrix0to1[6][1] = -0.617190160606918;
   fWeightMatrix0to1[7][1] = 0.678971391589929;
   fWeightMatrix0to1[0][2] = -0.412369633010636;
   fWeightMatrix0to1[1][2] = 1.7419043968005;
   fWeightMatrix0to1[2][2] = 0.155454707577123;
   fWeightMatrix0to1[3][2] = 1.38541179527866;
   fWeightMatrix0to1[4][2] = -0.323233452557825;
   fWeightMatrix0to1[5][2] = -0.746995816161549;
   fWeightMatrix0to1[6][2] = 0.74142601998807;
   fWeightMatrix0to1[7][2] = 0.0982051168337946;
   fWeightMatrix0to1[0][3] = -1.18353743943586;
   fWeightMatrix0to1[1][3] = -0.229746144308377;
   fWeightMatrix0to1[2][3] = 1.5125771980716;
   fWeightMatrix0to1[3][3] = -1.08113266357072;
   fWeightMatrix0to1[4][3] = -1.89036488071851;
   fWeightMatrix0to1[5][3] = 0.135176465538892;
   fWeightMatrix0to1[6][3] = 0.675698842667826;
   fWeightMatrix0to1[7][3] = 1.65579475051718;
   fWeightMatrix0to1[0][4] = -0.332142561461638;
   fWeightMatrix0to1[1][4] = -0.174318859292121;
   fWeightMatrix0to1[2][4] = 0.234974922815052;
   fWeightMatrix0to1[3][4] = -0.276584595924201;
   fWeightMatrix0to1[4][4] = -1.43839978788268;
   fWeightMatrix0to1[5][4] = 1.75435618652646;
   fWeightMatrix0to1[6][4] = -1.2129851955663;
   fWeightMatrix0to1[7][4] = 1.11352804985911;
   fWeightMatrix0to1[0][5] = 1.2020915839818;
   fWeightMatrix0to1[1][5] = 0.860513458056415;
   fWeightMatrix0to1[2][5] = 1.87272991560524;
   fWeightMatrix0to1[3][5] = 1.21123877688637;
   fWeightMatrix0to1[4][5] = -0.746146079380773;
   fWeightMatrix0to1[5][5] = -1.63104572054541;
   fWeightMatrix0to1[6][5] = 0.76347968770773;
   fWeightMatrix0to1[7][5] = 0.0724503159443765;
   fWeightMatrix0to1[0][6] = 1.50488884857516;
   fWeightMatrix0to1[1][6] = 1.46047249855969;
   fWeightMatrix0to1[2][6] = 1.57842520893041;
   fWeightMatrix0to1[3][6] = 1.31648019237821;
   fWeightMatrix0to1[4][6] = -1.65988600937636;
   fWeightMatrix0to1[5][6] = 1.31952173353774;
   fWeightMatrix0to1[6][6] = -1.84370397690277;
   fWeightMatrix0to1[7][6] = -0.90785571999851;
   fWeightMatrix0to1[0][7] = -1.32333910177126;
   fWeightMatrix0to1[1][7] = -1.7671324947105;
   fWeightMatrix0to1[2][7] = 1.51343561409565;
   fWeightMatrix0to1[3][7] = 0.683433351116954;
   fWeightMatrix0to1[4][7] = -1.60659742097866;
   fWeightMatrix0to1[5][7] = 0.369693035518771;
   fWeightMatrix0to1[6][7] = -0.322425378094631;
   fWeightMatrix0to1[7][7] = 0.686627379648318;
   fWeightMatrix0to1[0][8] = 1.83245572670446;
   fWeightMatrix0to1[1][8] = -0.349466553368064;
   fWeightMatrix0to1[2][8] = 0.132928639451445;
   fWeightMatrix0to1[3][8] = -1.21003992702942;
   fWeightMatrix0to1[4][8] = 0.767351355110793;
   fWeightMatrix0to1[5][8] = -0.839198972260475;
   fWeightMatrix0to1[6][8] = -0.732024802076461;
   fWeightMatrix0to1[7][8] = -1.4313592548352;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = 0.724698909972647;
   fWeightMatrix1to2[1][0] = 1.15807732114083;
   fWeightMatrix1to2[2][0] = 1.34747594712348;
   fWeightMatrix1to2[3][0] = -0.329993340638636;
   fWeightMatrix1to2[4][0] = -1.97825542437812;
   fWeightMatrix1to2[5][0] = -1.84879622396667;
   fWeightMatrix1to2[6][0] = 0.976901308579612;
   fWeightMatrix1to2[7][0] = 0.464380726299176;
   fWeightMatrix1to2[0][1] = 1.94942529721141;
   fWeightMatrix1to2[1][1] = 0.649973710822361;
   fWeightMatrix1to2[2][1] = 0.995445926933101;
   fWeightMatrix1to2[3][1] = -0.799706826188133;
   fWeightMatrix1to2[4][1] = -0.893648291286861;
   fWeightMatrix1to2[5][1] = -0.211225315359876;
   fWeightMatrix1to2[6][1] = 1.1494110874774;
   fWeightMatrix1to2[7][1] = -1.12128823967731;
   fWeightMatrix1to2[0][2] = -1.58707714269404;
   fWeightMatrix1to2[1][2] = -1.70663928501796;
   fWeightMatrix1to2[2][2] = -0.208496950321623;
   fWeightMatrix1to2[3][2] = -0.123090202338089;
   fWeightMatrix1to2[4][2] = 1.63443269213846;
   fWeightMatrix1to2[5][2] = -1.61532959414158;
   fWeightMatrix1to2[6][2] = -0.825542344296237;
   fWeightMatrix1to2[7][2] = 1.61352422356443;
   fWeightMatrix1to2[0][3] = -0.849359444277605;
   fWeightMatrix1to2[1][3] = -1.52169841530203;
   fWeightMatrix1to2[2][3] = -1.47984527010692;
   fWeightMatrix1to2[3][3] = 0.0995742175347269;
   fWeightMatrix1to2[4][3] = -1.92373276708035;
   fWeightMatrix1to2[5][3] = -1.6651989156721;
   fWeightMatrix1to2[6][3] = 0.714721932036028;
   fWeightMatrix1to2[7][3] = 1.66673114956691;
   fWeightMatrix1to2[0][4] = -1.17546893136276;
   fWeightMatrix1to2[1][4] = 1.66705159481542;
   fWeightMatrix1to2[2][4] = -0.928816158962712;
   fWeightMatrix1to2[3][4] = -0.784104336491293;
   fWeightMatrix1to2[4][4] = -0.086195809535974;
   fWeightMatrix1to2[5][4] = 0.3523023468842;
   fWeightMatrix1to2[6][4] = -1.81067987537371;
   fWeightMatrix1to2[7][4] = 0.231403676095024;
   fWeightMatrix1to2[0][5] = 0.285800506299877;
   fWeightMatrix1to2[1][5] = 0.469017954178786;
   fWeightMatrix1to2[2][5] = -1.40867890173972;
   fWeightMatrix1to2[3][5] = 1.83799125583673;
   fWeightMatrix1to2[4][5] = 0.328756826929315;
   fWeightMatrix1to2[5][5] = -0.948582023910457;
   fWeightMatrix1to2[6][5] = 0.784659620419024;
   fWeightMatrix1to2[7][5] = -1.09418919473992;
   fWeightMatrix1to2[0][6] = -1.60360010560994;
   fWeightMatrix1to2[1][6] = 0.147642097086185;
   fWeightMatrix1to2[2][6] = -0.338334946593163;
   fWeightMatrix1to2[3][6] = 1.80939032005684;
   fWeightMatrix1to2[4][6] = 0.750194224650527;
   fWeightMatrix1to2[5][6] = -0.0195236980818382;
   fWeightMatrix1to2[6][6] = -0.354526056406385;
   fWeightMatrix1to2[7][6] = 0.146418867828543;
   fWeightMatrix1to2[0][7] = -1.8001535599936;
   fWeightMatrix1to2[1][7] = 1.0618657208303;
   fWeightMatrix1to2[2][7] = 0.143539676708699;
   fWeightMatrix1to2[3][7] = -1.8186711698677;
   fWeightMatrix1to2[4][7] = 0.655275513586315;
   fWeightMatrix1to2[5][7] = -1.44018245455836;
   fWeightMatrix1to2[6][7] = 0.0595858295578957;
   fWeightMatrix1to2[7][7] = 1.16968567543011;
   fWeightMatrix1to2[0][8] = 1.75642239167611;
   fWeightMatrix1to2[1][8] = -1.85560013207552;
   fWeightMatrix1to2[2][8] = 0.355180502721041;
   fWeightMatrix1to2[3][8] = 1.55262802408501;
   fWeightMatrix1to2[4][8] = 1.56120575318492;
   fWeightMatrix1to2[5][8] = 0.177872927334208;
   fWeightMatrix1to2[6][8] = -1.47418996279001;
   fWeightMatrix1to2[7][8] = -0.240259468653191;
   // weight matrix from layer 2 to 3
   fWeightMatrix2to3[0][0] = -1.45725051288802;
   fWeightMatrix2to3[1][0] = 1.56641289431562;
   fWeightMatrix2to3[2][0] = 1.20952400135508;
   fWeightMatrix2to3[3][0] = -0.396383238675408;
   fWeightMatrix2to3[4][0] = -0.366957234497109;
   fWeightMatrix2to3[5][0] = 0.160321772510825;
   fWeightMatrix2to3[6][0] = -1.3267859571069;
   fWeightMatrix2to3[7][0] = 0.580478457922837;
   fWeightMatrix2to3[0][1] = 1.69504555118009;
   fWeightMatrix2to3[1][1] = -0.557165067363446;
   fWeightMatrix2to3[2][1] = -0.630214996662135;
   fWeightMatrix2to3[3][1] = 0.382540285353446;
   fWeightMatrix2to3[4][1] = 1.0486856853909;
   fWeightMatrix2to3[5][1] = 0.55842990898348;
   fWeightMatrix2to3[6][1] = 0.916305524839633;
   fWeightMatrix2to3[7][1] = -1.52490932399049;
   fWeightMatrix2to3[0][2] = 1.52388233931418;
   fWeightMatrix2to3[1][2] = 0.759515257691257;
   fWeightMatrix2to3[2][2] = 0.481193749819328;
   fWeightMatrix2to3[3][2] = 0.653483742259291;
   fWeightMatrix2to3[4][2] = 1.03291738564933;
   fWeightMatrix2to3[5][2] = -0.579682387907835;
   fWeightMatrix2to3[6][2] = -0.596668710561667;
   fWeightMatrix2to3[7][2] = 1.03388124137363;
   fWeightMatrix2to3[0][3] = -0.937030831611202;
   fWeightMatrix2to3[1][3] = -0.576463462245404;
   fWeightMatrix2to3[2][3] = 1.55979217304011;
   fWeightMatrix2to3[3][3] = 1.12045891144057;
   fWeightMatrix2to3[4][3] = -0.236922376788879;
   fWeightMatrix2to3[5][3] = 1.53314299081753;
   fWeightMatrix2to3[6][3] = 1.87298047710321;
   fWeightMatrix2to3[7][3] = -1.98692384673017;
   fWeightMatrix2to3[0][4] = 0.644803825172226;
   fWeightMatrix2to3[1][4] = -0.00908315907261414;
   fWeightMatrix2to3[2][4] = 0.474082659771868;
   fWeightMatrix2to3[3][4] = -1.64732748591001;
   fWeightMatrix2to3[4][4] = -1.51389513926734;
   fWeightMatrix2to3[5][4] = 1.1518185557098;
   fWeightMatrix2to3[6][4] = 1.80506997684186;
   fWeightMatrix2to3[7][4] = -1.76152474455766;
   fWeightMatrix2to3[0][5] = -0.20272450577505;
   fWeightMatrix2to3[1][5] = -0.579151735234703;
   fWeightMatrix2to3[2][5] = 0.310113244941663;
   fWeightMatrix2to3[3][5] = 1.7829339761667;
   fWeightMatrix2to3[4][5] = -0.359959912158439;
   fWeightMatrix2to3[5][5] = -0.47967793470477;
   fWeightMatrix2to3[6][5] = -1.04998544866103;
   fWeightMatrix2to3[7][5] = 1.04687649042948;
   fWeightMatrix2to3[0][6] = 1.61036126445275;
   fWeightMatrix2to3[1][6] = 1.08592276960458;
   fWeightMatrix2to3[2][6] = 0.290362799883546;
   fWeightMatrix2to3[3][6] = -0.774086615373471;
   fWeightMatrix2to3[4][6] = -1.97943667164408;
   fWeightMatrix2to3[5][6] = 1.09239836484278;
   fWeightMatrix2to3[6][6] = 0.471206022195878;
   fWeightMatrix2to3[7][6] = -1.39460353554484;
   fWeightMatrix2to3[0][7] = -0.701368632371692;
   fWeightMatrix2to3[1][7] = 0.313192991316923;
   fWeightMatrix2to3[2][7] = 0.0968895682475726;
   fWeightMatrix2to3[3][7] = -1.91271092514299;
   fWeightMatrix2to3[4][7] = 1.56803778457202;
   fWeightMatrix2to3[5][7] = 0.839712067337791;
   fWeightMatrix2to3[6][7] = -0.564686090008601;
   fWeightMatrix2to3[7][7] = -0.133260177206121;
   fWeightMatrix2to3[0][8] = 1.61532456033193;
   fWeightMatrix2to3[1][8] = 1.05544840472994;
   fWeightMatrix2to3[2][8] = 0.46681500136892;
   fWeightMatrix2to3[3][8] = -0.00787893987276997;
   fWeightMatrix2to3[4][8] = -1.87997811426913;
   fWeightMatrix2to3[5][8] = -0.915317994676064;
   fWeightMatrix2to3[6][8] = 1.73302214184782;
   fWeightMatrix2to3[7][8] = 1.2890587924315;
   // weight matrix from layer 3 to 4
   fWeightMatrix3to4[0][0] = 0.501507811689282;
   fWeightMatrix3to4[0][1] = -0.0506638899225405;
   fWeightMatrix3to4[0][2] = 1.70983483490532;
   fWeightMatrix3to4[0][3] = -1.83776251904722;
   fWeightMatrix3to4[0][4] = -1.36260540039368;
   fWeightMatrix3to4[0][5] = -0.360081062667424;
   fWeightMatrix3to4[0][6] = -1.73602569650811;
   fWeightMatrix3to4[0][7] = 0.923665000278058;
   fWeightMatrix3to4[0][8] = 1.43581459970156;
}

inline double ReadMLP3::GetMvaValue__( const std::vector<double>& inputValues ) const
{
   if (inputValues.size() != (unsigned int)fLayerSize[0]-1) {
      std::cout << "Input vector needs to be of size " << fLayerSize[0]-1 << std::endl;
      return 0;
   }

   for (int l=0; l<fLayers; l++)
      for (int i=0; i<fLayerSize[l]; i++) fWeights[l][i]=0;

   for (int l=0; l<fLayers-1; l++)
      fWeights[l][fLayerSize[l]-1]=1;

   for (int i=0; i<fLayerSize[0]-1; i++)
      fWeights[0][i]=inputValues[i];

   // layer 0 to 1
   for (int o=0; o<fLayerSize[1]-1; o++) {
      for (int i=0; i<fLayerSize[0]; i++) {
         double inputVal = fWeightMatrix0to1[o][i] * fWeights[0][i];
         fWeights[1][o] += inputVal;
      }
      fWeights[1][o] = ActivationFnc(fWeights[1][o]);
   }
   // layer 1 to 2
   for (int o=0; o<fLayerSize[2]-1; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = ActivationFnc(fWeights[2][o]);
   }
   // layer 2 to 3
   for (int o=0; o<fLayerSize[3]-1; o++) {
      for (int i=0; i<fLayerSize[2]; i++) {
         double inputVal = fWeightMatrix2to3[o][i] * fWeights[2][i];
         fWeights[3][o] += inputVal;
      }
      fWeights[3][o] = ActivationFnc(fWeights[3][o]);
   }
   // layer 3 to 4
   for (int o=0; o<fLayerSize[4]; o++) {
      for (int i=0; i<fLayerSize[3]; i++) {
         double inputVal = fWeightMatrix3to4[o][i] * fWeights[3][i];
         fWeights[4][o] += inputVal;
      }
      fWeights[4][o] = OutputActivationFnc(fWeights[4][o]);
   }

   return fWeights[4][0];
}

double ReadMLP3::ActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
double ReadMLP3::OutputActivationFnc(double x) const {
   // identity
   return x;
}
   
// Clean up
inline void ReadMLP3::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 5; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP3::GetMvaValue( const std::vector<double>& inputValues ) const
   {
      // classifier response value
      double retval = 0;

      // classifier response, sanity check first
      if (!IsStatusClean()) {
         std::cout << "Problem in class \"" << fClassName << "\": cannot return classifier response"
                   << " because status is dirty" << std::endl;
         retval = 0;
      }
      else {
         if (IsNormalised()) {
            // normalise variables
            std::vector<double> iV;
            iV.reserve(inputValues.size());
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(NormVariable( *varIt, fVmin[ivar], fVmax[ivar] ));
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
         else {
            std::vector<double> iV;
            int ivar = 0;
            for (std::vector<double>::const_iterator varIt = inputValues.begin();
                 varIt != inputValues.end(); varIt++, ivar++) {
               iV.push_back(*varIt);
            }
            Transform( iV, -1 );
            retval = GetMvaValue__( iV );
         }
      }

      return retval;
   }

//_______________________________________________________________________
inline void ReadMLP3::InitTransform_1()
{
   // Normalization transformation, initialisation
   fMin_1[0][0] = 5;
   fMax_1[0][0] = 2147.32006836;
   fMin_1[1][0] = 4.73000001907;
   fMax_1[1][0] = 817.520019531;
   fMin_1[2][0] = 4.73000001907;
   fMax_1[2][0] = 2147.32006836;
   fMin_1[0][1] = -3.98099994659;
   fMax_1[0][1] = 3.99799990654;
   fMin_1[1][1] = -3.99399995804;
   fMax_1[1][1] = 3.99699997902;
   fMin_1[2][1] = -3.99399995804;
   fMax_1[2][1] = 3.99799990654;
   fMin_1[0][2] = 0;
   fMax_1[0][2] = 6.28299999237;
   fMin_1[1][2] = 0;
   fMax_1[1][2] = 6.28299999237;
   fMin_1[2][2] = 0;
   fMax_1[2][2] = 6.28299999237;
   fMin_1[0][3] = 0;
   fMax_1[0][3] = 251.460006714;
   fMin_1[1][3] = 0;
   fMax_1[1][3] = 184.169998169;
   fMin_1[2][3] = 0;
   fMax_1[2][3] = 251.460006714;
   fMin_1[0][4] = 0;
   fMax_1[0][4] = 60;
   fMin_1[1][4] = 0;
   fMax_1[1][4] = 77;
   fMin_1[2][4] = 0;
   fMax_1[2][4] = 77;
   fMin_1[0][5] = 0;
   fMax_1[0][5] = 999;
   fMin_1[1][5] = 0;
   fMax_1[1][5] = 999;
   fMin_1[2][5] = 0;
   fMax_1[2][5] = 999;
   fMin_1[0][6] = 0;
   fMax_1[0][6] = 6.28299999237;
   fMin_1[1][6] = 0.0010000000475;
   fMax_1[1][6] = 6.28200006485;
   fMin_1[2][6] = 0;
   fMax_1[2][6] = 6.28299999237;
   fMin_1[0][7] = 3.57999992371;
   fMax_1[0][7] = 1585.47998047;
   fMin_1[1][7] = 100.010002136;
   fMax_1[1][7] = 662.650024414;
   fMin_1[2][7] = 3.57999992371;
   fMax_1[2][7] = 1585.47998047;
}

//_______________________________________________________________________
inline void ReadMLP3::Transform_1( std::vector<double>& iv, int cls) const
{
   // Normalization transformation
   if (cls < 0 || cls > 2) {
   if (2 > 1 ) cls = 2;
      else cls = 2;
   }
   const int nVar = 8;

   // get indices of used variables

   // define the indices of the variables which are transformed by this transformation
   static std::vector<int> indicesGet;
   static std::vector<int> indicesPut;

   if ( indicesGet.empty() ) { 
      indicesGet.reserve(fNvars);
      indicesGet.push_back( 0);
      indicesGet.push_back( 1);
      indicesGet.push_back( 2);
      indicesGet.push_back( 3);
      indicesGet.push_back( 4);
      indicesGet.push_back( 5);
      indicesGet.push_back( 6);
      indicesGet.push_back( 7);
   } 
   if ( indicesPut.empty() ) { 
      indicesPut.reserve(fNvars);
      indicesPut.push_back( 0);
      indicesPut.push_back( 1);
      indicesPut.push_back( 2);
      indicesPut.push_back( 3);
      indicesPut.push_back( 4);
      indicesPut.push_back( 5);
      indicesPut.push_back( 6);
      indicesPut.push_back( 7);
   } 

   static std::vector<double> dv;
   dv.resize(nVar);
   for (int ivar=0; ivar<nVar; ivar++) dv[ivar] = iv[indicesGet.at(ivar)];
   for (int ivar=0;ivar<8;ivar++) {
      double offset = fMin_1[cls][ivar];
      double scale  = 1.0/(fMax_1[cls][ivar]-fMin_1[cls][ivar]);
      iv[indicesPut.at(ivar)] = (dv[ivar]-offset)*scale * 2 - 1;
   }
}

//_______________________________________________________________________
inline void ReadMLP3::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP3::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
