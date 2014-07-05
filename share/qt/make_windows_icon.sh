#!/bin/bash
# create multiresolution windows icon
ICON_DST=../../src/qt/res/icons/LEOcoin.ico

convert ../../src/qt/res/icons/LEOcoin-16.png ../../src/qt/res/icons/LEOcoin-32.png ../../src/qt/res/icons/LEOcoin-48.png ${ICON_DST}
