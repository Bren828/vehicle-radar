
/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									20 October 2023
*
*   Version: 1.4
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


#if !defined MAX_VEHICLE_RADAR
    #define MAX_VEHICLE_RADAR 200
#endif

#if !defined VEHICLE_RADAR_OBJECT_MODEL
    #define VEHICLE_RADAR_OBJECT_MODEL 18880 // object model
#endif

#if !defined VEHICLE_RADAR_OBJECT_DISTANCE
    #define VEHICLE_RADAR_OBJECT_DISTANCE 200.0
#endif

#if !defined VEHICLE_RADAR_3DTEXT_LENGTH
	#define VEHICLE_RADAR_3DTEXT_LENGTH 144
#endif

#if !defined VEHICLE_RADAR_3DTEXT_TEXT
	static VEHICLE_RADAR_3DTEXT_TEXT[] = "Speed radar #%d\nSpeed limit: %d (km/h)";
#endif

#if !defined VEHICLE_RADAR_3DTEXT_DISTANCE
    #define VEHICLE_RADAR_3DTEXT_DISTANCE 15.0 // 3d text draw distance
#endif

#if !defined VEHICLE_RADAR_MAX_ROWS_LIST 
    #define VEHICLE_RADAR_MAX_ROWS_LIST 20 // max dialog list lines
#endif

#if !defined VEHICLE_RADAR_USE_EDITING_TOOLS
	#define VEHICLE_RADAR_USE_EDITING_TOOLS true // use editing tools
#endif

#if !defined VEHICLE_RADAR_COLOR_1
	#define VEHICLE_RADAR_COLOR_1 "{8fce00}" // 0x8fce00
#endif

#if !defined VEHICLE_RADAR_COLOR_2
	#define VEHICLE_RADAR_COLOR_2 "{f44747}" // 0xf44747
#endif

#if !defined VEHICLE_RADAR_COLOR_3
	#define VEHICLE_RADAR_COLOR_3 "{F5D742}" // 0xF5D742
#endif

#if !defined VEHICLE_RADAR_SPEED_MULTIPLIER
    static const Float:VEHICLE_RADAR_SPEED_MULTIPLIER = 179.28625; 
#endif

#if !defined VEHICLE_RADAR_CUSTOM_TYPE
    #define VEHICLE_RADAR_CUSTOM_TYPE 0xFF42CDFA12
#endif

#if !defined VEHICLE_RADAR_RESPONSE_DELAY
    #define VEHICLE_RADAR_RESPONSE_DELAY 10 // seconds
#endif

#if !defined VEHICLE_RADAR_ZONE_MULTIPLIER
    #define VEHICLE_RADAR_ZONE_MULTIPLIER 3 //The larger the multiplier, the larger the entry zone for checking "zone_size"
#endif

#if !defined VEHICLE_RADAR_DISABLE_TEXT3D
	#define VEHICLE_RADAR_DISABLE_TEXT3D false 
#endif


enum (<<= 1) {
    VEHICLE_RADAR_TYPE = 0,
    VEHICLE_RADAR_ID = 1,
    VEHICLE_RADAR_AREA_ID = 2
}


enum VEHICLE_RADAR_EN {
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

    vr_Sphere,
    Float:vr_ZoneSize,
    vr_SpeedLimit,
    vr_ActivationCount,
    vr_ExtraValue, 

    Text3D:vr_Text3D,
    vr_Text3D_Text[VEHICLE_RADAR_3DTEXT_LENGTH],
    vr_Text3D_Color,
    Float:vr_Text3D_Distance,
    bool:vr_CustomText3D
}

static vehicle_radar[MAX_VEHICLE_RADAR][VEHICLE_RADAR_EN];


enum PLAYER_VEHICLE_RADAR_EN {
    pvr_InRadarZone,
    pvr_InRadarID,
    pvr_Timer,
    pvr_ResponseDelay,
    pvr_RadarIDResponseDelay
}

static player_vehicle_radar[MAX_PLAYERS][PLAYER_VEHICLE_RADAR_EN];


#if VEHICLE_RADAR_USE_EDITING_TOOLS

    #if !defined _mdialog_included
        #error "Please include mdialog.inc before vehicle-radar.inc or disable VEHICLE_RADAR_USE_EDITING_TOOLS"
    #endif

    enum VEHICLE_RADAR_PLAYER_EN {
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
        vrp_EditObject,

        //list
        vrpList_Page,
        vrpList_Page_Button_Back,
        vrpList_SlotID[VEHICLE_RADAR_MAX_ROWS_LIST],
        vrpList_LineID,
        bool:vrpList_EditRadar[2]
    }

    static vehicle_radar_player[MAX_PLAYERS][VEHICLE_RADAR_PLAYER_EN];
#endif



stock VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, bool:disable_text3D = VEHICLE_RADAR_DISABLE_TEXT3D)
{
    new radarid;

    for(new i = 1; i < MAX_VEHICLE_RADAR; i ++)
    {
        if(vehicle_radar[i][vr_Create] == true) 
            continue;

        radarid = i;
        break;
    }

    if(!radarid) 
        return printf("vehicle-radar --->>> | VehicleRadarLoad | not all radars were created! | increase the value '#define MAX_VEHICLE_RADAR'") & 0;

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
    
    vehicle_radar[radarid][vr_SpeedLimit] = speed_limit;
    vehicle_radar[radarid][vr_ExtraValue] = 0;
    vehicle_radar[radarid][vr_ActivationCount] = 0;


    //Object
    vehicle_radar[radarid][vr_Object] = CreateDynamicObject(
        VEHICLE_RADAR_OBJECT_MODEL, 
        x, y, z,  
        rx, ry, rz,  
        worldid, 
        interiorid, 
        -1, 
        VEHICLE_RADAR_OBJECT_DISTANCE, 
        VEHICLE_RADAR_OBJECT_DISTANCE);
    


    //Sphere
    vehicle_radar[radarid][vr_ZoneSize] = zone_size;
    vehicle_radar[radarid][vr_Sphere] = CreateDynamicSphere(x, y, z, zone_size * VEHICLE_RADAR_ZONE_MULTIPLIER, worldid, interiorid);

    new rd_arr[3];
    rd_arr[VEHICLE_RADAR_TYPE] = VEHICLE_RADAR_CUSTOM_TYPE;
    rd_arr[VEHICLE_RADAR_ID] = radarid;
    rd_arr[VEHICLE_RADAR_AREA_ID] = vehicle_radar[radarid][vr_Sphere];
    Streamer_SetArrayData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_EXTRA_ID, rd_arr);    
    


    //Text3D
    vehicle_radar[radarid][vr_Text3D] = Text3D:INVALID_3DTEXT_ID;
    format(vehicle_radar[radarid][vr_Text3D_Text], VEHICLE_RADAR_3DTEXT_LENGTH, VEHICLE_RADAR_3DTEXT_TEXT, radarid, speed_limit);

    vehicle_radar[radarid][vr_Text3D_Color] = -1;
    vehicle_radar[radarid][vr_Text3D_Distance] = VEHICLE_RADAR_3DTEXT_DISTANCE;
    vehicle_radar[radarid][vr_CustomText3D] = false;


    if(!disable_text3D) {
        vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(
            vehicle_radar[radarid][vr_Text3D_Text], 
            vehicle_radar[radarid][vr_Text3D_Color], 
            x, 
            y, 
            z + 6.0, 
            vehicle_radar[radarid][vr_Text3D_Distance], 
            INVALID_PLAYER_ID, 
            INVALID_VEHICLE_ID, 
            0, 
            worldid, 
            interiorid);
    }

    return radarid;
}



stock DeleteVehicleRadar(playerid, radarid, bool:callback = true)
{
    if(vehicle_radar[radarid][vr_Create] == false || playerid !=-1) 
        return 0;

    if(IsValidDynamicObject(vehicle_radar[radarid][vr_Object])) 
        DestroyDynamicObject(vehicle_radar[radarid][vr_Object]);

    if(IsValidDynamicArea(vehicle_radar[radarid][vr_Sphere])) 
        DestroyDynamicArea(vehicle_radar[radarid][vr_Sphere]);

    if(vehicle_radar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID) 
        DestroyDynamic3DTextLabel(vehicle_radar[radarid][vr_Text3D]);


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
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    vehicle_radar[radarid][vr_ActivationCount] = count;
    return 1;
}



stock GetVehicleRadarActivationCount(radarid, &triggering)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    return vehicle_radar[radarid][vr_ActivationCount];
}



stock SetVehicleRadarSpeedLimit(radarid, speed)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    vehicle_radar[radarid][vr_SpeedLimit] = speed;
    return 1;
}



stock GetVehicleRadarSpeedLimit(radarid)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;

    return vehicle_radar[radarid][vr_SpeedLimit];
}



stock SetVehicleRadarZoneSize(radarid, Float:zone_size)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    vehicle_radar[radarid][vr_ZoneSize] = zone_size;

    Streamer_SetFloatData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_SIZE, vehicle_radar[radarid][vr_ZoneSize] * VEHICLE_RADAR_ZONE_MULTIPLIER);
    return 1;
}



stock GetVehicleRadarZoneSize(radarid, &Float:zone_size)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    zone_size = vehicle_radar[radarid][vr_ZoneSize];
    return 1;
}


stock SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = -1.0, Float:y = -1.0, Float:z = -1.0)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;

    if(vehicle_radar[radarid][vr_Text3D] == Text3D:INVALID_3DTEXT_ID) 
        return 0;


    x = (x == -1.0) ? (vehicle_radar[radarid][vr_Object_x]):(x);
    y = (y == -1.0) ? (vehicle_radar[radarid][vr_Object_y]):(y);
    z = (z == -1.0) ? (vehicle_radar[radarid][vr_Object_z] + 6.0):(z);


    if(text[0] == '-') {
        if(vehicle_radar[radarid][vr_CustomText3D] == false) { 
            format(vehicle_radar[radarid][vr_Text3D_Text], VEHICLE_RADAR_3DTEXT_LENGTH, VEHICLE_RADAR_3DTEXT_TEXT, radarid, vehicle_radar[radarid][vr_SpeedLimit]);
        }
    }
    else {
        format(vehicle_radar[radarid][vr_Text3D_Text], VEHICLE_RADAR_3DTEXT_LENGTH, text);
    }

    vehicle_radar[radarid][vr_Text3D_Color] = color;
    vehicle_radar[radarid][vr_Text3D_Distance] = drawdistance;
    vehicle_radar[radarid][vr_CustomText3D] = true;


    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_X, x);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_Y, y);
    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_Z, z);

    Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_WORLD_ID, vehicle_radar[radarid][vr_Object_Worldid]);
    Streamer_SetIntData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_INTERIOR_ID, vehicle_radar[radarid][vr_Object_Interiorid]);

    Streamer_SetFloatData(STREAMER_TYPE_3D_TEXT_LABEL, vehicle_radar[radarid][vr_Text3D], E_STREAMER_STREAM_DISTANCE, drawdistance);

    UpdateDynamic3DTextLabelText(vehicle_radar[radarid][vr_Text3D], color, vehicle_radar[radarid][vr_Text3D_Text]);
    return 1;
}



stock SetVehicleRadarExtraValue(radarid, value)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    vehicle_radar[radarid][vr_ExtraValue] = value;
    return 1;
}



stock GetVehicleRadarExtraValue(radarid)
{
    if(vehicle_radar[radarid][vr_Create] == false) 
        return 0;
    
    return vehicle_radar[radarid][vr_ExtraValue];
}



static stock Radar_GetVehSpeed(vehicleid)
{
    new Float:x, 
        Float:y, 
        Float:z;

    GetVehicleVelocity(vehicleid, x, y, z);
	return floatround(floatsqroot(floatpower(x, 2.0) + floatpower(y, 2.0) + floatpower(z, 2.0)) * VEHICLE_RADAR_SPEED_MULTIPLIER);
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

        if(rd_arr[VEHICLE_RADAR_TYPE] == VEHICLE_RADAR_CUSTOM_TYPE && areaid == rd_arr[VEHICLE_RADAR_AREA_ID])
        {
            new radarid = rd_arr[VEHICLE_RADAR_ID];

            if(!vehicle_radar[radarid][vr_Disabled]) {
                player_vehicle_radar[playerid][pvr_InRadarZone] = areaid;
                player_vehicle_radar[playerid][pvr_InRadarID] = radarid;

                if(!player_vehicle_radar[playerid][pvr_Timer]) {
                    player_vehicle_radar[playerid][pvr_Timer] = SetTimerEx("OnPlayerVehicleRadarTimer", 200, true, "d", playerid);
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
    if(player_vehicle_radar[playerid][pvr_InRadarZone] == areaid) {

        player_vehicle_radar[playerid][pvr_InRadarZone] = 0;

        KillTimer(player_vehicle_radar[playerid][pvr_Timer]);
        player_vehicle_radar[playerid][pvr_Timer] = 0;
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



forward OnPlayerVehicleRadarTimer(playerid);
public OnPlayerVehicleRadarTimer(playerid) {

    new vehicleid = GetPlayerVehicleID(playerid),
        radarid = player_vehicle_radar[playerid][pvr_InRadarID];

    if(!vehicle_radar[radarid][vr_Create]) {

        player_vehicle_radar[playerid][pvr_InRadarZone] = 0;

        KillTimer(player_vehicle_radar[playerid][pvr_Timer]);
        player_vehicle_radar[playerid][pvr_Timer] = 0;
        return 1;
    }

    if(vehicle_radar[radarid][vr_Disabled]) {
        return 1;
    }

    if(player_vehicle_radar[playerid][pvr_ResponseDelay] != 0 && 
        player_vehicle_radar[playerid][pvr_ResponseDelay] >= gettime() && 
        player_vehicle_radar[playerid][pvr_RadarIDResponseDelay] == radarid) {
        return 1;
    }


    new Float:distance = GetPlayerDistanceFromPoint(playerid, 
        vehicle_radar[radarid][vr_Object_x],
        vehicle_radar[radarid][vr_Object_y],
        vehicle_radar[radarid][vr_Object_z]);


    if(vehicleid && 
        GetPlayerState(playerid) == PLAYER_STATE_DRIVER && 
        distance < vehicle_radar[radarid][vr_ZoneSize] && 
        Radar_GetVehSpeed(vehicleid) >= vehicle_radar[radarid][vr_SpeedLimit]) {

        player_vehicle_radar[playerid][pvr_ResponseDelay] = gettime() + VEHICLE_RADAR_RESPONSE_DELAY;
        player_vehicle_radar[playerid][pvr_RadarIDResponseDelay] = radarid;

        vehicle_radar[radarid][vr_ActivationCount] ++;

        #if defined OnPlayerEnterVehicleRadar
            OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, vehicle_radar[radarid][vr_ActivationCount]);
        #endif
    }

    return 1;
}



public OnPlayerConnect(playerid)
{
    player_vehicle_radar[playerid][pvr_InRadarZone] = 0;
    player_vehicle_radar[playerid][pvr_Timer] = 0;

    #if defined OnPlayerConnect_vradar
        OnPlayerConnect_vradar(playerid);
    #endif
    return 1;
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



public OnPlayerDisconnect(playerid, reason)
{
    if(player_vehicle_radar[playerid][pvr_InRadarZone]) {

        player_vehicle_radar[playerid][pvr_InRadarZone] = 0;
        
        KillTimer(player_vehicle_radar[playerid][pvr_Timer]);
        player_vehicle_radar[playerid][pvr_Timer] = 0;
    }


    #if VEHICLE_RADAR_USE_EDITING_TOOLS

        if(vehicle_radar_player[playerid][vrp_EditObject] != 0 || vehicle_radar_player[playerid][vrpList_EditRadar][1] == true) {

            if(vehicle_radar_player[playerid][vrp_EditObject] == 2 || vehicle_radar_player[playerid][vrpList_EditRadar][1] == true)
            {
                new radarid = vehicle_radar_player[playerid][vrpList_LineID];

                SetDynamicObjectPos(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
                SetDynamicObjectRot(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);
            } 

            if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]))
                DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
            

            vehicle_radar_player[playerid][vrp_Object] = 0;
            vehicle_radar_player[playerid][vrp_EditObject] = 0;
        }
    #endif

    #if defined OnPlayerDisconnect_vradar
        OnPlayerDisconnect_vradar(playerid, reason);
    #endif
    return 1;
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

        if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
            DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);

        vehicle_radar_player[playerid][vrp_Object] = 0;
        vehicle_radar_player[playerid][vrp_EditObject] = 1;

        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }


    DialogCreate:_vehicle_radar_Create(playerid)
    {
        static const text[] =
            "%s\t\n\
            Position\tX: %.1f, Y: %.1f, Z: %.1f\n\
            Trigger distance\t%.1fm\n\
            Speed limit\t%d km/h\n\
            Status\t%s\n\
            Virtual world\t%d\n\
            Interior\t%d";
    
        new string[sizeof(text) + 23 + 30 + 10 + 10 + 11 + 10 + 10 + 21], 
            caption[55+10] = "Creating a radar",
            Float:x = vehicle_radar_player[playerid][vrp_x], 
            Float:y = vehicle_radar_player[playerid][vrp_y], 
            Float:z = vehicle_radar_player[playerid][vrp_z];

        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
        {
            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            x = vehicle_radar[radarid][vr_Object_x];
            y = vehicle_radar[radarid][vr_Object_y];
            z = vehicle_radar[radarid][vr_Object_z]; 
        }

        format(string, sizeof(string), text,
            (vehicle_radar_player[playerid][vrpList_EditRadar][0] == false) ? (""VEHICLE_RADAR_COLOR_1"Create a radar"):(""VEHICLE_RADAR_COLOR_2"Remove radar"),
            x, y, z,
            vehicle_radar_player[playerid][vrp_ZoneSize],
            vehicle_radar_player[playerid][vrp_SpeedLimit],
            (vehicle_radar_player[playerid][vrp_Disabled] == false) ? (""VEHICLE_RADAR_COLOR_1"On"):(""VEHICLE_RADAR_COLOR_2"Off"),
            vehicle_radar_player[playerid][vrp_Worldid],
            vehicle_radar_player[playerid][vrp_Interiorid]);


        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) 
        {
            strcat(string, "\nTeleport to radar\t");

            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            format(caption, sizeof(caption), "Radar editing | "VEHICLE_RADAR_COLOR_3"Triggers: %d", vehicle_radar[radarid][vr_ActivationCount]);
        }

        Dialog_Open(playerid, Dialog:_vehicle_radar_Create, DIALOG_STYLE_TABLIST, caption, string, "Select", "Cancel");
        return 1;
    }


    DialogResponse:_vehicle_radar_Create(playerid, response, listitem, inputtext[])
    {
        if(!response)
        {
            if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
                DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);

            vehicle_radar_player[playerid][vrp_EditObject] = 0;
            vehicle_radar_player[playerid][vrp_Object] = 0;

            if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
            {
                if(vehicle_radar_player[playerid][vrpList_EditRadar][1] == true) {
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Savechanges, DIALOG_STYLE_MSGBOX, "Acceptance of changes", 
                        "{FFFFFF}Save changes ?", "Yes", "No");
                    return 1;
                }

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
                    static const text[] = "{FFFFFF}Delete radar "VEHICLE_RADAR_COLOR_3"ID: %d ?";
                    new string[sizeof(text)+10];
                  
                    format(string, sizeof(string), text, vehicle_radar_player[playerid][vrpList_LineID]);
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Delete, DIALOG_STYLE_MSGBOX, "Remove radar", string, "Remove", "Back");
                    return 1;
                }

                new radarid = VehicleRadarLoad(
                    vehicle_radar_player[playerid][vrp_SpeedLimit],
                    vehicle_radar_player[playerid][vrp_ZoneSize],
                    vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                    vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz],
                    vehicle_radar_player[playerid][vrp_Worldid], vehicle_radar_player[playerid][vrp_Interiorid],
                    vehicle_radar_player[playerid][vrp_Disabled]);

                if(!radarid) {
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Create_back, DIALOG_STYLE_MSGBOX, "Creating a radar", 
                        "{FFFFFF}Radar limit reached", 
                    "Close", "Back");
                    return 1;
                }

                if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
                    DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                
                vehicle_radar_player[playerid][vrp_Object] = 0;


                #if defined OnPlayerVehicleRadarCreate
                    OnPlayerVehicleRadarCreate(playerid,
                        radarid, 
                        vehicle_radar_player[playerid][vrp_SpeedLimit],
                        vehicle_radar_player[playerid][vrp_ZoneSize], 
                        vehicle_radar_player[playerid][vrp_Disabled],
                        vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                        vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz],
                        vehicle_radar_player[playerid][vrp_Worldid], vehicle_radar_player[playerid][vrp_Interiorid]);
                #endif
                return 1;
            }
            case 1:
            {
                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
                {
                    new radarid = vehicle_radar_player[playerid][vrpList_LineID];

                    new Float:distance = GetPlayerDistanceFromPoint(playerid, 
                        vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
                    
                    if(distance >= 20.0) {
                        SetPlayerPos(playerid, 
                        vehicle_radar[radarid][vr_Object_x]+0.5, 
                        vehicle_radar[radarid][vr_Object_y]+0.5, 
                        vehicle_radar[radarid][vr_Object_z]+2.0);
                    }

                    vehicle_radar_player[playerid][vrp_EditObject] = 2;
                    EditDynamicObject(playerid, vehicle_radar[radarid][vr_Object]);
                    return 1;
                }

                if(!IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
                {
                    vehicle_radar_player[playerid][vrp_Object] = CreatePlayerObject(playerid, 
                        VEHICLE_RADAR_OBJECT_MODEL, 
                        vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z],
                        vehicle_radar_player[playerid][vrp_rx], vehicle_radar_player[playerid][vrp_ry], vehicle_radar_player[playerid][vrp_rz], 
                        200.0);

                    SetPlayerPos(playerid, 
                        vehicle_radar_player[playerid][vrp_x]+0.5, 
                        vehicle_radar_player[playerid][vrp_y]+0.5, 
                        vehicle_radar_player[playerid][vrp_z]);
                }

                new Float:distance = GetPlayerDistanceFromPoint(playerid, 
                    vehicle_radar_player[playerid][vrp_x], vehicle_radar_player[playerid][vrp_y], vehicle_radar_player[playerid][vrp_z]);
                
                if(distance >= 20.0) {
                    SetPlayerPos(playerid, 
                        vehicle_radar_player[playerid][vrp_x]+0.5, 
                        vehicle_radar_player[playerid][vrp_y]+0.5, 
                        vehicle_radar_player[playerid][vrp_z]+2.0);
                }

                vehicle_radar_player[playerid][vrp_EditObject] = 1;
                EditPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                return 1;
            }
            case 2:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_ZoneSize, DIALOG_STYLE_INPUT, "Trigger distance", 
                    "{FFFFFF}Enter the trigger distance:", "Select", "Cancel");
                return 1;
            }
            case 3:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_SpeedLimit, DIALOG_STYLE_INPUT, "Speed limit", 
                    "{FFFFFF}Enter the speed limit:", "Select", "Cancel");
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
                Dialog_Open(playerid, Dialog:_vehicle_radar_Worldid, DIALOG_STYLE_INPUT, 
                    "Virtual world", "{FFFFFF}Enter the Virtual world ID:", "Select", "Cancel");
                return 1;
            }
            case 6:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_Interior, DIALOG_STYLE_INPUT, "Interior", 
                    "{FFFFFF}Enter the interior ID:", "Select", "Cancel");
                return 1;
            }
            case 7:
            {
                new radarid = vehicle_radar_player[playerid][vrpList_LineID];

                SetPlayerPos(playerid, 
                    vehicle_radar[radarid][vr_Object_x]+0.5, 
                    vehicle_radar[radarid][vr_Object_y]+0.5, 
                    vehicle_radar[radarid][vr_Object_z]+2.0);
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
        if(floatstr(inputtext) < 0.0) return Dialog_Open(playerid, Dialog:_vehicle_radar_ZoneSize, DIALOG_STYLE_INPUT, "Trigger distance", "{FFFFFF}Enter the trigger distance:", "Select", "Cancel");

        vehicle_radar_player[playerid][vrp_ZoneSize] = floatstr(inputtext);
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }


    DialogResponse:_vehicle_radar_SpeedLimit(playerid, response, listitem, inputtext[])
    {
        if(!response) return Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        if(strval(inputtext) < 0) return Dialog_Open(playerid, Dialog:_vehicle_radar_SpeedLimit, DIALOG_STYLE_INPUT, "Speed limit", "{FFFFFF}Enter the speed limit:", "Select", "Cancel");

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
        if(vehicle_radar_player[playerid][vrp_EditObject] == 1 && (response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL))
        {
            vehicle_radar_player[playerid][vrp_EditObject] = 0;

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

            SetPlayerObjectPos(playerid, 
                vehicle_radar_player[playerid][vrp_Object], 
                vehicle_radar_player[playerid][vrp_x], 
                vehicle_radar_player[playerid][vrp_y], 
                vehicle_radar_player[playerid][vrp_z]);
            
            SetPlayerObjectRot(playerid, 
                vehicle_radar_player[playerid][vrp_Object], 
                vehicle_radar_player[playerid][vrp_rx], 
                vehicle_radar_player[playerid][vrp_ry], 
                vehicle_radar_player[playerid][vrp_rz]);
            
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



    #if defined _inc_y_hooks || defined _INC_y_hooks
        hook OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
    #else
        public OnPlayerEditDynamicObject(playerid, objectid, response, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz)
    #endif
    {
        if(vehicle_radar_player[playerid][vrp_EditObject] == 2 && (response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL))
        {
            vehicle_radar_player[playerid][vrp_EditObject] = 0;

            if(response == EDIT_RESPONSE_FINAL)
            {
                SetDynamicObjectPos(objectid, x, y, z);
                SetDynamicObjectRot(objectid, rx, ry, rz);

                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) vehicle_radar_player[playerid][vrpList_EditRadar][1] = true;
            }
            else
            {
                new radarid = vehicle_radar_player[playerid][vrpList_LineID];

                SetDynamicObjectPos(objectid, vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
                SetDynamicObjectRot(objectid, vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);
            }

            Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
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
        new string[ (27+ 10+10+10+16) * VEHICLE_RADAR_MAX_ROWS_LIST + 91] = "{FFFFFF}ID\t{FFFFFF}Triggers\t{FFFFFF}Trigger distance\t{FFFFFF}Status\n";
        
        for(new x; x < VEHICLE_RADAR_MAX_ROWS_LIST; x ++) vehicle_radar_player[playerid][vrpList_SlotID][x] = -1;

        new line_max, 
            block_back_button;

        for(new x = (vehicle_radar_player[playerid][vrpList_Page] * VEHICLE_RADAR_MAX_ROWS_LIST)+1; x < MAX_VEHICLE_RADAR; x ++)
        {
            if(x >= MAX_VEHICLE_RADAR) 
                break;

            if(vehicle_radar[x][vr_Create] == false) 
                continue;

            if(line_max <= VEHICLE_RADAR_MAX_ROWS_LIST-1)
            {
                vehicle_radar_player[playerid][vrpList_SlotID][line_max] = x;

                format(string, sizeof(string), "%s#%d\t%d km/h\t%.1fm\t%s\n", 
                    string, 
                    x, 
                    vehicle_radar[x][vr_SpeedLimit], 
                    vehicle_radar[x][vr_ZoneSize], 
                    (vehicle_radar[x][vr_Disabled] == false) ? (""VEHICLE_RADAR_COLOR_1"On"):(""VEHICLE_RADAR_COLOR_2"Off"));    

                if(x >= MAX_VEHICLE_RADAR -1)
                {
                    if(vehicle_radar_player[playerid][vrpList_Page] >= 1) block_back_button = 1;
                    break;
                }
            }

            line_max ++;
            if(line_max >= VEHICLE_RADAR_MAX_ROWS_LIST+1)
            {
                block_back_button = 2;
                strcat(string, "> Further\n");
                if(vehicle_radar_player[playerid][vrpList_Page] >= 1) strcat(string, "< Back\n");
                break;
            }
        }

        if(vehicle_radar_player[playerid][vrpList_Page] >= 1 && block_back_button == 0 || block_back_button == 1)
        {
            strcat(string, "< Back\n");
            vehicle_radar_player[playerid][vrpList_Page_Button_Back] = line_max + ((block_back_button == 0) ? (1):(2));
        }

        if(line_max == 0) 
            return Dialog_Message(playerid, "List of radars", "{FFFFFF}No radars created.", "Cancel");

        Dialog_Open(playerid, Dialog:_vehicle_radar_List, DIALOG_STYLE_TABLIST_HEADERS, "List of radars", string, "Select", "Cancel");
        return 1;
    }


    DialogResponse:_vehicle_radar_List(playerid, response, listitem, inputtext[])
    {
        if(!response) return 1;

        switch(listitem)
        {
            case VEHICLE_RADAR_MAX_ROWS_LIST:
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
            case VEHICLE_RADAR_MAX_ROWS_LIST+1:
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
                vehicle_radar_player[playerid][vrp_Worldid] = vehicle_radar[radarid][vr_Object_Worldid];
                vehicle_radar_player[playerid][vrp_Interiorid] = vehicle_radar[radarid][vr_Object_Interiorid];
                vehicle_radar_player[playerid][vrp_ZoneSize] = vehicle_radar[radarid][vr_ZoneSize];
                vehicle_radar_player[playerid][vrp_SpeedLimit] = vehicle_radar[radarid][vr_SpeedLimit];

                vehicle_radar_player[playerid][vrp_EditObject] = 0;

                Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
                return 1;
            }
        }
        return 1;
    }


    DialogResponse:_vehicle_radar_Savechanges(playerid, response, listitem, inputtext[])
    {
        new radarid = vehicle_radar_player[playerid][vrpList_LineID];

        if(vehicle_radar[radarid][vr_Create] == false) 
            return 1;


        if(!response) 
        {
            SetDynamicObjectPos(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
            SetDynamicObjectRot(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);
            
            vehicle_radar_player[playerid][vrpList_EditRadar][1] = false;
            Dialog_Show(playerid, Dialog:_vehicle_radar_List);
            return 1;
        }

        if(vehicle_radar_player[playerid][vrpList_EditRadar][1] == true)
        {

            vehicle_radar[radarid][vr_Disabled] = vehicle_radar_player[playerid][vrp_Disabled];
            vehicle_radar[radarid][vr_Object_Worldid] = vehicle_radar_player[playerid][vrp_Worldid];
            vehicle_radar[radarid][vr_Object_Interiorid] = vehicle_radar_player[playerid][vrp_Interiorid];
            vehicle_radar[radarid][vr_ZoneSize] = vehicle_radar_player[playerid][vrp_ZoneSize];
            vehicle_radar[radarid][vr_SpeedLimit] = vehicle_radar_player[playerid][vrp_SpeedLimit];


            //Object
            GetDynamicObjectPos(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
            GetDynamicObjectRot(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);
            Streamer_SetIntData(STREAMER_TYPE_OBJECT, vehicle_radar[radarid][vr_Object], E_STREAMER_WORLD_ID, vehicle_radar[radarid][vr_Object_Worldid]);
	        Streamer_SetIntData(STREAMER_TYPE_OBJECT, vehicle_radar[radarid][vr_Object], E_STREAMER_INTERIOR_ID, vehicle_radar[radarid][vr_Object_Interiorid]);


            //AREA
            Streamer_SetFloatData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_X, vehicle_radar[radarid][vr_Object_x]);
            Streamer_SetFloatData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_Y, vehicle_radar[radarid][vr_Object_y]);
            Streamer_SetFloatData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_Z, vehicle_radar[radarid][vr_Object_z]);
            Streamer_SetIntData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_WORLD_ID, vehicle_radar[radarid][vr_Object_Worldid]);
            Streamer_SetIntData(STREAMER_TYPE_AREA, vehicle_radar[radarid][vr_Sphere], E_STREAMER_INTERIOR_ID, vehicle_radar[radarid][vr_Object_Interiorid]);

            SetVehicleRadarZoneSize(radarid, vehicle_radar[radarid][vr_ZoneSize]);


            //Text3D
            if(vehicle_radar[radarid][vr_Text3D] != Text3D:INVALID_3DTEXT_ID)
            {
                new bool:customtext3d = vehicle_radar[radarid][vr_CustomText3D];

                SetVehicleRadarText(radarid, 
                    "-", 
                    vehicle_radar[radarid][vr_Text3D_Color], 
                    vehicle_radar[radarid][vr_Text3D_Distance], 
                    vehicle_radar[radarid][vr_Object_x], 
                    vehicle_radar[radarid][vr_Object_y], 
                    vehicle_radar[radarid][vr_Object_z] + 6.0);

                vehicle_radar[radarid][vr_CustomText3D] = customtext3d;    
            }


            #if defined OnPlayerVehicleRadarEdit
                OnPlayerVehicleRadarEdit(playerid,
                    radarid,
                    vehicle_radar[radarid][vr_SpeedLimit],
                    vehicle_radar[radarid][vr_ZoneSize],
                    vehicle_radar[radarid][vr_Disabled],
                    vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z],
                    vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz],
                    vehicle_radar[radarid][vr_Object_Worldid], vehicle_radar[radarid][vr_Object_Interiorid]);
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

        if(vehicle_radar_player[playerid][vrpList_Page] >= 1 && vehicle_radar_player[playerid][vrpList_SlotID][0] != -1 && vehicle_radar_player[playerid][vrpList_SlotID][1] == -1) {
            vehicle_radar_player[playerid][vrpList_Page] --;
        }

        Dialog_Show(playerid, Dialog:_vehicle_radar_List);
        return 1;
    }
#endif