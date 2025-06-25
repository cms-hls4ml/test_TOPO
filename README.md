# test_TOPO

This repo tests the TOPO repo and compiles the models. 

## Instructions for testing:

```
#on lxplus
git clone git@github.com:cms-hls4ml/test_TOPO.git  --recurse-submodules
cd test_TOPO

#if you make changes to the TOPO repository update the submodules
git submodule update --remote --merge

#needed for dependencies
export LD_LIBRARY_PATH=./:/cvmfs/cms.cern.ch/el8_amd64_gcc11/external/hls4mlEmulatorExtras/1.1.1-6933fcc7cdb4cdd5a649bd6579151d1b/lib64

make clean
make

#to remove existing models
rm *.o; rm *.so; cd TOPO/TOPO_v1/; rm *.o; rm *.so; cd -

#this should output your model binary that you can use for testing in cmssw:
topo_v1.so

#you can also run basic tests with the main.cpp script
./main.o

```
