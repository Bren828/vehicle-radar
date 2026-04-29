# vehicle-radar

Advanced speed radar library for SA-MP featuring dynamic creation, in-game editor, and multi-language interface.

> Note: The library supports both English and Russian languages. Use `#define VR_INTERFACE_LANGUAGE` 1 for Russian.

![Crosshair](https://raw.githubusercontent.com/Bren828/vehicle-radar/main/preview.png)

## Reference
* [Installation](#installation)
* [Example](#example)
* [Callbacks](#callbacks)
* [Functions](#functions)
* [Definition](#definition)

## Dependencies
* [mdialog](https://github.com/Open-GTO/mdialog)

Required if the radar editor is not disabled - `#define VR_DISABLE_EDITOR`

## Installation

Include in your code and begin using the library:
```pawn
#include <vehicle-radar>
```

## Example

```pawn
new radarid = CreateVehicleRadar(130, 50.0, 0.0, 0.0, 3.0, 0.0, 0.0, 0.0);
SetVehicleRadarExtraValue(radarid, 1005); // add the value


forward OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activationCount);
public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activationCount) {

    printf("Enter Vehicle Radar | radarid: %d | vehicleid: %d | activationCount: %d", radarid, vehicleid, activationCount);
    return 1;
}


forward OnPlayerVehicleRadarCreate(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid);
public OnPlayerVehicleRadarCreate(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid) {
    
    printf("Created | radarid: %d | speedLimit: %d | zoneSize: %f | x: %.2f | y: %.2f | z: %.2f | rx: %.2f | ry: %.2f | rz: %.2f | worldid: %d | interiorid: %d", 
        radarid, speedLimit, zoneSize, x, y, z,  rx, ry,  rz,  worldid, interiorid);
    

    //Save example
    static const mysql_str[] = "INSERT INTO `vehicle_radar` (\
        `speedLimit`,\
        `zoneSize`,\
        `disabled`,\
        `x`,\
        `y`,\
        `z`,\
        `rx`,\
        `ry`,\
        `rz`,\
        `world`,\
        `interior`) \
        \
        VALUE (\
        '%d',\
        '%f',\
        '%d',\
        '%f',\
        '%f',\
        '%f',\
        '%f',\
        '%f',\
        '%f',\
        '%d',\
        '%d')";
    new string[sizeof(mysql_str) + (10 * 10)];

    mysql_format(mysql, string, sizeof(string), mysql_str, 
        speedLimit, 
        zoneSize, 
        disabled, 
        x, y, z, 
        rx, ry, rz,  
        worldid, 
        interiorid);
    
    mysql_tquery(mysql, string, "OnSaveCreatedRadar", "d", radarid);
    return 1;
}


forward OnSaveCreatedRadar(radarid);
public OnSaveCreatedRadar(radarid) {

    SetVehicleRadarExtraValue(radarid, cache_insert_id()); // writes the id of the new row
	return 1;
}


forward OnPlayerVehicleRadarEdit(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid);
public OnPlayerVehicleRadarEdit(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid) {

    printf("Edit | radarid: %d | speedLimit: %d | zoneSize: %f | x: %.2f | y: %.2f | z: %.2f | rx: %.2f | ry: %.2f | rz: %.2f | world: %d | interior: %d", 
        radarid, speedLimit, zoneSize, x, y, z,  rx, ry,  rz,  worldid, interiorid);
    

    //Save example
    static const mysql_str[] = "UPDATE `vehicle_radar` SET \
        `speedLimit`='%d', \
        `zoneSize`='%f', \
        `disabled`='%d', \
        `x`='%f', \
        `y`='%f', \
        `z`='%f', \
        `rx`='%f', \
        `ry`='%f', \
        `rz`='%f', \
        `world`='%d', \
        `interior`='%d' WHERE `id`='%d' LIMIT 1";
    new string[sizeof(mysql_str) + (10 * 11)];

    mysql_format(mysql, string, sizeof(string), mysql_str, 
        speedLimit, 
        zoneSize, 
        disabled, 
        x, y, z, 
        rx, ry, rz,  
        worldid, 
        interiorid, 
        GetVehicleRadarExtraValue(radarid));
    
    mysql_tquery(mysql, string);
    return 1;
}


forward OnPlayerVehicleRadarDelete(playerid, radarid, extraValue);
public OnPlayerVehicleRadarDelete(playerid, radarid, extraValue) {

    printf("Delete | radarid %d | extraValue %d", radarid, extraValue);
    
    //Save example
    static const mysql_str[] = "DELETE FROM `vehicle_radar` WHERE `id`='%d' LIMIT 1";
    new string[sizeof(mysql_str) + 10];

    mysql_format(mysql, string, sizeof(string), mysql_str, extraValue);
    mysql_tquery(mysql, string);
    return 1;
}
```

## Callbacks
<details>
<summary>Click to expand the list</summary>

#### public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activationCount)
* Called when the radar is triggered
> * `playerid` - The ID of the player
> * `radarid` - The ID of the radar
> * `vehicleid` - The ID of vehicle
> * `activationCount` - Triggering


#### public OnPlayerVehicleRadarCreate(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Called when creating a radar
> * `radarid` - The ID of the radar
> * `speedLimit` - Speed limit in km/h
> * `Float:zoneSize` - Trigger distance
> * `bool:disabled` - Disabled radar (false | true)
> * `Float:x` - The x coordinate to create the object
> * `Float:y` - The y coordinate to create the object
> * `Float:z` - The z coordinate to create the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID 


#### public OnPlayerVehicleRadarEdit(playerid, radarid, speedLimit, Float:zoneSize, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Called when editing
> * `radarid` - The ID of the radar
> * `speedLimit` - Speed limit in km/h
> * `Float:zoneSize` - Trigger distance
> * `bool:disabled` - Disabled radar (false | true)
> * `Float:x` - The x coordinate the object
> * `Float:y` - The y coordinate the object
> * `Float:z` - The z coordinate the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID


#### public OnPlayerVehicleRadarDelete(playerid, radarid, extraValue)
> Called when the radar is removed
> * `radarid` - The ID of the radar
> * `extraValue` - Value
> * Note: `extraValue` is the value previously set via `SetVehicleRadarExtraValue`
</details>

## Functions
<details>
<summary>Click to expand the list</summary>

#### ShowRadarCreationDialog(playerid)
> Show the radar creation dialog
> * `playerid` - The ID of the player


#### ShowRadarListDialog(playerid)
> Show radar list dialog
> * `playerid` - The ID of the player


#### CreateVehicleRadar(speedLimit, Float:zoneSize, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, bool:disableText3D = false)
> Create a vehicle radar
> * `speedLimit` - Speed limit in km/h
> * `Float:zoneSize` - Trigger distance
> * `Float:x` - The x coordinate to create the object
> * `Float:y` - The y coordinate to create the object
> * `Float:z` - The z coordinate to create the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID
> * `bool:disabled` - Disabled radar
> * `bool:disableText3D` - Disabled text 3d
> * Returns (0) on failure or id radar


#### DeleteVehicleRadar(playerid, radarid, bool:callback = true)
> Remove radar
> * `playerid` - The ID of the player
> * `radarid` - The ID of the radar
> * `callback` - Call `OnPlayerVehicleRadarDelete` on deletion
> * Return: Returns (0) on failure or (1) on success


#### IsVehicleRadarCreated(radarid)
> Check if the vehicle radar is created
> * `radarid` - The ID of the radar
> * Return: Returns (0) on failure or (1) on success


#### SetVehicleRadarActivationCount(radarid, count)
> Set the number of triggers
> * `radarid` - The ID of the radar
> * `count` - Count
> * Return: Returns (0) on failure or (1) on success


#### GetVehicleRadarActivationCount(radarid)
> Get the number of triggers
> * `radarid` - The ID of the radar
> * Return: Returns (0) on failure or Count


#### SetVehicleRadarSpeedLimit(radarid, speed)
> Set a speed limit
> * `radarid` - The ID of the radar
> * `speed` - Speed in km/h
> * Return: Returns (0) on failure or (1) on success


#### GetVehicleRadarSpeedLimit(radarid)
> Get the speed limit
> * `radarid` - The ID of the radar
> * Return: Returns (0) on failure or speed


#### SetVehicleRadarZoneSize(radarid, Float:zoneSize)
> Set the trigger distance
> * `radarid` - The ID of the radar
> * `Float:zoneSize` - Trigger distance
> * Return: Returns (0) on failure or (1) on success


#### Float:GetVehicleRadarZoneSize(radarid)
> Get trigger distance
> * `radarid` - The ID of the radar
> * Return: Returns (0) on failure or ZoneSize


#### UpdateVehicleRadarText(radarid, const text[], color, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0)
> Update the radar text
> * `radarid` - The ID of the radar
> * `text[]` - Text
> * `color` - Color
> * `Float:x` - The X coordinate to create the text 
> * `Float:y` - The Y coordinate to create the text 
> * `Float:z` - The Z coordinate to create the text 
> * Return: Returns (0) on failure or (1) on success


#### SetVehicleRadarExtraValue(radarid, value)
> Set the value
> * `radarid` - The ID of the radar
> * `value` - value
> * Return: Returns (0) on failure or (1) on success


#### GetVehicleRadarExtraValue(radarid)
> Get the value
> * `radarid` - The ID of the radar
> * Return: Returns (0) on failure or Extra Value
</details>

## Definition
<details>
<summary>Click to expand the list</summary>

```pawn
#define VR_MAX_VEHICLE_RADAR 200
#define VR_INTERFACE_LANGUAGE 0 // 0 - English (default), 1 - Russian
#define VR_DISABLE_EDITOR
#define VR_OBJECT_MODEL 18880
#define VR_OBJECT_DISTANCE 200.0
#define VR_VEHICLE_SPEED_MULTIPLIER 179.28625 
#define VR_RESPONSE_DELAY 10 // seconds
#define VR_ZONE_MULTIPLIER 3 //The larger the multiplier, the larger the entry zone for checking "zone_size"
#define VR_MAX_ROWS_LIST 20 // max dialog list lines

#define VR_WHITE_COLOR_TAG "{ffffff}"
#define VR_GREEN_COLOR_TAG "{8fce00}"
#define VR_RED_COLOR_TAG "{f44747}"
#define VR_YELLOW_COLOR_TAG "{F5D742}"

#define VR_3DTEXT_LENGTH 144
#define VR_3DTEXT_DISTANCE 15.0 // 3d text draw distance
static VR_TEXT[] = "Speed radar #%d\nSpeed limit: %d (km/h)";

```
</details>
