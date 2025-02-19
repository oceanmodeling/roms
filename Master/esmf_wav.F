#include "cppdefs.h"
#if defined MODEL_COUPLING && defined ESMF_LIB
/*
** git $Id$
*************************************************** Hernan G. Arango ***
** Copyright (c) 2002-2024 The ROMS/TOMS Group                        **
**   Licensed under a MIT/X style license                             **
**   See License_ROMS.md                                              **
************************************************************************
**                                                                    **
**  Wave model gridded component coupled to ROMS using the ESMF       **
**  library with the NUOPC layer.                                     **
**                                                                    **
**  ESMF:   Earth System Modeling Framework (Version 7 or higher)     **
**            https://www.earthsystemcog.org/projects/esmf            **
**                                                                    **
**  NUOPC:  National Unified Operational Prediction Capability        **
**           https://www.earthsystemcog.org/projects/nuopc            **
**                                                                    **
************************************************************************
*/

# if defined WAV_COUPLING
#  if defined REFDIF_COUPLING_NOT_YET
#   include "esmf_wav_refdif.h"
#  elif defined SWAN_COUPLING_NOT_YET
#   include "esmf_wav_swan.h"
#  elif defined WAM_COUPLING
#   include "esmf_wav_wam.h"
#  else
#   include "esmf_wav_void.h"
#  endif
# else
      MODULE esmf_wav_mod
      END MODULE esmf_wav_mod
# endif
#else
      MODULE esmf_wav_mod
      END MODULE esmf_wav_mod
#endif
