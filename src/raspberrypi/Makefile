CC       = gcc
CFLAGS   = -DNDEBUG -O3
CXX      = g++
CXXFLAGS = -DNDEBUG -O3

ifdef FULLSPEC	# フルスペック(SCSI論理,標準ピンアサイン)
CONNECT_TYPE=FULLSPEC
else
ifdef AIBOM	# AIBOM版(正論理,固有ピンアサイン)
CONNECT_TYPE=AIBOM
else
ifdef GAMERNIUM	# GAMERnium.com版(標準論理,固有ピンアサイン)
CONNECT_TYPE=GAMERNIUM
else	# 標準(SCSI論理,標準ピンアサイン)
CONNECT_TYPE=STANDARD
endif
endif
endif
CFLAGS+=-DCONNECT_TYPE_$(CONNECT_TYPE)
CXXFLAGS+=-DCONNECT_TYPE_$(CONNECT_TYPE)
LDFLAGS+=-DCONNECT_TYPE_$(CONNECT_TYPE)

ifdef DISK_LOG # ディスクアクセスのログを出力する
CXXFLAGS+=-DDISK_LOG
endif

RASCSI = rascsi
RASCTL = rasctl
RASDUMP = rasdump

BIN_ALL = $(RASCSI) $(RASCTL) $(RASDUMP)

SRC_RASCSI = \
	rascsi.cpp \
	scsi.cpp \
	disk.cpp \
	gpiobus.cpp \
	ctapdriver.cpp \
	cfilesystem.cpp \
	filepath.cpp \
	fileio.cpp

SRC_RASCTL = \
	rasctl.cpp

SRC_RASDUMP = \
	rasdump.cpp \
	scsi.cpp \
	gpiobus.cpp \
	filepath.cpp \
	fileio.cpp

OBJ_RASCSI := $(SRC_RASCSI:.cpp=.o)
OBJ_RASCTL := $(SRC_RASCTL:.c=.o)
OBJ_RASDUMP := $(SRC_RASDUMP:.c=.o)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

ALL: $(BIN_ALL)

$(RASCSI): $(OBJ_RASCSI) $
	$(CXX) -o $@ $(LDFLAGS) $(OBJ_RASCSI) -lpthread

$(RASCTL): $(OBJ_RASCTL) $
	$(CXX) -o $@ $(LDFLAGS) $(OBJ_RASCTL)

$(RASDUMP): $(OBJ_RASDUMP) $
	$(CXX) -o $@ $(LDFLAGS) $(OBJ_RASDUMP)

clean:
	rm -f *.o $(BIN_ALL)
