
/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									15 March 2023
*
*   Version: 1.01
*
*   ---------------------------------------------------
*
*
*	https://github.com/Bren828/vehicle-radar
*
*
*
* Создать радар
*       VehicleRadarCreate(playerid)
*		* playerid: ID игрока
*
*
* Просмотреть список созданных радаров
*       VehicleRadarList(playerid)
*		* playerid: ID игрока
*
*
* Загрузить радар
*       VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "-1", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
*		* speed_limit: Ограничение скорости
*		* Float:zone_size: Дистанция срабатывания
*       * Float:x: Координата x
*       * Float:y: Координата y
*       * Float:z: Координата z
*       * Float:rx: Координата x вращение объекта
*       * Float:ry: Координата y вращение объекта
*       * Float:rz: Координата z вращение объекта
*		* worldid: ID виртуального мира
*       * interiorid: ID интерьера 
*       * bool:disabled: Выключить радар (false - нет | true - да)
*       * const text3D[]: 3DText
*       * text3D_color: Цвет 3DText 
*       * Float:text3D_distance: Дистанция отображения 3DText
*		
*		* Вернет: 0 при неудачи
*		* Вернет: ID радара при успехе
*
*
* Удалить радар
*       DeleteVehicleRadar(playerid, radarid, bool:callback = true)
*		* radarid: ID радара
*		* callback: Вызвать 'OnPlayerVehicleRadarDelete' при удаление
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Изменить количество срабатываний
*       SetVehicleRadarActivationCount(radarid, count)
*		* radarid: ID радара
*		* count: количество
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Узнать количество срабатываний
*       GetVehicleRadarActivationCount(radarid)
*		* radarid: ID радара
*		
*		* Вернет: 0 при неудачи
*		* Вернет: количество срабатываний
*
*
* Изменить ограничение скорости
*       SetVehicleRadarSpeedLimit(radarid, speed)
*		* radarid: ID радара
*		* speed: скорость км/ч
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Узнать ограничение скорости
*       GetVehicleRadarSpeedLimit(radarid)
*		* radarid: ID радара
*		
*		* Вернет: 0 при неудачи
*		* Вернет: текущую скорость
*
*
* Изменить дистанцию срабатывания
*       SetVehicleRadarZoneSize(radarid, Float:zone_size)
*		* radarid: ID радара
*		* Float:zone_size: дистанция
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Узнать дистанцию срабатывания
*       GetVehicleRadarZoneSize(radarid, &Float:zone_size)
*		* radarid: ID радара
*       * &Float:zone_size: текущая дистанция
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Изменить 3D Text
*       SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0)
*		* radarid: ID радара
*       * text[]: текст
*       * color: цвет
*       * Float:drawdistance: дистанция
*       * Float:x: Координата x
*       * Float:y: Координата y
*       * Float:z: Координата z
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*
*
* Изменить дополнительное значение
*       SetVehicleRadarExtraValue(radarid, value)
*		* radarid: ID радара
*       * value: значение
*		
*		* Вернет: 0 при неудачи
*		* Вернет: 1 при успехе
*       * ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL
*
*
* Узнать дополнительное значение
*       GetVehicleRadarExtraValue(radarid)
*		* radarid: ID радара
*		
*		* Вернет: 0 при неудачи
*		* Вернет: текущие значение
*		* ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL
*
*
* Вызывается при срабатывание радара
*       public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
*		* playerid: ID игрока
*		* radarid: ID радара
*       * vehicleid: ID транспорта
*       * activation_count: количество срабатываний
*
*
* Вызывается при создании нового радара
*       public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
*		* radarid: ID радара
*		* speed_limit: Ограничение скорости
*		* Float:zone_size: Дистанция срабатывания
*       * bool:disabled: состояние радара (false - включен | true - выключен)
*       * Float:x: Координата x
*       * Float:y: Координата y
*       * Float:z: Координата z
*       * Float:rx: Координата x вращение объекта
*       * Float:ry: Координата y вращение объекта
*       * Float:rz: Координата z вращение объекта
*		* worldid: ID виртуального 
*       * interiorid: ID интерьера 
*
*
* Вызывается при редактировании созданного радара
*       public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
*		* radarid: ID радара
*		* speed_limit: Ограничение скорости
*		* Float:zone_size: Дистанция срабатывания
*       * bool:disabled: состояние радара (false - включен | true - выключен)
*       * Float:x: Координата x
*       * Float:y: Координата y
*       * Float:z: Координата z
*       * Float:rx: Координата x вращение объекта
*       * Float:ry: Координата y вращение объекта
*       * Float:rz: Координата z вращение объекта
*		* worldid: ID виртуального 
*       * interiorid: ID интерьера 
*
*
* Вызывается при удалении радара
*       public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
*		* radarid: ID радара
*       * extra_value: дополнительное значение
*
*
*       
*       stock _GetVehSpeed(vehicleid)
*
* 		/////////////
*			Usage
* 		/////////////       
*       
*
*       new radarid = VehicleRadarLoad(130, 50.0,  0.0, 0.0, 0.0,  0.0, 0.0, 0.0); // create a radar
*       SetVehicleRadarExtraValue(radarid, 1005); // add the value
*
*       public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
*       {
*           printf("Enter Vehicle Radar | radarid: %d | vehicleid: %d | activation_count: %d", radarid, vehicleid, activation_count)
*	        return 1;
*       }
*
*
* 		/////////////
*			CMD
* 		/////////////   
*
*
*       CMD:radarcreate(playerid)
*       {
*	        VehicleRadarCreate(playerid);
*	        return 1;
*       }
*
*       CMD:radarlist(playerid)
*       {
*           VehicleRadarList(playerid);
*           return 1;
*       }
*
*/

#if defined _vehicle_radar_included 
	#endinput
#endif
#define _vehicle_radar_included


#if !defined MAX_VEHICLE_RADAR
    #define MAX_VEHICLE_RADAR                   200
#endif

#if !defined VEHICLE_RADAR_OBJECT_MODEL
    #define VEHICLE_RADAR_OBJECT_MODEL          18880 // модель объекта
#endif

#if !defined VEHICLE_RADAR_OBJECT_DISTANCE
    #define VEHICLE_RADAR_OBJECT_DISTANCE       200.0 // дистанция прорисовки объекта
#endif

#if !defined VEHICLE_RADAR_3DTEXT_LENGTH
	#define VEHICLE_RADAR_3DTEXT_LENGTH   	    144	// Длина 3d текста
#endif

#if !defined VEHICLE_RADAR_3DTEXT_TEXT
	#define VEHICLE_RADAR_3DTEXT_TEXT  	        "Радар скорости №%d\nОграничение скорости: %d (км/ч)" // текст при значение '-1' в 'VehicleRadarLoad'
#endif

#if !defined VEHICLE_RADAR_3DTEXT_DISTANCE
    #define VEHICLE_RADAR_3DTEXT_DISTANCE       15.0 // дистанция прорисовки 3d текста
#endif

#if !defined VEHICLE_RADAR_MAX_PAGES_LIST
    #define VEHICLE_RADAR_MAX_PAGES_LIST        20 // максимальное количество строчек в диалоге 
#endif

#if !defined VEHICLE_RADAR_USE_EDITING_TOOLS
	#define VEHICLE_RADAR_USE_EDITING_TOOLS  	true //использовать инструменты редактирования
#endif

enum VEHICLE_RADAR_EN
{
    bool:vr_Create,
    bool:vr_Disabled,
    vr_Object,
    Float:vr_Object_x,
    Float:vr_Object_y,
    Float:vr_Object_z,
    Float:vr_Object_rx,
    Float:vr_Object_ry,
    Float:vr_Object_rz,
    vr_Object_Worldid,
    vr_Object_Interiorid,

    Float:vr_ZoneSize,
    vr_Sphere,
    vr_SpeedLimit,
    vr_ActivationCount,
    vr_ExtraValue, 

    Text3D:vr_Text3D,
    vr_Text3D_Text[VEHICLE_RADAR_3DTEXT_LENGTH],
    vr_Text3D_Color,
    Float:vr_Text3D_Distance,
    Float:vr_Text3D_Z
}
static vehicle_radar[MAX_VEHICLE_RADAR][VEHICLE_RADAR_EN];

forward OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count);

#if VEHICLE_RADAR_USE_EDITING_TOOLS
    enum VEHICLE_RADAR_PLAYER_EN
    {
        bool:vrp_Disabled,
        Float:vrp_x,
        Float:vrp_y,
        Float:vrp_z,
        Float:vrp_rx,
        Float:vrp_ry,
        Float:vrp_rz,
        Float:vrp_ZoneSize,
        vrp_SpeedLimit,
        vrp_Worldid,
        vrp_Interiorid,
        vrp_Object,
        bool:vrp_EditObject,

        //list
        vrpList_Page,
        vrpList_Page_Button_Back,
        vrpList_SlotID[VEHICLE_RADAR_MAX_PAGES_LIST],
        vrpList_LineID,
        bool:vrpList_EditRadar[2]
    }
    static vehicle_radar_player[MAX_PLAYERS][VEHICLE_RADAR_PLAYER_EN];
#endif

stock VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "-1", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
{
    new radarid;
    for(new i = 1; i < MAX_VEHICLE_RADAR; i ++)
    {
        if(vehicle_radar[i][vr_Create] == true) continue;
        radarid = i;
        break;
    }
    if(!radarid) return printf("vehicle-radar --->>> | VehicleRadarLoad | not all radars were created! | increase the value '#define MAX_VEHICLE_RADAR'") & 0;

    vehicle_radar[radarid][vr_Create] = true;
    vehicle_radar[radarid][vr_Disabled] = disabled;
    vehicle_radar[radarid][vr_Object_x] = x;
    vehicle_radar[radarid][vr_Object_y] = y;
    vehicle_radar[radarid][vr_Object_z] = z;
    vehicle_radar[radarid][vr_Object_rx] = rx;
    vehicle_radar[radarid][vr_Object_ry] = ry;
    vehicle_radar[radarid][vr_Object_rz] = rz;
    vehicle_radar[radarid][vr_Object_Worldid] = worldid;
    vehicle_radar[radarid][vr_Object_Interiorid] = interiorid;
    vehicle_radar[radarid][vr_ZoneSize] = zone_size;
    vehicle_radar[radarid][vr_SpeedLimit] = speed_limit;
    vehicle_radar[radarid][vr_ExtraValue] = 0;
    vehicle_radar[radarid][vr_Text3D] = Text3D:INVALID_3DTEXT_ID;
    format(vehicle_radar[radarid][vr_Text3D_Text], VEHICLE_RADAR_3DTEXT_LENGTH, text3D);
    vehicle_radar[radarid][vr_Text3D_Color] = text3D_color;
    vehicle_radar[radarid][vr_Text3D_Distance] = text3D_distance;
    vehicle_radar[radarid][vr_Text3D_Z] = 0.0;
    vehicle_radar[radarid][vr_ActivationCount] = 0;

    vehicle_radar[radarid][vr_Object] = CreateDynamicObject(VEHICLE_RADAR_OBJECT_MODEL, x, y, z,  rx, ry, rz,  worldid, interiorid, -1, VEHICLE_RADAR_OBJECT_DISTANCE, VEHICLE_RADAR_OBJECT_DISTANCE);
    vehicle_radar[radarid][vr_Sphere] = CreateDynamicSphere(x, y, z, zone_size, worldid, interiorid);
    
    if(strlen(text3D) >= 1)
    {
        if(strlen(text3D) == 2 && text3D[0] == '-' && text3D[1] == '1') 
        {
            new string[VEHICLE_RADAR_3DTEXT_LENGTH];
            format(string, sizeof(string), VEHICLE_RADAR_3DTEXT_TEXT, radarid, speed_limit);
            vehicle_radar[radarid][vr_Text3D_Z] = 6.0;
            vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(string, text3D_color, x, y, z+6.0, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
        }
        else vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(text3D, text3D_color, x, y, z, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
    }
    return radarid;
}

stock DeleteVehicleRadar(playerid, radarid, bool:callback = true)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | DeleteVehicleRadar | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false || playerid !=-1) return 0;

    if(IsValidDynamicObject(vehicle_radar[radarid][vr_Object])) DestroyDynamicObject(vehicle_radar[radarid][vr_Object]);
    if(IsValidDynamicArea(vehicle_radar[radarid][vr_Sphere])) DestroyDynamicArea(vehicle_radar[radarid][vr_Sphere]);
    if(vehicle_radar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID) DestroyDynamic3DTextLabel(vehicle_radar[radarid][vr_Text3D]);

    if(callback == true)
    {
        #if defined OnPlayerVehicleRadarDelete
            OnPlayerVehicleRadarDelete(playerid, radarid, vehicle_radar[radarid][vr_ExtraValue]);
        #endif
    }
    vehicle_radar[radarid][vr_Create] = false;
    vehicle_radar[radarid][vr_Object] = 0;
    vehicle_radar[radarid][vr_Sphere] = 0;
    vehicle_radar[radarid][vr_Text3D] = Text3D:INVALID_3DTEXT_ID;
    return 1;
}

stock SetVehicleRadarActivationCount(radarid, count)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | SetVehicleRadarActivationCount | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    vehicle_radar[radarid][vr_ActivationCount] = count;
    return 1;
}

stock GetVehicleRadarActivationCount(radarid, &triggering)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | GetVehicleRadarActivationCount | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    return vehicle_radar[radarid][vr_ActivationCount];
}


stock SetVehicleRadarSpeedLimit(radarid, speed)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | SetVehicleRadarSpeedLimit | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    vehicle_radar[radarid][vr_SpeedLimit] = speed;
    return 1;
}

stock GetVehicleRadarSpeedLimit(radarid)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | GetVehicleRadarSpeedLimit | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    return vehicle_radar[radarid][vr_SpeedLimit];
}


stock SetVehicleRadarZoneSize(radarid, Float:zone_size)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | SetVehicleRadarZoneSize | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    vehicle_radar[radarid][vr_ZoneSize] = zone_size;
    if(IsValidDynamicArea(vehicle_radar[radarid][vr_Sphere])) DestroyDynamicArea(vehicle_radar[radarid][vr_Sphere]);

    vehicle_radar[radarid][vr_Sphere] = CreateDynamicSphere(
        vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z],
        vehicle_radar[radarid][vr_ZoneSize], vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid]
    );
    return 1;
}

stock GetVehicleRadarZoneSize(radarid, &Float:zone_size)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | GetVehicleRadarZoneSize | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    zone_size = vehicle_radar[radarid][vr_ZoneSize];
    return 1;
}


stock SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = -1.0, Float:y = -1.0, Float:z = -1.0)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | SetVehicleRadarText | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    
    if(vehicle_radar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID) DestroyDynamic3DTextLabel(vehicle_radar[radarid][vr_Text3D]);
    x = (x == -1.0) ? (vehicle_radar[radarid][vr_Object_x]):(x);
    y = (y == -1.0) ? (vehicle_radar[radarid][vr_Object_y]):(y);
    z = (z == -1.0) ? (vehicle_radar[radarid][vr_Object_z]):(z);
    format(vehicle_radar[radarid][vr_Text3D_Text], VEHICLE_RADAR_3DTEXT_LENGTH, text);
    vehicle_radar[radarid][vr_Text3D_Color] = color;
    vehicle_radar[radarid][vr_Text3D_Distance] = drawdistance;
    if(x == -1.0 && y == -1.0 && z == -1.0) vehicle_radar[radarid][vr_Text3D_Z] = 0.0;

    vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(text, color, x, y, z+vehicle_radar[radarid][vr_Text3D_Z], drawdistance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, drawdistance);
    return 1;
}


stock SetVehicleRadarExtraValue(radarid, value)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | SetVehicleRadarExtraValue | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    vehicle_radar[radarid][vr_ExtraValue] = value;
    return 1;
}

stock GetVehicleRadarExtraValue(radarid)
{
    if(radarid <= 0 || radarid >= MAX_VEHICLE_RADAR) return printf("vehicle-radar --->>> | GetVehicleRadarExtraValue | error, invalid radarid '%d'", radarid) & 0;
    if(vehicle_radar[radarid][vr_Create] == false) return 0;
    return vehicle_radar[radarid][vr_ExtraValue];
}


stock _GetVehSpeed(vehicleid)
{
    new Float:x, Float:y, Float:z;
    GetVehicleVelocity(vehicleid, x, y, z);
	return floatround(floatsqroot(floatpower(x, 2.0) + floatpower(y, 2.0) + floatpower(z, 2.0)) * 179.28625);
}


#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterDynamicArea(playerid, areaid)
#else
	public OnPlayerEnterDynamicArea(playerid, areaid)
#endif
{
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER && GetPlayerVehicleID(playerid) >= 1)
    {
        new vehicleid = GetPlayerVehicleID(playerid);
        for(new radarid = 1; radarid < MAX_VEHICLE_RADAR; radarid ++)
        {
            if(vehicle_radar[radarid][vr_Create] == false) continue;
            if(vehicle_radar[radarid][vr_Sphere] != areaid) continue;
            if(vehicle_radar[radarid][vr_Disabled] == true) break;
            if(vehicle_radar[radarid][vr_SpeedLimit] != 0 && _GetVehSpeed(vehicleid) < vehicle_radar[radarid][vr_SpeedLimit]) break;
            vehicle_radar[radarid][vr_ActivationCount] ++;

            #if defined OnPlayerEnterVehicleRadar
                OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, vehicle_radar[radarid][vr_ActivationCount]);
            #endif
            break;
        }
    }
    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerEnterDynamicArea_vradar
		return OnPlayerEnterDynamicArea_vradar(playerid, areaid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerEnterDynamicArea
		#undef OnPlayerEnterDynamicArea
	#else
		#define _ALS_OnPlayerEnterDynamicArea
	#endif
	#define OnPlayerEnterDynamicArea OnPlayerEnterDynamicArea_vradar
	#if defined OnPlayerEnterDynamicArea_vradar
		forward OnPlayerEnterDynamicArea_vradar(playerid, areaid);
	#endif
#endif


#if VEHICLE_RADAR_USE_EDITING_TOOLS
    stock VehicleRadarCreate(playerid)
    {
        vehicle_radar_player[playerid][vrpList_EditRadar][0] = false;
        vehicle_radar_player[playerid][vrp_Disabled] = false;
        GetPlayerPos(playerid, vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z]);
        vehicle_radar_player[playerid][vrp_rx] = 0.0;
        vehicle_radar_player[playerid][vrp_ry] = 0.0;
        vehicle_radar_player[playerid][vrp_rz] = 0.0;
        vehicle_radar_player[playerid][vrp_ZoneSize] = 30.0;
        vehicle_radar_player[playerid][vrp_SpeedLimit] = 50;
        vehicle_radar_player[playerid][vrp_Worldid] = GetPlayerVirtualWorld(playerid);
        vehicle_radar_player[playerid][vrp_Interiorid] = GetPlayerInterior(playerid);

        if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
        vehicle_radar_player[playerid][vrp_Object] = 0;
        vehicle_radar_player[playerid][vrp_EditObject] = false;

        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogCreate:_vehicle_radar_Create(playerid)
    {
        new string[166+ 21+30+10+10+16+10+10 + 23], caption[55+10] = "Создание радара";

        format(string, sizeof(string),
            "%s\t\n\
            Позиция\tX: %.1f, Y: %.1f, Z: %.1f\n\
            Дистанция срабатывания\t%.1fm\n\
            Скорость срабатывания\t%d км/ч\n\
            Статус радара\t%s\n\
            Виртуальный мир\t%d\n\
            Интерьер\t%d",
        (vehicle_radar_player[playerid][vrpList_EditRadar][0] == false) ? ("{8fce00}Создать радар"):("{f44747}Удалить радар"),
        vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
        vehicle_radar_player[playerid][vrp_ZoneSize],
        vehicle_radar_player[playerid][vrp_SpeedLimit],
        (vehicle_radar_player[playerid][vrp_Disabled] == false) ? ("{8fce00}Включен"):("{f44747}Выключен"),
        vehicle_radar_player[playerid][vrp_Worldid],
        vehicle_radar_player[playerid][vrp_Interiorid]);

        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) 
        {
            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            format(string, sizeof(string), "%s\nТелепорт к радару\t",  string);
            format(caption, sizeof(caption), "Редактирование радара | {F5D742}Кол-во срабатываний: %d", vehicle_radar[radarid][vr_ActivationCount]);
        }
        Dialog_Open(playerid, Dialog:_vehicle_radar_Create, DIALOG_STYLE_TABLIST, caption, string, "Выбрать", "Отмена");
        return 1;
    }

    DialogResponse:_vehicle_radar_Create(playerid, response, listitem, inputtext[])
    {
        if(!response)
        {
            vehicle_radar_player[playerid][vrp_EditObject] = false;
            if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
            {
                DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                vehicle_radar_player[playerid][vrp_Object] = 0;
            }

            if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
            {
                if(vehicle_radar_player[playerid][vrpList_EditRadar][1] == true) return Dialog_Open(playerid, Dialog:_vehicle_radar_Savechanges, DIALOG_STYLE_MSGBOX, "Принятие изменений", "{FFFFFF}Были найдены изменения желаете их сохранить ?", "Да", "Нет");
                Dialog_Show(playerid, Dialog:_vehicle_radar_List);
                return 1;
            }
            return 1;
        }
        switch(listitem)
        {
            case 0:
            {
                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
                {
                    new string[75+10];
                    format(string, sizeof(string), "{FFFFFF}Вы действительно желаете удалить автомобильный радар {F5D742}ID: %d", vehicle_radar_player[playerid][vrpList_LineID]);
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Delete, DIALOG_STYLE_MSGBOX, "Удалить автомобильный радар", string, "Удалить", "Назад");
                    return 1;
                }

                new radarid = VehicleRadarLoad(
                    vehicle_radar_player[playerid][vrp_SpeedLimit],
                    vehicle_radar_player[playerid][vrp_ZoneSize],
                    vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                    vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz],
                    vehicle_radar_player[playerid][vrp_Worldid], vehicle_radar_player[playerid][vrp_Interiorid],
                    vehicle_radar_player[playerid][vrp_Disabled]
                );
                if(!radarid)
                {
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Create_back, DIALOG_STYLE_MSGBOX, "Создание автомобильного радара", 
                        "{FFFFFF}Достигнут лимит по количеству созданих автомобильных радаров", 
                    "Закрыть", "Назад");
                    return 1;
                }
                if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]))
                {
                    DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                    vehicle_radar_player[playerid][vrp_Object] = 0;
                }

                #if defined OnPlayerVehicleRadarCreate
                    OnPlayerVehicleRadarCreate(playerid,
                        radarid, 
                        vehicle_radar_player[playerid][vrp_SpeedLimit],
                        vehicle_radar_player[playerid][vrp_ZoneSize], 
                        vehicle_radar_player[playerid][vrp_Disabled],
                        vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                        vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz],
                        vehicle_radar_player[playerid][vrp_Worldid], vehicle_radar_player[playerid][vrp_Interiorid]
                    );
                #endif
                return 1;
            }
            case 1:
            {
                if(!IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
                {
                    vehicle_radar_player[playerid][vrp_Object] = CreatePlayerObject(playerid, 
                        VEHICLE_RADAR_OBJECT_MODEL, 
                        vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                        vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz], 200.0
                    );

                    SetPlayerPos(playerid, vehicle_radar_player[playerid][vrp_x]+0.5, vehicle_radar_player[playerid][vrp_y]+0.5, vehicle_radar_player[playerid][vrp_z]);
                }

                new Float:distance = GetPlayerDistanceFromPoint(playerid, vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z]);
                if(distance >= 20.0) SetPlayerPos(playerid, vehicle_radar_player[playerid][vrp_x]+0.5, vehicle_radar_player[playerid][vrp_y]+0.5, vehicle_radar_player[playerid][vrp_z]+2.0);

                vehicle_radar_player[playerid][vrp_EditObject] = true;
                EditPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                return 1;
            }
            case 2:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_ZoneSize, DIALOG_STYLE_INPUT, "Дистанция срабатывания", "{FFFFFF}Введите дистанцию срабатывания автомобильного радара:", "Выбрать", "Отмена");
                return 1;
            }
            case 3:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_SpeedLimit, DIALOG_STYLE_INPUT, "Скорость срабатывания", "{FFFFFF}Введите скорость при которой будет срабатывать автомобильный радар:", "Выбрать", "Отмена");
                return 1;
            }
            case 4:
            {
                if(vehicle_radar_player[playerid][vrp_Disabled] == false) vehicle_radar_player[playerid][vrp_Disabled] = true;
                else vehicle_radar_player[playerid][vrp_Disabled] = false;

                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
                Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
                return 1;
            }
            case 5:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_Worldid, DIALOG_STYLE_INPUT, "Виртуальный мир", "{FFFFFF}Введите ID виртуального мира в котором будет отображаться радар:", "Выбрать", "Отмена");
                return 1;
            }
            case 6:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_Interior, DIALOG_STYLE_INPUT, "Интерьер", "{FFFFFF}Введите ID интерьера в котором будет отображаться радар:", "Выбрать", "Отмена");
                return 1;
            }
            case 7:
            {
                new radarid = vehicle_radar_player[playerid][vrpList_LineID];
                SetPlayerPos(playerid, vehicle_radar[radarid][vr_Object_x]+0.5, vehicle_radar[radarid][vr_Object_y]+0.5, vehicle_radar[radarid][vr_Object_z]+2.0);
                return 1;
            }
        }
        return 1;
    }

    DialogResponse:_vehicle_radar_Create_back(playerid, response, listitem, inputtext[])
    {
        if(!response) return 1;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogResponse:_vehicle_radar_ZoneSize(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        if(floatstr(inputtext) < 0.0) return Dialog_Open(playerid, Dialog:_vehicle_radar_ZoneSize, DIALOG_STYLE_INPUT, "Дистанция срабатывания", "{FFFFFF}Введите дистанцию срабатывания автомобильного радара:", "Выбрать", "Отмена");

        vehicle_radar_player[playerid][vrp_ZoneSize] = floatstr(inputtext);
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogResponse:_vehicle_radar_SpeedLimit(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        if(strval(inputtext) < 0) return Dialog_Open(playerid, Dialog:_vehicle_radar_SpeedLimit, DIALOG_STYLE_INPUT, "Скорость срабатывания", "{FFFFFF}Введите скорость при которой будет срабатывать автомобильный радар:", "Выбрать", "Отмена");

        vehicle_radar_player[playerid][vrp_SpeedLimit] = strval(inputtext);
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogResponse:_vehicle_radar_Worldid(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
 
        vehicle_radar_player[playerid][vrp_Worldid] = strval(inputtext);
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogResponse:_vehicle_radar_Interior(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);

        vehicle_radar_player[playerid][vrp_Interiorid] = strval(inputtext);
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    #if defined _inc_y_hooks || defined _INC_y_hooks
        hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
    #else
        public OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
    #endif
    {
        if(vehicle_radar_player[playerid][vrp_EditObject] == true && (response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL))
        {
            vehicle_radar_player[playerid][vrp_EditObject] = false;
            if(response == EDIT_RESPONSE_FINAL)
            {
                vehicle_radar_player[playerid][vrp_x] = fX;
                vehicle_radar_player[playerid][vrp_y] = fY;
                vehicle_radar_player[playerid][vrp_z] = fZ;

                vehicle_radar_player[playerid][vrp_rx] = fRotX;
                vehicle_radar_player[playerid][vrp_ry] = fRotY;
                vehicle_radar_player[playerid][vrp_rz] = fRotZ;
                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
            }
            SetPlayerObjectPos(playerid, vehicle_radar_player[playerid][vrp_Object], vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z]);
            SetPlayerObjectRot(playerid, vehicle_radar_player[playerid][vrp_Object], vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz]);
            
            Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
            return 1;
        }

        #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerEditObject_vradar
            return OnPlayerEditObject_vradar(playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ);
        #else
            return 1;
        #endif
    }

    #if !defined _inc_y_hooks && !defined _INC_y_hooks
        #if defined _ALS_OnPlayerEditObject
            #undef OnPlayerEditObject
        #else
            #define _ALS_OnPlayerEditObject
        #endif
        #define OnPlayerEditObject OnPlayerEditObject_vradar
        #if defined OnPlayerEditObject_vradar
            forward OnPlayerEditObject_vradar(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ);
        #endif
    #endif


    stock VehicleRadarList(playerid)
    {
        vehicle_radar_player[playerid][vrpList_EditRadar][0] = true;
        vehicle_radar_player[playerid][vrpList_EditRadar][1] = false;
        vehicle_radar_player[playerid][vrpList_Page] = 0;
        vehicle_radar_player[playerid][vrpList_Page_Button_Back] = 0;

        Dialog_Show(playerid, Dialog:_vehicle_radar_List);
        return 1;
    }

    DialogCreate:_vehicle_radar_List(playerid)
    {
        new string[ (27+ 10+10+10+16) * VEHICLE_RADAR_MAX_PAGES_LIST + 91] = "{FFFFFF}ID\t{FFFFFF}Скорость срабатывания\t{FFFFFF}Дистанция срабатывания\t{FFFFFF}Статус\n";
        for(new x; x < VEHICLE_RADAR_MAX_PAGES_LIST; x ++) vehicle_radar_player[playerid][vrpList_SlotID][x] = -1;

        new line_max, block_back_button;
        for(new x = (vehicle_radar_player[playerid][vrpList_Page] * VEHICLE_RADAR_MAX_PAGES_LIST)+1; x < MAX_VEHICLE_RADAR; x ++)
        {
            if(x >= MAX_PROMO_CODE) break;
            if(vehicle_radar[x][vr_Create] == false) continue;
            if(line_max <= VEHICLE_RADAR_MAX_PAGES_LIST-1)
            {
                vehicle_radar_player[playerid][vrpList_SlotID][line_max] = x;
                format(string, sizeof(string), "%s#%d\t%d км/ч\t%.1fm\t%s\n", string, x, vehicle_radar[x][vr_SpeedLimit], vehicle_radar[x][vr_ZoneSize], (vehicle_radar[x][vr_Disabled] == false) ? ("{8fce00}Включен"):("{f44747}Выключен"));    

                if(x >= MAX_PROMO_CODE -1)
                {
                    if(vehicle_radar_player[playerid][vrpList_Page] >= 1) block_back_button = 1;
                    break;
                }
            }
            line_max ++;
            if(line_max >= VEHICLE_RADAR_MAX_PAGES_LIST+1)
            {
                block_back_button = 2;
                strcat(string, "> Дальше\n");
                if(vehicle_radar_player[playerid][vrpList_Page] >= 1) strcat(string, "< Назад\n");
                break;
            }
        }
        if(vehicle_radar_player[playerid][vrpList_Page] >= 1 && block_back_button == 0 || block_back_button == 1)
        {
            strcat(string, "< Назад\n");
            vehicle_radar_player[playerid][vrpList_Page_Button_Back] = line_max + ((block_back_button == 0) ? (1):(2));
        }
        if(line_max == 0) return Dialog_Message(playerid, "Список автомобильных радаров", "{FFFFFF}Нет созданных автомобильных радаров.", "Закрыть");

        Dialog_Open(playerid, Dialog:_vehicle_radar_List, DIALOG_STYLE_TABLIST_HEADERS, "Список автомобильных радаров", string, "Выбрать", "Отмена");
        return 1;
    }

    DialogResponse:_vehicle_radar_List(playerid, response, listitem, inputtext[])
    {
        if(!response) return 1;
        switch(listitem)
        {
            case VEHICLE_RADAR_MAX_PAGES_LIST:
            {
                if(vehicle_radar_player[playerid][vrpList_Page_Button_Back] >= 1 && vehicle_radar_player[playerid][vrpList_Page_Button_Back] == listitem+1 && vehicle_radar_player[playerid][vrpList_Page] >= 1)
                {
                    vehicle_radar_player[playerid][vrpList_Page] --;
                    vehicle_radar_player[playerid][vrpList_Page_Button_Back] = 0;
                }
                else vehicle_radar_player[playerid][vrpList_Page] ++;

                Dialog_Show(playerid, Dialog:_vehicle_radar_List);
                return 1;
            }
            case VEHICLE_RADAR_MAX_PAGES_LIST+1:
            {
                if(vehicle_radar_player[playerid][vrpList_Page] >= 1)
                {
                    vehicle_radar_player[playerid][vrpList_Page] --;
                    Dialog_Show(playerid, Dialog:_vehicle_radar_List);
                }
                return 1;
            }
            default:
            {
                if(vehicle_radar_player[playerid][vrpList_Page_Button_Back] >= 1 && vehicle_radar_player[playerid][vrpList_Page_Button_Back] == listitem+1 && vehicle_radar_player[playerid][vrpList_Page] >= 1)
                {
                    vehicle_radar_player[playerid][vrpList_Page] --;
                    vehicle_radar_player[playerid][vrpList_Page_Button_Back] = 0;
                    Dialog_Show(playerid, Dialog:_vehicle_radar_List);
                    return 1;
                }
                new radarid = vehicle_radar_player[playerid][vrpList_SlotID][listitem];
                if(vehicle_radar[radarid][vr_Create] == false) return 1;

                vehicle_radar_player[playerid][vrpList_LineID] = radarid;
                vehicle_radar_player[playerid][vrpList_EditRadar][1] = false;

                vehicle_radar_player[playerid][vrp_Disabled] = vehicle_radar[radarid][vr_Disabled];
                vehicle_radar_player[playerid][vrp_x] = vehicle_radar[radarid][vr_Object_x];
                vehicle_radar_player[playerid][vrp_y] = vehicle_radar[radarid][vr_Object_y];
                vehicle_radar_player[playerid][vrp_z] = vehicle_radar[radarid][vr_Object_z];
                vehicle_radar_player[playerid][vrp_rx] = vehicle_radar[radarid][vr_Object_rx];
                vehicle_radar_player[playerid][vrp_ry] = vehicle_radar[radarid][vr_Object_ry];
                vehicle_radar_player[playerid][vrp_rz] = vehicle_radar[radarid][vr_Object_rz];
                vehicle_radar_player[playerid][vrp_Worldid] = vehicle_radar[radarid][vr_Object_Worldid];
                vehicle_radar_player[playerid][vrp_Interiorid] = vehicle_radar[radarid][vr_Object_Interiorid];
                vehicle_radar_player[playerid][vrp_ZoneSize] = vehicle_radar[radarid][vr_ZoneSize];
                vehicle_radar_player[playerid][vrp_SpeedLimit] = vehicle_radar[radarid][vr_SpeedLimit];

                vehicle_radar_player[playerid][vrp_EditObject] = false;

                Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
                return 1;
            }
        }
        return 1;
    }

    DialogResponse:_vehicle_radar_Savechanges(playerid, response, listitem, inputtext[])
    {
        if(response && vehicle_radar_player[playerid][vrpList_EditRadar][1] == true)
        {
            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            if(vehicle_radar[radarid][vr_Create] == false) return 1;
        
            vehicle_radar[radarid][vr_Disabled] = vehicle_radar_player[playerid][vrp_Disabled];
            vehicle_radar[radarid][vr_Object_x] = vehicle_radar_player[playerid][vrp_x];
            vehicle_radar[radarid][vr_Object_y] = vehicle_radar_player[playerid][vrp_y];
            vehicle_radar[radarid][vr_Object_z] = vehicle_radar_player[playerid][vrp_z];
            vehicle_radar[radarid][vr_Object_rx] = vehicle_radar_player[playerid][vrp_rx];
            vehicle_radar[radarid][vr_Object_ry] = vehicle_radar_player[playerid][vrp_ry];
            vehicle_radar[radarid][vr_Object_rz] = vehicle_radar_player[playerid][vrp_rz];
            vehicle_radar[radarid][vr_Object_Worldid] = vehicle_radar_player[playerid][vrp_Worldid];
            vehicle_radar[radarid][vr_Object_Interiorid] = vehicle_radar_player[playerid][vrp_Interiorid];
            vehicle_radar[radarid][vr_ZoneSize] = vehicle_radar_player[playerid][vrp_ZoneSize];
            vehicle_radar[radarid][vr_SpeedLimit] = vehicle_radar_player[playerid][vrp_SpeedLimit];


            if(IsValidDynamicObject(vehicle_radar[radarid][vr_Object])) DestroyDynamicObject(vehicle_radar[radarid][vr_Object]);
            vehicle_radar[radarid][vr_Object] = CreateDynamicObject(VEHICLE_RADAR_OBJECT_MODEL, vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z],  vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz],  vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid], -1, VEHICLE_RADAR_OBJECT_DISTANCE, VEHICLE_RADAR_OBJECT_DISTANCE);

            if(IsValidDynamicArea(vehicle_radar[radarid][vr_Sphere])) DestroyDynamicArea(vehicle_radar[radarid][vr_Sphere]);
            vehicle_radar[radarid][vr_Sphere] = CreateDynamicSphere(vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z], vehicle_radar[radarid][vr_ZoneSize], vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid]);
        
            if(vehicle_radar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID)
            {
                DestroyDynamic3DTextLabel(vehicle_radar[radarid][vr_Text3D]);
                new string[VEHICLE_RADAR_3DTEXT_LENGTH];
                if(strlen(vehicle_radar[radarid][vr_Text3D_Text]) == 2 && vehicle_radar[radarid][vr_Text3D_Text][0] == '-' && vehicle_radar[radarid][vr_Text3D_Text][1] == '1')
                {
                    format(string, sizeof(string), VEHICLE_RADAR_3DTEXT_TEXT, radarid, vehicle_radar[radarid][vr_SpeedLimit]);
                    vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(string, vehicle_radar[radarid][vr_Text3D_Color], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]+vehicle_radar[radarid][vr_Text3D_Z], vehicle_radar[radarid][vr_Text3D_Distance], INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid], -1, vehicle_radar[radarid][vr_Text3D_Distance]);
                }
                else vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(vehicle_radar[radarid][vr_Text3D_Text], vehicle_radar[radarid][vr_Text3D_Color], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]+vehicle_radar[radarid][vr_Text3D_Z], vehicle_radar[radarid][vr_Text3D_Distance], INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid], -1, vehicle_radar[radarid][vr_Text3D_Distance]);
            }

            #if defined OnPlayerVehicleRadarEdit
                OnPlayerVehicleRadarEdit(playerid,
                    radarid,
                    vehicle_radar[radarid][vr_SpeedLimit],
                    vehicle_radar[radarid][vr_ZoneSize],
                    vehicle_radar[radarid][vr_Disabled],
                    vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z],
                    vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz],
                    vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid]
                );
            #endif
        }

        vehicle_radar_player[playerid][vrpList_EditRadar][1] = false;
        Dialog_Show(playerid, Dialog:_vehicle_radar_List);
        return 1;
    }

    DialogResponse:_vehicle_radar_Delete(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        DeleteVehicleRadar(playerid, vehicle_radar_player[playerid][vrpList_LineID]);

        if(vehicle_radar_player[playerid][vrpList_Page] >= 1 && vehicle_radar_player[playerid][vrpList_SlotID][0] != -1 && vehicle_radar_player[playerid][vrpList_SlotID][1] == -1) vehicle_radar_player[playerid][vrpList_Page] --;
        Dialog_Show(playerid, Dialog:_vehicle_radar_List);
        return 1;
    }
#endif
