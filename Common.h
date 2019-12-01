#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

vector<string> mySplit(const string& str, string sp_string);
BaoHanRela BaoHan(KXian* firstK, KXian* secondK);
void OutputDebugInfo(std::vector<KXian *> &KXianVector);
void FillinPOut(float* pfOUT, vector<FXing *> FXVector);
void FillinPOutDefault(float* pfOUT, int DataLen);


