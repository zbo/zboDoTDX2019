#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

FXing* Search_Ding_FXing(vector<KXian *> KXianVector, FXing* FX_Di);
FXing* Search_Di_FXing_By_GG(vector<KXian*> KXianVector, int start);
FXing* Search_Ding_FXing_By_DD(vector<KXian*> KXianVector, int start);
std::vector<FXing*> SearchFenXing(vector<KXian*> KXianVector, int start, int fromMax);
void Search_From_Max_Min(KXian* KX_Max, KXian* KX_Min, std::vector<KXian *> KXianVector);