
/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									30 April 2026
*
*   Version: 1.5
*
*   ---------------------------------------------------
*
*
*	https://github.com/Bren828/vehicle-radar
*
*
*/


#if defined _vehicle_radar_included
	#endinput
#endif
#define _vehicle_radar_included


#if !defined VR_MAX_VEHICLE_RADAR
    #define VR_MAX_VEHICLE_RADAR 200 // Maximum number of radars
#endif

#if !defined VR_INTERFACE_LANGUAGE
    #define VR_INTERFACE_LANGUAGE 0 // 0 - English (default), 1 - Russian
#endif

#if !defined VR_DISABLE_EDITOR
	//#define VR_DISABLE_EDITOR
#endif

#if !defined VR_OBJECT_MODEL
    #define VR_OBJECT_MODEL 18880
#endif

#if !defined VR_OBJECT_DISTANCE
    #define VR_OBJECT_DISTANCE 200.0
#endif

#if !defined VR_VEHICLE_SPEED_MULTIPLIER
    #define VR_VEHICLE_SPEED_MULTIPLIER 179.28625 
#endif

#if !defined VR_RESPONSE_DELAY
    #define VR_RESPONSE_DELAY 10 // seconds
#endif

#if !defined VR_ZONE_MULTIPLIER
    #define VR_ZONE_MULTIPLIER 3 //The larger the multiplier, the larger the entry zone for checking "zone_size"
#endif

#if !defined VR_MAX_ROWS_LIST 
    #define VR_MAX_ROWS_LIST 20 // max dialog list lines
#endif

#if !defined VR_WHITE_COLOR_TAG
	#define VR_WHITE_COLOR_TAG "{ffffff}"
#endif

#if !defined VR_GREEN_COLOR_TAG
	#define VR_GREEN_COLOR_TAG "{8fce00}"
#endif

#if !defined VR_RED_COLOR_TAG
	#define VR_RED_COLOR_TAG "{f44747}"
#endif

#if !defined VR_YELLOW_COLOR_TAG
	#define VR_YELLOW_COLOR_TAG "{F5D742}"
#endif

#if !defined VR_3DTEXT_LENGTH
	#define VR_3DTEXT_LENGTH 144
#endif

#if !defined VR_3DTEXT_DISTANCE
    #define VR_3DTEXT_DISTANCE 15.0 // 3d text draw distance
#endif

#if !defined VR_TEXT
    #if VR_INTERFACE_LANGUAGE == 0
	    static VR_TEXT[] = "Speed radar "VR_GREEN_COLOR_TAG"#%d"VR_WHITE_COLOR_TAG"\nSpeed limit: "VR_GREEN_COLOR_TAG"%d (km/h)";
    #else 
	    static VR_TEXT[] = "Радар скорости "VR_GREEN_COLOR_TAG"#%d"VR_WHITE_COLOR_TAG"\nОграничение скорости: "VR_GREEN_COLOR_TAG"%d (km/h)";
    #endif
#endif


#define VR_STREAMER_CUSTOM_TYPE 0xFF02CDFA

enum (<<= 1) {
    VR_STREAMER_TYPE = 0,
    VR_STREAMER_ID = 1,
    VR_STREAMER_AREA_ID = 2
}


enum E_VEHICLE_RADAR {
    bool:vr_Created,
    bool:vr_Disabled,

    vr_Object,
    Float:vr_X,
    Float:vr_Y,
    Float:vr_Z,
    Float:vr_RX,
    Float:vr_RY,
    Float:vr_RZ,
    vr_World,
    vr_Interior,

    vr_Sphere,
    Float:vr_ZoneSize,
    vr_SpeedLimit,
    vr_ActivationCount,
    vr_ExtraValue, 

    Text3D:vr_Text3D,
    vr_Text3D_Text[VR_3DTEXT_LENGTH],
    vr_Text3D_Color,
    bool:vr_CustomText3D
}

static VehicleRadar[VR_MAX_VEHICLE_RADAR][E_VEHICLE_RADAR];


enum E_PLAYER_VEHICLE_RADAR {
    pvr_AreaID,
    pvr_RadarID,
    pvr_Timer,
    pvr_ResponseDelay,
    pvr_RadarIDResponseDelay
}

static PlayerVehicleRadar[MAX_PLAYERS][E_PLAYER_VEHICLE_RADAR];


#if !defined VR_DISABLE_EDITOR

    #if !defined _mdialog_included
        #error "Please include mdialog.inc before vehicle-radar.inc or disable VR_DISABLE_EDITOR"
    #endif

#if VR_INTERFACE_LANGUAGE == 0
    static const VR_SELECT_BUTTON[] = "Select";
    static const VR_FURTHER_BUTTON[] = "Further";
    static const VR_YES_BUTTON[] = "Yes";

    static const VR_CANCEL_BUTTON[] = "Cancel";
    static const VR_BACK_BUTTON[] = "Back";
    static const VR_CLOSE_BUTTON[] = "Close";

    static const VR_TEXT_OFF[] = ""VR_RED_COLOR_TAG"Off";
    static const VR_TEXT_ON[] = ""VR_GREEN_COLOR_TAG"On";

    static const VR_RadarCreationDialogText[] =
        "%s\t\n\
        Position\tX: %.1f | Y: %.1f | Z: %.1f\n\
        Trigger distance\t%.1fm\n\
        Speed limit\t%d km/h\n\
        Status\t%s\n\
        Virtual world\t%d\n\
        Interior\t%d";

    static const VR_TEXT_CREATE[] = ""VR_GREEN_COLOR_TAG"Create a radar";
    static const VR_TEXT_REMOVE[] = ""VR_RED_COLOR_TAG"Remove radar";
    static const VR_TEXT_TRIGGER[] = "Triggers";
    static const VR_TEXT_CREATING[] = "Creating a radar";
    static const VR_TEXT_TELEPORT[] = "Teleport to radar";
    static const VR_TEXT_EDITING[] = "Radar editing";
    static const VR_TEXT_STATUS[] = "Status";

    static const VR_TEXT_SAVE_TITLE[] = "Acceptance of changes";
    static const VR_TEXT_SAVE[] = ""VR_WHITE_COLOR_TAG"Save changes?";

    static const VR_TEXT_DELETE_TITLE[] = "Remove radar";
    static const VR_TEXT_DELETE_TEXT[] = ""VR_WHITE_COLOR_TAG"Delete radar "VR_YELLOW_COLOR_TAG"ID: %d ?";
    static const VR_TEXT_RADAR_LIMIT[] = ""VR_WHITE_COLOR_TAG"The maximum number of radars has been created";

    static const VR_TEXT_TRIGGER_TITLE[] = "Trigger distance";
    static const VR_TEXT_TRIGGER_TEXT[] = ""VR_WHITE_COLOR_TAG"Enter the trigger distance:";

    static const VR_TEXT_SPEED_LIMIT_TITLE[] = "Speed limit";
    static const VR_TEXT_SPEED_LIMIT_TEXT[] = ""VR_WHITE_COLOR_TAG"Enter the speed limit:";

    static const VR_TEXT_WORLD_TITLE[] = "Virtual world";
    static const VR_TEXT_WORLD_TEXT[] = ""VR_WHITE_COLOR_TAG"Enter the Virtual world ID:";

    static const VR_TEXT_INTERIOR_TITLE[] = "Interior";
    static const VR_TEXT_INTERIOR_TEXT[] = ""VR_WHITE_COLOR_TAG"Enter the interior ID:";

    static const VR_TEXT_LIST_RADARS[] = "List of radars";
    static const VR_TEXT_NOT_CREATED[] = ""VR_WHITE_COLOR_TAG"No radars created.";

#else 

    static const VR_SELECT_BUTTON[] = "Выбрать";
    static const VR_FURTHER_BUTTON[] = "Дальше";
    static const VR_YES_BUTTON[] = "Да";

    static const VR_CANCEL_BUTTON[] = "Отмена";
    static const VR_BACK_BUTTON[] = "Назад";
    static const VR_CLOSE_BUTTON[] = "Закрыть";

    static const VR_TEXT_OFF[] = ""VR_RED_COLOR_TAG"Выкл";
    static const VR_TEXT_ON[] = ""VR_GREEN_COLOR_TAG"Вкл";

    static const VR_RadarCreationDialogText[] =
        "%s\t\n\
        Позиция\tX: %.1f | Y: %.1f | Z: %.1f\n\
        Зона срабатывания\t%.1fm\n\
        Лимит скорости\t%d km/h\n\
        Статус\t%s\n\
        Виртуальный мир\t%d\n\
        Интерьер\t%d";

    static const VR_TEXT_CREATE[] = ""VR_GREEN_COLOR_TAG"Создать радар";
    static const VR_TEXT_REMOVE[] = ""VR_RED_COLOR_TAG"Удалить радар";
    static const VR_TEXT_TRIGGER[] = "Срабатываний";
    static const VR_TEXT_CREATING[] = "Создание радара";
    static const VR_TEXT_TELEPORT[] = "Телепортироваться к радару";
    static const VR_TEXT_EDITING[] = "Редактирование";
    static const VR_TEXT_STATUS[] = "Статус";
    
    static const VR_TEXT_SAVE_TITLE[] = "Принятие изменений";
    static const VR_TEXT_SAVE[] = ""VR_WHITE_COLOR_TAG"Сохранить изменения?";

    static const VR_TEXT_DELETE_TITLE[] = "Удалить радар";
    static const VR_TEXT_DELETE_TEXT[] = ""VR_WHITE_COLOR_TAG"Удалить радар "VR_YELLOW_COLOR_TAG"ID: %d ?";
    static const VR_TEXT_RADAR_LIMIT[] = ""VR_WHITE_COLOR_TAG"Создано максимальное количество радаров";

    static const VR_TEXT_TRIGGER_TITLE[] = "Зона срабатывания";
    static const VR_TEXT_TRIGGER_TEXT[] = ""VR_WHITE_COLOR_TAG"Введите расстояние срабатывания:";

    static const VR_TEXT_SPEED_LIMIT_TITLE[] = "Лимит скорости";
    static const VR_TEXT_SPEED_LIMIT_TEXT[] = ""VR_WHITE_COLOR_TAG"Введите ограничение скорости:";

    static const VR_TEXT_WORLD_TITLE[] = "Виртуальный мир";
    static const VR_TEXT_WORLD_TEXT[] = ""VR_WHITE_COLOR_TAG"Введите новый ID виртуального мира:";

    static const VR_TEXT_INTERIOR_TITLE[] = "Интерьер";
    static const VR_TEXT_INTERIOR_TEXT[] = ""VR_WHITE_COLOR_TAG"Введите новый ID интерьера:";

    static const VR_TEXT_LIST_RADARS[] = "Список радаров";
    static const VR_TEXT_NOT_CREATED[] = ""VR_WHITE_COLOR_TAG"Нет созданных радаров.";
#endif

    enum E_VEHICLE_RADAR_EDITOR {
        bool:vre_Disabled,
        Float:vre_X,
        Float:vre_Y,
        Float:vre_Z,
        Float:vre_RX,
        Float:vre_RY,
        Float:vre_RZ,
        Float:vre_ZoneSize,
        vre_SpeedLimit,
        vre_World,
        vre_Interior,
        vre_Object,
        vre_EditObject,

        //dialog
        vre_Page,
        vre_BackButton,
        vre_SlotID[VR_MAX_ROWS_LIST],
        vre_SelectedRadarID,
        bool:vre_EnableEditing,
        bool:vre_WasChangeRadar
    }

    static VehicleRadarEditor[MAX_PLAYERS][E_VEHICLE_RADAR_EDITOR];
#endif



stock CreateVehicleRadar(speedLimit, Float:zoneSize, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, bool:disableText3D = false) {
    
    new radarid;

    for(new i = 1; i < VR_MAX_VEHICLE_RADAR; i ++) {

        if(VehicleRadar[i][vr_Created]) {
            continue;
        }

        radarid = i;
        break;
    }

    if(!radarid) {
        printf("vehicle-radar --->>> The maximum number of transport radars has been created");
        return 0;
    }

    VehicleRadar[radarid][vr_Created] = true;
    VehicleRadar[radarid][vr_Disabled] = disabled;

    VehicleRadar[radarid][vr_X] = x;
    VehicleRadar[radarid][vr_Y] = y;
    VehicleRadar[radarid][vr_Z] = z;
    VehicleRadar[radarid][vr_RX] = rx;
    VehicleRadar[radarid][vr_RY] = ry;
    VehicleRadar[radarid][vr_RZ] = rz;
    VehicleRadar[radarid][vr_World] = worldid;
    VehicleRadar[radarid][vr_Interior] = interiorid;
    
    VehicleRadar[radarid][vr_SpeedLimit] = speedLimit;
    VehicleRadar[radarid][vr_ExtraValue] = 0;
    VehicleRadar[radarid][vr_ActivationCount] = 0;


//Object
    VehicleRadar[radarid][vr_Object] = CreateDynamicObject(
        VR_OBJECT_MODEL, 
        x, y, z,  
        rx, ry, rz,  
        worldid, 
        interiorid, 
        -1, 
        VR_OBJECT_DISTANCE, VR_OBJECT_DISTANCE);
    

//Sphere
    VehicleRadar[radarid][vr_ZoneSize] = zoneSize;
    VehicleRadar[radarid][vr_Sphere] = CreateDynamicSphere(x, y, z, zoneSize * VR_ZONE_MULTIPLIER, worldid, interiorid);

    new rd_arr[3];
    rd_arr[VR_STREAMER_TYPE] = VR_STREAMER_CUSTOM_TYPE;
    rd_arr[VR_STREAMER_ID] = radarid;
    rd_arr[VR_STREAMER_AREA_ID] = VehicleRadar[radarid][vr_Sphere];
    Streamer_SetArrayData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_EXTRA_ID, rd_arr);    
    

    //Text3D
    VehicleRadar[radarid][vr_Text3D] = Text3D:INVALID_3DTEXT_ID;
    format(VehicleRadar[radarid][vr_Text3D_Text], VR_3DTEXT_LENGTH, VR_TEXT, radarid, speedLimit);

    VehicleRadar[radarid][vr_Text3D_Color] = -1;
    VehicleRadar[radarid][vr_CustomText3D] = false;


    if(!disableText3D) {
        VehicleRadar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(
            VehicleRadar[radarid][vr_Text3D_Text], 
            VehicleRadar[radarid][vr_Text3D_Color], 
            x, 
            y, 
            z + 6.0, 
            VR_3DTEXT_DISTANCE, 
            INVALID_PLAYER_ID, 
            INVALID_VEHICLE_ID, 
            0, 
            worldid, 
            interiorid);
    }

    return radarid;
}


stock IsVehicleRadarCreated(radarid) {

    if(radarid <= 0 || radarid >= VR_MAX_VEHICLE_RADAR) {
        return 0;
    }

    return VehicleRadar[radarid][vr_Created];
}


stock DeleteVehicleRadar(playerid, radarid, bool:callback = true) {

    if(!IsVehicleRadarCreated(radarid) || playerid == -1) {
        return 0;
    }

    if(IsValidDynamicObject(VehicleRadar[radarid][vr_Object])) {
        DestroyDynamicObject(VehicleRadar[radarid][vr_Object]);
    }

    if(IsValidDynamicArea(VehicleRadar[radarid][vr_Sphere])) {
        DestroyDynamicArea(VehicleRadar[radarid][vr_Sphere]);
    }

    if(VehicleRadar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID) {
        DestroyDynamic3DTextLabel(VehicleRadar[radarid][vr_Text3D]);
    }

    if(callback) {
        #if defined OnPlayerVehicleRadarDelete
            OnPlayerVehicleRadarDelete(playerid, radarid, VehicleRadar[radarid][vr_ExtraValue]);
        #endif
    }

    VehicleRadar[radarid][vr_Created] = false;
    VehicleRadar[radarid][vr_Object] = 0;
    VehicleRadar[radarid][vr_Sphere] = 0;
    VehicleRadar[radarid][vr_Text3D] = Text3D:INVALID_3DTEXT_ID;
    return 1;
}



stock SetVehicleRadarActivationCount(radarid, count) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    VehicleRadar[radarid][vr_ActivationCount] = count;
    return 1;
}



stock GetVehicleRadarActivationCount(radarid) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    return VehicleRadar[radarid][vr_ActivationCount];
}



stock SetVehicleRadarSpeedLimit(radarid, speed) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    VehicleRadar[radarid][vr_SpeedLimit] = speed;

    if(!VehicleRadar[radarid][vr_CustomText3D]) { 
        format(VehicleRadar[radarid][vr_Text3D_Text], VR_3DTEXT_LENGTH, VR_TEXT, radarid, VehicleRadar[radarid][vr_SpeedLimit]);
        UpdateDynamic3DTextLabelText(VehicleRadar[radarid][vr_Text3D], VehicleRadar[radarid][vr_Text3D_Color], VehicleRadar[radarid][vr_Text3D_Text]);
    }
    return 1;
}



stock GetVehicleRadarSpeedLimit(radarid) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }

    return VehicleRadar[radarid][vr_SpeedLimit];
}



stock SetVehicleRadarZoneSize(radarid, Float:zoneSize) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    VehicleRadar[radarid][vr_ZoneSize] = zoneSize;

    Streamer_SetFloatData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_SIZE, VehicleRadar[radarid][vr_ZoneSize] * VR_ZONE_MULTIPLIER);
    return 1;
}



stock Float:GetVehicleRadarZoneSize(radarid) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0.0;
    }
    
    return VehicleRadar[radarid][vr_ZoneSize];
}



stock UpdateVehicleRadarText(radarid, const text[], color, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }

    if(VehicleRadar[radarid][vr_Text3D] == Text3D:INVALID_3DTEXT_ID) {
        return 0;
    }

    x = (x == 0.0) ? (VehicleRadar[radarid][vr_X]) : (x);
    y = (y == 0.0) ? (VehicleRadar[radarid][vr_Y]) : (y);
    z = (z == 0.0) ? (VehicleRadar[radarid][vr_Z] + 6.0) : (z);

    if(text[0] == '-') {
        if(!VehicleRadar[radarid][vr_CustomText3D]) { 
            format(VehicleRadar[radarid][vr_Text3D_Text], VR_3DTEXT_LENGTH, VR_TEXT, radarid, VehicleRadar[radarid][vr_SpeedLimit]);
        }
    }
    else {
        format(VehicleRadar[radarid][vr_Text3D_Text], VR_3DTEXT_LENGTH, text);
    }

    VehicleRadar[radarid][vr_Text3D_Color] = color;
    VehicleRadar[radarid][vr_CustomText3D] = true;

    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, VehicleRadar[radarid][vr_Text3D], E_STREAMER_X, x);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, VehicleRadar[radarid][vr_Text3D], E_STREAMER_Y, y);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, VehicleRadar[radarid][vr_Text3D], E_STREAMER_Z, z);

    Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, VehicleRadar[radarid][vr_Text3D], E_STREAMER_WORLD_ID, VehicleRadar[radarid][vr_World]);
    Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, VehicleRadar[radarid][vr_Text3D], E_STREAMER_INTERIOR_ID, VehicleRadar[radarid][vr_Interior]);

    UpdateDynamic3DTextLabelText(VehicleRadar[radarid][vr_Text3D], color, VehicleRadar[radarid][vr_Text3D_Text]);
    return 1;
}



stock SetVehicleRadarExtraValue(radarid, value) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    VehicleRadar[radarid][vr_ExtraValue] = value;
    return 1;
}



stock GetVehicleRadarExtraValue(radarid) {

    if(!IsVehicleRadarCreated(radarid)) {
        return 0;
    }
    
    return VehicleRadar[radarid][vr_ExtraValue];
}



static stock R_GetVehicleSpeed(vehicleid) {

    new Float:x, 
        Float:y, 
        Float:z;

    GetVehicleVelocity(vehicleid, x, y, z);
	return floatround(floatsqroot(floatpower(x, 2.0) + floatpower(y, 2.0) + floatpower(z, 2.0)) * VR_VEHICLE_SPEED_MULTIPLIER);
}


#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerEnterDynamicArea(playerid, areaid)
#else
	public OnPlayerEnterDynamicArea(playerid, areaid)
#endif
{

    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER) {

        new rd_arr[3];
        Streamer_GetArrayData(STREAMER_TYPE_AREA, areaid, E_STREAMER_EXTRA_ID, rd_arr);

        if(rd_arr[VR_STREAMER_TYPE] == VR_STREAMER_CUSTOM_TYPE && areaid == rd_arr[VR_STREAMER_AREA_ID]) {

            new radarid = rd_arr[VR_STREAMER_ID];

            if(!VehicleRadar[radarid][vr_Disabled]) {
                PlayerVehicleRadar[playerid][pvr_AreaID] = areaid;
                PlayerVehicleRadar[playerid][pvr_RadarID] = radarid;

                if(!PlayerVehicleRadar[playerid][pvr_Timer]) {
                    PlayerVehicleRadar[playerid][pvr_Timer] = SetTimerEx("VR_PlayerTimer", 200, true, "d", playerid);
                }
            }
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



#if defined _inc_y_hooks || defined _INC_y_hooks
	hook OnPlayerLeaveDynamicArea(playerid, areaid)
#else
	public OnPlayerLeaveDynamicArea(playerid, areaid)
#endif
{
    if(PlayerVehicleRadar[playerid][pvr_AreaID] == areaid) {

        PlayerVehicleRadar[playerid][pvr_AreaID] = 0;

        KillTimer(PlayerVehicleRadar[playerid][pvr_Timer]);
        PlayerVehicleRadar[playerid][pvr_Timer] = 0;
    }

    #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerLeaveDynamicArea_vradar
		return OnPlayerLeaveDynamicArea_vradar(playerid, areaid);
	#else
		return 1;
	#endif
}

#if !defined _inc_y_hooks && !defined _INC_y_hooks
	#if defined _ALS_OnPlayerLeaveDynamicArea
		#undef OnPlayerLeaveDynamicArea
	#else
		#define _ALS_OnPlayerLeaveDynamicArea
	#endif
	#define OnPlayerLeaveDynamicArea OnPlayerLeaveDynamicArea_vradar
	#if defined OnPlayerLeaveDynamicArea_vradar
		forward OnPlayerLeaveDynamicArea_vradar(playerid, areaid);
	#endif
#endif



forward VR_PlayerTimer(playerid);
public VR_PlayerTimer(playerid) {

    new vehicleid = GetPlayerVehicleID(playerid),
        radarid = PlayerVehicleRadar[playerid][pvr_RadarID];

    if(!IsVehicleRadarCreated(radarid)) {
        PlayerVehicleRadar[playerid][pvr_AreaID] = 0;

        KillTimer(PlayerVehicleRadar[playerid][pvr_Timer]);
        PlayerVehicleRadar[playerid][pvr_Timer] = 0;
        return 1;
    }

    if(VehicleRadar[radarid][vr_Disabled]) {
        return 1;
    }

    if(PlayerVehicleRadar[playerid][pvr_ResponseDelay] != 0 && 
        PlayerVehicleRadar[playerid][pvr_ResponseDelay] >= gettime() && 
        PlayerVehicleRadar[playerid][pvr_RadarIDResponseDelay] == radarid) {
        return 1;
    }

    new Float:distance = GetPlayerDistanceFromPoint(playerid, 
        VehicleRadar[radarid][vr_X],
        VehicleRadar[radarid][vr_Y],
        VehicleRadar[radarid][vr_Z]);

    if(vehicleid && 
       GetPlayerState(playerid) == PLAYER_STATE_DRIVER && 
       distance < VehicleRadar[radarid][vr_ZoneSize] && 
       R_GetVehicleSpeed(vehicleid) >= VehicleRadar[radarid][vr_SpeedLimit]) {

        PlayerVehicleRadar[playerid][pvr_ResponseDelay] = gettime() + VR_RESPONSE_DELAY;
        PlayerVehicleRadar[playerid][pvr_RadarIDResponseDelay] = radarid;

        VehicleRadar[radarid][vr_ActivationCount] ++;

        #if defined OnPlayerEnterVehicleRadar
            OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, VehicleRadar[radarid][vr_ActivationCount]);
        #endif
    }
    return 1;
}



public OnPlayerConnect(playerid) {

    PlayerVehicleRadar[playerid][pvr_AreaID] = 0;
    PlayerVehicleRadar[playerid][pvr_Timer] = 0;

    #if defined OnPlayerConnect_vradar
        return OnPlayerConnect_vradar(playerid);
    #else 
        return 1;
    #endif
}
#if defined _ALS_OnPlayerConnect
    #undef OnPlayerConnect
#else
    #define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect OnPlayerConnect_vradar
#if defined OnPlayerConnect_vradar
    forward OnPlayerConnect_vradar(playerid);
#endif



public OnPlayerDisconnect(playerid, reason) {

    if(PlayerVehicleRadar[playerid][pvr_AreaID]) {
        PlayerVehicleRadar[playerid][pvr_AreaID] = 0;
        
        KillTimer(PlayerVehicleRadar[playerid][pvr_Timer]);
        PlayerVehicleRadar[playerid][pvr_Timer] = 0;
    }

    #if !defined VR_DISABLE_EDITOR
        if(VehicleRadarEditor[playerid][vre_EditObject] != 0 || VehicleRadarEditor[playerid][vre_WasChangeRadar]) {

            if(VehicleRadarEditor[playerid][vre_EditObject] == 2 || VehicleRadarEditor[playerid][vre_WasChangeRadar]) {
                new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

                SetDynamicObjectPos(VehicleRadar[radarid][vr_Object], 
                    VehicleRadar[radarid][vr_X], 
                    VehicleRadar[radarid][vr_Y], 
                    VehicleRadar[radarid][vr_Z]);
                
                SetDynamicObjectRot(VehicleRadar[radarid][vr_Object], 
                    VehicleRadar[radarid][vr_RX], 
                    VehicleRadar[radarid][vr_RY], 
                    VehicleRadar[radarid][vr_RZ]);
            } 

            if(IsValidPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object])) {
                DestroyPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object]);
            }
            
            VehicleRadarEditor[playerid][vre_Object] = 0;
            VehicleRadarEditor[playerid][vre_EditObject] = 0;
        }
    #endif

    #if defined OnPlayerDisconnect_vradar
        return OnPlayerDisconnect_vradar(playerid, reason);
    #else 
        return 1;
    #endif
}
#if defined _ALS_OnPlayerDisconnect
    #undef OnPlayerDisconnect
#else
    #define _ALS_OnPlayerDisconnect
#endif
#define OnPlayerDisconnect OnPlayerDisconnect_vradar
#if defined OnPlayerDisconnect_vradar
    forward OnPlayerDisconnect_vradar(playerid, reason);
#endif



#if !defined VR_DISABLE_EDITOR
    stock ShowRadarCreationDialog(playerid) {
        
        VehicleRadarEditor[playerid][vre_EnableEditing] = false;
        VehicleRadarEditor[playerid][vre_Disabled] = false;

        VehicleRadarEditor[playerid][vre_RX] = 0.0;
        VehicleRadarEditor[playerid][vre_RY] = 0.0;
        VehicleRadarEditor[playerid][vre_RZ] = 0.0;
        VehicleRadarEditor[playerid][vre_World] = GetPlayerVirtualWorld(playerid);
        VehicleRadarEditor[playerid][vre_Interior] = GetPlayerInterior(playerid);
        GetPlayerPos(playerid, VehicleRadarEditor[playerid][vre_X], VehicleRadarEditor[playerid][vre_Y], VehicleRadarEditor[playerid][vre_Z]);

        VehicleRadarEditor[playerid][vre_ZoneSize] = 30.0;
        VehicleRadarEditor[playerid][vre_SpeedLimit] = 50;

        if(IsValidPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object])) {
            DestroyPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object]);
        }

        VehicleRadarEditor[playerid][vre_Object] = 0;
        VehicleRadarEditor[playerid][vre_EditObject] = 1;

        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    DialogCreate:vrd_Create(playerid) {

        new vr_string[sizeof(VR_RadarCreationDialogText) + 
            sizeof(VR_TEXT_CREATE) + 
            sizeof(VR_TEXT_OFF) + 
            20 + 
            (4 * 10) + 
            sizeof(VR_TEXT_TELEPORT)];

        new vr_caption[sizeof(VR_TEXT_EDITING) + sizeof(VR_TEXT_TRIGGER) + 8 + 10];
        
        new Float:x = VehicleRadarEditor[playerid][vre_X], 
            Float:y = VehicleRadarEditor[playerid][vre_Y], 
            Float:z = VehicleRadarEditor[playerid][vre_Z];

        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

            x = VehicleRadar[radarid][vr_X];
            y = VehicleRadar[radarid][vr_Y];
            z = VehicleRadar[radarid][vr_Z]; 
        }

        format(vr_string, sizeof(vr_string), VR_RadarCreationDialogText,
            (!VehicleRadarEditor[playerid][vre_EnableEditing]) ? (VR_TEXT_CREATE) : (VR_TEXT_REMOVE),
            x, y, z,
            VehicleRadarEditor[playerid][vre_ZoneSize],
            VehicleRadarEditor[playerid][vre_SpeedLimit],
            (!VehicleRadarEditor[playerid][vre_Disabled]) ? (VR_TEXT_ON) : (VR_TEXT_OFF),
            VehicleRadarEditor[playerid][vre_World],
            VehicleRadarEditor[playerid][vre_Interior]);


        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            format(vr_string, sizeof(vr_string), "%s\n%s\t", vr_string, VR_TEXT_TELEPORT);

            new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];
            format(vr_caption, sizeof(vr_caption), "%s | "VR_YELLOW_COLOR_TAG"%s: %d", 
                VR_TEXT_EDITING, 
                VR_TEXT_TRIGGER, 
                VehicleRadar[radarid][vr_ActivationCount]);
        }
        else {
            strcat(vr_caption, VR_TEXT_CREATING);
        }

        Dialog_Open(playerid, Dialog:vrd_Create, DIALOG_STYLE_TABLIST, vr_caption, vr_string, 
            VR_SELECT_BUTTON, 
            (!VehicleRadarEditor[playerid][vre_EnableEditing]) ? VR_CANCEL_BUTTON : VR_BACK_BUTTON);
        return 1;
    }


    DialogResponse:vrd_Create(playerid, response, listitem, inputtext[]) {

        if(!response) {
            if(IsValidPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object])) {
                DestroyPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object]); 
            }

            VehicleRadarEditor[playerid][vre_EditObject] = 0;
            VehicleRadarEditor[playerid][vre_Object] = 0;

            if(VehicleRadarEditor[playerid][vre_EnableEditing]) {

                if(VehicleRadarEditor[playerid][vre_WasChangeRadar]) {
                    Dialog_Open(playerid, Dialog:vrd_SaveChanges, DIALOG_STYLE_MSGBOX, VR_TEXT_SAVE_TITLE, 
                        VR_TEXT_SAVE, 
                        VR_YES_BUTTON, 
                        VR_CANCEL_BUTTON);
                    return 1;
                }

                Dialog_Show(playerid, Dialog:vrd_RadarList);
                return 1;
            }
            return 1;
        }

        switch(listitem) {

            case 0: {

                if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
                    
                    new vr_string[sizeof(VR_TEXT_DELETE_TEXT) + 10];
                  
                    format(vr_string, sizeof(vr_string), VR_TEXT_DELETE_TEXT, VehicleRadarEditor[playerid][vre_SelectedRadarID]);
                    Dialog_Open(playerid, Dialog:vrd_Delete, DIALOG_STYLE_MSGBOX, VR_TEXT_DELETE_TITLE, 
                        vr_string, 
                        VR_YES_BUTTON, 
                        VR_BACK_BUTTON);
                    return 1;
                }

                new radarid = CreateVehicleRadar(
                    VehicleRadarEditor[playerid][vre_SpeedLimit],
                    VehicleRadarEditor[playerid][vre_ZoneSize],
                    VehicleRadarEditor[playerid][vre_X], VehicleRadarEditor[playerid][vre_Y], VehicleRadarEditor[playerid][vre_Z],
                    VehicleRadarEditor[playerid][vre_RX], VehicleRadarEditor[playerid][vre_RY], VehicleRadarEditor[playerid][vre_RZ],
                    VehicleRadarEditor[playerid][vre_World], VehicleRadarEditor[playerid][vre_Interior],
                    VehicleRadarEditor[playerid][vre_Disabled]);

                if(!radarid) {
                    Dialog_Open(playerid, Dialog:vrd_CreateBack, DIALOG_STYLE_MSGBOX, VR_TEXT_CREATING, 
                        VR_TEXT_RADAR_LIMIT, 
                        VR_CLOSE_BUTTON, 
                        VR_BACK_BUTTON);
                    return 1;
                }

                if(IsValidPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object])) {
                    DestroyPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object]);
                }
                
                VehicleRadarEditor[playerid][vre_Object] = 0;

                #if defined OnPlayerVehicleRadarCreate
                    OnPlayerVehicleRadarCreate(playerid,
                        radarid, 
                        VehicleRadarEditor[playerid][vre_SpeedLimit],
                        VehicleRadarEditor[playerid][vre_ZoneSize], 
                        VehicleRadarEditor[playerid][vre_Disabled],
                        VehicleRadarEditor[playerid][vre_X], VehicleRadarEditor[playerid][vre_Y], VehicleRadarEditor[playerid][vre_Z],
                        VehicleRadarEditor[playerid][vre_RX], VehicleRadarEditor[playerid][vre_RY], VehicleRadarEditor[playerid][vre_RZ],
                        VehicleRadarEditor[playerid][vre_World], VehicleRadarEditor[playerid][vre_Interior]);
                #endif
                return 1;
            }

            case 1: {

                if(VehicleRadarEditor[playerid][vre_EnableEditing]) {

                    new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

                    new Float:distance = GetPlayerDistanceFromPoint(playerid, 
                        VehicleRadar[radarid][vr_X], VehicleRadar[radarid][vr_Y], VehicleRadar[radarid][vr_Z]);
                    
                    if(distance >= 20.0) {
                        SetPlayerPos(playerid, 
                        VehicleRadar[radarid][vr_X] + 0.5, 
                        VehicleRadar[radarid][vr_Y] + 0.5, 
                        VehicleRadar[radarid][vr_Z] + 2.0);
                    }

                    VehicleRadarEditor[playerid][vre_EditObject] = 2;
                    EditDynamicObject(playerid, VehicleRadar[radarid][vr_Object]);
                    return 1;
                }

                if(!IsValidPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object])) {

                    VehicleRadarEditor[playerid][vre_Object] = CreatePlayerObject(playerid, 
                        VR_OBJECT_MODEL, 
                        VehicleRadarEditor[playerid][vre_X], VehicleRadarEditor[playerid][vre_Y], VehicleRadarEditor[playerid][vre_Z],
                        VehicleRadarEditor[playerid][vre_RX], VehicleRadarEditor[playerid][vre_RY], VehicleRadarEditor[playerid][vre_RZ], 
                        200.0);

                    SetPlayerPos(playerid, 
                        VehicleRadarEditor[playerid][vre_X] + 0.5, 
                        VehicleRadarEditor[playerid][vre_Y] + 0.5, 
                        VehicleRadarEditor[playerid][vre_Z]);
                }

                new Float:distance = GetPlayerDistanceFromPoint(playerid, 
                    VehicleRadarEditor[playerid][vre_X], 
                    VehicleRadarEditor[playerid][vre_Y], 
                    VehicleRadarEditor[playerid][vre_Z]);
                
                if(distance >= 20.0) {
                    SetPlayerPos(playerid, 
                        VehicleRadarEditor[playerid][vre_X] + 0.5, 
                        VehicleRadarEditor[playerid][vre_Y] + 0.5, 
                        VehicleRadarEditor[playerid][vre_Z] + 2.0);
                }

                VehicleRadarEditor[playerid][vre_EditObject] = 1;
                EditPlayerObject(playerid, VehicleRadarEditor[playerid][vre_Object]);
                return 1;
            }

            case 2: {
                Dialog_Open(playerid, Dialog:vrd_ZoneSize, DIALOG_STYLE_INPUT, VR_TEXT_TRIGGER_TITLE, 
                    VR_TEXT_TRIGGER_TEXT, 
                    VR_SELECT_BUTTON, 
                    VR_CANCEL_BUTTON);
                return 1;
            }

            case 3: {
                Dialog_Open(playerid, Dialog:vrd_SpeedLimit, DIALOG_STYLE_INPUT, VR_TEXT_SPEED_LIMIT_TITLE, 
                    VR_TEXT_SPEED_LIMIT_TEXT, 
                    VR_SELECT_BUTTON, 
                    VR_CANCEL_BUTTON);
                return 1;
            }

            case 4: {

                if(!VehicleRadarEditor[playerid][vre_Disabled]) { 
                    VehicleRadarEditor[playerid][vre_Disabled] = true;
                }
                else { 
                    VehicleRadarEditor[playerid][vre_Disabled] = false;
                }

                if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
                    VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
                }

                Dialog_Show(playerid, Dialog:vrd_Create);
                return 1;
            }

            case 5: {
                Dialog_Open(playerid, Dialog:vrd_World, DIALOG_STYLE_INPUT, VR_TEXT_WORLD_TITLE, 
                    VR_TEXT_WORLD_TEXT, 
                    VR_SELECT_BUTTON, 
                    VR_CANCEL_BUTTON);
                return 1;
            }

            case 6: {
                Dialog_Open(playerid, Dialog:vrd_Interior, DIALOG_STYLE_INPUT, VR_TEXT_INTERIOR_TITLE, 
                    VR_TEXT_INTERIOR_TEXT, 
                    VR_SELECT_BUTTON, 
                    VR_CANCEL_BUTTON);
                return 1;
            }

            case 7: {
                new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

                SetPlayerPos(playerid, 
                    VehicleRadar[radarid][vr_X] + 0.5, 
                    VehicleRadar[radarid][vr_Y] + 0.5, 
                    VehicleRadar[radarid][vr_Z] + 2.0);
                return 1;
            }
        }
        return 1;
    }


    DialogResponse:vrd_CreateBack(playerid, response, listitem, inputtext[]) {
        if(response) {
            return 1;
        }

        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    DialogResponse:vrd_ZoneSize(playerid, response, listitem, inputtext[]) {
        if(!response) {
            return Dialog_Show(playerid, Dialog:vrd_Create);
        }

        if(!strlen(inputtext) || strval(inputtext) <= 0.0) {
            Dialog_Open(playerid, Dialog:vrd_ZoneSize, DIALOG_STYLE_INPUT, VR_TEXT_TRIGGER_TITLE, 
                VR_TEXT_TRIGGER_TEXT, 
                VR_SELECT_BUTTON, 
                VR_CANCEL_BUTTON);
            return 1;
        }

        VehicleRadarEditor[playerid][vre_ZoneSize] = floatstr(inputtext);
        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
        }
        
        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    DialogResponse:vrd_SpeedLimit(playerid, response, listitem, inputtext[]) {

        if(!response) {
            return Dialog_Show(playerid, Dialog:vrd_Create);
        }
        
        if(!strlen(inputtext) || strval(inputtext) < 0) {
            Dialog_Open(playerid, Dialog:vrd_SpeedLimit, DIALOG_STYLE_INPUT, VR_TEXT_SPEED_LIMIT_TITLE, 
                VR_TEXT_SPEED_LIMIT_TEXT, 
                VR_SELECT_BUTTON, 
                VR_CANCEL_BUTTON);
            return 1;
        }

        VehicleRadarEditor[playerid][vre_SpeedLimit] = strval(inputtext);
        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
        }
        
        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    DialogResponse:vrd_World(playerid, response, listitem, inputtext[]) {
        
        if(!response) {
            return Dialog_Show(playerid, Dialog:vrd_Create);
        }

        if(!strlen(inputtext)) {
            Dialog_Open(playerid, Dialog:vrd_World, DIALOG_STYLE_INPUT, VR_TEXT_WORLD_TITLE, 
                VR_TEXT_WORLD_TEXT, 
                VR_SELECT_BUTTON, 
                VR_CANCEL_BUTTON);
            return 1;
        }

        VehicleRadarEditor[playerid][vre_World] = strval(inputtext);
        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
        }

        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    DialogResponse:vrd_Interior(playerid, response, listitem, inputtext[]) {

        if(!response) {
            return Dialog_Show(playerid, Dialog:vrd_Create);
        }

        if(!strlen(inputtext)) {
            Dialog_Open(playerid, Dialog:vrd_Interior, DIALOG_STYLE_INPUT, VR_TEXT_INTERIOR_TITLE, 
                VR_TEXT_INTERIOR_TEXT, 
                VR_SELECT_BUTTON, 
                VR_CANCEL_BUTTON);
            return 1;
        }

        VehicleRadarEditor[playerid][vre_Interior] = strval(inputtext);
        if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
        }
        
        Dialog_Show(playerid, Dialog:vrd_Create);
        return 1;
    }


    #if defined _inc_y_hooks || defined _INC_y_hooks
        hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
    #else
        public OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ)
    #endif
    {
        if(VehicleRadarEditor[playerid][vre_EditObject] == 1 && (response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL)) {

            VehicleRadarEditor[playerid][vre_EditObject] = 0;

            if(response == EDIT_RESPONSE_FINAL) {
                VehicleRadarEditor[playerid][vre_X] = fX;
                VehicleRadarEditor[playerid][vre_Y] = fY;
                VehicleRadarEditor[playerid][vre_Z] = fZ;

                VehicleRadarEditor[playerid][vre_RX] = fRotX;
                VehicleRadarEditor[playerid][vre_RY] = fRotY;
                VehicleRadarEditor[playerid][vre_RZ] = fRotZ;

                if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
                    VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
                }
            }

            SetPlayerObjectPos(playerid, 
                VehicleRadarEditor[playerid][vre_Object], 
                VehicleRadarEditor[playerid][vre_X], 
                VehicleRadarEditor[playerid][vre_Y], 
                VehicleRadarEditor[playerid][vre_Z]);
            
            SetPlayerObjectRot(playerid, 
                VehicleRadarEditor[playerid][vre_Object], 
                VehicleRadarEditor[playerid][vre_RX], 
                VehicleRadarEditor[playerid][vre_RY], 
                VehicleRadarEditor[playerid][vre_RZ]);
            
            Dialog_Show(playerid, Dialog:vrd_Create);
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



    #if defined _inc_y_hooks || defined _INC_y_hooks
        hook OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
    #else
        public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
    #endif
    {
        if(VehicleRadarEditor[playerid][vre_EditObject] == 2 && (response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL)) {

            VehicleRadarEditor[playerid][vre_EditObject] = 0;

            if(response == EDIT_RESPONSE_FINAL) {
                SetDynamicObjectPos(objectid, x, y, z);
                SetDynamicObjectRot(objectid, rx, ry, rz);

                if(VehicleRadarEditor[playerid][vre_EnableEditing]) {
                    VehicleRadarEditor[playerid][vre_WasChangeRadar] = true;
                }
            }
            else {

                new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

                SetDynamicObjectPos(objectid, VehicleRadar[radarid][vr_X], VehicleRadar[radarid][vr_Y], VehicleRadar[radarid][vr_Z]);
                SetDynamicObjectRot(objectid, VehicleRadar[radarid][vr_RX], VehicleRadar[radarid][vr_RY], VehicleRadar[radarid][vr_RZ]);
            }

            Dialog_Show(playerid, Dialog:vrd_Create);
            return 1;
        }

        #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerEditDynamicObjectVradar
            return OnPlayerEditDynamicObjectVradar(playerid, objectid, response, x, y, z, rx, ry, rz);
        #else
            return 1;
        #endif
    }

    #if !defined _inc_y_hooks && !defined _INC_y_hooks
        #if defined _ALS_OnPlayerEditDynamicObject
            #undef OnPlayerEditDynamicObject
        #else
            #define _ALS_OnPlayerEditDynamicObject
        #endif
        #define OnPlayerEditDynamicObject OnPlayerEditDynamicObjectVradar
        #if defined OnPlayerEditDynamicObjectVradar
            forward OnPlayerEditDynamicObjectVradar(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz);
        #endif
    #endif


    stock ShowRadarListDialog(playerid) {

        VehicleRadarEditor[playerid][vre_EnableEditing] = true;
        VehicleRadarEditor[playerid][vre_WasChangeRadar] = false;
        VehicleRadarEditor[playerid][vre_Page] = 1;

        Dialog_Show(playerid, Dialog:vrd_RadarList);
        return 1;
    }

    DialogCreate:vrd_RadarList(playerid) {

        new vr_string[ ((27 + 10 + 10 + 10 + sizeof(VR_TEXT_OFF)) * VR_MAX_ROWS_LIST) + 
            sizeof(VR_FURTHER_BUTTON) + 
            sizeof(VR_BACK_BUTTON) + 
            (4 * 12) + 
            sizeof(VR_TEXT_SPEED_LIMIT_TITLE) + 
            sizeof(VR_TEXT_TRIGGER_TITLE) + 
            sizeof(VR_TEXT_STATUS)];

        format(vr_string, sizeof(vr_string), ""VR_WHITE_COLOR_TAG"ID\t"VR_WHITE_COLOR_TAG"%s\t"VR_WHITE_COLOR_TAG"%s\t"VR_WHITE_COLOR_TAG"%s\n", 
            VR_TEXT_SPEED_LIMIT_TITLE,
            VR_TEXT_TRIGGER_TITLE,
            VR_TEXT_STATUS);
        
        new	max_page = VR_MAX_ROWS_LIST,
            page = VehicleRadarEditor[playerid][vre_Page],
            next = 0,
            totalLine,
            totalRadarLines;

        for(new i = 0; i < VR_MAX_VEHICLE_RADAR; i++) {

            if(!IsVehicleRadarCreated(i)) {
                continue;
            }
  
            if(totalLine >= (page * max_page) && totalLine < (page * max_page) + max_page) {
                next ++;
            }

            if(totalLine >= (page - 1) * max_page && totalLine < ((page - 1) * max_page) + max_page) {

                format(vr_string, sizeof(vr_string), "%s#%d\t%d km/h\t%.1fm\t%s\n", 
                    vr_string, 
                    i, 
                    VehicleRadar[i][vr_SpeedLimit], 
                    VehicleRadar[i][vr_ZoneSize], 
                    (!VehicleRadar[i][vr_Disabled]) ? (VR_TEXT_ON) : (VR_TEXT_OFF));   
          
                VehicleRadarEditor[playerid][vre_SlotID][totalRadarLines] = i;
                totalRadarLines++;
            }

            totalLine++;
        }

        if(next) {
            format(vr_string, sizeof(vr_string), "%s> %s\n", vr_string, VR_FURTHER_BUTTON);
        }

        if(page >= 2) {
            format(vr_string, sizeof(vr_string), "%s> %s", vr_string, VR_BACK_BUTTON);
        }

        if(totalRadarLines == 0 && page <= 1) {
            Dialog_Message(playerid, VR_TEXT_LIST_RADARS, VR_TEXT_NOT_CREATED, VR_CANCEL_BUTTON);
            return 1;
        }	

        Dialog_Open(playerid, Dialog:vrd_RadarList, DIALOG_STYLE_TABLIST_HEADERS, VR_TEXT_LIST_RADARS, 
            vr_string, 
            VR_SELECT_BUTTON, 
            VR_CANCEL_BUTTON);

        return 1;
    }


    DialogResponse:vrd_RadarList(playerid, response, listitem, inputtext[]) {

        if(!response) {
            return 1;
        }

        new vr_TextFurther[sizeof(VR_FURTHER_BUTTON) + 4];
        format(vr_TextFurther, sizeof(vr_TextFurther), "> %s", VR_FURTHER_BUTTON);

        new vr_TextBack[sizeof(VR_BACK_BUTTON) + 4];
        format(vr_TextBack, sizeof(vr_TextBack), "> %s", VR_BACK_BUTTON);

        if(!strcmp(inputtext, vr_TextFurther)) {
            VehicleRadarEditor[playerid][vre_Page]++;
        }
        else if(!strcmp(inputtext, vr_TextBack)) {
            VehicleRadarEditor[playerid][vre_Page]--;	
        }
        else {
            if(!(0 <= listitem < VR_MAX_ROWS_LIST)) {
                return 1;
            }

            new radarid = VehicleRadarEditor[playerid][vre_SlotID][listitem];

            if(!IsVehicleRadarCreated(radarid)) {
                return 1;
            }

            VehicleRadarEditor[playerid][vre_SelectedRadarID] = radarid;
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = false;

            VehicleRadarEditor[playerid][vre_Disabled] = VehicleRadar[radarid][vr_Disabled];
            VehicleRadarEditor[playerid][vre_World] = VehicleRadar[radarid][vr_World];
            VehicleRadarEditor[playerid][vre_Interior] = VehicleRadar[radarid][vr_Interior];
            VehicleRadarEditor[playerid][vre_ZoneSize] = VehicleRadar[radarid][vr_ZoneSize];
            VehicleRadarEditor[playerid][vre_SpeedLimit] = VehicleRadar[radarid][vr_SpeedLimit];

            VehicleRadarEditor[playerid][vre_EditObject] = 0;

            Dialog_Show(playerid, Dialog:vrd_Create);
            return 1;
        }

        Dialog_Show(playerid, Dialog:vrd_RadarList);
        return 1;
    }


    DialogResponse:vrd_SaveChanges(playerid, response, listitem, inputtext[]) {

        new radarid = VehicleRadarEditor[playerid][vre_SelectedRadarID];

        if(!IsVehicleRadarCreated(radarid)) {
            return 1;
        }

        if(!response) {
            SetDynamicObjectPos(VehicleRadar[radarid][vr_Object], 
                VehicleRadar[radarid][vr_X], 
                VehicleRadar[radarid][vr_Y], 
                VehicleRadar[radarid][vr_Z]);

            SetDynamicObjectRot(VehicleRadar[radarid][vr_Object], 
                VehicleRadar[radarid][vr_RX], 
                VehicleRadar[radarid][vr_RY], 
                VehicleRadar[radarid][vr_RZ]);
            
            VehicleRadarEditor[playerid][vre_WasChangeRadar] = false;
            Dialog_Show(playerid, Dialog:vrd_RadarList);
            return 1;
        }

        if(VehicleRadarEditor[playerid][vre_WasChangeRadar]) {

            VehicleRadar[radarid][vr_Disabled] = VehicleRadarEditor[playerid][vre_Disabled];
            VehicleRadar[radarid][vr_World] = VehicleRadarEditor[playerid][vre_World];
            VehicleRadar[radarid][vr_Interior] = VehicleRadarEditor[playerid][vre_Interior];
            VehicleRadar[radarid][vr_ZoneSize] = VehicleRadarEditor[playerid][vre_ZoneSize];
            VehicleRadar[radarid][vr_SpeedLimit] = VehicleRadarEditor[playerid][vre_SpeedLimit];


            //Object
            GetDynamicObjectPos(VehicleRadar[radarid][vr_Object], 
                VehicleRadar[radarid][vr_X], 
                VehicleRadar[radarid][vr_Y], 
                VehicleRadar[radarid][vr_Z]);

            GetDynamicObjectRot(VehicleRadar[radarid][vr_Object], 
                VehicleRadar[radarid][vr_RX], 
                VehicleRadar[radarid][vr_RY], 
                VehicleRadar[radarid][vr_RZ]);
            
            Streamer_SetIntData(STREAMER_TYPE_OBJECT, VehicleRadar[radarid][vr_Object], E_STREAMER_WORLD_ID, VehicleRadar[radarid][vr_World]);
	        Streamer_SetIntData(STREAMER_TYPE_OBJECT, VehicleRadar[radarid][vr_Object], E_STREAMER_INTERIOR_ID, VehicleRadar[radarid][vr_Interior]);


            //AREA
            Streamer_SetFloatData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_X, VehicleRadar[radarid][vr_X]);
            Streamer_SetFloatData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_Y, VehicleRadar[radarid][vr_Y]);
            Streamer_SetFloatData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_Z, VehicleRadar[radarid][vr_Z]);

            Streamer_SetIntData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_WORLD_ID, VehicleRadar[radarid][vr_World]);
            Streamer_SetIntData(STREAMER_TYPE_AREA, VehicleRadar[radarid][vr_Sphere], E_STREAMER_INTERIOR_ID, VehicleRadar[radarid][vr_Interior]);

            SetVehicleRadarZoneSize(radarid, VehicleRadar[radarid][vr_ZoneSize]);


            //Text3D
            if(VehicleRadar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID) {
                new bool:customtext3d = VehicleRadar[radarid][vr_CustomText3D];

                UpdateVehicleRadarText(radarid, "-", 
                    VehicleRadar[radarid][vr_Text3D_Color], 
                    VehicleRadar[radarid][vr_X], 
                    VehicleRadar[radarid][vr_Y], 
                    VehicleRadar[radarid][vr_Z] + 6.0);

                VehicleRadar[radarid][vr_CustomText3D] = customtext3d;    
            }


            #if defined OnPlayerVehicleRadarEdit
                OnPlayerVehicleRadarEdit(playerid,
                    radarid,
                    VehicleRadar[radarid][vr_SpeedLimit],
                    VehicleRadar[radarid][vr_ZoneSize],
                    VehicleRadar[radarid][vr_Disabled],
                    VehicleRadar[radarid][vr_X], VehicleRadar[radarid][vr_Y], VehicleRadar[radarid][vr_Z],
                    VehicleRadar[radarid][vr_RX], VehicleRadar[radarid][vr_RY], VehicleRadar[radarid][vr_RZ],
                    VehicleRadar[radarid][vr_World], VehicleRadar[radarid][vr_Interior]);
            #endif
        }

        VehicleRadarEditor[playerid][vre_WasChangeRadar] = false;
        Dialog_Show(playerid, Dialog:vrd_RadarList);
        return 1;
    }


    DialogResponse:vrd_Delete(playerid, response, listitem, inputtext[]) {

        if(!response) {
            return Dialog_Show(playerid, Dialog:vrd_Create);
        }
        
        DeleteVehicleRadar(playerid, VehicleRadarEditor[playerid][vre_SelectedRadarID]);

        Dialog_Show(playerid, Dialog:vrd_RadarList);
        return 1;
    }
#endif