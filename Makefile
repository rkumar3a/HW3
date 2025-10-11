# Sin-Yaw Wang <swang24@scu.edu>
CXX=c++
OPT=-g
STD=-std=c++20
CXXFLAGS=$(OPT) $(STD)

%.o:	%.cxx
	$(CXX) -c $(CXXFLAGS) $<

SRCS=bag.cxx bagtest.cxx stack.cxx stacktest.cxx
OBJS=$(SRCS:.cxx=.o)

all: bag test stack

bag: bag.o bagtest.o
	$(CXX) -o $@ $(CXXFLAGS) $+

stack: stack.o stacktest.o
	$(CXX) -o $@ $(CXXFLAGS) $+

test: testgen.cxx
	$(CXX) -o $@ $(CXXFLAGS) $+

clean:
	/bin/rm bag test stack $(OBJS)
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
stack.o: stack.cxx stack.h
stacktest.o: stacktest.cxx stack.h
