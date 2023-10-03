
/*
*
*
*
*   ---------------------------------------------------
*
*	Creater - @Bren828	
*									3 October 2023
*
*   Version: 1.3.1
*
*   ---------------------------------------------------
*
*
*	https://github.com/Bren828/vehicle-radar
*
*
*
* Create a radar through tools
*       VehicleRadarCreate(playerid)
*		* playerid: The ID of the player
*
*
* List of created radars
*       VehicleRadarList(playerid)
*		* playerid: The ID of the player
*
*
* Create a radar
*       VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "-1", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
*		* speed_limit: Speed limit in km/h
*		* Float:zone_size: Trigger distance
*       * Float:x: The z coordinate to create the object
*       * Float:y: The y coordinate to create the object
*       * Float:z: The z coordinate to create the object
*       * Float:rx: The rx rotation of the object
*       * Float:ry: The ry rotation of the object
*       * Float:rz: The rz rotation of the object
*		* worldid: The virtual world ID
*       * interiorid: The interior ID
*       * bool:disabled: Disabled radar (false | true)
*       * const text3D[]: 3DText
*       * text3D_color: 3DText color
*       * Float:text3D_distance: 3DText draw distance
*		
*		* Return: 0 or Radar ID
*
*
* Remove radar
*       DeleteVehicleRadar(playerid, radarid, bool:callback = true)
*		* radarid: The ID of the radar
*		* callback: Call 'OnPlayerVehicleRadarDelete' on delete
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Set the number of triggers
*       SetVehicleRadarActivationCount(radarid, count)
*		* radarid: The ID of the radar
*		* count: count
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Get the number of triggers
*       GetVehicleRadarActivationCount(radarid)
*		* radarid: The ID of the radar
*		
*		* Return: Returns (0) on failure or quantity
*
*
* Set a speed limit
*       SetVehicleRadarSpeedLimit(radarid, speed)
*		* radarid: The ID of the radar
*		* speed: speed km/h
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Get the speed limit
*       GetVehicleRadarSpeedLimit(radarid)
*		* radarid: The ID of the radar
*		
*		* Return: Returns (0) on failure or speed
*
*
* Set the trigger distance
*       SetVehicleRadarZoneSize(radarid, Float:zone_size)
*		* radarid: The ID of the radar
*		* Float:zone_size: Trigger distance
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Get trigger distance
*       GetVehicleRadarZoneSize(radarid, &Float:zone_size)
*		* radarid: The ID of the radar
*       * &Float:zone_size: Current distance
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Set 3D Text
*       SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0)
*		* radarid: The ID of the radar
*       * text[]: Text
*       * color: Color
*       * Float:drawdistance: Draw distance
*       * Float:x: The X coordinate to create the text
*       * Float:y: The y coordinate to create the text
*       * Float:z: The z coordinate to create the text
*		
*		* Return: Returns (0) on failure or (1) on success
*
*
* Set the value
*       SetVehicleRadarExtraValue(radarid, value)
*		* radarid: The ID of the radar
*       * value: your value
*		
*		* Return: Returns (0) on failure or (1) on success
*       * Note: This free variable
*
*
* Get the value
*       GetVehicleRadarExtraValue(radarid)
*		* radarid: The ID of the radar
*		
*		* Return: Returns (0) on failure or your value
*		* Note: This free variable
*
*
* Called when the radar is triggered
*       public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
*		* playerid: The ID of the player
*		* radarid: The ID of the radar
*       * vehicleid: The ID of vehicle
*       * activation_count: Triggering
*
*
* Called when creating a radar
*       public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
*		* radarid: The ID of the radar
*		* speed_limit: Speed limit in km/h
*		* Float:zone_size: Trigger distance
*       * bool:disabled: Disabled radar (false | true)
*       * Float:x: The x coordinate to create the object
*       * Float:y: The y coordinate to create the object
*       * Float:z: The z coordinate to create the object
*       * Float:rx: The x rotation of the object
*       * Float:ry: The y rotation of the object
*       * Float:rz: The z rotation of the object
*		* worldid: The virtual world ID
*       * interiorid: The interior ID
*
*
* Called when editing
*       public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
*		* radarid: The ID of the radar
*		* speed_limit:  Speed limit in km/h
*		* Float:zone_size: Trigger distance
*       * bool:disabled: Disabled radar (false | true)
*       * Float:x: The x coordinate to create the object
*       * Float:y: The y coordinate to create the object
*       * Float:z: The z coordinate to create the object
*       * Float:rx: The x rotation of the object
*       * Float:ry: The y rotation of the object
*       * Float:rz: The z rotation of the object
*		* worldid: The virtual world ID
*       * interiorid: The interior ID
*
*
* Called when the radar is removed
*       public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
*		* radarid: The ID of the radar
*       * extra_value: Value
*
*
*       
*/

#if defined _vehicle_radar_included
	#endinput
#endif
#define _vehicle_radar_included


#if !defined MAX_VEHICLE_RADAR
    #define MAX_VEHICLE_RADAR                           200
#endif

#if !defined VEHICLE_RADAR_OBJECT_MODEL
    #define VEHICLE_RADAR_OBJECT_MODEL                  18880 // object model
#endif

#if !defined VEHICLE_RADAR_OBJECT_DISTANCE
    #define VEHICLE_RADAR_OBJECT_DISTANCE               200.0
#endif

#if !defined VEHICLE_RADAR_3DTEXT_LENGTH
	#define VEHICLE_RADAR_3DTEXT_LENGTH   	            144
#endif

#if !defined VEHICLE_RADAR_3DTEXT_TEXT
	static VEHICLE_RADAR_3DTEXT_TEXT[] =  	            "Speed radar ¹%d\nSpeed limit: %d (km/h)";
#endif

#if !defined VEHICLE_RADAR_3DTEXT_DISTANCE
    #define VEHICLE_RADAR_3DTEXT_DISTANCE               15.0 // 3d text draw distance
#endif

#if !defined VEHICLE_RADAR_MAX_ROWS_LIST 
    #define VEHICLE_RADAR_MAX_ROWS_LIST                 20 // max dialog list lines
#endif

#if !defined VEHICLE_RADAR_USE_EDITING_TOOLS
	#define VEHICLE_RADAR_USE_EDITING_TOOLS  	        true // use editing tools
#endif

#if !defined VEHICLE_RADAR_COLOR_1
	#define VEHICLE_RADAR_COLOR_1                       "{8fce00}" // 0x8fce00
#endif

#if !defined VEHICLE_RADAR_COLOR_2
	#define VEHICLE_RADAR_COLOR_2                       "{f44747}" // 0xf44747
#endif

#if !defined VEHICLE_RADAR_COLOR_3
	#define VEHICLE_RADAR_COLOR_3                       "{F5D742}" // 0xF5D742
#endif

#if !defined VEHICLE_RADAR_SPEED_MULTIPLIER
    static const Float:VEHICLE_RADAR_SPEED_MULTIPLIER = 179.28625; 
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


#if VEHICLE_RADAR_USE_EDITING_TOOLS

    #if !defined _mdialog_included
        #error "Please include mdialog.inc before vehicle-radar.inc or disable VEHICLE_RADAR_USE_EDITING_TOOLS"
    #endif

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

stock VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
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
    vehicle_radar[radarid][vr_Text3D_Z] = 6.0;
    vehicle_radar[radarid][vr_ActivationCount] = 0;

    vehicle_radar[radarid][vr_Object] = CreateDynamicObject(VEHICLE_RADAR_OBJECT_MODEL, x, y, z,  rx, ry, rz,  worldid, interiorid, -1, VEHICLE_RADAR_OBJECT_DISTANCE, VEHICLE_RADAR_OBJECT_DISTANCE);
    vehicle_radar[radarid][vr_Sphere] = CreateDynamicSphere(x, y, z, zone_size, worldid, interiorid);
    
    if(strlen(text3D) == 0)
    {
        new string[VEHICLE_RADAR_3DTEXT_LENGTH];
        format(string, sizeof(string), VEHICLE_RADAR_3DTEXT_TEXT, radarid, speed_limit);
        vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(string, text3D_color, x, y, z+6.0, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
    }
    else 
    {
        vehicle_radar[radarid][vr_Text3D] = CreateDynamic3DTextLabel(text3D, text3D_color, x, y, z+6.0, text3D_distance, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, worldid, interiorid, -1, text3D_distance);
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


static stock Radar_GetVehSpeed(vehicleid)
{
    new Float:x, Float:y, Float:z;
    GetVehicleVelocity(vehicleid, x, y, z);
	return floatround(floatsqroot(floatpower(x, 2.0) + floatpower(y, 2.0) + floatpower(z, 2.0)) * VEHICLE_RADAR_SPEED_MULTIPLIER);
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
            if(vehicle_radar[radarid][vr_SpeedLimit] != 0 && Radar_GetVehSpeed(vehicleid) < vehicle_radar[radarid][vr_SpeedLimit]) break;
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
        vehicle_radar_player[playerid][vrp_EditObject] = 1;

        Dialog_Show(playerid, Dialog:_vehicle_radar_Create);
        return 1;
    }

    DialogCreate:_vehicle_radar_Create(playerid)
    {
        new string[166+ 21+30+10+10+16+10+10 + 23], caption[55+10] = "Creating a radar", Float:x = vehicle_radar_player[playerid][vrp_x], Float:y = vehicle_radar_player[playerid][vrp_y], Float:z = vehicle_radar_player[playerid][vrp_z];
        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
        {
            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            x = vehicle_radar[radarid][vr_Object_x];
            y = vehicle_radar[radarid][vr_Object_y];
            z = vehicle_radar[radarid][vr_Object_z];
        }

        format(string, sizeof(string),
            "%s\t\n\
            Position\tX: %.1f, Y: %.1f, Z: %.1f\n\
            Trigger distance\t%.1fm\n\
            Speed limit\t%d km/h\n\
            Status\t%s\n\
            Virtual world\t%d\n\
            Interior\t%d",
        (vehicle_radar_player[playerid][vrpList_EditRadar][0] == false) ? (""VEHICLE_RADAR_COLOR_1"Create a radar"):(""VEHICLE_RADAR_COLOR_2"Remove radar"),
        x, y, z,
        vehicle_radar_player[playerid][vrp_ZoneSize],
        vehicle_radar_player[playerid][vrp_SpeedLimit],
        (vehicle_radar_player[playerid][vrp_Disabled] == false) ? (""VEHICLE_RADAR_COLOR_1"On"):(""VEHICLE_RADAR_COLOR_2"Off"),
        vehicle_radar_player[playerid][vrp_Worldid],
        vehicle_radar_player[playerid][vrp_Interiorid]);

        if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true) 
        {
            new radarid = vehicle_radar_player[playerid][vrpList_LineID];
            format(string, sizeof(string), "%s\nTeleport to radar\t",  string);
            format(caption, sizeof(caption), "Radar editing | "VEHICLE_RADAR_COLOR_3"Triggers: %d", vehicle_radar[radarid][vr_ActivationCount]);
        }
        Dialog_Open(playerid, Dialog:_vehicle_radar_Create, DIALOG_STYLE_TABLIST, caption, string, "Select", "Cancel");
        return 1;
    }

    DialogResponse:_vehicle_radar_Create(playerid, response, listitem, inputtext[])
    {
        if(!response)
        {
            vehicle_radar_player[playerid][vrp_EditObject] = 0;
            if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object])) 
            {
                DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                vehicle_radar_player[playerid][vrp_Object] = 0;
            }

            if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
            {
                if(vehicle_radar_player[playerid][vrpList_EditRadar][1] == true) return Dialog_Open(playerid, Dialog:_vehicle_radar_Savechanges, DIALOG_STYLE_MSGBOX, "Acceptance of changes", "{FFFFFF}Save changes ?", "Yes", "No");
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
                    new string[50+10];
                    format(string, sizeof(string), "{FFFFFF}Delete radar "VEHICLE_RADAR_COLOR_3"ID: %d ?", vehicle_radar_player[playerid][vrpList_LineID]);
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Delete, DIALOG_STYLE_MSGBOX, "Remove radar", string, "Remove", "Back");
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
                    Dialog_Open(playerid, Dialog:_vehicle_radar_Create_back, DIALOG_STYLE_MSGBOX, "Creating a radar", 
                        "{FFFFFF}Radar limit reached", 
                    "Close", "Back");
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
                if(vehicle_radar_player[playerid][vrpList_EditRadar][0] == true)
                {
                    new radarid = vehicle_radar_player[playerid][vrpList_LineID];

                    new Float:distance = GetPlayerDistanceFromPoint(playerid, vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
                    if(distance >= 20.0) SetPlayerPos(playerid, vehicle_radar[radarid][vr_Object_x]+0.5, vehicle_radar[radarid][vr_Object_y]+0.5, vehicle_radar[radarid][vr_Object_z]+2.0);

                    vehicle_radar_player[playerid][vrp_EditObject] = 2;
                    EditDynamicObject(playerid, vehicle_radar[radarid][vr_Object]);
                    return 1;
                }
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

                vehicle_radar_player[playerid][vrp_EditObject] = 1;
                EditPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                return 1;
            }
            case 2:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_ZoneSize, DIALOG_STYLE_INPUT, "Trigger distance", "{FFFFFF}Enter the trigger distance:", "Select", "Cancel");
                return 1;
            }
            case 3:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_SpeedLimit, DIALOG_STYLE_INPUT, "Speed limit", "{FFFFFF}Enter the speed limit:", "Select", "Cancel");
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
                Dialog_Open(playerid, Dialog:_vehicle_radar_Worldid, DIALOG_STYLE_INPUT, "Virtual world", "{FFFFFF}Enter the Virtual world ID:", "Select", "Cancel");
                return 1;
            }
            case 6:
            {
                Dialog_Open(playerid, Dialog:_vehicle_radar_Interior, DIALOG_STYLE_INPUT, "Interior", "{FFFFFF}Enter the interior ID:", "Select", "Cancel");
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


    #if defined _inc_y_hooks || defined _INC_y_hooks
        hook OnPlayerDisconnect(playerid, reason)
    #else
        public OnPlayerDisconnect(playerid, reason)
    #endif
    {
        if(vehicle_radar_player[playerid][vrp_EditObject] != 0 || vehicle_radar_player[playerid][vrpList_EditRadar][1] == true)
        {
            if(vehicle_radar_player[playerid][vrp_EditObject] == 2 || vehicle_radar_player[playerid][vrpList_EditRadar][1] == true)
            {
                new radarid = vehicle_radar_player[playerid][vrpList_LineID];
                SetDynamicObjectPos(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
                SetDynamicObjectRot(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);
            } 
            if(IsValidPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]))
            {
                DestroyPlayerObject(playerid, vehicle_radar_player[playerid][vrp_Object]);
                vehicle_radar_player[playerid][vrp_Object] = 0;
            }
            vehicle_radar_player[playerid][vrp_EditObject] = 0;
        }

        #if !defined _inc_y_hooks && !defined _INC_y_hooks && defined OnPlayerDisconnect_vradar
            return OnPlayerDisconnect_vradar(playerid, reason);
        #else
            return 1;
        #endif
    }

    #if !defined _inc_y_hooks && !defined _INC_y_hooks
        #if defined _ALS_OnPlayerDisconnect
            #undef OnPlayerDisconnect
        #else
            #define _ALS_OnPlayerDisconnect
        #endif
        #define OnPlayerDisconnect OnPlayerDisconnect_vradar
        #if defined OnPlayerDisconnect_vradar
            forward OnPlayerDisconnect_vradar(playerid, reason);
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

        new line_max, block_back_button;
        for(new x = (vehicle_radar_player[playerid][vrpList_Page] * VEHICLE_RADAR_MAX_ROWS_LIST)+1; x < MAX_VEHICLE_RADAR; x ++)
        {
            if(x >= MAX_VEHICLE_RADAR) break;
            if(vehicle_radar[x][vr_Create] == false) continue;
            if(line_max <= VEHICLE_RADAR_MAX_ROWS_LIST-1)
            {
                vehicle_radar_player[playerid][vrpList_SlotID][line_max] = x;
                format(string, sizeof(string), "%s#%d\t%d km/h\t%.1fm\t%s\n", string, x, vehicle_radar[x][vr_SpeedLimit], vehicle_radar[x][vr_ZoneSize], (vehicle_radar[x][vr_Disabled] == false) ? (""VEHICLE_RADAR_COLOR_1"On"):(""VEHICLE_RADAR_COLOR_2"Off"));    

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
        if(line_max == 0) return Dialog_Message(playerid, "List of radars", "{FFFFFF}No radars created.", "Cancel");

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
        if(vehicle_radar[radarid][vr_Create] == false) return 1;

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
            GetDynamicObjectPos(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_x], vehicle_radar[radarid][vr_Object_y], vehicle_radar[radarid][vr_Object_z]);
            GetDynamicObjectRot(vehicle_radar[radarid][vr_Object], vehicle_radar[radarid][vr_Object_rx], vehicle_radar[radarid][vr_Object_ry], vehicle_radar[radarid][vr_Object_rz]);

            vehicle_radar[radarid][vr_Disabled] = vehicle_radar_player[playerid][vrp_Disabled];
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