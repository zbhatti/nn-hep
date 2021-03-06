// Class: ReadMLP1-BP
// Automatically generated by MethodBase::MakeClass
//

/* configuration options =====================================================

#GEN -*-*-*-*-*-*-*-*-*-*-*- general info -*-*-*-*-*-*-*-*-*-*-*-

Method         : MLP::MLP1-BP
TMVA Release   : 4.2.0         [262656]
ROOT Release   : 5.34/18       [336402]
Creator        : zxb0111
Date           : Tue Dec  2 16:55:01 2014
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
TrainingMethod: "BP" [Train with Back-Propagation (BP), BFGS Algorithm (BFGS), or Genetic Algorithm (GA - slower and worse)]
TestRate: "5" [Test for overtraining performed at each #th epochs]
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
BPMode: "sequential" [Back-propagation learning mode: sequential or batch]
BatchSize: "-1" [Batch size: number of events/batch, only set if in Batch Mode, -1 for BatchSize=number_of_events]
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

class ReadMLP1-BP : public IClassifierReader {

 public:

   // constructor
   ReadMLP1-BP( std::vector<std::string>& theInputVars ) 
      : IClassifierReader(),
        fClassName( "ReadMLP1-BP" ),
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
   virtual ~ReadMLP1-BP() {
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

inline void ReadMLP1-BP::Initialize()
{
   // build network structure
   fLayers = 3;
   fLayerSize[0] = 9; fWeights[0] = new double[9]; 
   fLayerSize[1] = 16; fWeights[1] = new double[16]; 
   fLayerSize[2] = 1; fWeights[2] = new double[1]; 
   // weight matrix from layer 0 to 1
   fWeightMatrix0to1[0][0] = -2.61285764619445;
   fWeightMatrix0to1[1][0] = 6.80452544027257;
   fWeightMatrix0to1[2][0] = 1.77713036923337;
   fWeightMatrix0to1[3][0] = 3.69907652560544;
   fWeightMatrix0to1[4][0] = -1.49020400092931;
   fWeightMatrix0to1[5][0] = 0.135595021490915;
   fWeightMatrix0to1[6][0] = -0.526853067855249;
   fWeightMatrix0to1[7][0] = 0.502552297878323;
   fWeightMatrix0to1[8][0] = -0.839841249292321;
   fWeightMatrix0to1[9][0] = -1.21588301997523;
   fWeightMatrix0to1[10][0] = -0.124620419936796;
   fWeightMatrix0to1[11][0] = 0.254374376132462;
   fWeightMatrix0to1[12][0] = -0.180068353337165;
   fWeightMatrix0to1[13][0] = 2.93153436853215;
   fWeightMatrix0to1[14][0] = 0.27962735019299;
   fWeightMatrix0to1[0][1] = -0.0493955226745396;
   fWeightMatrix0to1[1][1] = -0.290715028739749;
   fWeightMatrix0to1[2][1] = 1.24814251591353;
   fWeightMatrix0to1[3][1] = -9.69923418386564e-05;
   fWeightMatrix0to1[4][1] = -0.145732195224794;
   fWeightMatrix0to1[5][1] = 0.112278086406585;
   fWeightMatrix0to1[6][1] = 0.332172403256343;
   fWeightMatrix0to1[7][1] = 0.0532753455842268;
   fWeightMatrix0to1[8][1] = 0.592310379771899;
   fWeightMatrix0to1[9][1] = -1.12231966260389;
   fWeightMatrix0to1[10][1] = -0.0708513582341122;
   fWeightMatrix0to1[11][1] = -0.0798782657111415;
   fWeightMatrix0to1[12][1] = -1.28965472767849;
   fWeightMatrix0to1[13][1] = -0.3167538132762;
   fWeightMatrix0to1[14][1] = 0.120844997044588;
   fWeightMatrix0to1[0][2] = 0.0142593311705082;
   fWeightMatrix0to1[1][2] = 0.0237986594625322;
   fWeightMatrix0to1[2][2] = -0.398099978357479;
   fWeightMatrix0to1[3][2] = -0.0076579366046078;
   fWeightMatrix0to1[4][2] = -0.0590340665662659;
   fWeightMatrix0to1[5][2] = -4.78929242822527;
   fWeightMatrix0to1[6][2] = -2.09876743273687;
   fWeightMatrix0to1[7][2] = 5.33941505672496;
   fWeightMatrix0to1[8][2] = -0.701164093718342;
   fWeightMatrix0to1[9][2] = 0.760753781757769;
   fWeightMatrix0to1[10][2] = 5.30308228943592;
   fWeightMatrix0to1[11][2] = 5.239525285548;
   fWeightMatrix0to1[12][2] = 0.110398685206574;
   fWeightMatrix0to1[13][2] = 0.0390025883287002;
   fWeightMatrix0to1[14][2] = -0.491292257813927;
   fWeightMatrix0to1[0][3] = -2.6737831856718;
   fWeightMatrix0to1[1][3] = 0.264481372547303;
   fWeightMatrix0to1[2][3] = 0.603407886741988;
   fWeightMatrix0to1[3][3] = 2.07923233744345;
   fWeightMatrix0to1[4][3] = 1.45530236000414;
   fWeightMatrix0to1[5][3] = 0.789271345946847;
   fWeightMatrix0to1[6][3] = 1.57202140092871;
   fWeightMatrix0to1[7][3] = -0.407462485134377;
   fWeightMatrix0to1[8][3] = 2.10691599939877;
   fWeightMatrix0to1[9][3] = -1.89261242650266;
   fWeightMatrix0to1[10][3] = -0.53958720612906;
   fWeightMatrix0to1[11][3] = -0.419217738558011;
   fWeightMatrix0to1[12][3] = 0.116163056681708;
   fWeightMatrix0to1[13][3] = 0.435410488821608;
   fWeightMatrix0to1[14][3] = 1.62022303938305;
   fWeightMatrix0to1[0][4] = 0.64028118087582;
   fWeightMatrix0to1[1][4] = 1.43391606019415;
   fWeightMatrix0to1[2][4] = -0.0838134129655091;
   fWeightMatrix0to1[3][4] = 0.0892095970105599;
   fWeightMatrix0to1[4][4] = 2.79105448950753;
   fWeightMatrix0to1[5][4] = -0.6484194270051;
   fWeightMatrix0to1[6][4] = 0.170235632636581;
   fWeightMatrix0to1[7][4] = 1.04839845255772;
   fWeightMatrix0to1[8][4] = 1.30109260822478;
   fWeightMatrix0to1[9][4] = -0.855525069898258;
   fWeightMatrix0to1[10][4] = -0.628606639112352;
   fWeightMatrix0to1[11][4] = 0.00399740679094185;
   fWeightMatrix0to1[12][4] = 0.95518648455775;
   fWeightMatrix0to1[13][4] = 0.66941538696207;
   fWeightMatrix0to1[14][4] = 2.11931624311402;
   fWeightMatrix0to1[0][5] = -1.18003847050535;
   fWeightMatrix0to1[1][5] = -4.78436161113317;
   fWeightMatrix0to1[2][5] = -0.982956097276205;
   fWeightMatrix0to1[3][5] = 1.20416154696138;
   fWeightMatrix0to1[4][5] = 0.376875949737278;
   fWeightMatrix0to1[5][5] = 2.90734850390367;
   fWeightMatrix0to1[6][5] = 0.913687381469366;
   fWeightMatrix0to1[7][5] = 2.46641421293216;
   fWeightMatrix0to1[8][5] = -0.560393840845417;
   fWeightMatrix0to1[9][5] = -1.14582150810881;
   fWeightMatrix0to1[10][5] = -2.2086045859092;
   fWeightMatrix0to1[11][5] = 1.81383294831895;
   fWeightMatrix0to1[12][5] = 1.99018240699748;
   fWeightMatrix0to1[13][5] = -4.00665198339744;
   fWeightMatrix0to1[14][5] = -0.540266737243392;
   fWeightMatrix0to1[0][6] = 0.0558203175381334;
   fWeightMatrix0to1[1][6] = 0.0860229649546572;
   fWeightMatrix0to1[2][6] = 0.913948598978774;
   fWeightMatrix0to1[3][6] = -0.0327230758717189;
   fWeightMatrix0to1[4][6] = -0.151536569335028;
   fWeightMatrix0to1[5][6] = 5.00121305534665;
   fWeightMatrix0to1[6][6] = -0.302352485061475;
   fWeightMatrix0to1[7][6] = -5.30093853874919;
   fWeightMatrix0to1[8][6] = -0.387431274843531;
   fWeightMatrix0to1[9][6] = 0.408941153676089;
   fWeightMatrix0to1[10][6] = -5.40592061990573;
   fWeightMatrix0to1[11][6] = -5.1701832584492;
   fWeightMatrix0to1[12][6] = 0.094468699553441;
   fWeightMatrix0to1[13][6] = 0.0036962165636013;
   fWeightMatrix0to1[14][6] = -0.913985170248387;
   fWeightMatrix0to1[0][7] = 16.1539483243273;
   fWeightMatrix0to1[1][7] = 3.24570433906525;
   fWeightMatrix0to1[2][7] = -0.105025526327079;
   fWeightMatrix0to1[3][7] = -11.932546287316;
   fWeightMatrix0to1[4][7] = 0.123066727945949;
   fWeightMatrix0to1[5][7] = 1.34572469665713;
   fWeightMatrix0to1[6][7] = 0.278009656076655;
   fWeightMatrix0to1[7][7] = -0.359950814031494;
   fWeightMatrix0to1[8][7] = 1.16493748954523;
   fWeightMatrix0to1[9][7] = -1.2010782641137;
   fWeightMatrix0to1[10][7] = 1.14553236806897;
   fWeightMatrix0to1[11][7] = 1.983131893536;
   fWeightMatrix0to1[12][7] = -1.39218601104191;
   fWeightMatrix0to1[13][7] = 3.38134706190272;
   fWeightMatrix0to1[14][7] = -0.744962715414101;
   fWeightMatrix0to1[0][8] = 7.01492954349722;
   fWeightMatrix0to1[1][8] = 3.92969654814485;
   fWeightMatrix0to1[2][8] = -1.35984020347173;
   fWeightMatrix0to1[3][8] = -3.82911838815593;
   fWeightMatrix0to1[4][8] = 0.498640941712025;
   fWeightMatrix0to1[5][8] = -1.1973634967948;
   fWeightMatrix0to1[6][8] = -0.92430344542581;
   fWeightMatrix0to1[7][8] = -1.7896559575675;
   fWeightMatrix0to1[8][8] = -2.11747750601365;
   fWeightMatrix0to1[9][8] = 1.48006765164494;
   fWeightMatrix0to1[10][8] = 2.38748596777116;
   fWeightMatrix0to1[11][8] = -2.56535777627075;
   fWeightMatrix0to1[12][8] = -1.53111047776051;
   fWeightMatrix0to1[13][8] = 1.08843408353546;
   fWeightMatrix0to1[14][8] = -1.04295582765239;
   // weight matrix from layer 1 to 2
   fWeightMatrix1to2[0][0] = 2.75556566962716;
   fWeightMatrix1to2[0][1] = 0.729170143632788;
   fWeightMatrix1to2[0][2] = -0.454978157351114;
   fWeightMatrix1to2[0][3] = 3.08266718289765;
   fWeightMatrix1to2[0][4] = 0.469020270570811;
   fWeightMatrix1to2[0][5] = 1.16316144263218;
   fWeightMatrix1to2[0][6] = -0.0207554757430235;
   fWeightMatrix1to2[0][7] = -1.24448575354391;
   fWeightMatrix1to2[0][8] = -0.504551991911194;
   fWeightMatrix1to2[0][9] = -0.800138635565971;
   fWeightMatrix1to2[0][10] = 1.07070012174461;
   fWeightMatrix1to2[0][11] = 1.24937513970431;
   fWeightMatrix1to2[0][12] = -1.03856179864591;
   fWeightMatrix1to2[0][13] = -1.12935505547992;
   fWeightMatrix1to2[0][14] = -0.266039174763814;
   fWeightMatrix1to2[0][15] = -1.73756790410952;
}

inline double ReadMLP1-BP::GetMvaValue__( const std::vector<double>& inputValues ) const
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

double ReadMLP1-BP::ActivationFnc(double x) const {
   // sigmoid
   return 1.0/(1.0+exp(-x));
}
double ReadMLP1-BP::OutputActivationFnc(double x) const {
   // identity
   return x;
}
   
// Clean up
inline void ReadMLP1-BP::Clear() 
{
   // clean up the arrays
   for (int lIdx = 0; lIdx < 3; lIdx++) {
      delete[] fWeights[lIdx];
   }
}
   inline double ReadMLP1-BP::GetMvaValue( const std::vector<double>& inputValues ) const
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
inline void ReadMLP1-BP::InitTransform_1()
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
inline void ReadMLP1-BP::Transform_1( std::vector<double>& iv, int cls) const
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
inline void ReadMLP1-BP::InitTransform()
{
   InitTransform_1();
}

//_______________________________________________________________________
inline void ReadMLP1-BP::Transform( std::vector<double>& iv, int sigOrBgd ) const
{
   Transform_1( iv, sigOrBgd );
}
