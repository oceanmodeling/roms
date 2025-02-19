# git $Id$
#::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# Copyright (c) 2002-2024 The ROMS/TOMS Group                           :::
#   Licensed under a MIT/X style license                                :::
#   See License_ROMS.md                                                 :::
#::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
#
# Include file for UNICOS F90 compiler on CRAY
# -------------------------------------------------------------------------
#
# ARPACK_LIBDIR  ARPACK libary directory
# FC             Name of the fortran compiler to use
# FFLAGS         Flags to the fortran compiler
# CPP            Name of the C-preprocessor
# CPPFLAGS       Flags to the C-preprocessor
# HDF5_INCDIR    HDF5 include directory
# HDF5_LIBDIR    HDF5 library directory
# HDF5_LIBS      HDF5 library switches
# LIBS           Required libraries during linking
# ROMS_LIB       Directory and name for ROMS library
# NF_CONFIG      NetCDF Fortran configuration script
# NETCDF_INCDIR  NetCDF include directory
# NETCDF_LIBDIR  NetCDF library directory
# NETCDF_LIBS    NetCDF library switches
# PIO_INCDIR     Parallel-IO (PIO) from SCORPIO library include directory
# PIO_LIBDIR     Parallel-IO (PIO) from SCORPIO libary directory
# PIO_LIBS       Parallel-IO (PIO) from SCORPIO library switches
# PNETCDF_INCDIR PNetCDF include directory
# PNETCDF_LIBDIR PNetCDF libary directory
# PNETCDF_LIBS   PNetCDF library switches

# LD             Program to load the objects into an executable or shared library
# LDFLAGS        Flags to the loader
# RANLIB         Name of ranlib command
# MDEPFLAGS      Flags for sfmakedepend  (-s if you keep .f files)
#
# First the defaults
#
               FC := f90
           FFLAGS := -e I -e m
       FIXEDFLAGS := -f fixed
        FREEFLAGS := -f free
              CPP := /opt/ctl/bin/cpp
         CPPFLAGS := -P -N
           INCDIR := /usr/include /usr/local/bin
            SLIBS := -L/usr/local/lib -L/usr/lib
            ULIBS :=
             LIBS :=
         ROMS_LIB := -L$(BUILD_DIR) -lROMS
       MOD_SUFFIX := mod
               LD := $(FC)
          LDFLAGS :=
               AR := ar
          ARFLAGS := -r
            MKDIR := mkdir -p
               CP := cp -p -v
               RM := rm -f
           RANLIB := ranlib
             PERL := perl
             TEST := test
      ST_LIB_NAME := libROMS.a
      SH_LIB_NAME := libROMS.dylib

#--------------------------------------------------------------------------
# Compiling flags for ROMS Applications.
#--------------------------------------------------------------------------

ifdef USE_ROMS
 ifdef USE_DEBUG
           FFLAGS += -g
 else
           FFLAGS += -O3
 endif

 ifdef SHARED
       SH_LDFLAGS += -dynamiclib
 endif

        MDEPFLAGS := --cpp --fext=f90 --file=- --objdir=$(BUILD_DIR)
endif

#--------------------------------------------------------------------------
# Compiling flags for CICE Applications.
#--------------------------------------------------------------------------

ifdef CICE_APPLICATION
          CPPDEFS := -DLINUS $(MY_CPP_FLAGS)
 ifdef USE_DEBUG
           FFLAGS := -g
          LDFLAGS += -Wl,-no_compact_unwind
 else
           FFLAGS := -O3
          LDFLAGS += -Wl,-no_compact_unwind
 endif
endif

#--------------------------------------------------------------------------
# Coupled models libraries.
#--------------------------------------------------------------------------

ifdef USE_COAMPS
             LIBS += $(COAMPS_LIB_DIR)/libashare.a
             LIBS += $(COAMPS_LIB_DIR)/libcoamps.a
             LIBS += $(COAMPS_LIB_DIR)/libaa.a
             LIBS += $(COAMPS_LIB_DIR)/libam.a
             LIBS += $(COAMPS_LIB_DIR)/libfishpak.a
             LIBS += $(COAMPS_LIB_DIR)/libfnoc.a
             LIBS += $(COAMPS_LIB_DIR)/libtracer.a
#            LIBS += $(COAMPS_LIB_DIR)/libnl_beq.a
endif

ifdef CICE_APPLICATION
            SLIBS += $(SLIBS) $(LIBS)
endif

ifdef USE_WRF
             LIBS += $(WRF_LIB_DIR)/module_wrf_top.o
             LIBS += $(WRF_LIB_DIR)/libwrflib.a
             LIBS += $(WRF_LIB_DIR)/libfftpack.a
             LIBS += $(WRF_LIB_DIR)/libio_grib1.a
             LIBS += $(WRF_LIB_DIR)/libio_grib_share.a
             LIBS += $(WRF_LIB_DIR)/libwrfio_int.a
             LIBS += $(WRF_LIB_DIR)/libesmf_time.a
             LIBS += $(WRF_LIB_DIR)/librsl_lite.a
             LIBS += $(WRF_LIB_DIR)/module_internal_header_util.o
             LIBS += $(WRF_LIB_DIR)/pack_utils.o
ifneq ($(NETCDFPAR),)
             LIBS += $(WRF_LIB_DIR)/libwrfio_nfpar.a
endif
             LIBS += $(WRF_LIB_DIR)/libwrfio_nf.a
endif

#--------------------------------------------------------------------------
# Library locations, can be overridden by environment variables.
#--------------------------------------------------------------------------

ifdef USE_PIO
       PIO_INCDIR ?= /usr/local/include
       PIO_LIBDIR ?= /usr/local/lib
           FFLAGS += -I$(PIO_INCDIR)
             LIBS += -L$(PIO_LIBDIR) -lpiof -lpioc

   PNETCDF_INCDIR ?= /usr/local/include
   PNETCDF_LIBDIR ?= /usr/local/lib
           FFLAGS += -I$(PNETCDF_INCDIR)
             LIBS += -L$(PNETCDF_LIBDIR) -lpnetcdf
endif

ifdef USE_SCORPIO
       PIO_INCDIR ?= /usr/local/include
       PIO_LIBDIR ?= /usr/local/lib
           FFLAGS += -I$(PIO_INCDIR)
             LIBS += -L$(PIO_LIBDIR) -lpiof -lpioc

   PNETCDF_INCDIR ?= /usr/local/include
   PNETCDF_LIBDIR ?= /usr/local/lib
           FFLAGS += -I$(PNETCDF_INCDIR)
             LIBS += -L$(PNETCDF_LIBDIR) -lpnetcdf
endif

ifdef USE_NETCDF4
        NC_CONFIG ?= nc-config
   TEST_NC_CONFIG := $(shell which $(NC_CONFIG))
  ifneq ($(TEST_NC_CONFIG),)
             LIBS += $(shell $(NC_CONFIG) --libs)
  endif
        NF_CONFIG ?= nf-config
    NETCDF_INCDIR ?= $(shell $(NF_CONFIG) --prefix)/include
             LIBS += $(shell $(NF_CONFIG) --flibs)
           INCDIR += $(NETCDF_INCDIR) $(INCDIR)
else
    NETCDF_INCDIR ?= /usr/local/include
    NETCDF_LIBDIR ?= /usr/local/lib
      NETCDF_LIBS ?= -lnetcdf
             LIBS += -L$(NETCDF_LIBDIR) $(NETCDF_LIBS)
           INCDIR += $(NETCDF_INCDIR) $(INCDIR)
endif

ifdef USE_HDF5
      HDF5_INCDIR ?= /usr/local/include
      HDF5_LIBDIR ?= /usr/local/lib
        HDF5_LIBS ?= -lhdf5_fortran -lhdf5hl_fortran -lhdf5 -lz
             LIBS += -L$(HDF5_LIBDIR) $(HDF5_LIBS)
           INCDIR += $(HDF5_INCDIR)
endif

ifdef USE_ARPACK
 ifdef USE_MPI
   PARPACK_LIBDIR ?= /usr/local/lib
             LIBS += -L$(PARPACK_LIBDIR) -lparpack
 endif
    ARPACK_LIBDIR ?= /usr/local/lib
             LIBS += -L$(ARPACK_LIBDIR) -larpack
endif

ifdef USE_MPI
         CPPFLAGS += -DMPI
endif

ifdef USE_OpenMP
         CPPFLAGS += -D_OPENMP
endif

ifdef USE_MCT
       MCT_INCDIR ?= /usr/local/mct/include
       MCT_LIBDIR ?= /usr/local/mct/lib
           FFLAGS += -I$(MCT_INCDIR)
             LIBS += -L$(MCT_LIBDIR) -lmct -lmpeu
           INCDIR += $(MCT_INCDIR) $(INCDIR)
endif

ifdef USE_ESMF
                     include $(ESMFMKFILE)
          ESMF_OS ?= $(OS)
      ESMF_SUBDIR := $(ESMF_OS).$(ESMF_COMPILER).$(ESMF_ABI).$(ESMF_COMM).$(ESMF_SITE)
      ESMF_MK_DIR ?= $(ESMF_DIR)/lib/lib$(ESMF_BOPT)/$(ESMF_SUBDIR)
           FFLAGS += $(ESMF_F90COMPILEPATHS)
             LIBS += $(ESMF_F90LINKPATHS) $(ESMF_F90ESMFLINKLIBS)
endif

# Use full path of compiler.

               FC := $(shell which ${FC})
               LD := $(FC)

#--------------------------------------------------------------------------
# ROMS specific rules.
#--------------------------------------------------------------------------

# Set free form format in some ROMS source files to allow long string for
# local directory and compilation flags inside the code.

ifdef USE_ROMS
 $(BUILD_DIR)/mod_ncparam.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/mod_strings.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/analytical.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/biology.o: FFLAGS += $(FREEFLAGS)

 ifdef USE_ADJOINT
  $(BUILD_DIR)/ad_biology.o: FFLAGS += $(FREEFLAGS)
 endif
 ifdef USE_REPRESENTER
  $(BUILD_DIR)/rp_biology.o: FFLAGS += $(FREEFLAGS)
 endif
 ifdef USE_TANGENT
  $(BUILD_DIR)/tl_biology.o: FFLAGS += $(FREEFLAGS)
 endif
endif

#--------------------------------------------------------------------------
# Model coupling specific rules.
#--------------------------------------------------------------------------

# Add COAMPS library directory to include path of ESMF coupling files.

ifdef USE_COAMPS
 $(BUILD_DIR)/esmf_atm.o: FFLAGS += -I$(COAMPS_LIB_DIR)
 $(BUILD_DIR)/esmf_esm.o: FFLAGS += -I$(COAMPS_LIB_DIR)
endif

# Add WRF library directory to include path of ESMF coupling files.

ifdef USE_WRF
 $(BUILD_DIR)/esmf_atm.o: FFLAGS += -I$(WRF_LIB_DIR)
endif

# Supress free format in SWAN source files since there are comments
# beyond column 72.

ifdef USE_SWAN
 $(BUILD_DIR)/ocpcre.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/ocpids.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/ocpmix.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swancom1.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swancom2.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swancom3.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swancom4.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swancom5.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanmain.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanout1.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanout2.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanparll.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanpre1.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanpre2.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swanser.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swmod1.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/swmod2.o: FFLAGS += $(FIXEDFLAGS)
 $(BUILD_DIR)/m_constants.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/m_fileio.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/mod_xnl4v5.o: FFLAGS += $(FREEFLAGS)
 $(BUILD_DIR)/serv_xnl4v5.o: FFLAGS += $(FREEFLAGS)
endif
