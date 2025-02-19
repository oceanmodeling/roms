!!
      SUBROUTINE ana_tclima (ng, tile, model)
!
!! git $Id$
!!======================================================================
!! Copyright (c) 2002-2024 The ROMS/TOMS Group                         !
!!   Licensed under a MIT/X style license                              !
!!   See License_ROMS.md                                               !
!=======================================================================
!                                                                      !
!  This routine sets analytical tracer climatology fields.             !
!                                                                      !
!=======================================================================
!
      USE mod_param
      USE mod_ncparam
!
! Imported variable declarations.
!
      integer, intent(in) :: ng, tile, model
!
!  Local variable declarations.
!
      character (len=*), parameter :: MyFile =                          &
     &  __FILE__
!
#include "tile.h"
!
      CALL ana_tclima_tile (ng, tile, model,                            &
     &                      LBi, UBi, LBj, UBj,                         &
     &                      IminS, ImaxS, JminS, JmaxS)
!
! Set analytical header file name used.
!
#ifdef DISTRIBUTE
      IF (Lanafile) THEN
#else
      IF (Lanafile.and.(tile.eq.0)) THEN
#endif
        ANANAME(33)=MyFile
      END IF
!
      RETURN
      END SUBROUTINE ana_tclima
!
!***********************************************************************
      SUBROUTINE ana_tclima_tile (ng, tile, model,                      &
     &                            LBi, UBi, LBj, UBj,                   &
     &                            IminS, ImaxS, JminS, JmaxS)
!***********************************************************************
!
      USE mod_param
      USE mod_clima
      USE mod_grid
      USE mod_scalars
!
      USE exchange_3d_mod, ONLY : exchange_r3d_tile
#ifdef DISTRIBUTE
      USE mp_exchange_mod, ONLY : mp_exchange4d
#endif
!
!  Imported variable declarations.
!
      integer, intent(in) :: ng, tile, model
      integer, intent(in) :: LBi, UBi, LBj, UBj
      integer, intent(in) :: IminS, ImaxS, JminS, JmaxS
!
!  Local variable declarations.
!
      integer :: i, itrc, j, k
!
      real(r8) :: val1, val2, val3, val4

#include "set_bounds.h"
!
!-----------------------------------------------------------------------
!  Set tracer climatology.
!-----------------------------------------------------------------------
!
      IF (ANY(LtracerCLM(:,ng)).or.ANY(LnudgeTCLM(:,ng))) THEN
#if defined DOUBLE_GYRE
        val1=(44.69_r8/39.382_r8)**2
        val2=val1*(rho0*100.0_r8/g)*                                    &
     &       (5.0E-5_r8/((42.689_r8/44.69_r8)**2))
        DO k=1,N(ng)
          DO j=JstrT,JendT
            DO i=IstrT,IendT
              val3=T0(ng)+val2*EXP(GRID(ng)%z_r(i,j,k)/100.0_r8)*       &
     &             (10.0_r8-0.4_r8*TANH(GRID(ng)%z_r(i,j,k)/100.0_r8))
              val4=GRID(ng)%yr(i,j)/el(ng)
              CLIMA(ng)%tclm(i,j,k,itemp)=val3-3.0_r8*val4
# ifdef SALINITY
              CLIMA(ng)%tclm(i,j,k,isalt)=34.5_r8-                      &
     &                                    0.001_r8*GRID(ng)%z_r(i,j,k)- &
     &                                    val4
# endif
            END DO
          END DO
        END DO
#else
        DO k=1,N(ng)
          DO j=JstrT,JendT
            DO i=IstrT,IendT
              CLIMA(ng)%tclm(i,j,k,itemp)=???
# ifdef SALINITY
              CLIMA(ng)%tclm(i,j,k,isalt)=???
# endif
            END DO
          END DO
        END DO
#endif
!
!  Exchange boundary data.
!
        IF (EWperiodic(ng).or.NSperiodic(ng)) THEN
          DO itrc=1,NTCLM(ng)
            CALL exchange_r3d_tile (ng, tile,                           &
     &                              LBi, UBi, LBj, UBj, 1, N(ng),       &
     &                              CLIMA(ng)%tclm(:,:,:,itrc))
          END DO
        END IF

#ifdef DISTRIBUTE
        CALL mp_exchange4d (ng, tile, model, 1,                         &
     &                      LBi, UBi, LBj, UBj, 1, N(ng), 1, NTCLM(ng), &
     &                      NghostPoints,                               &
     &                      EWperiodic(ng), NSperiodic(ng),             &
     &                      CLIMA(ng) % tclm)
#endif
      END IF
!
      RETURN
      END SUBROUTINE ana_tclima_tile
