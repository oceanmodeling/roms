/*
** git $Id$
*************************************************** Hernan G. Arango ***
** Copyright (c) 2002-2024 The ROMS/TOMS Group                        **
**   Licensed under a MIT/X style license                             **
**   See License_ROMS.md                                              **
************************************************************************
**                                                                    **
**  Assigns metadata indices for the EcoSim bio-optical model         **
**  variables that are used in input and output NetCDF files.         **
**  The metadata information is read from "varinfo.yaml".             **
**                                                                    **
**  This file is included in file "mod_ncparam.F", routine            **
**  "initialize_ncparm".                                              **
**                                                                    **
************************************************************************
*/

/*
**  Model state biological tracers.
*/

          CASE ('idTvar(iNO3_)')
            idTvar(iNO3_)=varid
          CASE ('idTvar(iNH4_)')
            idTvar(iNH4_)=varid
          CASE ('idTvar(iPO4_)')
            idTvar(iPO4_)=varid
          CASE ('idTvar(iFeO_)')
            idTvar(iFeO_)=varid
          CASE ('idTvar(iSiO_)')
            idTvar(iSiO_)=varid
          CASE ('idTvar(iDIC_)')
            idTvar(iDIC_)=varid
          CASE ('idTvar(iBacC)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nbac
              varid=varid+1
              idTvar(iBacC(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iBacF)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nbac
              varid=varid+1
              idTvar(iBacF(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iBacN)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nbac
              varid=varid+1
              idTvar(iBacN(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iBacP)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nbac
              varid=varid+1
              idTvar(iBacP(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iCDMC)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Ndom
              varid=varid+1
              idTvar(iCDMC(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iDOMC)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Ndom
              varid=varid+1
              idTvar(iDOMC(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iDOMN)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Ndom
              varid=varid+1
              idTvar(iDOMN(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iDOMP)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Ndom
              varid=varid+1
              idTvar(iDOMP(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iFecC)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nfec
              varid=varid+1
              idTvar(iFecC(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iFecF)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nfec
              varid=varid+1
              idTvar(iFecF(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iFecN)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nfec
              varid=varid+1
              idTvar(iFecN(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iFecP)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nfec
              varid=varid+1
              idTvar(iFecP(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iFecS)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nfec
              varid=varid+1
              idTvar(iFecS(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iPhyC)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nphy
              varid=varid+1
              idTvar(iPhyC(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iPhyF)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nphy
              varid=varid+1
              idTvar(iPhyF(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iPhyN)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nphy
              varid=varid+1
              idTvar(iPhyN(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iPhyP)')
            load=.FALSE.
            varid=varid-1
            DO i=1,Nphy
              varid=varid+1
              idTvar(iPhyP(i))=varid
              DO ng=1,Ngrids
                Fscale(varid,ng)=scale
                Iinfo(1,varid,ng)=gtype
              END DO
              WRITE (Vname(1,varid),'(a,i1)')                           &
     &              TRIM(ADJUSTL(Vinfo(1))), i
              WRITE (Vname(2,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(2))), i
              WRITE (Vname(3,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(3)))
              WRITE (Vname(4,varid),'(a,1x,i1)')                        &
     &              TRIM(ADJUSTL(Vinfo(4))), i
              WRITE (Vname(5,varid),'(a)')                              &
     &              TRIM(ADJUSTL(Vinfo(5)))
              WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
              CALL StandardName (Vname(6,varid), string,                &
     &                           suffix='_in_sea_water')
            END DO
            varid=varid+1
          CASE ('idTvar(iPhyS)')
            load=.FALSE.
            j=0
            DO i=1,Nphy
              IF (PHY(i).le.2) j=j+1
            END DO
            IF (j.gt.0) varid=varid-1
            DO i=1,Nphy
              IF (PHY(i).le.2) THEN
                varid=varid+1
                idTvar(iPhyS(i))=varid
                DO ng=1,Ngrids
                  Fscale(varid,ng)=scale
                  Iinfo(1,varid,ng)=gtype
                END DO
                WRITE (Vname(1,varid),'(a,i1)')                         &
     &                TRIM(ADJUSTL(Vinfo(1))), i
                WRITE (Vname(2,varid),'(a,1x,i1)')                      &
     &                TRIM(ADJUSTL(Vinfo(2))), i
                WRITE (Vname(3,varid),'(a)')                            &
     &                TRIM(ADJUSTL(Vinfo(3)))
                WRITE (Vname(4,varid),'(a,1x,i1)')                      &
     &                TRIM(ADJUSTL(Vinfo(4))), i
                WRITE (Vname(5,varid),'(a)')                            &
     &                TRIM(ADJUSTL(Vinfo(5)))
                WRITE (string,'(a,i1)') TRIM(ADJUSTL(Vinfo(6))), i
                CALL StandardName (Vname(6,varid), string,              &
     &                             suffix='_in_sea_water')
              END IF
            END DO
            varid=varid+1
          CASE ('idTvar(iPigs)')
            load=.FALSE.
            varid=varid-1
            DO j=1,Npig
              DO i=1,Nphy
                IF (PIG(PHY(i),j).gt.0) THEN
                  varid=varid+1
                  idTvar(iPigs(i,j))=varid
                  DO ng=1,Ngrids
                    Fscale(varid,ng)=scale
                    Iinfo(1,varid,ng)=gtype
                  END DO
                  WRITE (Vname(1,varid),'(a,i1,i1)')                    &
     &                  TRIM(ADJUSTL(Vinfo(1))), i, j
                  WRITE (Vname(2,varid),'(3a)')                         &
     &                  TRIM(PhyName(i)), ', ', TRIM(PigName(j))
                  WRITE (Vname(3,varid),'(a)')                          &
     &                  TRIM(ADJUSTL(Vinfo(3)))
                  WRITE (Vname(4,varid),'(3a)')                         &
     &                  TRIM(PhyName(i)), ', ', TRIM(PigName(j))
                  WRITE (Vname(5,varid),'(a)')                          &
     &                  TRIM(ADJUSTL(Vinfo(5)))
                  WRITE (string,'(4a)') TRIM(ADJUSTL(Vinfo(6))),        &
     &                  TRIM(PigName(j)), '_pigment_by_',               &
     &                  TRIM(PhyName(i))
                  CALL StandardName (Vname(6,varid), string,            &
     &                               suffix='_in_sea_water')
                END IF
              END DO
            END DO
            varid=varid+1

#ifdef DIAGNOSTICS_BIO

/*
**  Biological tracers term diagnostics.
*/
          CASE ('iDbio3(idSpIr)')
            iDbio3(idSpIr)=varid
          CASE ('iDbio4(iddIrr)')
            iDbio4(iddIrr)=varid
          CASE ('iDbio4(idsIrr)')
            iDbio4(idsIrr)=varid
          CASE ('iDbio4(idLatt)')
            iDbio4(idLatt)=varid
          CASE ('iDbio4(idaPHY)')
            iDbio4(idaPHY)=varid
          CASE ('iDbio4(idaDET)')
            iDbio4(idaDET)=varid
          CASE ('iDbio4(idaCDC)')
            iDbio4(idaCDC)=varid
          CASE ('iDbio4(idAcos)')
            iDbio4(idAcos)=varid
          CASE ('iDbio4(idbPHY)')
            iDbio4(idbPHY)=varid
          CASE ('iDbio4(idsPHY)')
            iDbio4(idsPHY)=varid
          CASE ('iDbio4(idbTOT)')
            iDbio4(idbTOT)=varid
          CASE ('iDbio4(idsTOT)')
            iDbio4(idsTOT)=varid
#endif

