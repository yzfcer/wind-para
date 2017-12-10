#include "wind_para.h"
#include "para_dictionary.h"
extern dic_item_s g_dic[];

void main()
{
    param_s pm = {-24,-2678,-267378,-256352865486325,156,2678,267378,256352865486325,B_TRUE,
        {6,-6578497,8,75849873},{23,456789,9868593},"test","uhfefhdufdulfguiuifguhgfdufgduhuigfd"};   
    param_set(g_dic,13,"pch",&pm.pch);
    param_set(g_dic,13,"pint16",&pm.pint16);
    param_set(g_dic,13,"pint32",&pm.pint32);
    param_set(g_dic,13,"pint64",&pm.pint64);
    param_set(g_dic,13,"puch",&pm.puch);
    param_set(g_dic,13,"puint16",&pm.puint16);
    param_set(g_dic,13,"puint32",&pm.puint32);
    param_set(g_dic,13,"puint64",&pm.puint64);
    param_set(g_dic,13,"pbool",&pm.pbool);
    param_set(g_dic,13,"arr16",&pm.arr16);
    param_set(g_dic,13,"arru32",&pm.arru32);
    param_set(g_dic,13,"str16",&pm.str16);
    param_set(g_dic,13,"str128",&pm.str128);
    param_print(g_dic,13);
}
