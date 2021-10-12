#include <string>
#define GMEXPORT extern "C" __declspec(dllexport)
const int EVENT_OTHER_SOCIAL = 70;

void (*CreateAsynEventWithDSMap)(int,int) = NULL;
int (*CreateDsMap)(int _num, ... ) = NULL;
bool (*DsMapAddDouble)(int _index,char *_pKey,double value)=NULL;
bool (*DsMapAddString)(int _index, char *_pKey, char *pVal)=NULL;


GMEXPORT double RegisterCallbacks(char *arg1, char *arg2, char *arg3,  char *arg4 )
{
    void (*CreateAsynEventWithDSMapPtr)(int,int) = (void (*)(int,int))(arg1);
    int(*CreateDsMapPtr)(int _num,...) = (int(*)(int _num,...)) (arg2);
    CreateAsynEventWithDSMap = CreateAsynEventWithDSMapPtr;
    CreateDsMap = CreateDsMapPtr;

    bool (*DsMapAddDoublePtr)(int _index,char *_pKey,double value)= (bool(*)(int,char*,double))(arg3);
    bool (*DsMapAddStringPtr)(int _index, char *_pKey, char *pVal)= (bool(*)(int,char*,char*))(arg4);

    DsMapAddDouble = DsMapAddDoublePtr;
    DsMapAddString = DsMapAddStringPtr;

    return double(1);
}




GMEXPORT double check()
{
    int myMap = CreateDsMap(0);

    DsMapAddDouble(myMap, "result", 1);
    return (double)myMap;
}






















