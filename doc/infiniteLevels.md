



this is the working formula for masternode as an economic balancer 
copyright 2018 SpayseMcG

















float iLevel(nHeight){       // the infinite level  lets make the ancients smile :)
   bool iLActive(nHeight){
      if (nHeight >= 23098) {
          return true
      }
       
   }
    
    bool isPerfectSquare(nHeight)
{
    int s = sqrt(nHeight);
    return (s*s == nHeight);
}
    
    bool isFibonacci(nHeight)
{
  
    return isPerfectSquare(5*nHeight*nHeight + 4) ||
           isPerfectSquare(5*nHeight*nHeight - 4);
}
   
    
    bool isPrime(nHeight){
        
        int n = nHeight 
        
          for(i = 2; i <= n / 2; ++i)
  {
      if(n % i == 0)
      {
          isPrime = false;
          break;
      }
  }
        
    }
    
    if(iLActive = true){     // lets do some nerd shit(mcg)
        
        switch(nHeight){
                
            case isPrime = true: iLevel += iLevel/133;   
                
                                    break;
            case isPerfectSquare = true :iLevel+=iLevel/200; 
                                    break;
            case  isFibonacci = true : iLevel += iLevel/70;
                                    break;
            case isPrime = true &&  isFibonacci = true: iLevel+=iLevel * 0.666;
                break;
        }
        
        
         }else(iLActive = false){
        iLevel=1;
    }
    
    return iLevel;
}
//  returns the current iLevel

int colatBase = 65000 * COIN;   // base MNcolat 
float dynamNC(iLevel,colatBase,nHeight){
    dynamNC = colatBase;
    
    if(iLActive=true){
        dynamNC == colatBase * iLevel
    }
    
 return dynamNC;
    
    
};

int64_t GetBlockValue(int nHeight)
{
    int64_t nSubsidy = 0;

    if (nHeight == 0) {
        nSubsidy = 10000000 * COIN; // Developer Fund -- Block 1
    } else if (nHeight < 15000 && nHeight > 0) {
        nSubsidy = 1000 * COIN; // 20 days -- Emissions: 207.356, Cumulative: 507.356
    } else if (nHeight <= Params().LAST_POW_BLOCK() && nHeight >= 15000 ) {
        nSubsidy = 250 * COIN; // 2 years -- Emissions: 2.522.880, Cumulative: 4.297.436
    }else if (nHeight < 300000 && nHeight > 262980) {
        nSubsidy = 100 * COIN;
    }else {
        nSubsidy = 50 * COIN;
    }
    return nSubsidy;
}

int64_t GetMasternodePayment(int nHeight, int64_t blockValue, int nMasternodeCount)
{
    int64_t ret = 0;

    if (Params().NetworkID() == CBaseChainParams::TESTNET) {
        if (nHeight < 200)
            return 0;
    }
	
	if (nHeight == 0)
		return 0;
	
    if (nHeight >= 2500 && nHeight <= 1499) {
        ret = blockValue * 0.75;
    } else if (nHeight >= 12500 && nHeight <= 15000){
         ret = blockValue * 0.75;
        
    }
    else if (nHeight > Params().LAST_POW_BLOCK()) {
        int64_t nMoneySupply = chainActive.Tip()->nMoneySupply;
        int64_t mNodeCoins = mnodeman.size() * dynamNC;

        //if a mn count is inserted into the function we are looking for a specific result for a masternode count
        if(nMasternodeCount)
            mNodeCoins = nMasternodeCount * dynamNC;

        if (fDebug)
            LogPrintf("GetMasternodePayment(): moneysupply=%s, nodecoins=%s \n", FormatMoney(nMoneySupply).c_str(),
                FormatMoney(mNodeCoins).c_str());

        if (mNodeCoins == 0) {
            ret = 0;
            
            // begin game theory
            
        } else if (nHeight >=15000  && nHeight <= 262980) { 
            
            float mNRatio = nMoneySupply/(nMasternodeCount*mNodeCoins);
        
            
                switch(mNRatio) {  // this is to balance the availible supply before year 1 milestone
                        
                    case mNRatio > 10 : ret = blockValue  * 0.85;        
                                break;
                    case mNRatio > 6 :  ret = blockValue  * 0.74 ;
                                break;
                    case mNRatio > 3 :  ret = blockValue  * 0.66 ;    
                                break;
                    case mNRatio > 2 :  ret = blockValue  * 0.55 ;    
                                break; 
                    case mNRatio > 1 :  ret = blockValue  * 0.42 ; 
                                break;  
                        
                    default :  ret = blockValue  * 0.33 ;    
                        
                }
            
        }else(nHeight >= 262980){
            
            ret = blockValue - (blockValue/iLevel);
            
            return ret;
            
        }