#include "wind_para.h"
#include "para_dictionary.h"
//extern dic_item_s &sys_dict[];
DICT_DECLARE(sys_dict);

void main()
{
    param_s pm = {-24,-2678,-267378,-256352865486325,156,2678,267378,256352865486325,B_TRUE,
        {6,-6578497,8,75849873},{23,456789,9868593},"test","uhfefhdufdulfguiuifguhgfdufgduhuigfd"};   
    param_set(&sys_dict,"pch",&pm.pch);
    param_set(&sys_dict,"pint16",&pm.pint16);
    param_set(&sys_dict,"pint32",&pm.pint32);
    param_set(&sys_dict,"pint64",&pm.pint64);
    param_set(&sys_dict,"puch",&pm.puch);
    param_set(&sys_dict,"puint16",&pm.puint16);
    param_set(&sys_dict,"puint32",&pm.puint32);
    param_set(&sys_dict,"puint64",&pm.puint64);
    param_set(&sys_dict,"pbool",&pm.pbool);
    param_set(&sys_dict,"arr16",&pm.arr16);
    param_set(&sys_dict,"arru32",&pm.arru32);
    param_set(&sys_dict,"str16",&pm.str16);
    param_set(&sys_dict,"str128",&pm.str128);
    param_print(&sys_dict);
}
