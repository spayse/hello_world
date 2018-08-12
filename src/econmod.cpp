//copyright 2018 SpayseMcG


#include "activemasternode.h"
#include "econmod.h"
#include "addrman.h"
#include "masternode.h"
#include "masternodeconfig.h"
#include "masternodeman.h"
#include "protocol.h"
#include "spork.h"
#include "main.cpp"
#include "main.h"

#include "accumulators.h"
#include "addrman.h"
#include "alert.h"
#include "chainparams.h"
#include "checkpoints.h"
#include "checkqueue.h"
#include "init.h"
#include "kernel.h"
#include "masternode-budget.h"
#include "masternode-payments.h"
#include "masternodeman.h"
#include "merkleblock.h"
#include "net.h"
#include "obfuscation.h"
#include "pow.h"
#include "spork.h"
#include "sporkdb.h"
#include "swifttx.h"
#include "txdb.h"
#include "txmempool.h"
#include "ui_interface.h"
#include "util.h"
#include "utilmoneystr.h"

#include "primitives/zerocoin.h"
#include "libzerocoin/Denominations.h"

#include <sstream>

#include <boost/algorithm/string/replace.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/thread.hpp>

//this  is my first experiment with balancing economic factors.  the ultimate goal is infinite mint with deflationary properties.  this is not the complete solution the infinite level increases over time  making more coins needed for Mn holders.  

int iLevel(nHeight){       // the infinite level 
   bool iLActive(nHeight){
      if (nHeight >= 23098) {
          return true
      }
       
   }
    if(nHeight % 1618 = 0 && iLActive = true){     // golden ratio
        iLevel += 0.1618
    }else(iLActive = false){
        iLevel=1;
    }
    
    return iLevel;
}
//  returns the current iLevel

int colatBase = 65000 * COIN;   // base MNcolat 
int dynamNC(iLevel,colatBase,nHeight){
    dynamNC = colatBase;
    
    if(iLActive=true){
        dynamNC == colatBase * iLevel
    }
    
 return dynamNC;
    
    
};