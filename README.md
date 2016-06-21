# HadHadScaleFactors
## Installation
### RootCore
```
setupATLAS
mkdir workarea
cd workarea
# Setup an ABR
rcSetup 2.4.10, Base 
git clone https://github.com/qbuat/HadHadScaleFactors.git
rc find_packages
rc compile
```
In your running script you then need to load the ABR packages:

```
ROOT.gROOT.Macro('$ROOTCOREDIR/scripts/load_packages.C')
```


### Standalone ROOT
```
setupATLAS
lsetup root
mkdir workarea
cd workarea
git clone https://github.com/qbuat/HadHadScaleFactors.git
cd HadHadScaleFactors/cmt/
make -f Makefile.Standalone
```
In your running script you then need to load the library
```
# from the workarea directory
ROOT.gSystem.Load('HadHadScaleFactors/cmt/libHadHadScaleFactors.so')
```