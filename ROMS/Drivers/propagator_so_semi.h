      MODULE propagator_mod
!
!git $Id$
!================================================== Hernan G. Arango ===
!  Copyright (c) 2002-2024 The ROMS/TOMS Group       Andrew M. Moore   !
!    Licensed under a MIT/X style license                              !
!    See License_ROMS.md                                               !
!=======================================================================
!                                                                      !
!  Stochastic Optimals, Seminorm Estimation:                           !
!                                                                      !
!  This routine is used during the computation of the eigenvectors of  !
!  the stochastic optimals operator  with respect the seminorm of the  !
!  chosen functional.                                                  !
!                                                                      !
!   Reference:                                                         !
!                                                                      !
!     Moore, A.M. et al., 2004: A comprehensive ocean prediction and   !
!       analysis system based on the tangent linear and adjoint of a   !
!       regional ocean model, Ocean Modelling, 7, 227-258.             !
!                                                                      !
!=======================================================================
!
      USE mod_kinds
!
      implicit none
!
      PRIVATE
      PUBLIC  :: propagator_so_semi
!
      CONTAINS
!
!***********************************************************************
      SUBROUTINE propagator_so_semi (RunInterval, state, ad_state)
!***********************************************************************
!
      USE mod_param
      USE mod_parallel
      USE mod_iounits
      USE mod_ocean
      USE mod_scalars
      USE mod_stepping
!
#ifdef SO_SEMI_WHITE
      USE packing_mod, ONLY : so_semi_white
#else
      USE packing_mod, ONLY : so_semi_red
#endif
      USE strings_mod, ONLY : FoundError
!
!  Imported variable declarations.
!
      real(dp), intent(in) :: RunInterval
!
      TYPE (T_GST), intent(in) :: state(Ngrids)
      TYPE (T_GST), intent(inout) :: ad_state(Ngrids)
!
!  Local variable declarations.
!
      logical, save :: FirstPass = .TRUE.
!
      integer :: ng, tile
!
      character (len=*), parameter :: MyFile =                          &
     &  __FILE__
!
!=======================================================================
!  Backward integration of adjoint model forced with the seminorm of
!  the chosen functional. The adjoint model is run only only once in
!  the first iteration.
!=======================================================================
!
      Nrun=Nrun+1
      DO ng=1,Ngrids
        SOrec(ng)=0
      END DO
!
      FIRST_PASS : IF (FirstPass) THEN
        FirstPass=.FALSE.
!
!  Initialize the adjoint model always from rest.
!
        DO ng=1,Ngrids
          CALL ad_initial (ng)
          IF (FoundError(exit_flag, NoError, __LINE__, MyFile)) RETURN
        END DO
!
!  Activate adjoint output.
!
        DO ng=1,Ngrids
          LdefADJ(ng)=.TRUE.
          LwrtADJ(ng)=.TRUE.
          LcycleADJ(ng)=.FALSE.
        END DO
!
!  Time-step adjoint model forced with chosen functional at initial
!  time only.
!
        DO ng=1,Ngrids
          IF (Master) THEN
            WRITE (stdout,10) 'AD', ng, ntstart(ng), ntend(ng)
          END IF
          DstrS(ng)=tdays(ng)
          DendS(ng)=DstrS(ng)
        END DO

#ifdef SOLVE3D
        CALL ad_main3d (RunInterval)
#else
        CALL ad_main2d (RunInterval)
#endif
        IF (FoundError(exit_flag, NoError, __LINE__, MyFile)) RETURN

      END IF FIRST_PASS
!
!-----------------------------------------------------------------------
!  Compute new packed adjoint state vector containing surface forcing
!  variables.
!-----------------------------------------------------------------------
!
      DO ng=1,Ngrids
        DO tile=first_tile(ng),last_tile(ng),+1
# ifdef SO_SEMI_WHITE
          CALL so_semi_white (ng, tile, Nstr(ng), Nend(ng),             &
     &                        state(ng)%vector,                         &
     &                        ad_state(ng)%vector)
# else
          CALL so_semi_red (ng, tile, Nstr(ng), Nend(ng),               &
     &                      state(ng)%vector,                           &
     &                      ad_state(ng)%vector)
# endif
        END DO
      END DO
!
!-----------------------------------------------------------------------
!  Report iteration and trace or stochastic optimals matrix.
!-----------------------------------------------------------------------
!
      IF (Master) THEN
        DO ng=1,Ngrids
          WRITE (stdout,20) ' PROPAGATOR - Grid: ', ng,                 &
     &                      ',  Iteration: ', Nrun,                     &
     &                      ',  number converged RITZ values: ',        &
     &                      Nconv(ng), 'TRnorm = ', TRnorm(ng)
        END DO
      END IF
!
 10   FORMAT (/,1x,a,1x,'ROMS/TOMS: started time-stepping:',            &
     &        ' (Grid: ',i2.2,' TimeSteps: ',i8.8,' - ',i8.8,')')
 20   FORMAT (/,a,i2.2,a,i3.3,a,i3.3,/,42x,a,1p,e15.8)
!
      RETURN
      END SUBROUTINE propagator_so_semi

      END MODULE propagator_mod
