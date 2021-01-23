CXX=g++
CXXFLAGS= -Wall -Wextra -L. -g
LDFLAGS= -fPIC -shared
FILES = string.cpp field.cpp ip.cpp port.cpp
RM=rm -f

all:firewall.exe

firewall:
	$(CXX) ${CXXFLAGS} ${LDFLAGS} ${FILES} -o libfirewall.so

firewall.exe: firewall
	$(CXX) ${CXXFLAGS} main.cpp -o firewall.exe -lfirewall -linput

clean:
	-${RM} firewall ${TARGET_APP}