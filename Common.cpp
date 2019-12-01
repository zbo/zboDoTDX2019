//#include "Common.h"
#include "stdafx.h"
#include <vector>

#include "Common.h"


vector<string> mySplit(const string& str, string sp_string)  // split(), str 是要分割的string
{ 
    vector<string> vecString; 
    int sp_stringLen = sp_string.size(); 
    int lastPosition = 0; 
    int index = -1; 
    while(-1 != (index=str.find(sp_string , lastPosition))) 
    { 
        vecString.push_back(str.substr(lastPosition, index - lastPosition)); 
        lastPosition = index +sp_stringLen; 
    } 
    string lastStr = str.substr(lastPosition); 
    if ( !lastStr.empty() ) 
    { 
        vecString.push_back(lastStr); 
    } 
    return vecString; 
} 

BaoHanRela BaoHan(KXian* firstK, KXian* secondK){
	BaoHanRela rela;
	if(firstK->High>=secondK->High&&firstK->Low<=secondK->Low){
		rela.isBaoHan=true;
		rela.BaoHanType = -1;
		return rela;
	}else if(firstK->High<=secondK->High&&firstK->Low>=secondK->Low){
		rela.isBaoHan=true;
		rela.BaoHanType = 1;
		return rela;
	}
	else{
		rela.isBaoHan=false;
		rela.BaoHanType = 0;
		return rela;}
}

void OutputDebugInfo(std::vector<KXian *> &KXianVector)
{
	ofstream debug_file("debug.txt",ios::trunc);
	for(int i=0; i<KXianVector.size(); i++){
		debug_file<<KXianVector[i]->High<<" "<<KXianVector[i]->Low<<'\n';
	}
	debug_file.close();
}

void FillinPOut(float* pfOUT, vector<FXing *> FXVector)
{
	for(int i=0;i<FXVector.size();i++){
		int index = FXVector[i]->Second->i;
		int fxtype = FXVector[i]->FXType;
		pfOUT[index]=fxtype;
	}
}
void FillinPOutDefault(float* pfOUT, int DataLen)
{
	for(int i=0;i<DataLen;i++){
		pfOUT[i]=0;
	}
}