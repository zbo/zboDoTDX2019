#include "stdafx.h"
#include "TCalcFuncSets.h"
#include "Common.h"
#include "SearchApp.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//生成的dll及相关依赖dll请拷贝到通达信安装目录的T0002/dlls/下面,再在公式管理器进行绑定



void TestPlugin1(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	for(int i=0;i<DataLen;i++)
		pfOUT[i]=i;
}




void TestPlugin2(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	ofstream outfile("out.txt",ios::app);	
	std::vector<KXian*> KXianVector;
	//构造K线序列
	for(int i=0; i<DataLen; i++){
		KXian* KX = new KXian;
		KX->High = pfINa[i];
		KX->Low = pfINb[i];
		KX->i = i;
		KXianVector.push_back(KX);
		
	}
	//找到K线最高点和最低点
	KXian* KX_Max = KXianVector[0];
	KXian* KX_Min = KXianVector[0];
	for(int i=0; i<KXianVector.size(); i++){
		KXian* KX = KXianVector[i];
		if(KXianVector[i]->High>KX_Max->High){
			KX_Max=KXianVector[i];
		}
		if(KXianVector[i]->Low<KX_Min->Low){
			KX_Min=KXianVector[i];
		}
		//outfile << "序号：" << KX->i << "高点：" << KX->High << " 低点：" << KX->Low <<'\n';
	}
	outfile << "最高点：" << KX_Max->i << "最低点：" << KX_Min->i << "数据总数：" << DataLen <<'\n';
	//找到Max和Min比较靠前的一个，开始有方向的搜索
	//Search_From_Max_Min(KX_Max, KX_Min, KXianVector);
	//测试输出指标
	for(int i=1;i<DataLen-1;i++)
	{
		if(i==KX_Max->i){
			pfOUT[i]=1;
		}
		else if(i==KX_Min->i){
			pfOUT[i]=-1;
		}
		else{
			pfOUT[i]=0;
		}
	}
	outfile<<"------------------------------------------------"<<'\n';
	outfile.close();
	ofstream debug_file("debug.txt",ios::trunc);
	for(int i=0; i<KXianVector.size(); i++){
		debug_file<<KXianVector[i]->High<<" "<<KXianVector[i]->Low<<'\n';
	}
	debug_file.close();
}


//加载的函数
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&TestPlugin1},
	{2,(pPluginFUNC)&TestPlugin2},
	{0,NULL},
};

//导出给TCalc的注册函数
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}




int _tmain(int argc, _TCHAR* argv[])
{
	fstream file;
	file.open("C:\\zd_pazq_hy\\debug2.txt",ios::in);
	vector<float> pfINa_high;
	vector<float> pfINb_low;
	char buf[1024];
    while (file.getline(buf, sizeof(buf))) {
        std:string str(buf);
		vector<string> strarr = mySplit(str," ");
		float high = atof(strarr[0].c_str());
		pfINa_high.push_back(high);
		float low = atof(strarr[1].c_str());
		pfINb_low.push_back(low);
        cout << str << endl;
    }
	file.close();
	int DataLength = pfINa_high.size();
	float *out = new float[DataLength];
	float *pfINa = new float[DataLength];
	float *pfINb = new float[DataLength];
	float *pfINc = new float[DataLength];
	memcpy(pfINa, &pfINa_high[0], pfINa_high.size()*sizeof(float)); 
	memcpy(pfINb, &pfINb_low[0], pfINb_low.size()*sizeof(float)); 
	TestPlugin2(DataLength,out,pfINa,pfINb,pfINc);
	return 0;
}

