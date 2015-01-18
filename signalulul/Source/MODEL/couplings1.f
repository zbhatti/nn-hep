ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
c      written by the UFO converter
ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc

      SUBROUTINE COUP1()

      IMPLICIT NONE

      DOUBLE PRECISION PI, ZERO
      PARAMETER  (PI=3.141592653589793D0)
      PARAMETER  (ZERO=0D0)
      INCLUDE 'input.inc'
      INCLUDE 'coupl.inc'

      INCLUDE 'model_functions.inc'
      GC_237 = (-2.000000D+00*MDL_CW*MDL_EE*MDL_COMPLEXI*MDL_NN1X1
     $ *MDL_RU4X4*MDL_SQRT__2)/(3.000000D+00*(-1.000000D+00+MDL_SW)
     $ *(1.000000D+00+MDL_SW))
      GC_414 = (MDL_CW*MDL_EE*MDL_COMPLEXI*MDL_RU2X2*MDL_CONJG__NN1X1)
     $ /(3.000000D+00*(-1.000000D+00+MDL_SW)*(1.000000D+00+MDL_SW)
     $ *MDL_SQRT__2)+(MDL_EE*MDL_COMPLEXI*MDL_RU2X2*MDL_CONJG__NN1X2)
     $ /((-1.000000D+00+MDL_SW)*MDL_SW*(1.000000D+00+MDL_SW)*MDL_SQRT__
     $ 2)-(MDL_EE*MDL_COMPLEXI*MDL_RU2X2*MDL_SW*MDL_CONJG__NN1X2)/((
     $ -1.000000D+00+MDL_SW)*(1.000000D+00+MDL_SW)*MDL_SQRT__2)
      END
