// Class: ReadMLP1-0
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP1-0
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 5.34/18       [336402]
Creator        : zxb0111
Date           : Tue Dec  2 15:59:44 2014
Host           : Linux localhost.localdomain 2.6.32-431.17.1.el6.x86_64 #1 SMP Wed May 7 14:14:17 CDT 2014 x86_64 x86_64 x86_64 GNU/Linux
Dir            : /home/zxb0111/seminar
Training events: 35264
Analysis type  : [Classification]


#OPT -*-*-*-*-*-*-*-*-*-*-*-*- options -*-*-*-*-*-*-*-*-*-*-*-*-

# Set by User:
NCycles: "600" [Number of training cycles]
HiddenLayers: "N+7" [Specification of hidden layer architecture]
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

class ReadMLP1-0 : public IClassifierReader {

 public:

   // constructor
   ReadMLP1-0( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP1-0" ),
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
   virtual ~ReadMLP1-0() {
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
   int fLayerSize[3];
   double fWeightMatrix0to1[16][9];   // weight matrix from layer 0 to 1
   double fWeightMatrix1to2[1][16];   // weight matrix from layer 1 to 2

   double * fWeights[3];
};

inline void ReadMLP1-0::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 9; fWeights[0] = new double[9]; 
   fLayerSize[1] = 16; fWeights[1] = new double[16]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -0.351160926953439;
   fWeightMatrix0to1[1][0] = 1.96686913951265;
   fWeightMatrix0to1[2][0] = 0.838073844222836;
   fWeightMatrix0to1[3][0] = 1.73494890973416;
   fWeightMatrix0to1[4][0] = -1.98795337592105;
   fWeightMatrix0to1[5][0] = -1.51338622394045;
   fWeightMatrix0to1[6][0] = -0.795438252719383;
   fWeightMatrix0to1[7][0] = 1.97024224886616;
   fWeightMatrix0to1[8][0] = -1.41208915458605;
   fWeightMatrix0to1[9][0] = -1.05272601287076;
   fWeightMatrix0to1[10][0] = -1.72974419396661;
   fWeightMatrix0to1[11][0] = -0.389969894075075;
   fWeightMatrix0to1[12][0] = -1.25139242228769;
   fWeightMatrix0to1[13][0] = -0.439973082307888;
   fWeightMatrix0to1[14][0] = -0.622250980051811;
   fWeightMatrix0to1[0][1] = 0.679370172544213;
   fWeightMatrix0to1[1][1] = -0.422699479320527;
   fWeightMatrix0to1[2][1] = 1.74234826281439;
   fWeightMatrix0to1[3][1] = 0.155180347303441;
   fWeightMatrix0to1[4][1] = 1.38330595548006;
   fWeightMatrix0to1[5][1] = -0.32595373763023;
   fWeightMatrix0to1[6][1] = -0.746805837632146;
   fWeightMatrix0to1[7][1] = 0.734173473326397;
   fWeightMatrix0to1[8][1] = 0.0982671896294874;
   fWeightMatrix0to1[9][1] = -1.18247420611917;
   fWeightMatrix0to1[10][1] = -0.23253465281767;
   fWeightMatrix0to1[11][1] = 1.52160584616736;
   fWeightMatrix0to1[12][1] = -1.08193346362006;
   fWeightMatrix0to1[13][1] = -1.89024196336965;
   fWeightMatrix0to1[14][1] = 0.136949240681914;
   fWeightMatrix0to1[0][2] = 0.574884699324088;
   fWeightMatrix0to1[1][2] = 1.50998626692243;
   fWeightMatrix0to1[2][2] = -0.232687849274172;
   fWeightMatrix0to1[3][2] = -0.183444394126411;
   fWeightMatrix0to1[4][2] = 0.111776742687658;
   fWeightMatrix0to1[5][2] = -0.425165050170828;
   fWeightMatrix0to1[6][2] = -1.45218020829956;
   fWeightMatrix0to1[7][2] = 1.83438678652398;
   fWeightMatrix0to1[8][2] = -1.19682258690123;
   fWeightMatrix0to1[9][2] = 1.11754370893974;
   fWeightMatrix0to1[10][2] = 1.11598988280665;
   fWeightMatrix0to1[11][2] = 0.792124850216237;
   fWeightMatrix0to1[12][2] = 1.87798523894436;
   fWeightMatrix0to1[13][2] = 1.22380596035309;
   fWeightMatrix0to1[14][2] = -0.761135820980232;
   fWeightMatrix0to1[0][3] = -1.67261684094229;
   fWeightMatrix0to1[1][3] = 0.717328009562465;
   fWeightMatrix0to1[2][3] = 0.0453434885387944;
   fWeightMatrix0to1[3][3] = 1.5061783598372;
   fWeightMatrix0to1[4][3] = 1.4530823646442;
   fWeightMatrix0to1[5][3] = 1.52487002448988;
   fWeightMatrix0to1[6][3] = 1.30942948063451;
   fWeightMatrix0to1[7][3] = -1.66255570874634;
   fWeightMatrix0to1[8][3] = 1.32078948031267;
   fWeightMatrix0to1[9][3] = -1.83928281033031;
   fWeightMatrix0to1[10][3] = -1.0323593724274;
   fWeightMatrix0to1[11][3] = -1.31249178265439;
   fWeightMatrix0to1[12][3] = -1.75791469765507;
   fWeightMatrix0to1[13][3] = 1.5249213083705;
   fWeightMatrix0to1[14][3] = 0.673181437555726;
   fWeightMatrix0to1[0][4] = -1.63739866633201;
   fWeightMatrix0to1[1][4] = 0.338236639867051;
   fWeightMatrix0to1[2][4] = -0.34141115756812;
   fWeightMatrix0to1[3][4] = 0.687220753313706;
   fWeightMatrix0to1[4][4] = 1.83356197189568;
   fWeightMatrix0to1[5][4] = -0.387791356445801;
   fWeightMatrix0to1[6][4] = 0.127523335062394;
   fWeightMatrix0to1[7][4] = -1.21213200729229;
   fWeightMatrix0to1[8][4] = 0.768973419710197;
   fWeightMatrix0to1[9][4] = -0.838001820306666;
   fWeightMatrix0to1[10][4] = -0.831995939138111;
   fWeightMatrix0to1[11][4] = -1.42426353105588;
   fWeightMatrix0to1[12][4] = 0.750115251642834;
   fWeightMatrix0to1[13][4] = 1.14211056898962;
   fWeightMatrix0to1[14][4] = 1.33198784222629;
   fWeightMatrix0to1[0][5] = -0.417776959623517;
   fWeightMatrix0to1[1][5] = -2.00851723707915;
   fWeightMatrix0to1[2][5] = -1.87812821752952;
   fWeightMatrix0to1[3][5] = 0.997246355269131;
   fWeightMatrix0to1[4][5] = 0.46471106678565;
   fWeightMatrix0to1[5][5] = 1.8716769024058;
   fWeightMatrix0to1[6][5] = 0.632255660722928;
   fWeightMatrix0to1[7][5] = 1.00604025357059;
   fWeightMatrix0to1[8][5] = -0.801793932363864;
   fWeightMatrix0to1[9][5] = -0.871339402569123;
   fWeightMatrix0to1[10][5] = -0.371133665416063;
   fWeightMatrix0to1[11][5] = 1.15590101865285;
   fWeightMatrix0to1[12][5] = -1.10449023340537;
   fWeightMatrix0to1[13][5] = -1.56978780069504;
   fWeightMatrix0to1[14][5] = -1.71945395168933;
   fWeightMatrix0to1[0][6] = -0.10611073938221;
   fWeightMatrix0to1[1][6] = 0.023848784608333;
   fWeightMatrix0to1[2][6] = 1.54877411657209;
   fWeightMatrix0to1[3][6] = -1.60427470599766;
   fWeightMatrix0to1[4][6] = -0.714033896251277;
   fWeightMatrix0to1[5][6] = 1.74963937040548;
   fWeightMatrix0to1[6][6] = -0.838227894519387;
   fWeightMatrix0to1[7][6] = -1.60041196687883;
   fWeightMatrix0to1[8][6] = -1.48815297952144;
   fWeightMatrix0to1[9][6] = 0.0967279395445047;
   fWeightMatrix0to1[10][6] = -1.83815810993482;
   fWeightMatrix0to1[11][6] = -1.60646381057906;
   fWeightMatrix0to1[12][6] = 0.713498159847208;
   fWeightMatrix0to1[13][6] = 1.64934954287423;
   fWeightMatrix0to1[14][6] = -1.13749472104968;
   fWeightMatrix0to1[0][7] = 1.63435026046907;
   fWeightMatrix0to1[1][7] = -0.935013396480964;
   fWeightMatrix0to1[2][7] = -0.859985730333458;
   fWeightMatrix0to1[3][7] = -0.0298938105450059;
   fWeightMatrix0to1[4][7] = 0.368852137011579;
   fWeightMatrix0to1[5][7] = -1.78889148884574;
   fWeightMatrix0to1[6][7] = 0.261491193550662;
   fWeightMatrix0to1[7][7] = 0.262055416221057;
   fWeightMatrix0to1[8][7] = 0.454809663996504;
   fWeightMatrix0to1[9][7] = -1.41090255289617;
   fWeightMatrix0to1[10][7] = 1.74295733376404;
   fWeightMatrix0to1[11][7] = 0.390962440341438;
   fWeightMatrix0to1[12][7] = -0.953299759858003;
   fWeightMatrix0to1[13][7] = 0.803430975861545;
   fWeightMatrix0to1[14][7] = -1.07676430575644;
   fWeightMatrix0to1[0][8] = -1.52438284623605;
   fWeightMatrix0to1[1][8] = 0.215223948228749;
   fWeightMatrix0to1[2][8] = -0.327630546946163;
   fWeightMatrix0to1[3][8] = 1.80253178747279;
   fWeightMatrix0to1[4][8] = 0.806682973710949;
   fWeightMatrix0to1[5][8] = 0.0554257883477178;
   fWeightMatrix0to1[6][8] = -0.333257650705487;
   fWeightMatrix0to1[7][8] = 0.150175474395722;
   fWeightMatrix0to1[8][8] = -1.80434824555244;
   fWeightMatrix0to1[9][8] = 1.05514486023047;
   fWeightMatrix0to1[10][8] = 0.299286049239333;
   fWeightMatrix0to1[11][8] = -1.81813400565038;
   fWeightMatrix0to1[12][8] = 0.648356881718378;
   fWeightMatrix0to1[13][8] = -1.45750881953823;
   fWeightMatrix0to1[14][8] = 0.0722678218208597;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = 1.23365519272338;
   fWeightMatrix1to2[0][1] = 1.78356358033946;
   fWeightMatrix1to2[0][2] = -1.60572444897785;
   fWeightMatrix1to2[0][3] = 0.361633561803088;
   fWeightMatrix1to2[0][4] = 1.52092807921628;
   fWeightMatrix1to2[0][5] = 1.77935817510086;
   fWeightMatrix1to2[0][6] = 0.241331279148868;
   fWeightMatrix1to2[0][7] = -1.59018726733399;
   fWeightMatrix1to2[0][8] = -0.177364972517847;
   fWeightMatrix1to2[0][9] = -1.23614732783114;
   fWeightMatrix1to2[0][10] = 1.59694914136171;
   fWeightMatrix1to2[0][11] = 1.09224344246692;
   fWeightMatrix1to2[0][12] = -0.299522911345128;
   fWeightMatrix1to2[0][13] = -0.329888919443843;
   fWeightMatrix1to2[0][14] = 0.276937644712861;
   fWeightMatrix1to2[0][15] = -1.12626533685789;
}

inline double ReadMLP1-0::GetMvaValue__( const std::vector<double>& inputValues ) const
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
   for (int o=0; o<fLayerSize[2]; o++) {
      for (int i=0; i<fLayerSize[1]; i++) {
         double inputVal = fWeightMatrix1to2[o][i] * fWeights[1][i];
         fWeights[2][o] += inputVal;
      }
      fWeights[2][o] = OutputActivationFnc(fWeights[2][o]);
   }

   return fWeights[2][0];
}

double ReadMLP1-0::ActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
double ReadMLP1-0::OutputActivationFnc(double x) const {
   // identity
   return x;
}
   
// Clean up
inline void ReadMLP1-0::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP1-0::GetMvaValue( const std::vector<double>& inputValues ) const
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
inline void ReadMLP1-0::InitTransform_1()
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
inline void ReadMLP1-0::Transform_1( std::vector<double>& iv, int cls) const
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
inline void ReadMLP1-0::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP1-0::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
