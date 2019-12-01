#include "stdafx.h"
#include <vector>

#include "Common.h"

FXing* Search_Ding_FXing(vector<KXian *> KXianVector, FXing* FX_Di)
{
	int i = FX_Di->Third->i;

	throw std::logic_error("The method or operation is not implemented.");
}

FXing* Search_Di_FXing_By_GG(vector<KXian*> KXianVector, int start){
	ofstream outfile("out.txt",ios::app);
	outfile <<"from "<<start<< "进入搜底分型函数"<<'\n';
	FXing* FX_Di=new FXing;
	return FX_Di;
}
FXing* Search_Ding_FXing_By_DD(vector<KXian*> KXianVector, int start){
	ofstream outfile("out.txt",ios::app);
	outfile <<"from "<<start<< "进入搜顶分型函数"<<'\n';
	FXing* FX_Di=new FXing;
	FX_Di->First=KXianVector[start-1];
	FX_Di->Second=KXianVector[start];
	int i=1;
	while(BaoHan(FX_Di->Second, KXianVector[start+i]).isBaoHan){
		FX_Di->Second->High=KXianVector[start+i]->High;
		i++;
	}
	FX_Di->Third=KXianVector[start+i];
	FXing* FX_Ding=Search_Ding_FXing(KXianVector,FX_Di);

	return FX_Ding;
}

std::vector<FXing*> SearchFenXing(vector<KXian*> KXianVector, int start, int fromMax){
	ofstream outfile("out.txt",ios::app);
	std::vector<FXing*> FXingVector;
	if(fromMax==1){
		FXing* Di_FXing = Search_Di_FXing_By_GG(KXianVector, start);
	}else{
		FXing* Ding_FXing = Search_Ding_FXing_By_DD(KXianVector, start);
	}
	return FXingVector;

}

void Search_From_Max_Min(KXian* KX_Max, KXian* KX_Min, std::vector<KXian *> KXianVector)
{
	std::vector<FXing*> Fxlist;
	if(KX_Max->i>=KX_Min->i){ //Max比Min大，从Min开始搜索,fromMax=-1
		if(KX_Min->i!=0)
		{Fxlist = SearchFenXing(KXianVector,KX_Min->i,-1);}
		else
		{Fxlist = SearchFenXing(KXianVector,KX_Max->i,1);}
	}else{
		if(KX_Max->i!=0)
		{Fxlist = SearchFenXing(KXianVector,KX_Max->i,1);}
		else
		{Fxlist = SearchFenXing(KXianVector,KX_Min->i,-1);}
	}
}