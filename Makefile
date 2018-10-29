
all: encode_weak_cisco

encode_weak_cisco:
	g++ -Wall encode_weak_cisco.cpp -o encode_weak_cisco

test: vimtest

vimtest: encode_weak_cisco
	./dc --salt=2 totoIStoto
	echo "02120B4F042F3C35435A06"
	./dc -h
	./dc --help
	./dc --salt=3 -- -tagada
	
clean:
	rm -f encode_weak_cisco

install: encode_weak_cisco
	cp ./encode_weak_cisco /usr/local/bin/encode_weak_cisco
	chmod 755 /usr/local/bin/encode_weak_cisco

