Language: **English** or [Russian](https://github.com/Bren828/vehicle-radar/blob/main/README.md)

# vehicle-radar
Создание транспортных радаров с ограничением скорости и зоной срабатывания.

## Reference
* [Download](https://github.com/Bren828/vehicle-radar#download)
* [Installation](https://github.com/Bren828/vehicle-radar#installation)
* [Example](https://github.com/Bren828/vehicle-radar#example)
* [Callbacks](https://github.com/Bren828/vehicle-radar#callbacks)
* [Functions](https://github.com/Bren828/vehicle-radar#functions)
* [Definition](https://github.com/Bren828/vehicle-radar#definition)

## Download
[Releases page](https://github.com/Bren828/vehicle-radar/releases)

## Installation

Include in your code and begin using the library:
```pawn
#include <vehicle-radar>
```

## Example

```pawn
new radarid = VehicleRadarLoad(130, 50.0,  0.0, 0.0, 0.0,  0.0, 0.0, 0.0); // create a radar
SetVehicleRadarExtraValue(radarid, 1005); // add the value

public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
{
    printf("Enter Vehicle Radar | radarid: %d | vehicleid: %d | activation_count: %d", radarid, vehicleid, activation_count)
    return 1;
}

public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
{
    printf("Create | radarid %d | speed_limit %d | zone_size %f | x %.2f | y %.2f | z %.2f | rx %.2f | ry %.2f | rz %.2f | worldid %d | int %d", 
        radarid, speed_limit, zone_size, x, y, z,  rx, ry,  rz,  worldid, interiorid
    );
    
    //Mysql R39-6 save example
    static const mysql_str[] = 
        "INSERT INTO vehicle_radar (`speed_limit`,`zone_size`,`x`,`y`,`z`,`rx`,`ry`,`rz`,`worldid`,`interiorid`) VALUE ('%d','%f','%f','%f','%f','%f','%f','%f','%d','%d')";
    new string[sizeof(mysql_str)];
    mysql_format(mysql, string, sizeof(string), mysql_str, speed_limit, zone_size,  x, y, z, rx, ry, rz,  worldid, interiorid);
    new Cache:result = mysql_query(mysql, string);
    if(!cache_is_valid(result))
    {
        SendClientMessage(playerid, -1, "mysql error creating a vehicle radar");
        cache_delete(result);
        return 1;
    }
    SetVehicleRadarExtraValue(radarid, cache_insert_id()); // writes the id of the new row
    cache_delete(result);
    return 1;
}

public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
{
    printf("Edit | radarid %d | speed_limit %d | zone_size %f | x %.2f | y %.2f | z %.2f | rx %.2f | ry %.2f | rz %.2f | worldid %d | int %d", 
        radarid, speed_limit, zone_size, x, y, z,  rx, ry,  rz,  worldid, interiorid
    );
    
    //Mysql R39-6 save example
    static const mysql_str[] = 
        "UPDATE vehicle_radar SET speed_limit=%d,zone_size='%f',x='%f',y='%f',z='%f',rx='%f',ry='%f',rz='%f',worldid=%d,interiorid=%d WHERE id=%d LIMIT 1";
    new string[sizeof(mysql_str)];
    mysql_format(mysql, string, sizeof(string), mysql_str, speed_limit, zone_size,  x, y, z, rx, ry, rz,  worldid, interiorid,  GetVehicleRadarExtraValue(radarid));
    mysql_tquery(mysql, string);
    return 1;
}

public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
{
    printf("Delete | radarid %d | extra_value %d", radarid, extra_value);
    
    //Mysql R39-6 save example
    static const mysql_str[] = "DELETE FROM vehicle_radar WHERE id=%d LIMIT 1";
    new string[sizeof(mysql_str) + 11];
    mysql_format(mysql, string, sizeof(string), mysql_str, extra_value);
    mysql_tquery(mysql, string);
    return 1;
}
```

## Callbacks
#### public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
* Вызывается при срабатывание радара
> * `playerid` - The ID of the player
> * `radarid` - The ID of the radar
> * `vehicleid` - The ID of vehicle
> * `activation_count` - количество срабатываний


#### public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Вызывается при создании нового радара
> * `radarid` - The ID of the radar
> * `speed_limit` - Speed limit in km/h
> * `Float:zone_size` - Trigger distance
> * `bool:disabled` - Disabled radar (false | true)
> * `Float:x` - The x coordinate to create the object at
> * `Float:y` - The y coordinate to create the object at
> * `Float:z` - The z coordinate to create the object at
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID 


#### public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Вызывается при редактировании созданного радара
> * `radarid` - The ID of the radar
> * `speed_limit` - Speed limit in km/h
> * `Float:zone_size` - Trigger distance
> * `bool:disabled` - Disabled radar (false | true)
> * `Float:x` - The x coordinate the object
> * `Float:y` - The y coordinate the object
> * `Float:z` - The z coordinate the object
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID


#### public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
> Вызывается при удалении радара
> * `radarid` - The ID of the radar
> * `extra_value` - Value
> * ПРИМЕЧАНИЕ: `extra_value` устанавливается через `SetVehicleRadarExtraValue`. Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


## Functions
#### VehicleRadarCreate(playerid)
> Create a radar
> * `playerid` - The ID of the player


#### VehicleRadarList(playerid)
> List of created radars
> * `playerid` - The ID of the player


#### VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "-1", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
> Load Radar
> * `speed_limit` - Speed limit in km/h
> * `Float:zone_size` - Trigger distance
> * `Float:x` - The x coordinate to create the object at
> * `Float:y` - The y coordinate to create the object at
> * `Float:z` - The z coordinate to create the object at
> * `Float:rx` - The x rotation of the object
> * `Float:ry` - The y rotation of the object
> * `Float:rz` - The z rotation of the object
> * `worldid` - The virtual world ID 
> * `interiorid` - The interior ID
> * `bool:disabled` - Disabled radar (false | true)
> * `const text3D[]` - 3DText
> * `text3D_color` - 3DText color
> * `Float:text3D_distance` - 3DText draw distance
> * Вернет (0) при неудачи или (ID) радара при успехе


#### DeleteVehicleRadar(playerid, radarid, bool:callback = true)
> Remove radar
> * `radarid` - The ID of the radar
> * `callback` - Call `OnPlayerVehicleRadarDelete` on deletion
> * Вернет (0) при неудачи или (1) при успехе


#### SetVehicleRadarActivationCount(radarid, count)
> Изменить количество срабатываний
> * `radarid` - The ID of the radar
> * `count` - количество
> * Вернет (0) при неудачи или (1) при успехе


#### GetVehicleRadarActivationCount(radarid)
> Узнать количество срабатываний
> * `radarid` - The ID of the radar
> * Вернет (0) при неудачи или количество срабатываний


#### SetVehicleRadarSpeedLimit(radarid, speed)
> Change the speed limit
> * `radarid` - The ID of the radar
> * `speed` - Speed in km/h
> * Вернет (0) при неудачи или (1) при успехе


#### GetVehicleRadarSpeedLimit(radarid)
> Узнать ограничение скорости
> * `radarid` - The ID of the radar
> * Вернет (0) при неудачи или текущую скорость


#### SetVehicleRadarZoneSize(radarid, Float:zone_size)
> Change the trigger distance
> * `radarid` - The ID of the radar
> * `Float:zone_size` - Trigger distance
> * Вернет (0) при неудачи или (1) при успехе


#### GetVehicleRadarZoneSize(radarid, &Float:zone_size)
> Узнать дистанцию срабатывания
> * `radarid` - The ID of the radar
> * `&Float:zone_size` - Current distance
> * Вернет (0) при неудачи или (1) при успехе


#### SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0)
> Change 3D Text
> * `radarid` - The ID of the radar
> * `text[]` - Test
> * `color` - Color
> * `Float:drawdistance` - Draw distance
> * `Float:x` - The X coordinate to create the text 
> * `Float:y` - The Y coordinate to create the text 
> * `Float:z` - The Z coordinate to create the text 
> * Вернет (0) при неудачи или (1) при успехе


#### SetVehicleRadarExtraValue(radarid, value)
> Изменить дополнительное значение
> * `radarid` - The ID of the radar
> * `value` - value
> * Вернет (0) при неудачи или (1) при успехе
> * ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


#### GetVehicleRadarExtraValue(radarid)
> Узнать дополнительное значение
> * `radarid` - The ID of the radar
> * Вернет (0) при неудачи или текущие значение
> * ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


## Definition
```pawn
#define MAX_VEHICLE_RADAR                   200

#define VEHICLE_RADAR_OBJECT_MODEL          18880 // object model

#define VEHICLE_RADAR_OBJECT_DISTANCE       200.0 // object draw distance

#define VEHICLE_RADAR_3DTEXT_LENGTH         144	// 3d text length

#define VEHICLE_RADAR_3DTEXT_TEXT           "Speed radar №%d\nSpeed Limit: %d (км/ч)" // text with value '-1' in 'VehicleRadarLoad'

#define VEHICLE_RADAR_3DTEXT_DISTANCE       15.0 // 3d text draw distance

#define VEHICLE_RADAR_MAX_ROWS_LIST         20 // максимальное количество строчек списка диалога

#define VEHICLE_RADAR_USE_EDITING_TOOLS     true //use editing tools

#define VEHICLE_RADAR_COLOR_1               "{8fce00}" // 0x8fce00

#define VEHICLE_RADAR_COLOR_2               "{f44747}" // 0xf44747

#define VEHICLE_RADAR_COLOR_3               "{F5D742}" // 0xF5D742

const Float:VEHICLE_RADAR_SPEED_MULTIPLIER = 179.28625; // speed multiplier
```
