ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc
c      written by the UFO converter
ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc

      SUBROUTINE COUP2()

      IMPLICIT NONE

      DOUBLE PRECISION PI, ZERO
      PARAMETER  (PI=3.141592653589793D0)
      PARAMETER  (ZERO=0D0)
      INCLUDE 'input.inc'
      INCLUDE 'coupl.inc'

      INCLUDE 'model_functions.inc'
      GC_7 = MDL_COMPLEXI*G
      GC_53 = -(MDL_COMPLEXI*G*MDL_I51X22)
      GC_518 = MDL_COMPLEXI*G*MDL_CONJG__RD4X4*MDL_SQRT__2
      GC_587 = -(MDL_COMPLEXI*G*MDL_CONJG__RU2X2*MDL_SQRT__2)
      END
