
.PHONY: test build wolfroot

# OPT := ""


all:
# build: wolfroot
# wolfroot: 
# test: wolfroot

# # write the Absolute Path in Makefile of each directory.
# wolfroot: 
# 	source search_wolfdir.sh


test: 
	@./test.sh ${OPT}

clean:
	cd rsa_vfy_only && make clean
	cd rsa_buffer && make clean 
	cd ecc-sign-verify && make clean 

