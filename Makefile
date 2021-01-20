CXX=g++
CXXFLAGS= -Wall -Wextra -L. -g
LDFLAGS= -fPIC -shared
FILES = string.cpp field.cpp ip.cpp port.cpp
RM=rm -f

all:firewall.exe

firewall:
	$(CCX) ${CXXFLAGS} ${LDFLAGS} ${FILES} -o libfirewall.so

firewall.exe: firewall
	$(CCX) ${CXXFLAGS} main.cpp -o firewall.exe -lfirewall -linput

clean:
	-${RM} ${TARGET_LIB} ${TARGET_APP}