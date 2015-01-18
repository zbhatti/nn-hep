      FUNCTION GET_COLOR(IPDG)
      IMPLICIT NONE
      INTEGER GET_COLOR, IPDG

      IF(IPDG.EQ.-2000002)THEN
        GET_COLOR=-3
        RETURN
      ELSE IF(IPDG.EQ.-1000002)THEN
        GET_COLOR=-3
        RETURN
      ELSE IF(IPDG.EQ.-2)THEN
        GET_COLOR=-3
        RETURN
      ELSE IF(IPDG.EQ.2)THEN
        GET_COLOR=3
        RETURN
      ELSE IF(IPDG.EQ.21)THEN
        GET_COLOR=8
        RETURN
      ELSE IF(IPDG.EQ.1000002)THEN
        GET_COLOR=3
        RETURN
      ELSE IF(IPDG.EQ.1000021)THEN
        GET_COLOR=8
        RETURN
      ELSE IF(IPDG.EQ.1000022)THEN
        GET_COLOR=1
        RETURN
      ELSE IF(IPDG.EQ.2000002)THEN
        GET_COLOR=3
        RETURN
      ELSE IF(IPDG.EQ.7)THEN
C       This is dummy particle used in multiparticle vertices
        GET_COLOR=2
        RETURN
      ELSE
        WRITE(*,*)'Error: No color given for pdg ',IPDG
        GET_COLOR=0
        RETURN
      ENDIF
      END

