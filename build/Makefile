.SUFFIXES:	.o .cc .h .c
.PRECIOUS:	.cc .h .c

VPATH =  ../source
 
  # Set maximum orbital angular momentum LMAX 
  # for AR (at rest), OA (on-axis total momentum (0,0,n)),
  # PD (planar diagonal total momentum (0,n,n)),
  # CD (cubic diagonal total momentum (n,n,n))
  # LMAX<=6 currently supported; decreasing speeds up compile time.
  # Setting any one to a negative value eliminates that momentum ray.

AR_LMAX_VALUE=6
OA_LMAX_VALUE=6
PD_LMAX_VALUE=6
CD_LMAX_VALUE=6

  # Set maximum total intrinsic spin (times two) SX2MAX 
  # for AR (at rest), OA (on-axis total momentum (0,0,n)),
  # PD (planar diagonal total momentum (0,n,n)),
  # CD (cubic diagonal total momentum (n,n,n))
  # SX2MAX<=4 currently supported for AR,OA; SX2MAX<=3 for PD,CD.
  # Decreasing these values speeds up compile time.
  # Setting less than 0 eliminates all routines for the momentum ray.

AR_SX2MAX_VALUE=4
OA_SX2MAX_VALUE=4
PD_SX2MAX_VALUE=3
CD_SX2MAX_VALUE=3



CXX = g++
CXXFLAGS = -O3 -std=c++11 -Wall -I../source
#CXXFLAGS = -O3 -std=c++0x -Wall
DFLAGS = -DAR_LMAX=$(AR_LMAX_VALUE) -DOA_LMAX=$(OA_LMAX_VALUE) \
         -DPD_LMAX=$(PD_LMAX_VALUE) -DCD_LMAX=$(CD_LMAX_VALUE) \
         -DAR_SX2MAX=$(AR_SX2MAX_VALUE) -DOA_SX2MAX=$(OA_SX2MAX_VALUE) \
         -DPD_SX2MAX=$(PD_SX2MAX_VALUE) -DCD_SX2MAX=$(CD_SX2MAX_VALUE) \
	 -fPIC
LDFLAGS =
LIBS=-llapack

SRCS = \
  box_matrix.cc      \
  box_matrix_ar.cc   \
  box_matrix_oa.cc   \
  box_matrix_pd1.cc  \
  box_matrix_pd2.cc  \
  box_matrix_cd1.cc  \
  box_matrix_cd2.cc  \
  box_quant.cc       \
  cmframe.cc         \
  fit_forms.cc       \
  K_matrix_calc.cc   \
  K_matrix_info.cc   \
  matrix.cc          \
  utils.cc           \
  xml_handler.cc     \
  zeta.cc

INCS = \
  box_matrix.h     \
  box_quant.h      \
  cmframe.h        \
  fit_forms.h      \
  K_matrix_base.h  \
  K_matrix_calc.h  \
  K_matrix_info.h  \
  matrix.h         \
  utils.h          \
  xml_handler.h    \
  zeta.h

OBJS = $(SRCS:.cc=.o)

.SECONDARY: $(OBJS)

all:  driver1 driver2

lib: $(OBJS)
	$(CXX) $(CXXFLAGS) -shared $(LDFLAGS) -o libBox.so $(OBJS) $(LDFLAGS)

driver%: driver%.cc $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o driver$* ../source/driver$*.cc $(OBJS) $(LIBS) 

  #  do not optimize these routines (very long compile time)

box_matrix_ar.o: box_matrix_ar.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_ar.cc

box_matrix_oa.o: box_matrix_oa.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_oa.cc

box_matrix_pd1.o: box_matrix_pd1.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_pd1.cc

box_matrix_pd2.o: box_matrix_pd2.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_pd2.cc

box_matrix_cd1.o: box_matrix_cd1.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_cd1.cc

box_matrix_cd2.o: box_matrix_cd2.cc $(INCS) Makefile
	$(CXX) $(DFLAGS) -c ../source/box_matrix_cd2.cc

   #  can optimize all other files

%.o: %.cc $(INCS) Makefile
	$(CXX) $(CXXFLAGS) $(DFLAGS) -c $< -o $@

clean:
	rm -f *.o driver1 driver2
