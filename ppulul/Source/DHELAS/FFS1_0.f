C     This File is Automatically generated by ALOHA 
C     The process calculated in this file is: 
C     ProjM(2,1)
C     
      SUBROUTINE FFS1_0(F1, F2, S3, COUP,VERTEX)
      IMPLICIT NONE
      COMPLEX*16 CI
      PARAMETER (CI=(0D0,1D0))
      COMPLEX*16 S3(*)
      COMPLEX*16 TMP0
      COMPLEX*16 F1(*)
      COMPLEX*16 F2(*)
      COMPLEX*16 VERTEX
      COMPLEX*16 COUP
      TMP0 = (F2(3)*F1(3)+F2(4)*F1(4))
      VERTEX = COUP*-CI * TMP0*S3(3)
      END


