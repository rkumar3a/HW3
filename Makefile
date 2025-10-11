# Sin-Yaw Wang <swang24@scu.edu>
CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:	%.cxx
	$(CXX) -c $(CXXFLAGS) $<

SRCS=bag.cxx bagtest.cxx set.cxx settest.cxx
OBJS=$(SRCS:.cxx=.o)

all: bag test set

bag: bag.o bagtest.o
	$(CXX) -o $@ $(CXXFLAGS) $+

set: set.o settest.o
	$(CXX) -o $@ $(CXXFLAGS) $+

test: testgen.cxx
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm bag test set $(OBJS)
	/bin/rm -rf $(ALL:=.dSYM)

depend: $(SRCS)
	TMP=`mktemp -p .`; export TMP; \
	sed -e '/^# DEPENDENTS/,$$d' Makefile > $$TMP; \
	echo '# DEPENDENTS' >> $$TMP; \
	$(CXX) -MM $+ >> $$TMP; \
	/bin/mv -f $$TMP Makefile

# DEPENDENTS
bag.o: bag.cxx bag.h
bagtest.o: bagtest.cxx bag.h
set.o: set.cxx set.h
settest.o: settest.cxx set.h
