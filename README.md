LEOcoin integration/staging tree
https://www.leocoin.org   
Copyright (c) 2009-2013 Bitcoin Developers  
Copyright (c) 2011-2013 Litecoin Developers  
Copyright (c) 2014-2015 LEOcoin Developers  

What is LEOcoin?
============

LEOcoin is a version of Litecoin using scrypt-Jane as a proof-of-work and proof-of-stake algorithm. 
- Algorithm: Scrypt-Jane Proof-Of-Work with modified nFactor
- N increases over time to increase memory requirements.
- Max Coins: 1 Billion LEO 
- Company Stock: 50 Million LEO (5%) 
- Block Time: 60 Seconds
- Minmum Stack age: 10 days.
- Maxmum Stack age: 30 days.
- Difficulty: Retarget every block, No block Halving Rate, Block Award: 20 LEO

For more information, as well as an immediately useable, binary version of the LEOcoin client sofware, see https://www.leocoin.org 

License
============
LEOcoin is released under the terms of the MIT license. See COPYING for more information or see http://opensource.org/licenses/MIT.

Development process
============
Developers work in their own trees, then submit pull requests when they think their feature or bug fix is ready.
If it is a simple/trivial/non-controversial change, then one of the LEOcoin development team members simply pulls it.
If it is a more complicated or potentially controversial change, then the patch submitter will be asked to start a discussion (if they haven't already) on the appropriate channels.
The patch will be accepted if there is broad consensus that it is a good thing. Developers should expect to rework and resubmit patches if the code doesn't match the project's coding conventions (see doc/coding.txt) or are controversial.
The master branch is regularly built and tested, but is not guaranteed to be completely stable. regularly to indicate new official, stable release versions of LEOcoin.

Testing
============
Testing and code review is the bottleneck for development; we get more pull requests than we can review and test. Please be patient and help out, and remember this is a security-critical project where any mistake might cost people lots of money.

Automated Testing
Developers are strongly encouraged to write unit tests for new code, and to submit new unit tests for old code.
Unit tests for the core code are in src/test/. To compile and run them:
cd src; make -f makefile.unix test
Unit tests for the GUI code are in src/qt/test/. To compile and run them:
qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
make -f Makefile.test
./LEOcoin-qt_test


qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
make -f Makefile.test
./LEOcoin-qt_test

To compile on ubuntu:
- sudo apt-get update
- sudo apt-get install git build-essential libboost-all-dev libdb++-dev libminiupnpc-dev libcurl4-openssl-dev
- git clone https://github.com/Leocoin-project/LEOcoin 
- cd LEOcoin/src
- make -f makefile.unix 

